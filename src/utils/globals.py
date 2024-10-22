
DEFAULT_FUNCTION_NAME = "ltmp0"

SYMBOLIC_VARIABLE_PREFIX = "symbolic_"
SYMBOLIC_VARIABLE_NAME = SYMBOLIC_VARIABLE_PREFIX + "goal"
SECOND_SYMBOLIC_VARIABLE_NAME = SYMBOLIC_VARIABLE_PREFIX + "2"
IMPACT_MAXIMUM_SPAN_VARIABLE_NAME = SYMBOLIC_VARIABLE_PREFIX + "impact_maximum_span"
COUNTER_VARIABLE_NAME = SYMBOLIC_VARIABLE_PREFIX + "counter"

INPUT_STREAM_VARIABLE_PREFIX = "inp_"
INPUT_STREAM_COUNTER_VARIABLE_PREFIX = INPUT_STREAM_VARIABLE_PREFIX + "counter_"
RANDOM_VARIABLE_PREFIX = "rand_"

CINCLUDE_PATH = "benchmarks/s2n-bignum/include"

BOTTOM_CHAR = "\u22a5"
TOP_CHAR = "\u22a4"
INFINITY_CHAR = "\u221e"
SPECIAL_COMMA = "\u1808"

INPUT_FUNCTION_NAME = "__VERIFIER_nondet_int"


def get_global_symbolic_variables():
  return {
    "SYMBOLIC_VARIABLE_NAME": SYMBOLIC_VARIABLE_NAME,
    "COUNTER_VARIABLE_NAME": COUNTER_VARIABLE_NAME,
  }

def get_global_settings():
  return {
    "COUNTER_VARIABLE_NAME": COUNTER_VARIABLE_NAME,
    "INPUT_STREAM_VARIABLE_PREFIX": INPUT_STREAM_VARIABLE_PREFIX,
    "INPUT_STREAM_COUNTER_VARIABLE_PREFIX": INPUT_STREAM_COUNTER_VARIABLE_PREFIX,
    "RANDOM_VARIABlE_PREFIX": RANDOM_VARIABLE_PREFIX,
    "CINCLUDE_PATH": CINCLUDE_PATH,
    "RANDOM_FUNCTION_NAME": INPUT_FUNCTION_NAME,
    **get_global_symbolic_variables(),
  }

class IsDependencyAnalysis:
  _active = True

  @staticmethod
  def deactivate():
    IsDependencyAnalysis._active = False

  @staticmethod
  def active():
    return IsDependencyAnalysis._active

class IsVerbose:
  _active = False

  @staticmethod
  def activate():
    IsVerbose._active = True

  @staticmethod
  def active():
    return IsVerbose._active
