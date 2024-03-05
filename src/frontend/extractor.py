
from pycparser.c_ast import (
  ID,
  ArrayRef,
  BinaryOp,
  Cast,
  Constant,
  FuncCall,
  Node,
  StructRef,
  UnaryOp,
)

from src.frontend.symbolic import (
  MyArrayVariable,
  MyAtomicExpression,
  MyBinaryExpression,
  MyBinaryOperator,
  MyConstantExpression,
  MyExpression,
  MyFunctionCallExpression,
  MyStructVariable,
  MyUnaryExpression,
  MyUnaryOperator,
  MyVariable,
  MyVariableExpression,
  my_zero,
)


def extract_array_dereference_from_ast(expr: Node) -> MyArrayVariable:
  match expr:
    case ID(name=name):
      return MyArrayVariable(name, MyConstantExpression(0))
    case ArrayRef(name=ID(name=name), subscript=subscript):
      my_subscript = extract_expression_from_ast(subscript)
      return MyArrayVariable(name, my_subscript)
    case Cast(expr=expr):
      return extract_array_dereference_from_ast(expr)
    case UnaryOp(op="*", expr=child):
      return extract_array_dereference_from_ast(child)
    case BinaryOp(op="+", left=lhs, right=rhs):
      my_lhs = extract_expression_from_ast(lhs)
      my_rhs = extract_expression_from_ast(rhs)
      return MyArrayVariable.from_sum(my_lhs, my_rhs)
    case _:
      raise NotImplementedError("Unsupported array dereference during extraction from ast: " + \
        f"{expr} (at {getattr(expr, "coord", None)})")

def extract_variable_from_ast(expr: Node) -> MyVariable:
  match expr:
    case ID(name=name):
      return MyVariable(name)
    case StructRef(name=ID(name=name), field=ID(name=field)):
      return MyStructVariable(name, field)
    case Cast(expr=expr):
      return extract_variable_from_ast(expr)
    case ArrayRef() | UnaryOp(op="*"):
      return extract_array_dereference_from_ast(expr)
    case _:
      raise NotImplementedError("Unsupported variable during extraction from ast: " + \
        f"{expr} (at {getattr(expr, "coord", None)})")

def extract_expression_from_ast(expr: Node) -> MyExpression:
  match expr:
    case ID(name="false") | ID(name="true"):
      return MyConstantExpression(expr.name == "true")
    case ID() | StructRef() | ArrayRef() | UnaryOp(op="*"):
      return MyVariableExpression(extract_variable_from_ast(expr))
    case Constant(value=value):
      return MyConstantExpression.from_string(value)

    case Cast(expr=expr):
      return extract_expression_from_ast(expr)
    case FuncCall(name=ID(name=name), args=arguments, coord=coord):
      if arguments:
        my_args = tuple(extract_expression_from_ast(arg) for arg in arguments)
      else:
        my_args = tuple()
      return MyFunctionCallExpression(name, my_args, coord=(coord.line, coord.column)) # type: ignore
    case BinaryOp(op="<<", left=ID(name=variable), right=Constant(value=value)):
      return MyBinaryExpression(
        MyBinaryOperator.MUL,
        MyConstantExpression(2 ** MyConstantExpression.from_string(value).value),
        MyVariableExpression(MyVariable(variable)))
    case BinaryOp(op=">>", left=ID(name=name), right=Constant(value=value)):
      return MyBinaryExpression(
        MyBinaryOperator.MUL,
        MyConstantExpression(1 / (2 * MyConstantExpression.from_string(value).value)), # type: ignore
        MyVariableExpression(MyVariable(name)))
    case BinaryOp(op=">>", left=BinaryOp(op="+", left=ID(name=name), right=Constant(value=constant_value)), right=Constant(value=value)):
      return MyBinaryExpression(
        MyBinaryOperator.ADD,
        MyBinaryExpression(
          MyBinaryOperator.MUL,
          MyConstantExpression(1 / (2 ** MyConstantExpression.from_string(value).value)),
          MyVariableExpression(MyVariable(name))),
        MyConstantExpression(
          MyConstantExpression.from_string(constant_value).value /
          (2 ** MyConstantExpression.from_string(value).value)))
    case BinaryOp(op=operator, left=lhs, right=rhs):
      if operator not in MyBinaryOperator:
        raise NotImplementedError("Unsupported binary operator during extraction from ast: " + \
          f"{operator} (at {expr.coord})")
      my_lhs = extract_expression_from_ast(lhs)
      my_rhs = extract_expression_from_ast(rhs)
      return MyBinaryExpression(MyBinaryOperator(operator), my_lhs, my_rhs)
    case UnaryOp(op=operator, expr=child):
      if operator not in MyUnaryOperator:
        raise NotImplementedError("Unsupported unary operator during extraction from ast: " + \
          f"{operator} (at {expr.coord})")
      my_child = extract_expression_from_ast(child)
      return MyUnaryExpression(MyUnaryOperator(operator), my_child)
    case _:
      raise NotImplementedError("Unsupported expression during extraction from ast: " + \
        f"{expr} (at {getattr(expr, "coord", None)})")

def extract_condition_from_ast(cond: Node) -> MyExpression:
  def add_equality_with_zero_for_variables(expr: MyExpression) -> MyExpression:
    match expr:
      case MyAtomicExpression() | MyFunctionCallExpression():
        return MyBinaryExpression(MyBinaryOperator.EQUAL, expr, my_zero)
      case MyBinaryExpression(op, left, right):
        match op:
          case MyBinaryOperator.LOGICAL_AND | MyBinaryOperator.LOGICAL_OR:
            return MyBinaryExpression(
              op,
              add_equality_with_zero_for_variables(left),
              add_equality_with_zero_for_variables(right))
        return MyBinaryExpression(op, left, right)
      case MyUnaryExpression(op, child):
        return MyUnaryExpression(op, add_equality_with_zero_for_variables(child))
    return expr
  extracted_exp = extract_expression_from_ast(cond)
  return add_equality_with_zero_for_variables(extracted_exp)
