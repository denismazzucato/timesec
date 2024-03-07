
from dataclasses import dataclass, field
from enum import Enum
from logging import warning

from src.utils.counter import Counter
from src.utils.globals import (
  INPUT_FUNCTION_NAME,
  INPUT_STREAM_VARIABLE_PREFIX,
  SYMBOLIC_VARIABLE_PREFIX,
)


class MyUnaryOperator(Enum):
  LOGICAL_NOT = "!"
  BITWISE_NOT = "~"
  PLUS = "+"
  MINUS = "-"

class MyBinaryOperator(Enum):
  # Arithmetic
  ADD = "+"
  SUB = "-"
  MUL = "*"
  DIV = "/"
  MOD = "%"
  # Bitwise
  BITWISE_AND = "&"
  BITWISE_OR = "|"
  BITWISE_XOR = "^"
  BITWISE_LSHIFT = "<<"
  BITWISE_RSHIFT = ">>"
  # Logical
  LOGICAL_AND = "&&"
  LOGICAL_OR = "||"
  # Comparison
  EQUAL = "=="
  NOT_EQUAL = "!="
  LESS_THAN = "<"
  LESS_THAN_OR_EQUAL = "<="
  GREATER_THAN = ">"
  GREATER_THAN_OR_EQUAL = ">="

class MyEnvironment:
  _variables: set[str] = set()
  _input_variables: set[str] = set()

  @staticmethod
  def add(var: "MyVariable") -> None:
    MyEnvironment._variables.add(var.name)

  @staticmethod
  def add_input(var: "MyVariable") -> None:
    MyEnvironment.add(var)
    MyEnvironment._input_variables.add(var.name)

  @staticmethod
  def variables() -> set[str]:
    return MyEnvironment._variables

  @staticmethod
  def my_variables() -> set["MyVariable"]:
    return {MyVariable(x) for x in MyEnvironment._variables}

  @staticmethod
  def my_input_variables() -> set["MyVariable"]:
    return {MyVariable(x) for x in MyEnvironment._input_variables} | \
      MyEnvironment.my_input_streams()

  @staticmethod
  def my_input_streams() -> set["MyVariable"]:
    return {MyVariable(x) for x in MyEnvironment._variables if
      x.startswith(INPUT_STREAM_VARIABLE_PREFIX)}

  @staticmethod
  def my_symbolic_variables() -> set["MyVariable"]:
    return {MyVariable(x) for x in MyEnvironment._variables if
      x.startswith(SYMBOLIC_VARIABLE_PREFIX)}

  @staticmethod
  def clear() -> None:
    MyEnvironment._variables = set()
    MyEnvironment._input_variables = set()

class BehavesLikeArrays:
  _variables: set[str] = set()

  @staticmethod
  def add(var: "MyVariable") -> None:
    BehavesLikeArrays._variables.add(var.name)

  @staticmethod
  def variables() -> set[str]:
    return BehavesLikeArrays._variables

  @staticmethod
  def my_variables() -> set["MyVariable"]:
    return {MyVariable(x) for x in BehavesLikeArrays._variables}

  @staticmethod
  def clear() -> None:
    BehavesLikeArrays._variables = set()

my_environments = (MyEnvironment, BehavesLikeArrays)

@dataclass(frozen=True)
class MyVariable:
  name: str

  def __post_init__(self):
    MyEnvironment.add(self)

  def __str__(self):
    return f"{self.name}"

  @property
  def base(self) -> "MyVariable":
    return MyVariable(self.name)

  # def to_counter(self) -> "MyVariable":
  #   if not self.name.startswith(INPUT_STREAM_VARIABLE_PREFIX):
  #     raise ValueError(f"Invalid user input variable: {self.name}")
  #   idx = self.name[len(INPUT_STREAM_VARIABLE_PREFIX):]
  #   return MyVariable(INPUT_STREAM_COUNTER_VARIABLE_PREFIX + idx)

  # def to_counter_length(self) -> "MyVariable":
  #   if not self.name.startswith(INPUT_STREAM_VARIABLE_PREFIX):
  #     raise ValueError(f"Invalid user input variable: {self.name}")
  #   idx = self.name[len(INPUT_STREAM_VARIABLE_PREFIX):]
  #   return MyVariable(INPUT_STREAM_COUNTER_LENGTH_VARIABLE_PREFIX + idx)


