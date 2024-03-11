

from pathlib import Path

from pycparser import parse_file
from pycparser.c_ast import (
  ID,
  Assignment,
  BinaryOp,
  Compound,
  Constant,
  Decl,
  DeclList,
  DoWhile,
  EmptyStatement,
  FileAST,
  For,
  IdentifierType,
  If,
  Node,
  StaticAssert,
  TypeDecl,
  UnaryOp,
  While,
)

from src.frontend.abstract_syntax_tree import (
  MyAssign,
  MyAssume,
  MyComposedASTNode,
  MyFunction,
  MyIf,
  MySequence,
  MySkip,
  MyStatement,
  MyWhile,
  bucket_end,
  bucket_init,
  cache_is_relevant,
  counter_increment,
)
from src.frontend.extractor import (
  extract_condition_from_ast,
  extract_expression_from_ast,
  extract_variable_from_ast,
)
from src.frontend.safe_ast import get_function_name, get_function_params
from src.frontend.symbolic import (
  MyBinaryExpression,
  MyBinaryOperator,
  MyConstantExpression,
  MyEnvironment,
  MyExpression,
  MyVariable,
  MyVariableExpression,
  my_environments,
  my_zero,
)
from src.user_interface.logging import debug1
from src.utils.colors import title
from src.utils.counter import Counter
from src.utils.globals import (
  CINCLUDE_PATH,
  IMPACT_MAXIMUM_SPAN_VARIABLE_NAME,
  SECOND_SYMBOLIC_VARIABLE_NAME,
  get_global_symbolic_variables,
)
from src.utils.time import Timeit


def pycparser_wrapper(path: Path) -> tuple[FileAST, int]:
  cinclude_path = Path(CINCLUDE_PATH)
  cpp_args: str = [r"-E"] # type: ignore
  if cinclude_path.exists():
    cpp_args = [f"-I{cinclude_path}", *cpp_args] # type: ignore

  number_of_lines = -1
  with open(path, "r", encoding="utf-8") as f:
    number_of_lines = sum(1 for _ in f)

  debug1(title("Preprocessing") + f"gcc {" ".join(cpp_args)} {path}")
  return parse_file(
    path,
    use_cpp=True,
    cpp_path="gcc",
    cpp_args=cpp_args), number_of_lines

def is_unsigned(lhs_type: IdentifierType | None) -> bool:
  return lhs_type is not None and \
    all(t.startswith("u") for t in lhs_type.names if not t.startswith("undef"))

