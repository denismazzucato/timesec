

from json import load
from pathlib import Path
from statistics import mean
from typing import Sequence

from tabulate import tabulate

from src.frontend.symbolic import MyEnvironment, MyVariable
from src.impact import ImpactIntWrapper, QualitativeZero
from src.utils.colors import cyan, green, orange, red, title, yellow
from src.utils.globals import (
  INPUT_STREAM_COUNTER_VARIABLE_PREFIX,
  INPUT_STREAM_VARIABLE_PREFIX,
)
from src.utils.time import Timeit

MAXIMUM_LEN_CELL = 40

def get_str_data(
    impacts: dict[MyVariable, ImpactIntWrapper]) -> Sequence[tuple[str, str, str, str, str]]:

  input_streams_codes = list(map(
    lambda x: x.name[len(INPUT_STREAM_VARIABLE_PREFIX):],
    filter(
      lambda x: not x.name.startswith(INPUT_STREAM_COUNTER_VARIABLE_PREFIX),
      MyEnvironment.my_input_streams())))

  input_streams_data = []
  for k in input_streams_codes:
    v = impacts[MyVariable(INPUT_STREAM_VARIABLE_PREFIX + k)]
    input_streams_data.append((
      INPUT_STREAM_VARIABLE_PREFIX + k,
      "Input Stream",
      green("Unused") if isinstance(v, QualitativeZero) else orange("May Used"),
      str(v),
      red("Possibly Dangerous") if v.n > 0 else green("Definitely Safe")))
  input_streams_data.sort(key=lambda x: x[0])

  only_input_variables = MyEnvironment.my_input_variables() - MyEnvironment.my_input_streams()

  input_variables_data = [(
    str(k),
    "Input",
    green("Unused") if isinstance(v, QualitativeZero) else orange("May Used"),
    str(v),
    red("Possibly Dangerous") if v.n > 0 else green("Definitely Safe"))
      for k, v in impacts.items() if k in only_input_variables]
  input_variables_data.sort(key=lambda x: x[0])

  local_variables = MyEnvironment.my_variables() \
    - MyEnvironment.my_input_variables() \
    - MyEnvironment.my_symbolic_variables()

  local_variables_data = [(
    str(k),
    "Local",
    green("Unused") if isinstance(v, QualitativeZero) else orange("May Used"),
    str(v),
    orange("Possibly Dangerous") if v.n > 0 else cyan("Definitely Safe"))
      for k, v in impacts.items() if k in local_variables]
  local_variables_data.sort(key=lambda x: x[0])
  return input_streams_data + input_variables_data + local_variables_data

def headers() -> list[str]:
  return ["Variable", "Type", "Usage", "Impact", "Notes"]

def format_analysis_results(
    impacts: dict[MyVariable, ImpactIntWrapper]) -> str:
  data = get_str_data(impacts)
  table = tabulate(data, headers=headers(), showindex=True)
  return table

def print_analysis_results(
    impacts: dict[MyVariable, ImpactIntWrapper]) -> None:
  timings = Timeit.get_running_times()

  str_timings = "(" + ", ".join(f"{k}: {v:.2f}s" for k, v in timings.items()) + ")"
  print()
  print(title("Analysis Results") + str_timings)
  print()
  print(format_analysis_results(impacts))
  print()