@dataclass(frozen=True)
class MyStructVariable(MyVariable):
  field: str

  def __str__(self):
    return f"{self.name}.{self.field}"

@dataclass(frozen=True)
class MyExpression:
  id: int = field(
    default_factory=lambda: Counter.incr("expr"),
    hash=False,
    init=False,
    repr=False,
  )

  @property
  def variables(self) -> set[MyVariable]:
    return set()

  @property
  def logical_negate(self) -> "MyExpression":
    match self:
      case MyConstantExpression(True):
        return my_false
      case MyConstantExpression(False):
        return my_true
      case MyUnaryExpression(MyUnaryOperator.LOGICAL_NOT, child):
        return child
      case MyBinaryExpression(operator, left, right):
        match operator:
          case MyBinaryOperator.EQUAL:
            return MyBinaryExpression(MyBinaryOperator.NOT_EQUAL, left, right)
          case MyBinaryOperator.NOT_EQUAL:
            return MyBinaryExpression(MyBinaryOperator.EQUAL, left, right)
          case MyBinaryOperator.LESS_THAN:
            return MyBinaryExpression(MyBinaryOperator.GREATER_THAN_OR_EQUAL, left, right)
          case MyBinaryOperator.LESS_THAN_OR_EQUAL:
            return MyBinaryExpression(MyBinaryOperator.GREATER_THAN, left, right)
          case MyBinaryOperator.GREATER_THAN:
            return MyBinaryExpression(MyBinaryOperator.LESS_THAN_OR_EQUAL, left, right)
          case MyBinaryOperator.GREATER_THAN_OR_EQUAL:
            return MyBinaryExpression(MyBinaryOperator.LESS_THAN, left, right)
          case MyBinaryOperator.LOGICAL_AND:
            return MyBinaryExpression(
              MyBinaryOperator.LOGICAL_OR,
              left.logical_negate,
              right.logical_negate)
          case MyBinaryOperator.LOGICAL_OR:
            return MyBinaryExpression(
              MyBinaryOperator.LOGICAL_AND,
              left.logical_negate,
              right.logical_negate)
    raise NotImplementedError(f"Unsupported logical negation for {self}")


  def contains_input_streams(self) -> set[MyVariable]:
    match self:
      case MyFunctionCallExpression(name, _) if name == INPUT_FUNCTION_NAME:
        return { self.to_user_input_variable() } # pylint: disable=no-member
      case MyUnaryExpression(_, child):
        return child.contains_input_streams()
      case MyBinaryExpression(_, left, right):
        return left.contains_input_streams() | right.contains_input_streams()
    return set()

@dataclass(frozen=True)
class MyArrayVariable(MyVariable):
  index: MyExpression = field(hash=False)

  def __post_init__(self):
    super().__post_init__()
    BehavesLikeArrays.add(self)

  def __str__(self):
    return f"{self.name}[{self.index}]"

  @staticmethod
  def from_sum(lhs: MyExpression, rhs: MyExpression) -> "MyArrayVariable":
    match lhs, rhs:
      case (MyVariableExpression(MyVariable(name)), MyConstantExpression(value)) | \
          (MyConstantExpression(value), MyVariableExpression(MyVariable(name))):
        return MyArrayVariable(name, MyConstantExpression(value))
      case MyVariableExpression(MyVariable(name)), \
          MyVariableExpression(MyVariable()):
        return MyArrayVariable(name, rhs)
      case (MyVariableExpression(MyVariable(name)), # name + (value * other)
            MyBinaryExpression(MyBinaryOperator.MUL,
                               MyConstantExpression(value),
                               MyVariableExpression(MyVariable(other)))) | \
            (MyBinaryExpression(MyBinaryOperator.MUL, # (value * other) + name
                                MyConstantExpression(value),
                                MyVariableExpression(MyVariable(other))),
             MyVariableExpression(MyVariable(name))) | \
            (MyVariableExpression(MyVariable(name)), # name + (other * value)
             MyBinaryExpression(MyBinaryOperator.MUL,
                                MyVariableExpression(MyVariable(other)),
                                MyConstantExpression(value))) | \
            (MyBinaryExpression(MyBinaryOperator.MUL, # (other * value) + name
                                MyVariableExpression(MyVariable(other)),
                                MyConstantExpression(value)),
             MyVariableExpression(MyVariable(name))):
        return MyArrayVariable(name, MyBinaryExpression(MyBinaryOperator.MUL,
                                MyConstantExpression(value),
                                MyVariableExpression(MyVariable(other))))
      case MyVariableExpression(MyVariable(name)), other_expression: # name + other_expression
        warning(f"Potentially unsound array expression from sum: {lhs} + {rhs}")
        return MyArrayVariable(name, other_expression)
      case _:
        raise NotImplementedError(f"Unsupported array expression from sum: {lhs} + {rhs}")

