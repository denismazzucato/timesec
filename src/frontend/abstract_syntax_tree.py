
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Callable

from src.frontend.symbolic import (
  MyBinaryExpression,
  MyBinaryOperator,
  MyEnvironment,
  MyExpression,
  MyVariable,
  MyVariableExpression,
  my_one,
  my_zero,
)
from src.proto.abstract_value_domain import AnalysisDirection
from src.utils.colors import cyan, green, orange, red, yellow
from src.utils.counter import Counter
from src.utils.globals import (
  BOTTOM_CHAR,
  COUNTER_VARIABLE_NAME,
  INPUT_STREAM_COUNTER_VARIABLE_PREFIX,
  INPUT_STREAM_VARIABLE_PREFIX,
  SYMBOLIC_VARIABLE_NAME,
)

TAB = "  "

@dataclass
class Coord:
  line: int
  column: int

  @staticmethod
  def from_pycparser(pycparser_coord):
    return Coord(pycparser_coord.line, pycparser_coord.column)

  def __str__(self):
    if self == Coord.empty():
      return BOTTOM_CHAR
    return f"{self.line}:{self.column}"

  @staticmethod
  def empty():
    return Coord(0, 0)

class AnnotationKey(Enum):
  DEPS_PRE = "deps_pre"
  DEPS_POST = "deps_post"
  ABS_PRE = "abs_pre"
  ABS_POST = "abs_post"
  FUTURE_ABS_PRE = "future_abs_pre"
  FUTURE_ABS_POST = "future_abs_post"

  @staticmethod
  def from_analysis_direction(direction: AnalysisDirection):
    if direction == AnalysisDirection.FORWARD:
      return AnnotationKey.ABS_POST
    return AnnotationKey.ABS_PRE

  @staticmethod
  def for_future_iterations(key: "AnnotationKey") -> "AnnotationKey":
    return AnnotationKey("future_" + key.value)

@dataclass(frozen=True)
class MyAtomicASTNode:
  id: int = field(
    default=Counter.incr("ast_id"),
    init=False,
    repr=False,
    compare=False,
    hash=False)
  coord: Coord = field(
    default_factory=Coord.empty,
    init=False,
    repr=False,
    compare=False,
    hash=False)
  annotations: dict[AnnotationKey, Any] = field(
    default_factory=dict,
    init=False,
    repr=False,
    compare=False,
    hash=False)

  def set_annotations(self, key: AnnotationKey, value: Any):
    self.annotations[key] = value

  def collect_all_deps(self) -> set[MyVariable]:
    x, y = self.annotations.get(AnnotationKey.DEPS_PRE, None), \
      self.annotations.get(AnnotationKey.DEPS_POST, None)
    xs = set()
    if x:
      xs |= x.may_used_variables()
    if y:
      xs |= y.may_used_variables()
    return xs

@dataclass(frozen=True)
class MySkip(MyAtomicASTNode):
  pass

@dataclass(frozen=True)
class MyAssign(MyAtomicASTNode):
  lhs: MyVariable
  rhs: MyExpression

@dataclass(frozen=True)
class MyAssume(MyAtomicASTNode):
  condition: MyExpression

