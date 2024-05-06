
from logging import debug
from traceback import print_exception

from src.abstract_domains.polka import Polka
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


def debug_command_line(program, function_name, bounds):
  """
    This function is used for debugging. It prints the command line that would be used to run the program with the given parameters.

    Args:
      program (str): The name of the program to run.
      function_name (str): The name of the function to analyze.
      bounds (tuple): The input bounds for the function.
  """
  debug(title("Command line") + " ".join([
    "python", "timesec.py",
    str(program),
    "--function", function_name,
    "--debug", "2",
    "--input-bounds", str(bounds[0]), str(bounds[1]),
  ]))

def single_run(
    program,
    function_name,
    widening,
    narrowing,
    repeat,
    forward,
    bounds,
    output):
  """
    This function is the main entry point for running the TimeSec analysis on a single program.

    Args:
      program (str): The name of the program to run.
      function_name (str): The name of the function to analyze.
      widening (str): The widening strategy to use.
      narrowing (str): The narrowing strategy to use.
      repeat (int): The number of times to repeat the analysis.
      forward (bool): Whether to perform a forward analysis.
      bounds (tuple): The input bounds for the function.
      output (str): The name of the file to write the results to.
  """
  debug_command_line(program, function_name, bounds)

  # first, we parse the program
  function = parse(program, function_name, bounds)

  # we perform the points-to analysis to discover shared memory regions,
  # useful for the dependency analysis
  points_to = points_to_analysis(function)

  # syntactic dependency analysis to discover variables that are used in the
  # loop iterations
  input_deps = dependency_analysis(function)

  # we perform the fixpoint iterator, forward and backward analysis
  pre = iterator(
    PolkaWithStreams,
    function,
    widening,
    narrowing,
    repeat,
    forward)

  # quantification of the impact of each variable
  impacts = impact_analysis(input_deps, pre)

  # print the results to the user
  print_analysis_results(impacts)

  # store the results for benchmark mode
  write_result(
    output,
    program,
    input_deps,
    function,
    points_to,
    pre,
    impacts,
    MyEnvironment.my_input_variables(),
    bounds)

def destruct_cli_params_for_main(args):
  """
    This function destructs the command line parameters for the main function.

    Args:
      args (argparse.Namespace): The command line arguments.

    Returns:
      tuple: A tuple containing the destructed command line parameters.
  """
  return \
    args.function, \
    args.widening, \
    args.narrowing, \
    args.repeat, \
    args.forward, \
    args.input_bounds, \
    args.output

def main(args: list[str] | None = None):
  """
    This is the main function that is called when the script is run. It processes the command line arguments and runs the analysis on the specified programs.

    Args:
      args (list[str] | None): The command line arguments. If None, the arguments will be taken from sys.argv.
  """
  input_parameters = helper(args)
  if input_parameters.input.is_file():
    single_run(
      input_parameters.input,
      *destruct_cli_params_for_main(input_parameters))
  else:
    it = sorted(input_parameters.input.glob("*.c"), key=lambda f: f.name)
    for i, file in enumerate(it):
      progress = f"{i + 1: <2}/{len(it)} "
      print(progress + title("Analyzing") + file.name)
      try:
        single_run(
          file,
          *destruct_cli_params_for_main(input_parameters))
      except NotImplementedError as e:
        if not input_parameters.dev_no_exception_traceback:
          print_exception(type(e), e, e.__traceback__)
        print(progress + title("Failed to analyze") + file.name)
        print()

        write_failure(input_parameters.output, file, input_parameters.function, e)

        if input_parameters.dev_stop_at_first_exception:
          raise e

    print_overall_statistics(input_parameters.output)
