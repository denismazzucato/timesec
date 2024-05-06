from json import load
from pathlib import Path
from statistics import mean
from sys import argv

import numpy as np


def retrieve_statistics(output: Path):

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
  impacts = []
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

    quantities = [
      float(q) for k, q in v["impacts"].items() if float(q) != float("inf") and k in v["input_deps"] and k not in v["symbolic_variables"]
    ]
    if len(quantities) > 0:
      # print(f"{name}: {quantities}")
      impacts.append(mean(quantities))

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

  return (
    sum(number_of_dangerous_input_variables),
    # sum(number_of_dangerous_input_variables)+sum(len(v) for v in dangerous_local_variables.values()),
    sum(number_of_zero_used_input_variables),
    # sum(number_of_zero_used_input_variables)+sum(len(v) for v in zero_used_local_variables.values()),
    sum(number_of_unused_input_variables),
    # sum(number_of_unused_input_variables)+sum(len(v) for v in unused_local_variables.values()),
    round(sum(timings_dependency_analysis), 2),
    round(sum(timings_fixpoint_iterator), 2),
    round(sum(timings_impact_analysis), 2),
    round(sum(timings_total), 2),
    round(np.std(timings_total), 2)
  )


files = [Path(x) for x in [
  "tmp/bignum-no-dep-no-opt.json",
  "tmp/bignum-dep-no-opt.json",
  "tmp/bignum-dep-opt.json",
]]

str_options = ["\\nodepnoopt", "\\depnoopt", "\\depopt"]

preamble = r"""
\setcounter{table}{4}
\begin{table}[t]
  \centering
  \caption{Ablation study of \toolname{} on the \bignum{} benchmark.}
  \label{tab:bignum-abl}
  \begin{tabular}{c||c|cc||ccc|rcl}
    \multirow{2}{*}{\textsc{Component}}  & \multicolumn{3}{c||}{\textsc{Input Variables}} & \multicolumn{6}{c}{\textsc{Total Analysis Time} (s)} \\
    & \spacearound{\makecell{\textsc{Maybe} \\ \textsc{Dangerous}}} & \spacearound{\makecell{\textsc{Zero}\\ \textsc{Impact}}} & \spacearound{\textsc{Unused}} & \spacearound{\depslabel} & \spacearound{\invlabel} & \spacearound{\lplabel} & \multicolumn{3}{c}{\textsc{Tot}}  \\
  \hline\hline
"""
end = r"""
  \end{tabular}
\end{table}"""

line = "    {} & {} & {} & {} & {} & {} & {} & ${}\pm{}$"

first = " \\\\ \n".join([
  line.format(s, *retrieve_statistics(c)) for s, c in zip(str_options, files)
])


print(preamble + first + end)
with open(argv[1], "w") as f:
  f.write(preamble + first + end)