@dataclass(frozen=True)
class MyComposedASTNode:
  annotations: dict[AnnotationKey, Any] = field(
    default_factory=dict,
    init=False,
    repr=False,
    compare=False,
    hash=False)
  id: int = field(
    default_factory=lambda: Counter.incr("ast_id"),
    init=False,
    repr=False,
    compare=False,
    hash=False)

  def set_annotations(self, key: AnnotationKey, value: Any):
    self.annotations[key] = value

  def pretty_str(
      self,
      indent: int = 0,
      _format: Callable[["MyComposedASTNode"], str] = lambda _: "") -> str:
    inner = ""
    formatted_annotations = _format(self)
    comment = " // " + formatted_annotations if formatted_annotations else ""
    match self:
      case MyStatement(ctx):
        match ctx:
          case MySkip():
            inner = "skip"
          case MyAssign(variable, value):
            inner = f"{variable} = {value}"
          case MyAssume(condition):
            inner = f"assume {condition}"
        inner = "\n" + inner + ";" + comment
      case MySequence(head, tail):
        inner = f"{head.pretty_str(_format=_format)}{tail.pretty_str(_format=_format)}"
      case MyWhile(condition, body):
        inner = f"\nwhile {condition} do{comment}{body.pretty_str(1, _format=_format)}\ndone;"
      case MyIf(condition, then_body, MySkip()):
        inner = f"\nif {condition} then{comment}{then_body.pretty_str(1, format=_format)}\nendif;"
      case MyIf(condition, then_body, else_body):
        inner = f"\nif {condition} then{comment}{then_body.pretty_str(1, _format=_format)}\n" + \
          f"else{else_body.pretty_str(1, _format=_format)}\nendif;"

    return inner.replace("\n", "\n" + "  " * indent)

  def update_annotations(self, direction: AnalysisDirection):
    key = AnnotationKey.from_analysis_direction(direction)
    future_key = AnnotationKey.for_future_iterations(key)
    self.annotations[key] = self.annotations[future_key]
    match self:
      case MySequence(first, second):
        first.update_annotations(direction)
        second.update_annotations(direction)
      case MyWhile(_, body):
        body.update_annotations(direction)
      case MyIf(_, then_branch, else_branch):
        then_branch.update_annotations(direction)
        else_branch.update_annotations(direction)

  def collect_all_deps(self) -> set[MyVariable]:
    match self:
      case MyStatement(statement):
        return statement.collect_all_deps()
      case MySequence(first, second):
        return first.collect_all_deps() | second.collect_all_deps()
      case MyWhile(_, body):
        return body.collect_all_deps()
      case MyIf(_, then_branch, else_branch):
        return then_branch.collect_all_deps() | else_branch.collect_all_deps()
      case _:
        return set()

@dataclass(frozen=True)
class MyStatement(MyComposedASTNode):
  ctx: MyAtomicASTNode

  def set_annotations(self, key: AnnotationKey, value: Any):
    super().set_annotations(key, value)
    self.ctx.set_annotations(key, value)

@dataclass(frozen=True)
class MySequence(MyComposedASTNode):
  first: MyComposedASTNode
  second: MyComposedASTNode

  def set_annotations(self, key: AnnotationKey, value: Any):
    super().set_annotations(key, value)
    self.first.set_annotations(key, value)
    self.second.set_annotations(key, value)

@dataclass(frozen=True)
class MyWhile(MyComposedASTNode):
  condition: MyExpression
  body: MyComposedASTNode

  def set_annotations(self, key: AnnotationKey, value: Any):
    super().set_annotations(key, value)
    self.body.set_annotations(key, value)

@dataclass(frozen=True)
class MyIf(MyComposedASTNode):
  condition: MyExpression
  then_branch: MyComposedASTNode
  else_branch: MyComposedASTNode

  def set_annotations(self, key: AnnotationKey, value: Any):
    super().set_annotations(key, value)
    self.then_branch.set_annotations(key, value)
    self.else_branch.set_annotations(key, value)