class ASTGenerator:

  def __init__(self):
    self.inputs: set[MyVariable] = set()
    self.opened_loops = set()

  def handle_input_streams_or_randoms(self, expr: MyExpression) -> MyExpression:
    if not self.opened_loops:
      self.inputs |= expr.contains_input_streams()
      expr = expr.replace_input_with_variables()
    else:
      expr.contains_randoms()
    return expr

  def handle_empty_statement(self) -> MyComposedASTNode:
    return MyStatement(MySkip())

  def handle_assignment(
      self,
      lhs: ID,
      rhs: Node | None,
      name_type: IdentifierType | None = None) -> MyComposedASTNode:
    lhs_var = extract_variable_from_ast(lhs)
    if rhs is not None:
      rhs_expr = extract_expression_from_ast(rhs)
      rhs_expr = self.handle_input_streams_or_randoms(rhs_expr)

      statement = MyAssign(lhs_var, rhs_expr)
    elif is_unsigned(name_type):
      cond = MyBinaryExpression(
        MyBinaryOperator.GREATER_THAN_OR_EQUAL,
        MyVariableExpression(lhs_var),
        my_zero)
      statement = MyAssume(cond)
    else:
      statement = MySkip()
    return MyStatement(statement)

  def handle_unary(self, op: str, expr: Node) -> MyComposedASTNode:
    if not isinstance(expr, ID):
      raise NotImplementedError(f"Unary operation {op} not supported for {expr}")
    match op:
      case "++" | "p++":
        rhs_op = "+"
      case "--" | "p--":
        rhs_op = "-"
      case _:
        raise NotImplementedError(f"Unary operation {op} not supported")

    return self.handle_assignment(expr, BinaryOp(rhs_op, expr, Constant("int", "1")))


  def handle_if(
      self,
      cond: Node,
      then_branch: Compound,
      else_branch: Compound | None) -> MyComposedASTNode:
    cond_expr = extract_condition_from_ast(cond)
    cond_expr = self.handle_input_streams_or_randoms(cond_expr)

    then_node = self.handle_compound(then_branch)
    else_node = self.handle_compound(else_branch)
    return MyIf(cond_expr, then_node, else_node)

  def handle_while(self, cond: Node, loop_body: Compound) -> MyComposedASTNode:
    cond_expr = extract_condition_from_ast(cond)
    cond_expr = self.handle_input_streams_or_randoms(cond_expr)

    body_node = self.handle_compound(loop_body)
    return MyWhile(
      cond_expr,
      MySequence(body_node, MyStatement(counter_increment)))

  def handle_dowhile(self, cond: Node, loop_body: Compound) -> MyComposedASTNode:
    cond_expr = extract_condition_from_ast(cond)
    cond_expr = self.handle_input_streams_or_randoms(cond_expr)

    body_node = self.handle_compound(loop_body)
    return MySequence(
            MySequence(
              body_node,
              MyStatement(counter_increment)),
            MyWhile(cond_expr, MySequence(
              body_node,
              MyStatement(counter_increment))))

  def handle_for(
      self,
      init: Node | None,
      cond: Node,
      op: Node,
      for_body: Compound) -> MyComposedASTNode:
    init_node = self.handle_compound(init)
    cond_expr = extract_condition_from_ast(cond)
    cond_expr = self.handle_input_streams_or_randoms(cond_expr)

    op_node = self.handle_compound(op)
    body_node = self.handle_compound(for_body)
    return MySequence(
            init_node,
            MyWhile(cond_expr, MySequence(
              body_node,
              MySequence(
                op_node,
                MyStatement(counter_increment)))))

  def handle_static_assert(self, cond: Node) -> MyComposedASTNode:
    cond_expr = extract_condition_from_ast(cond)
    return MyStatement(MyAssume(cond_expr))

  def handle_compound(self, items: Node | Compound | None) -> MyComposedASTNode:
    def handle_node(node: Node) -> MyComposedASTNode:
      match node:
        case EmptyStatement():
          return self.handle_empty_statement()
        case Assignment(op="=", lvalue=lhs, rvalue=rhs):
          return self.handle_assignment(lhs, rhs)
        case Assignment(op="+=", lvalue=lhs, rvalue=rhs):
          return self.handle_assignment(lhs, BinaryOp("+", lhs, rhs))
        case Assignment(op="-=", lvalue=lhs, rvalue=rhs):
          return self.handle_assignment(lhs, BinaryOp("-", lhs, rhs))
        case Decl(name=name, init=rhs, type=TypeDecl(type=name_type)):
          return self.handle_assignment(ID(name), rhs, name_type)
        case Decl(name=name, init=rhs):
          return self.handle_assignment(ID(name), rhs)
        case DeclList(decls=decls):
          return self.handle_compound(Compound(decls))
        case UnaryOp(op=op, expr=expr):
          return self.handle_unary(op, expr)
        case If(cond=cond, iftrue=then_branch, iffalse=else_branch):
          return self.handle_if(cond, then_branch, else_branch)
        case While(cond=cond, stmt=loop_body, coord=coord):
          self.opened_loops.add(coord)
          out = self.handle_while(cond, loop_body)
          self.opened_loops.remove(coord)
          return out
        case DoWhile(cond=cond, stmt=loop_body, coord=coord):
          self.opened_loops.add(coord)
          out = self.handle_dowhile(cond, loop_body)
          self.opened_loops.remove(coord)
          return out
        case StaticAssert(cond=cond):
          return self.handle_static_assert(cond)
        case For(init=init, cond=cond, next=op, stmt=for_body, coord=coord):
          self.opened_loops.add(coord)
          out = self.handle_for(init, cond, op, for_body)
          self.opened_loops.remove(coord)
          return out
        case _:
          node.show()
          raise NotImplementedError(f"Node {node} not supported during ast generation")

    if items is None or (isinstance(items, Compound) and not items.block_items):
      return self.handle_empty_statement()
    if not isinstance(items, Compound):
      return handle_node(items)
    if len(items.block_items) == 1:
      return handle_node(items.block_items[0])

    current, *rest = items.block_items
    return MySequence(handle_node(current), self.handle_compound(Compound(rest)))

  @staticmethod
  def create_input_bounds(
      input_variables: set[MyVariable],
      bounds: tuple[float, float]) -> MyComposedASTNode:
    input_constraints = MyStatement(MySkip())
    for input_variable in input_variables:
      lower, upper = bounds
      MyEnvironment.add_input(input_variable)
      input_expr = MyVariableExpression(input_variable)
      if lower != -float("inf"):
        lower_expr = MyConstantExpression(int(lower))
        input_constraints = MySequence(
          input_constraints,
          MyStatement(
            MyAssume(
              MyBinaryExpression(
                MyBinaryOperator.GREATER_THAN_OR_EQUAL,
                input_expr,
                lower_expr))))
      if upper != float("inf"):
        upper_expr = MyConstantExpression(int(upper))
        input_constraints = MySequence(
          input_constraints,
          MyStatement(
            MyAssume(
              MyBinaryExpression(
                MyBinaryOperator.LESS_THAN_OR_EQUAL,
                input_expr,
                upper_expr))))
    return input_constraints

  @staticmethod
  def handle_function(
      function_name: str,
      lines: int,
      params: list[Decl],
      body: list[Node],
      bounds: tuple[float, float]) -> MyFunction:
    for env in my_environments:
      env.clear()
    Counter.reset()
    Timeit.clear_running_times()
    cache_is_relevant.clear()
    MyVariable(SECOND_SYMBOLIC_VARIABLE_NAME)
    MyVariable(IMPACT_MAXIMUM_SPAN_VARIABLE_NAME)
    for global_symbolic_variable_name in get_global_symbolic_variables().values():
      MyVariable(global_symbolic_variable_name)
    composed_body = Compound([
      *params,
      *body
    ])
    gen = ASTGenerator()
    my_body = gen.handle_compound(composed_body)
    input_constraints = ASTGenerator.create_input_bounds(
      {MyVariable(param.name) for param in params} | gen.inputs,
      bounds)
    # for stream, within_loops in gen.streams:
    #   my_body = MySequence(MyStatement(assign_to_zero(stream.to_counter())), my_body)
    ast = MySequence(
      MyStatement(bucket_init),
      MySequence(
        input_constraints,
        MySequence(
          my_body,
          MyStatement(bucket_end))))
    # for stream in gen.streams:
    #   counter = stream.to_counter()
    #   length = stream.to_counter_length()
    #   ast = MySequence(ast, MyStatement(MyAssume(
    #     MyBinaryExpression(
    #       MyBinaryOperator.EQUAL,
    #       MyVariableExpression(length),
    #       MyVariableExpression(counter)))))
    return MyFunction(function_name, lines, ast)

@Timeit("parse")
def parse(program: Path, function_name: str, bounds: tuple[float, float]) -> MyFunction:
  pycparser_ast, lines = pycparser_wrapper(program)

  for ext in pycparser_ast.ext:
    if function_name == get_function_name(ext):
      params: list[Decl] = get_function_params(ext)
      body: list[Node] = ext.body.block_items
      if body is None:
        body = []
      my_function = ASTGenerator.handle_function(function_name, lines, params, body, bounds)
      return my_function

  raise ValueError(f"Function {function_name} not found in {program}")
