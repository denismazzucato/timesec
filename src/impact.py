
from collections import defaultdict
from dataclasses import dataclass
from math import inf

import numpy as np
from apronpy.polka import PyPolka
from scipy.optimize import LinearConstraint, milp

from src.abstract_domains.polka import Polka, to_a_bl_bu
from src.abstract_domains.syntactic_dependencies.usage_lattice import (
  UsageAbstractDomain,
)
from src.frontend.symbolic import (
  MyBinaryExpression,
  MyBinaryOperator,
  MyEnvironment,
  MyVariable,
  MyVariableExpression,
  my_zero,
)
from src.frontend.symbolic_to_apron import (
  arithmetic_to_apron,
  condition_to_apron,
  variable_to_apron,
)
from src.proto.abstract_value_domain import AbstractValueDomain
from src.user_interface.logging import debug2
from src.utils.colors import cyan
from src.utils.globals import (
  IMPACT_MAXIMUM_SPAN_VARIABLE_NAME,
  INFINITY_CHAR,
  SECOND_SYMBOLIC_VARIABLE_NAME,
  SYMBOLIC_VARIABLE_NAME,
)
from src.utils.time import Timeit, Timeout

INFEASIBLE = 2
UNBOUNDED = 3
OTHER = 4


@dataclass
class ImpactIntWrapper:
  """
    Wrapper class for representing impact values.

    Attributes:
        n (int | float): The numerical value representing the impact.
  """
  n: int | float

  def to_number(self) -> int | float:
    if self.n == float("inf"):
      return float("inf")
    if self.n.is_integer():
      return int(self.n)
    raise ValueError("Quantitative impact must be an integer of infinity")

  def __lt__(self, other: "ImpactIntWrapper") -> bool:
    return self.n < other.n



@dataclass
class QualitativeZero(ImpactIntWrapper):
  """
    Class representing a qualitative impact value of zero.
  """
  n: int = 0

  def __str__(self) -> str:
    return "0"

@dataclass
class QuantitativeInt(ImpactIntWrapper):
  """
    Class representing a quantitative impact value as an integer or infinity.
  """
  n: float

  def __str__(self) -> str:
    if self.n == float("inf"):
      return str(INFINITY_CHAR)
    if self.n.is_integer():
      return f"{int(self.n)}"
    raise ValueError("Quantitative impact must be an integer of infinity")

def compute_impact_of(
  inv: PyPolka,
  variable: MyVariable,
  symbolic_variable: MyVariable) -> float:
  """
  Compute the impact of a variable on a given invariant.

  Args:
    inv (PyPolka): The invariant to compute the impact on.
    variable (MyVariable): The variable to compute the impact for.
    symbolic_variable (MyVariable): The symbolic variable used in the computation.

  Returns:
    float: The computed impact value.

  Raises:
    ValueError: If the computation of impact fails.

  """
  if inv.is_bottom():
    return 0
  if inv.is_top():
    return float("inf")
  debug2(f"Impact computation for variable {cyan(variable)}, initial: {inv}")
  inv_without_variable = inv.forget([variable_to_apron(variable)])
  debug2(f"Inv without variable: {inv_without_variable}")
  second_symbolic_variable = MyVariable(SECOND_SYMBOLIC_VARIABLE_NAME)
  impact_maximum_span_variable = MyVariable(IMPACT_MAXIMUM_SPAN_VARIABLE_NAME)
  inv_without_variable_copy = inv_without_variable.substitute(
    variable_to_apron(symbolic_variable),
    arithmetic_to_apron(MyVariableExpression(second_symbolic_variable)))
  debug2(f"Inv without variable copy: {inv_without_variable_copy}")
  diff = Polka(condition_to_apron(
    MyBinaryExpression(
      MyBinaryOperator.LOGICAL_AND,
      MyBinaryExpression(
        MyBinaryOperator.GREATER_THAN_OR_EQUAL,
        MyVariableExpression(impact_maximum_span_variable),
        my_zero),
      MyBinaryExpression(
        MyBinaryOperator.LESS_THAN_OR_EQUAL,
        MyBinaryExpression(
          MyBinaryOperator.ADD,
          MyVariableExpression(symbolic_variable),
          MyVariableExpression(impact_maximum_span_variable),
        ),
        MyVariableExpression(second_symbolic_variable),)
  ))).core
  debug2(f"Diff: {diff}")
  p = inv_without_variable.meet(inv_without_variable_copy).meet(diff)
  debug2(f"LP: {p}")
  mapping, a, b_l, b_u = to_a_bl_bu(p)

  c = np.zeros(len(mapping))
  c[mapping[impact_maximum_span_variable]] = -1

  constraints = LinearConstraint(a, b_l, b_u) # type: ignore
  integrality = np.ones_like(c)

  res = milp(c=c, constraints=constraints, integrality=integrality)

  if res.success:
    return -res.fun
  if res.status == UNBOUNDED or \
      (res.status == OTHER and "The problem is unbounded or infeasible" in res.message):
    return float("inf")
  if res.status == INFEASIBLE:
    return 0
  raise ValueError(f"Failed to compute impact (status: {res.status}): {res.message}")


def compute_impact(
    inv: PyPolka,
    variables: set[MyVariable],
    symbolic_variable: MyVariable) -> dict[MyVariable, ImpactIntWrapper]:
  """
    Compute impacts of variables on a given invariant.

    Args:
        inv (PyPolka): The invariant to compute the impacts on.
        variables (set[MyVariable]): Set of variables to compute impacts for.
        symbolic_variable (MyVariable): The symbolic variable used in the computation.

    Returns:
        dict[MyVariable, ImpactIntWrapper]: Dictionary mapping variables to their impacts.
    """
  return {variable:
          QuantitativeInt(compute_impact_of(inv, variable, symbolic_variable))
          for variable in variables}

@Timeit("impact_analysis")
@Timeout(defaultdict(lambda: QuantitativeInt(inf)))
def impact_analysis(
    input_deps: UsageAbstractDomain,
    inv: AbstractValueDomain | None) -> dict[MyVariable, ImpactIntWrapper]:
  """
    Perform impact analysis.

    Args:
        input_deps (UsageAbstractDomain): Usage lattice representing syntactic dependencies.
        inv (AbstractValueDomain | None): The invariant to analyze.

    Returns:
        dict[MyVariable, ImpactIntWrapper]: Dictionary mapping variables to their impacts.
    """
  if inv is None:
    return defaultdict(lambda: QuantitativeInt(inf))
  if not isinstance(inv, Polka):
    raise ValueError("Impact analysis requires Polka abstract domain as precondition")

  variables = MyEnvironment.my_variables() - MyEnvironment.my_symbolic_variables()

  inv_polka = inv.core
  symbolic_variable = MyVariable(SYMBOLIC_VARIABLE_NAME)
  used_variables = input_deps.may_used_variables() - MyEnvironment.my_symbolic_variables()
  unused_variables = variables - used_variables | MyEnvironment.my_symbolic_variables()
  qualitative_impacts = {variable: QualitativeZero() for variable in unused_variables}
  quantitative_impacts = compute_impact(
    inv_polka,
    used_variables,
    symbolic_variable)
  debug2(f"Quantitative impacts: {quantitative_impacts}")
  return {**qualitative_impacts, **quantitative_impacts}
