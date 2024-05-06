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
    round(mean(impacts), 2),
    round(np.std(impacts), 2),
    round(sum(timings_dependency_analysis), 2),
    round(sum(timings_fixpoint_iterator), 2),
    round(sum(timings_impact_analysis), 2),
    round(sum(timings_total), 2)
  )


crafted = [Path(x) for x in [
  "tmp/termination-crafted-0-10.json",
  "tmp/termination-crafted-0-100.json",
  "tmp/termination-crafted-0-1000.json",
  "tmp/termination-crafted-0-inf.json",
  "tmp/termination-crafted-inf.json",
]]
lit = [Path(x) for x in [
  "tmp/termination-crafted-lit-0-10.json",
  "tmp/termination-crafted-lit-0-100.json",
  "tmp/termination-crafted-lit-0-1000.json",
  "tmp/termination-crafted-lit-0-inf.json",
  "tmp/termination-crafted-lit-inf.json",
]]

bounds = ["0-10", "0-100", "0-1000", "0-inf", "inf"]
str_bounds = ["0-10", "0-100", "0-1000", "\\ge 0", "[-\\infty,+\\infty]"]

preamble = r"""
\begin{table}[t]
  \centering
  \caption{Quantitative results for the \svcomp{} benchmarks.}
  \label{tab:svcomp}
  \begin{tabular}{c|c|cc|cccc}
    \multirow{2}{*}{\textsc{Benchmark}} & \multirow{2}{*}{~\makecell{\textsc{Bound} \\ \textsc{Ranges}}~} & \multicolumn{2}{c|}{\textsc{Quantities} $(< \infty)$} & \multicolumn{4}{c}{\textsc{Analysis Time} (s)} \\
    & & \textsc{Average} & \textsc{Std} & \spacearound{\depslabel} & \spacearound{\invlabel} & \spacearound{\lplabel} & \spacearound{\textsc{Tot}} \\
    \hline\hline
    \multirow{5}{*}{\makecell{\textsc{Termination}\\ \textsc{Crafted} \\ (68 programs)}}
"""
mid = r"""\\
  \hline\hline
  \multirow{5}{*}{\makecell{\textsc{Termination}\\ \textsc{Crafted}\\ \textsc{Lit} \\ (140 programs)}}
"""
end = r"""
  \end{tabular}
\end{table}"""

line = "    & ${}$ & {} & {} & {} & {} & {} & {}"

first = " \\\\ \n".join([
  line.format(s, *retrieve_statistics(c)) for s, c in zip(str_bounds, crafted)
])

second = " \\\\ \n".join([
  line.format(s, *retrieve_statistics(c)) for s, c in zip(str_bounds, lit)
])

print(preamble + first + mid + second + end)
with open(argv[1], "w") as f:
  f.write(preamble + first + mid + second + end)
