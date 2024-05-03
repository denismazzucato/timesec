from json import load
from pathlib import Path
from statistics import mean
from sys import argv

import numpy as np


def retrieve_statistics(output: Path, program):

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
  input_variables_each_program = {}
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

    input_variables_each_program.update({
      name: v["input_variables"]
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

  program = program + ":ltmp0"
  return (
    dangerous_input_variables[program], zero_used_input_variables[program], unused_input_variables[program], input_variables_each_program[program]
  )

programs = [
  "bignum_add.c",
  "bignum_amontifier.c",
  "bignum_amontmul.c",
  "bignum_amontredc.c",
  "bignum_amontsqr.c",
  "bignum_bitfield.c",
  "bignum_bitsize.c",
  "bignum_cdiv.c",
  "bignum_cdiv_exact.c",
  "bignum_cld.c",
  "bignum_clz.c",
  "bignum_cmadd.c",
  "bignum_cmnegadd.c",
  "bignum_cmod.c",
  "bignum_cmul.c",
  "bignum_coprime.c",
  "bignum_copy.c",
  "bignum_copy_row_from_table.c",
  "bignum_copy_row_from_table_16_neon.c",
  "bignum_copy_row_from_table_32_neon.c",
  "bignum_copy_row_from_table_8n_neon.c",
  "bignum_ctd.c",
  "bignum_ctz.c",
  "bignum_demont.c",
  "bignum_digit.c",
  "bignum_digitsize.c",
  "bignum_divmod10.c",
  "bignum_emontredc.c",
  "bignum_eq.c",
  "bignum_even.c",
  "bignum_ge.c",
  "bignum_gt.c",
  "bignum_iszero.c",
  "bignum_le.c",
  "bignum_lt.c",
  "bignum_madd.c",
  "bignum_modadd.c",
  "bignum_moddouble.c",
  "bignum_modifier.c",
  "bignum_modinv.c",
  "bignum_modoptneg.c",
  "bignum_modsub.c",
  "bignum_montifier.c",
  "bignum_montmul.c",
  "bignum_montredc.c",
  "bignum_montsqr.c",
  "bignum_mul.c",
  "bignum_muladd10.c",
  "bignum_mux.c",
  "bignum_mux16.c",
  "bignum_negmodinv.c",
  "bignum_nonzero.c",
  "bignum_normalize.c",
  "bignum_odd.c",
  "bignum_of_word.c",
  "bignum_optadd.c",
  "bignum_optneg.c",
  "bignum_optsub.c",
  "bignum_optsubadd.c",
  "bignum_pow2.c",
  "bignum_shl_small.c",
  "bignum_shr_small.c",
  "bignum_sqr.c",
  "bignum_sub.c",
  "word_bytereverse.c",
  "word_clz.c",
  "word_ctz.c",
  "word_divstep59.c",
  "word_max.c",
  "word_min.c",
  "word_negmodinv.c",
  "word_recip.c",]

nominals = {
  "bignum_add.c": ["param_1", "param_3", "param_5"],
  "bignum_amontifier.c": ["param_1"],
  "bignum_amontmul.c": ["param_1"],
  # "bignum_amontredc.c": ["param_1", "param_3"],
    "bignum_amontredc.c": ["param_1", "param_3", "param_6"],
  "bignum_amontsqr.c": ["param_1"],
  "bignum_bitfield.c": ["param_1"],
  "bignum_bitsize.c": ["param_1"],
  "bignum_cdiv.c": ["param_1", "param_3"],
  "bignum_cdiv_exact.c": ["param_1", "param_3"],
  "bignum_cld.c": ["param_1"],
  "bignum_clz.c": ["param_1"],
  "bignum_cmadd.c": ["param_1", "param_4"],
  "bignum_cmnegadd.c": ["param_1", "param_4"],
  "bignum_cmod.c": ["param_1"],
  "bignum_cmul.c": ["param_1", "param_4"],
  "bignum_coprime.c": ["param_1", "param_3"],
  "bignum_copy.c": ["param_1", "param_3"],
  "bignum_copy_row_from_table.c": ["param_3", "param_4"],
  "bignum_copy_row_from_table_16_neon.c": ["param_3"],
  "bignum_copy_row_from_table_32_neon.c": ["param_3"],
  "bignum_copy_row_from_table_8n_neon.c": ["param_3", "param_4"],
  "bignum_ctd.c": ["param_1"],
  "bignum_ctz.c": ["param_1"],
  "bignum_demont.c": ["param_1"],
  "bignum_digit.c": ["param_1"],
  "bignum_digitsize.c": ["param_1"],
  "bignum_divmod10.c": ["param_1"],
  "bignum_emontredc.c": ["param_1"],
  "bignum_eq.c": ["param_1", "param_3"],
  "bignum_even.c": ["param_1"],
  "bignum_ge.c": ["param_1", "param_3"],
  "bignum_gt.c": ["param_1", "param_3"],
  "bignum_iszero.c": ["param_1"],
  "bignum_le.c": ["param_1", "param_3"],
  "bignum_lt.c": ["param_1", "param_3"],
  "bignum_madd.c": ["param_1", "param_3", "param_5"],
  "bignum_modadd.c": ["param_1"],
  "bignum_moddouble.c": ["param_1"],
  "bignum_modifier.c": ["param_1"],
  "bignum_modinv.c": ["param_1"],
  "bignum_modoptneg.c": ["param_1"],
  "bignum_modsub.c": ["param_1"],
  "bignum_montifier.c": ["param_1"],
  "bignum_montmul.c": ["param_1"],
  # "bignum_montredc.c": ["param_1", "param_3"],
    "bignum_montredc.c": ["param_1", "param_3", "param_6"],
  "bignum_montsqr.c": ["param_1"],
  "bignum_mul.c": ["param_1", "param_3", "param_5"],
  "bignum_muladd10.c": ["param_1"],
  "bignum_mux.c": ["param_2"],
  "bignum_mux16.c": ["param_1"],
  "bignum_negmodinv.c": ["param_1"],
  "bignum_nonzero.c": ["param_1"],
  "bignum_normalize.c": ["param_1"],
  "bignum_odd.c": ["param_1"],
  "bignum_of_word.c": ["param_1"],
  "bignum_optadd.c": ["param_1"],
  "bignum_optneg.c": ["param_1"],
  "bignum_optsub.c": ["param_1"],
  "bignum_optsubadd.c": ["param_1"],
  "bignum_pow2.c": ["param_1"],
  "bignum_shl_small.c": ["param_1", "param_3"],
  "bignum_shr_small.c": ["param_1", "param_3"],
  "bignum_sqr.c": ["param_1", "param_3"],
  "bignum_sub.c": ["param_1", "param_3", "param_5"],
  "word_bytereverse.c": [],
  "word_clz.c": [],
  "word_ctz.c": [],
  "word_divstep59.c": [],
  "word_max.c": [],
  "word_min.c": [],
  "word_negmodinv.c": [],
  "word_recip.c": [],
}



file = Path("tmp/bignum-dep-opt.json")

preamble = r"""
\begin{table}[p]
  \rowcolors{3}{white}{\customrowcolor}
  \centering
  \caption{Input composition of the \bignum{} benchmark. The nominal size variables and parameters are \green{highlighted in green}, while the numerical variables are \red{highlighted in red}. No numerical variable should be \textsc{Maybe Dangerous}.}
  \label{tab:bignum-inputs}
  \renewcommand{\arraystretch}{0.675}
  \begin{adjustbox}{max width=\textwidth}
  \begin{tabular}{l  cc || ccc}
    \multirow{2}{*}{\textsc{Program}}  & \multicolumn{2}{c||}{\textsc{Input Variables} $\inputspace$} & \textsc{Maybe} & \textsc{Zero} & \multirow{2}{*}{\textsc{Unused}} \\
    & \spacearound{\textsc{Safe} $\nominalvariabels$} & \spacearound{\textsc{Numerical} $\numericalvariables$} & \spacearound{\textsc{Dangerous}} & \spacearound{\textsc{Used}} & \\[2pt]
    \hline\hline
"""
end = r"""\\
  \end{tabular}
  \end{adjustbox}
\end{table}"""

line = "    {} & {} & {} & {} & {} & {}"

def colorize(p, x):
  if x not in nominals[p]:
    return r"\red{" + x + "}"
  else:
    return r"\green{" + x + "}"

sanitize = lambda x: "\\texttt{"+x.replace("_", r"\_").replace(".c", "").replace(r"bignum\_", "").capitalize()+"}"
from_list = lambda p, x: "$ " + ", ".join([colorize(p, i).replace("param", "p") for i in sorted(x)]) + "$"

first = " \\\\ \n".join([
  line.format(
    sanitize(p),
    from_list(p, nominals[p]),
    from_list(p, set(d)-set(nominals[p])),
    from_list(p, a),
    from_list(p, b),
    from_list(p, c)) for p in programs for a, b, c, d in [retrieve_statistics(file, p)]
])


print(preamble + first + end)
with open(argv[1], "w") as f:
  f.write(preamble + first + end)
