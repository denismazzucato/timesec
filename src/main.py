
from logging import debug
from traceback import print_exception

from src.abstract_domains.polka_with_streams import PolkaWithStreams
from src.engine.dependency_analysis import dependency_analysis
from src.engine.fixpoint import iterator
from src.engine.points_to_analysis import points_to_analysis
from src.frontend.parser import parse
from src.frontend.symbolic import MyEnvironment
from src.impact import impact_analysis
from src.user_interface.cli import helper
from src.user_interface.format_analysis import (
  print_analysis_results,
  print_overall_statistics,
)
from src.user_interface.output import write_failure, write_result
from src.utils.colors import title


def debug_command_line(program, function_name):
  debug(title("Command line") + " ".join([
    "python", "timesec.py",
    str(program),
    "--function", function_name,
    "--debug", "2"
  ]))

def single_run(program, function_name, k_widening, decreasing_chain, repeat, output):
  debug_command_line(program, function_name)

  function = parse(program, function_name)

  points_to = points_to_analysis(function)

  input_deps = dependency_analysis(function)

  pre = iterator(
    PolkaWithStreams,
    function,
    k_widening,
    decreasing_chain,
    repeat)

  impacts = impact_analysis(input_deps, pre)

  print_analysis_results(impacts)

  write_result(
    output,
    program,
    input_deps,
    function,
    points_to,
    pre,
    impacts,
    MyEnvironment.my_input_variables())


def main(args: list[str] | None = None):

  input_parameters = helper(args)
  if input_parameters.input.is_file():
    single_run(
      input_parameters.input,
      input_parameters.function,
      input_parameters.k_widening,
      input_parameters.decreasing_chain,
      input_parameters.repeat,
      input_parameters.output)
  else:
    it = sorted(input_parameters.input.glob("*.c"), key=lambda f: f.name)
    for i, file in enumerate(it):
      progress = f"{i + 1: <2}/{len(it)} "
      print(progress + title("Analyzing") + file.name)
      try:
        single_run(
          file,
          input_parameters.function,
          input_parameters.k_widening,
          input_parameters.decreasing_chain,
          input_parameters.repeat,
          input_parameters.output)
      except NotImplementedError as e:
        if not input_parameters.dev_no_exception_traceback:
          print_exception(type(e), e, e.__traceback__)
        print(progress + title("Failed to analyze") + file.name)
        print()

        write_failure(input_parameters.output, file, input_parameters.function, e)

        if input_parameters.dev_stop_at_first_exception:
          raise e

    print_overall_statistics(input_parameters.output)