@dataclass(frozen=True)
class MyFunction:
  name: str
  lines: int
  body: MyComposedASTNode

  def _str(self, body_ctx: str) -> str:
    input_variables = set(map(lambda x: x.name, MyEnvironment.my_input_variables()))
    streams = set(filter(
      lambda x: x.startswith(INPUT_STREAM_VARIABLE_PREFIX) and \
        not x.startswith(INPUT_STREAM_COUNTER_VARIABLE_PREFIX),
      input_variables))
    params = set(filter(lambda x: not x.startswith(INPUT_STREAM_VARIABLE_PREFIX), input_variables))

    sorted_streams = sorted(streams)
    sorted_params = sorted(params)

    sorted_inputs = " |,| ".join([", ".join(sorted_params), ", ".join(sorted_streams)])

    return f"{yellow("function")} {self.name} ({sorted_inputs}):{body_ctx}"

  def __str__(self):
    return self._str(self.body.pretty_str())

  def str_with_dependencies(self) -> str:
    def _format(current: MyComposedASTNode) -> str:
      if not cached_is_relevant(current):
        return red("not relevant")
      match current:
        case MyStatement(ctx):
          annotations = ctx.annotations
          if AnnotationKey.DEPS_POST not in annotations or \
            AnnotationKey.DEPS_PRE not in annotations:
            return orange("no deps found")
          deps_pre = annotations[AnnotationKey.DEPS_PRE]
          deps_post = annotations[AnnotationKey.DEPS_POST]
          maybe_used = deps_pre.join(deps_post).may_used_variables()
          return f"{green("deps")}={{{", ".join(map(str, maybe_used))}}}"
        case _:
          return green("relevant")

    return self._str(self.body.pretty_str(_format=_format)) + "\n"

  def str_with_abstract_values(
      self,
      direction: AnalysisDirection = AnalysisDirection.BACKWARD) -> str:
    def _format(current: MyComposedASTNode) -> str:
      if not cached_is_relevant(current):
        return red("not relevant")
      key = AnnotationKey.from_analysis_direction(direction)
      if key not in current.annotations:
        return orange("no abs found")
      abs_elem = current.annotations[key]
      return cyan(str(abs_elem))

    last_comment = "// "
    if AnnotationKey.ABS_POST not in self.body.annotations:
      last_comment += orange("no abs found")
    else:
      last_comment += cyan(str(self.body.annotations[AnnotationKey.ABS_POST]))
    return self._str(self.body.pretty_str(_format=_format)) + "\n" + last_comment + "\n"

  def collect_all_deps(self) -> set[MyVariable]:
    return self.body.collect_all_deps()

  def set_annotations(self, key: AnnotationKey, default_value: Any):
    self.body.set_annotations(key, default_value)

  def annotation_exists(self, key: AnnotationKey) -> bool:
    return key in self.body.annotations

  def update_annotations(self, direction: AnalysisDirection):
    self.body.update_annotations(direction)

def increment(counter: MyVariable) -> MyAssign:
  return MyAssign(
    counter,
    MyBinaryExpression(
      MyBinaryOperator.ADD,
      MyVariableExpression(counter),
      my_one))

def assign_to_zero(counter: MyVariable) -> MyAssign:
  return MyAssign(
    counter,
    my_zero)

bucket_init = assign_to_zero(MyVariable(COUNTER_VARIABLE_NAME))
counter_increment = increment(MyVariable(COUNTER_VARIABLE_NAME))
bucket_end = MyAssume(
  MyBinaryExpression(
    MyBinaryOperator.EQUAL,
    MyVariableExpression(MyVariable(COUNTER_VARIABLE_NAME)),
    MyVariableExpression(MyVariable(SYMBOLIC_VARIABLE_NAME))))


def _is_relevant(ast: MyComposedASTNode) -> bool:
  match ast:
    case MyStatement(statement):
      match statement:
        case MyAssign(lhs, _, annotations=deps):
          return lhs.base in deps[AnnotationKey.DEPS_POST].may_used_variables() | \
            deps[AnnotationKey.DEPS_PRE].may_used_variables()
        case MyAssume(condition, annotations=deps):
          return condition.variables & \
            (deps[AnnotationKey.DEPS_POST].may_used_variables() | \
            deps[AnnotationKey.DEPS_PRE].may_used_variables())
    case MyIf(_, then_branch, else_branch):
      return _is_relevant(then_branch) or _is_relevant(else_branch)
    case MyWhile(_, loop_body):
      return _is_relevant(loop_body)
    case MySequence(first, second):
      return _is_relevant(first) or _is_relevant(second)

  return False

cache_is_relevant: dict[int, bool] = {}
def cached_is_relevant(ast: MyComposedASTNode) -> bool:
  if ast.id not in cache_is_relevant:
    cache_is_relevant[ast.id] = _is_relevant(ast)
  return cache_is_relevant[ast.id]
