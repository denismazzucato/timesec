

from copy import deepcopy
from json import dumps, load
from pathlib import Path

from src.abstract_domains.syntactic_dependencies.usage_lattice import (
  UsageAbstractDomain,
)
from src.frontend.abstract_syntax_tree import MyFunction
from src.frontend.symbolic import MyVariable
from src.impact import ImpactIntWrapper
from src.proto.abstract_value_domain import AbstractValueDomain
from src.utils.globals import get_global_symbolic_variables
from src.utils.time import Timeit, Timeout


def write_result(
    output: Path | None,
    input_file: Path,
    input_deps: UsageAbstractDomain,
    function: MyFunction,
    points_to: dict[MyVariable, set[MyVariable]],
    pre: AbstractValueDomain,
    impacts: dict[MyVariable, ImpactIntWrapper],
    input_variables: set[MyVariable],
    bounds) -> None:
  if output is None:
    return
  if ".json" != output.suffix:
    raise ValueError("Output file must be a .json file")

  try:
    with open(output, "r", encoding="utf-8") as output_file:
      original_data = load(output_file)
      data = deepcopy(original_data)
  except FileNotFoundError:
    data = {}

  timeout = Timeout.get_timeout()
  key = input_file.name + ":" + function.name
  symbolic_variables = get_global_symbolic_variables()
  data[key] = {
    "program": input_file.as_posix(),
    "function": function.name,
    "loc": function.lines,
    "points_to": {str(k): [str(v) for v in points_to[k]] for k in points_to},
    "deps": [str(x) for x in function.collect_all_deps()],
    "input_deps": [str(x) for x in input_deps.may_used_variables()],
    "pre": str(pre) if pre is not None else f"Timeout({timeout}s)",
    "impacts": {str(k): str(v.to_number()) for k, v in impacts.items()},
    "input_variables": [str(v) for v in input_variables],
    "local_variables": [str(v) for v in impacts.keys() - input_variables
                        if str(v) not in symbolic_variables],
    "symbolic_variables": list(map(str, symbolic_variables.values())),
    "lowerbound": str(bounds[0]),
    "upperbound": str(bounds[1]),
    "timing": {
      "parsing": Timeit.get_running_time("parse"),
      "points_to_analysis": Timeit.get_running_time("points_to_analysis"),
      "dependency_analysis": Timeit.get_running_time("dependency_analysis"),
      "fixpoint_iterator": Timeit.get_running_time("fixpoint_iterator"),
      "impact_analysis": Timeit.get_running_time("impact_analysis"),
    }
  }

  serialized = dumps(data, indent=2)
  output.parent.mkdir(exist_ok=True, parents=True)
  with open(output, "w", encoding="utf-8") as output_file:
    output_file.write(serialized)

def write_failure(output: Path, input_file: Path, function: str, error: Exception):
  if output is None:
    return
  if ".json" != output.suffix:
    raise ValueError("Output file must be a .json file")

  try:
    with open(output, "r", encoding="utf-8") as output_file:
      original_data = load(output_file)
      data = deepcopy(original_data)
  except FileNotFoundError:
    data = {}
  key = input_file.name + ":" + function
  data[key] = {
    "program": input_file.as_posix(),
    "function": function,
    "error": str(error),
  }

  serialized = dumps(data, indent=2)
  output.parent.mkdir(exist_ok=True, parents=True)
  with open(output, "w", encoding="utf-8") as output_file:
    output_file.write(serialized)
