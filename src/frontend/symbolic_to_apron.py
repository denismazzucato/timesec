from math import inf
from typing import Literal

from apronpy.coeff import (
  PyCoeff,
  PyMPQInterval,
  PyMPQIntervalCoeff,
  PyMPQScalarCoeff,
  PyScalarCoeff,
)
from apronpy.environment import PyEnvironment
from apronpy.lincons0 import ConsTyp
from apronpy.lincons1 import PyLincons1
from apronpy.linexpr1 import PyLinexpr1
from apronpy.polka import PyPolka
from apronpy.tcons1 import PyTcons1
from apronpy.var import PyVar
from interval import interval

from src.frontend.symbolic import (
  MyArrayVariable,
  MyBinaryExpression,
  MyBinaryOperator,
  MyConstantExpression,
  MyEnvironment,
  MyExpression,
  MyFunctionCallExpression,
  MyUnaryExpression,
  MyUnaryOperator,
  MyVariable,
  MyVariableExpression,
)
from src.utils.globals import INPUT_FUNCTION_NAME

DefaultScalarCoeff = PyMPQScalarCoeff
infinite_interval = PyMPQIntervalCoeff(PyMPQInterval.top()) # type: ignore

def default_scalar_coeff(value: float | int | interval) -> PyCoeff:
  if isinstance(value, (float, int)):
    return DefaultScalarCoeff(value)
  assert isinstance(value, interval)
  lower, upper = value[0].inf, value[-1].sup
  if lower != -inf or upper != inf:
    return PyMPQIntervalCoeff(PyMPQInterval(lower, upper))  # type: ignore
  return infinite_interval

class SymbolicToApronError(Exception):
  pass

def variable_to_apron(variable: MyVariable) -> PyVar:
  return PyVar(variable.name)

def environment_to_apron() -> PyEnvironment:
  return PyEnvironment([variable_to_apron(x) for x in MyEnvironment.my_variables()])

def numeric_constant_to_apron(constant: MyConstantExpression) -> PyScalarCoeff:
  if isinstance(constant.value, bool):
    raise SymbolicToApronError("Boolean constants cannot be translated to apron")
  return DefaultScalarCoeff(constant.value)

def get_coeff(expr: MyExpression, variable: MyVariable) -> float:
  if variable not in expr.variables:
    return 0
  match expr:
    case MyFunctionCallExpression(name, _) if name == INPUT_FUNCTION_NAME:
      return 0
    case MyArrayVariable():
      raise SymbolicToApronError(f"Array variable {expr} is not supported " + \
        "when translating to apron")
    case MyVariableExpression(MyVariable(name)):
      if name == variable.name:
        return 1
      return 0
    case MyConstantExpression():
      return 0
    case MyUnaryExpression(operator, child):
      match operator:
        case MyUnaryOperator.MINUS:
          return -get_coeff(child, variable)
        case MyUnaryOperator.PLUS:
          return get_coeff(child, variable)
    case MyBinaryExpression(operator, left, right):
      match operator:
        case MyBinaryOperator.ADD:
          return get_coeff(left, variable) + get_coeff(right, variable)
        case MyBinaryOperator.SUB:
          return get_coeff(left, variable) - get_coeff(right, variable)
        case MyBinaryOperator.MUL:
          match left, right:
            case (MyConstantExpression(value), MyVariableExpression(MyVariable(name))) | \
                (MyVariableExpression(MyVariable(name)), MyConstantExpression(value)):
              if variable.name == name:
                return value
              return 0
            case (MyUnaryExpression(MyUnaryOperator.MINUS, MyConstantExpression(value)),
                  MyVariableExpression(MyVariable(name))) | \
              (MyVariableExpression(MyVariable(name)),
               MyUnaryExpression(MyUnaryOperator.MINUS, MyConstantExpression(value))):
              if variable.name == name:
                return -value
              return 0
        case MyBinaryOperator.DIV:
          match right:
            case MyConstantExpression(value):
              return get_coeff(left, variable) / value

  raise SymbolicToApronError(f"Failed to get coefficient for {variable} in {expr}")

