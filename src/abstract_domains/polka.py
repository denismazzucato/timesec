
from copy import deepcopy
from typing import Callable

import numpy as np
from apronpy.lincons0 import ConsTyp
from apronpy.lincons1 import PyLincons1Array
from apronpy.polka import PyPolka, PyPolkaMPQstrictManager
from apronpy.tcons1 import PyTcons1, PyTcons1Array

from src.frontend.symbolic import MyEnvironment, MyVariable
from src.frontend.symbolic_to_apron import (
  arithmetic_to_apron,
  condition_to_apron,
  environment_to_apron,
  variable_to_apron,
)
from src.proto.abstract_value_domain import AbstractValueDomain, AnalysisDirection
from src.utils.globals import BOTTOM_CHAR, TOP_CHAR


class Polka(AbstractValueDomain):
  man = PyPolkaMPQstrictManager()

  def __init__(self, exprs: list[PyTcons1] | PyTcons1Array):
    self.man = Polka.man
    self.env = environment_to_apron()
    if isinstance(exprs, list):
      cons_array = PyTcons1Array(exprs, self.env)
    else:
      cons_array = exprs
    self.core = PyPolka(self.man, self.env, array=cons_array)

  def __deepcopy__(self, memodict=None) -> "Polka":
    new_polka = Polka([])
    new_polka.core = deepcopy(self.core)
    return new_polka

  def update_environment(self) -> "Polka":
    self.env = environment_to_apron()
    self.core.environment = self.env
    return self

  def _compute_new(self, operation: "Callable[[PyPolka], PyPolka]") -> "Polka":
    new_polka = deepcopy(self)
    new_polka.core = operation(new_polka.core)
    return new_polka

  def _join(self, other: "Polka") -> "Polka":
    return self._compute_new(
      lambda x: x.join(other.core)
    )

  def _meet(self, other: "Polka") -> "Polka":
    return self._compute_new(
      lambda x: x.meet(other.core)
    )

  def __str__(self) -> str:
    if self.is_bottom():
      return BOTTOM_CHAR
    if self.is_top():
      return TOP_CHAR
    return str(self.core)

  def _less_equal(self, other: "Polka") -> bool:
    return self.core <= other.core

  def _widening(self, other: "Polka") -> "Polka":
    return self._compute_new(
      lambda x: x.widening(other.core)
    )

  def assign(self, lhs, rhs, direction) -> "Polka":
    def _assign(x: PyPolka) -> PyPolka:
      if direction == AnalysisDirection.FORWARD:
        return x.assign(variable_to_apron(lhs), arithmetic_to_apron(rhs))
      return x.substitute(variable_to_apron(lhs), arithmetic_to_apron(rhs))
    return self._compute_new(_assign)

  def filter(self, cond, direction) -> "Polka":
    def _filter(x: PyPolka) -> PyPolka:
      return x.meet(PyTcons1Array(condition_to_apron(cond)))
    return self._compute_new(_filter)

  @staticmethod
  def bottom() -> "Polka":
    self = Polka([])
    self.core = PyPolka.bottom(Polka.man, self.env)
    return self

  @staticmethod
  def top() -> "Polka":
    self = Polka([])
    self.core = PyPolka.top(Polka.man, self.env)
    return self

  def __hash__(self) -> int:
    return hash(self.core.__repr__())

def to_a_bl_bu(p: PyPolka) -> tuple[dict[MyVariable, int], np.ndarray, np.ndarray, np.ndarray]:
  constraints: PyLincons1Array = p.to_lincons
  variables = MyEnvironment.my_variables()
  mapping = {variable: i for i, variable in enumerate(variables)}
  a, b_u, b_l = [], [], []
  for i in range(len(constraints)):
    current = constraints.get(i)
    operator = current.get_typ()
    free_coeff = float(str(current.get_cst()))
    match operator:
      case ConsTyp.AP_CONS_EQ:
        b_u.append(-free_coeff)
        b_l.append(-free_coeff)
      case ConsTyp.AP_CONS_SUPEQ:
        b_u.append(float("inf"))
        b_l.append(-free_coeff)
      case ConsTyp.AP_CONS_SUP:
        b_u.append(float("inf"))
        b_l.append(-free_coeff + 1)
      case _:
        raise NotImplementedError(f"Unsupported operator: {operator} during to_a_bl_bu")

    row = [0.] * len(variables)
    for k, j in mapping.items():
      coeff = float(str(current.get_coeff(variable_to_apron(k))))
      row[j] = coeff
    a.append(row)

  return mapping, np.array(a), np.array(b_l), np.array(b_u)