def print_overall_statistics(output: Path):
  if output is None or not output.exists():
    return
  with open(output, "r", encoding="utf-8") as output_file:
    data = load(output_file)
  number_of_programs = len(data)
  successes = {k: v for k, v in data.items() if "error" not in v}
  failures = {k: v for k, v in data.items() if "error" in v}
  number_of_failures = len(failures)
  number_of_successes = len(successes)

  input_variables, local_variables, all_variables = [], [], []
  analysis_variables, removed_variables = [], []
  locs = []
  dangerous_input_variables, zero_used_input_variables, unused_input_variables  = {}, {}, {}
  timings_parsing, timings_points_to, timings_dependency_analysis, timings_fixpoint_iterator, timings_impact_analysis = [], [], [], [], []
  dangerous_local_variables, zero_used_local_variables, unused_local_variables = {}, {}, {}
  timings_total = []
  shared_points_to = []
  for name, v in successes.items():
    input_variables.append(len(v["input_variables"]))
    local_variables.append(len(v["local_variables"]) - len(v["symbolic_variables"]))
    all_variables.append(len(v["input_variables"]) + len(v["local_variables"]) - 2)
    analysis_variables.append(len(v["deps"]))
    removed_variables.append(len(v["input_variables"]) + len(v["local_variables"]) - 2 - len(v["deps"]))
    locs.append(v["loc"])

    dangerous_input_variables.update({
      name: [k for k in v["input_variables"] if float(v["impacts"][k]) > 0]
    })
    zero_used_input_variables.update({
      name: [k for k in v["input_variables"] if float(v["impacts"][k]) == 0 and k in v["deps"]]
    })
    unused_input_variables.update({
      name: [k for k in v["input_variables"] if k not in v["deps"]]
    })

    dangerous_local_variables.update({
      name: [k for k in set(v["local_variables"]) - set(v["symbolic_variables"]) if float(v["impacts"][k]) > 0]
    })
    zero_used_local_variables.update({
      name: [k for k in set(v["local_variables"]) - set(v["symbolic_variables"]) if float(v["impacts"][k]) == 0 and k in v["input_deps"]]
    })
    unused_local_variables.update({
      name: [k for k in set(v["local_variables"]) - set(v["symbolic_variables"]) if k not in v["input_deps"]]
    })

    timings_parsing.append(v["timing"]["parsing"])
    timings_points_to.append(v["timing"]["points_to_analysis"])
    timings_dependency_analysis.append(v["timing"]["dependency_analysis"])
    timings_fixpoint_iterator.append(v["timing"]["fixpoint_iterator"])
    timings_impact_analysis.append(v["timing"]["impact_analysis"])
    timings_total.append(
      v["timing"]["parsing"] +
      v["timing"]["points_to_analysis"] +
      v["timing"]["dependency_analysis"] +
      v["timing"]["fixpoint_iterator"] +
      v["timing"]["impact_analysis"]
    )

    for a, b in v["points_to"].items():
      if len(b) > 0:
        shared_points_to.append(b + [a])


  number_of_dangerous_input_variables = [len(v) for v in dangerous_input_variables.values()]
  number_of_zero_used_input_variables = [len(v) for v in zero_used_input_variables.values()]
  number_of_unused_input_variables = [len(v) for v in unused_input_variables.values()]


  print(
f"""
{"=" * 80}

{title("Overall Statistics")} (over {number_of_programs} programs: {green(f"{number_of_successes} succeeded")} and {red(f"{number_of_failures} failed")}):

  {title("Lines of code")}
    - {green(f"{sum(locs)}")} lines of code in total
    - {round(mean(locs))} lines of code on average for {number_of_successes} analyzed programs
    - {max(locs)} lines of code in the program with the most lines of code
    - {min(locs)} lines of code in the program with the least lines of code

  {title("Timings")}
    - {green(f"{sum(timings_total):.2f}")} seconds in total for the analysis of {number_of_successes} programs
    - {round(sum(timings_parsing), 2)} seconds in total for parsing
    - {round(sum(timings_points_to), 2)} seconds in total for the points-to analysis
    - {round(sum(timings_dependency_analysis), 2)} seconds in total for the dependency analysis
    - {round(sum(timings_fixpoint_iterator), 2)} seconds in total for the fixpoint iterator
    - {round(sum(timings_impact_analysis), 2)} seconds in total for the impact analysis
    - {round(mean(timings_total), 2)} seconds on average for the analysis of {number_of_successes} programs
    - {round(max(timings_total), 2)} seconds in the program with the longest analysis
    - {round(min(timings_total), 2)} seconds in the program with the shortest analysis
    - {round(mean(timings_parsing), 2)} seconds on average for parsing of {number_of_successes} programs
    - {round(mean(timings_dependency_analysis), 2)} seconds on average for the dependency analysis of {number_of_successes} programs
    - {round(mean(timings_fixpoint_iterator), 2)} seconds on average for the fixpoint iterator of {number_of_successes} programs
    - {round(mean(timings_impact_analysis), 2)} seconds on average for the impact analysis of {number_of_successes} programs

  {title("Input variables")}
    - {green(f"{sum(input_variables)}")} input variables in total
    - {round(mean(input_variables))} input variables on average for {number_of_successes} analyzed programs
    - {max(input_variables)} input variables in the program with the most input variables
    - {min(input_variables)} input variables in the program with the least input variables

  {title("Local variables")}
    - {green(f"{sum(local_variables)}")} local variables in total
    - {round(mean(local_variables))} local variables on average for {number_of_successes} analyzed programs
    - {max(local_variables)} local variables in the program with the most local variables
    - {min(local_variables)} local variables in the program with the least local variables

  {title("In total")}(with two symbolic variables each program)
    - {green(f"{sum(all_variables)}")} variables in total
    - {round(mean(all_variables))} variables on average for {number_of_successes} analyzed programs
    - {max(all_variables)} variables in the program with the most variables
    - {min(all_variables)} variables in the program with the least variables

  {title("Slicing from dependency analysis")}
    - {sum(analysis_variables)} variables in use during the forward-backward analysis ({green(f"{round(sum(analysis_variables)*100/sum(all_variables))}%")} of the total variables)
    - {round(mean(analysis_variables))} variables in use on average for {number_of_successes} analyzed programs
    - {max(analysis_variables)} variables in use in the program with the most variables
    - {min(analysis_variables)} variables in use in the program with the least variables
    - {sum(removed_variables)} variables removed from the forward-backward analysis ({green(f"{round(sum(removed_variables)*100/sum(all_variables))}%")} of the total variables)
    - {round(mean(removed_variables))} variables removed on average for {number_of_successes} analyzed programs
    - {max(removed_variables)} variables removed in the program with the most variables
    - {min(removed_variables)} variables removed in the program with the least variables

  {title("Quantitative impact of input variables on the number of iterations")}
    - {red(f"{sum(number_of_dangerous_input_variables)} maybe dangerous")} input variables in total
    - {green(f"{sum(number_of_zero_used_input_variables)}")} input variables with {green("definitely no impact")} (discovered by the {green("quantitative")} analysis)
    - {yellow(f"{sum(number_of_unused_input_variables)}")} input variables that are {yellow("definitely not used")} (discovered by the {yellow("qualitative")} analysis)

  {title("Quantitative impact of local variables on the number of iterations")}
    - {red(f"{sum(len(v) for v in dangerous_local_variables.values())} maybe dangerous")} local variables in total
    - {green(f"{sum(len(v) for v in zero_used_local_variables.values())}")} local variables with {green("definitely no impact")} (discovered by the {green("quantitative")} analysis)
    - {yellow(f"{sum(len(v) for v in unused_local_variables.values())}")} local variables that are {yellow("definitely not used")} (discovered by the {yellow("qualitative")} analysis)

"""
  )

  print(title("Usage Composition"))
  function_names = sorted(successes.keys())
  rows = []
  for k in function_names:
    original = Path(f"/Users/mazzu/src/s2n-bignum/arm/generic/{k.split(":")[0].split(".")[0]}.S")
    if not original.exists():
      original = Path(successes[k]["program"])

    program_str = k.split(":")[0]
    function_str = k.split(":")[1]
    d = sorted([red(str(x)) for x in dangerous_input_variables[k]])
    z = sorted([green(str(x)) for x in zero_used_input_variables[k]])
    u = sorted([str(x) for x in unused_input_variables[k]])
    len_d = sum(len(x) for x in d)
    len_z = sum(len(x) for x in z)
    len_u = sum(len(x) for x in u)
    rows.append((
      program_str,
      function_str,
      (", " if len_d < MAXIMUM_LEN_CELL else "\n").join(d),
      (", " if len_z < MAXIMUM_LEN_CELL else "\n").join(z),
      (", " if len_u < MAXIMUM_LEN_CELL else "\n").join(u),
      original.as_posix()
    ))

  recap_headers = ["Program", "Function", "Dangerous", "Zero Used", "Unused", "Original File"]
  print(tabulate(rows, headers=recap_headers, showindex=False))