def get_free_coeff(expr: MyExpression) -> float | interval:
  match expr:
    case MyVariableExpression(_):
      return 0
    case MyFunctionCallExpression(name, args) if name == INPUT_FUNCTION_NAME:
      if not args:
        return interval(-inf, inf)
      if len(args) == 2 and isinstance(args[0], MyConstantExpression) and \
          isinstance(args[1], MyConstantExpression):
        low, up = args[0].value, args[1].value
        return interval(low, up)
    case MyConstantExpression(value):
      return value
    case MyUnaryExpression(operator, child):
      match operator:
        case MyUnaryOperator.MINUS:
          return -get_free_coeff(child)
        case MyUnaryOperator.PLUS:
          return get_free_coeff(child)
    case MyBinaryExpression(operator, left, right):
      match operator:
        case MyBinaryOperator.ADD:
          return get_free_coeff(left) + get_free_coeff(right) # type: ignore
        case MyBinaryOperator.SUB:
          return get_free_coeff(left) - get_free_coeff(right)
        case MyBinaryOperator.MUL:
          match left, right:
            case (MyConstantExpression(), MyVariableExpression()) | \
                (MyVariableExpression(), MyConstantExpression()):
              return 0
            case (MyUnaryExpression(MyUnaryOperator.MINUS, MyConstantExpression(value)),
                  MyVariableExpression(MyVariable(name))) | \
              (MyVariableExpression(MyVariable(name)),
               MyUnaryExpression(MyUnaryOperator.MINUS, MyConstantExpression(value))):
              return 0
        case MyBinaryOperator.DIV:
          match right:
            case MyConstantExpression(value):
              return get_free_coeff(left) / value
  raise SymbolicToApronError(f"Failed to get free coefficient in {expr}")

# @cache
def _arithmetic_to_apron(expr: MyExpression) -> dict[MyVariable | Literal["_"], float | interval]:
  variables = expr.variables
  result: dict[MyVariable | Literal["_"], float] = {
    variable: get_coeff(expr, variable) for variable in variables}
  result["_"] = get_free_coeff(expr)
  return result

def arithmetic_to_apron(expr: MyExpression) -> PyLinexpr1:
  lexpr = PyLinexpr1(environment_to_apron())
  for variable, coeff in _arithmetic_to_apron(expr).items():
    apron_coeff = default_scalar_coeff(coeff)
    if variable == "_":
      lexpr.set_cst(apron_coeff)
    else:
      lexpr.set_coeff(variable_to_apron(variable), apron_coeff)
  return lexpr

def condition_to_apron(condition: MyExpression) -> list[PyTcons1]:
  match condition:
    case MyVariableExpression(MyVariable(name)):
      lexpr = PyLinexpr1(environment_to_apron())
      lexpr.set_coeff(variable_to_apron(MyVariable(name)), DefaultScalarCoeff(1))
      return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_EQ, lexpr))]
    case MyBinaryExpression(MyBinaryOperator.LOGICAL_AND, left, right):
      return condition_to_apron(left) + condition_to_apron(right)
    case MyBinaryExpression(MyBinaryOperator.LOGICAL_OR, left, right):
      lexpr = PyLinexpr1(environment_to_apron())
      lexpr.set_cst(DefaultScalarCoeff(1))
      apron_true = PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, lexpr))
      return [apron_true]
    case MyBinaryExpression(operator, left, right):
      lexpr = arithmetic_to_apron(MyBinaryExpression(MyBinaryOperator.SUB, left, right))
      neg_lexpr = arithmetic_to_apron(MyBinaryExpression(MyBinaryOperator.SUB, right, left))
      match operator:
        case MyBinaryOperator.EQUAL:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_EQ, lexpr))]
        case MyBinaryOperator.NOT_EQUAL:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_DISEQ, lexpr))]
        case MyBinaryOperator.GREATER_THAN_OR_EQUAL:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, lexpr))]
        case MyBinaryOperator.GREATER_THAN:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUP, lexpr))]
        case MyBinaryOperator.LESS_THAN_OR_EQUAL:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, neg_lexpr))]
        case MyBinaryOperator.LESS_THAN:
          return [PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUP, neg_lexpr))]
    case MyUnaryExpression(operator, child):
      match operator:
        case MyUnaryOperator.LOGICAL_NOT:
          return condition_to_apron(child.logical_negate)
    case MyConstantExpression(True):
      lexpr = PyLinexpr1(environment_to_apron())
      lexpr.set_cst(DefaultScalarCoeff(1))
      apron_true = PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, lexpr))
      return [apron_true]
    case MyConstantExpression(False):
      lexpr = PyLinexpr1(environment_to_apron())
      lexpr.set_cst(DefaultScalarCoeff(-1))
      apron_false = PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, lexpr))
      return [apron_false]
    case MyFunctionCallExpression(name, x) if name == INPUT_FUNCTION_NAME:
      lexpr = PyLinexpr1(environment_to_apron())
      lexpr.set_cst(DefaultScalarCoeff(1))
      apron_true = PyTcons1(PyLincons1(ConsTyp.AP_CONS_SUPEQ, lexpr))
      return [apron_true]
  raise SymbolicToApronError(f"Failed to translate {condition} to apron")

def concretize_polka(p: PyPolka, variable: MyVariable, value: int) -> PyPolka:
  var = variable_to_apron(variable)
  lexpr = PyLinexpr1(p.environment)
  lexpr.set_cst(DefaultScalarCoeff(value))
  return p.substitute(var, lexpr)