@dataclass(frozen=True)
class MyAtomicExpression(MyExpression):
  pass

@dataclass(frozen=True)
class MyVariableExpression(MyAtomicExpression):
  variable: MyVariable

  def __str__(self):
    return f"{self.variable}"

  @property
  def variables(self):
    return { self.variable.base }

@dataclass(frozen=True)
class MyConstantExpression(MyAtomicExpression):
  value: int | bool

  def __str__(self):
    return f"{self.value}"

  @staticmethod
  def from_string(s: str):
    if s in ("true", "false"):
      return MyConstantExpression(s == "true")
    cast_base = 16 if s.startswith("0x") else 10
    if s[-1] in ("u", "U", "l", "L"):
      s = s[:-1]
    return MyConstantExpression(int(s, cast_base))

@dataclass(frozen=True)
class MyUnaryExpression(MyExpression):
  operator: MyUnaryOperator
  child: MyExpression

  def __str__(self):
    return f"{self.operator.value}{self.child}"

  @property
  def variables(self):
    return self.child.variables

@dataclass(frozen=True)
class MyBinaryExpression(MyExpression):
  operator: MyBinaryOperator
  left: MyExpression
  right: MyExpression

  def __str__(self):
    return f"({self.left} {self.operator.value} {self.right})"

  @property
  def variables(self):
    return self.left.variables | self.right.variables

@dataclass(frozen=True)
class MyFunctionCallExpression(MyExpression):
  name: str
  arguments: tuple
  coord: tuple[int, int] = (0, 0)

  def __post_init__(self):
    if any(not isinstance(x, MyExpression) for x in self.arguments):
      raise ValueError(f"Invalid arguments for function call {self.name}: {self.arguments}")

    if self.name == INPUT_FUNCTION_NAME:
      self.to_user_input_variable()
      # stream.to_counter()

  def __str__(self):
    return f"{self.name}({", ".join(map(str, self.arguments))})"

  def to_user_input_variable(self) -> MyVariable:
    if self.name != INPUT_FUNCTION_NAME:
      raise ValueError(f"Invalid function call to user input variable: {self.name}")
    if len(self.arguments) != 0:
      raise ValueError(f"Invalid number of arguments for user input variable: {self.arguments}")
    idx = f"l{self.coord[0]}_c{self.coord[1]}"
    return MyVariable(INPUT_STREAM_VARIABLE_PREFIX + idx)

  @property
  def variables(self):
    if self.name == INPUT_FUNCTION_NAME:
      stream = self.to_user_input_variable()
      return { stream }
      # return { stream, stream.to_counter() }
    return {x for arg in self.arguments for x in arg.variables}

my_zero = MyConstantExpression(0)
my_one = MyConstantExpression(1)
my_two = MyConstantExpression(2)

my_true = MyBinaryExpression(MyBinaryOperator.GREATER_THAN_OR_EQUAL, my_one, my_zero)
my_false = MyUnaryExpression(MyUnaryOperator.LOGICAL_NOT, my_true)
