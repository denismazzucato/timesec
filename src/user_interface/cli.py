from argparse import (
  ArgumentDefaultsHelpFormatter,
  ArgumentParser,
  ArgumentTypeError,
  Namespace,
  RawTextHelpFormatter,
)
from logging import debug
from pathlib import Path
from sys import argv
from typing import Callable

from src.user_interface.interactive import Interactive
from src.user_interface.logging import debug1, setup_log_levels, setup_logs
from src.utils.colors import title
from src.utils.globals import DEFAULT_FUNCTION_NAME, get_global_settings
from src.utils.time import Timeout


def show_settings(args: Namespace) -> None:
  debug1(title("Found settings"))
  for k, v in vars(args).items():
    debug1(f"  {k}: {v}")
  for k, v in get_global_settings().items():
    debug1(f"  {k}: {v}")

class RawTextArgumentDefaultsHelpFormatter(ArgumentDefaultsHelpFormatter, RawTextHelpFormatter):
  pass

def existing_path(path: str) -> Path:
  path_obj = Path(path)
  if not path_obj.exists():
    raise ArgumentTypeError(f"File {path} does not exist")
  return path_obj

def int_greater_equal(threshold: int) -> Callable[[str], int]:
  def inner(value: str) -> int:
    try:
      int_value = int(value)
    except ValueError as e:
      raise ArgumentTypeError(f"Invalid integer value: {value}") from e
    if int_value < threshold:
      raise ArgumentTypeError(f"Invalid negative or null value: {value}")
    return int_value
  return inner

def helper(raw_args: list[str] | None = None) -> Namespace:

  setup_logs()

  parser = ArgumentParser(
    description="QuantIt, A Static Analyzer by Abstract Interpretation to quantify " + \
      "the influence of variables to the number of iterations of a given C program",
    formatter_class=RawTextArgumentDefaultsHelpFormatter)
  parser.add_argument("input", metavar="INPUT", type=existing_path,
    help="path to the C program INPUT, or folder containing C programs")
  parser.add_argument("-f", "--function", metavar="FUNCTION", type=str,
    default=DEFAULT_FUNCTION_NAME,
    help="name of the function to analyze")
  parser.add_argument("-w", "--k-widening", metavar="K", type=int_greater_equal(1),
    default=5,
    help="widening from the K-th iteration")
  parser.add_argument("-dc", "--decreasing-chain", metavar="DC", type=int_greater_equal(0),
    default=5,
    help="apply decreasing chain for DC iterations after the application of widening")
  parser.add_argument("-r", "--repeat", metavar="R", type=int_greater_equal(1),
    default=1,
    help="repeat the combination of forward-backward analysis R times")
  parser.add_argument("-i", "--interactive", action="store_true",
    help="enable interactive mode, stopping each iteration of the worklist algorithm" + \
      "(setting the debug level to 2)")
  parser.add_argument("-d", "--debug", nargs="?", type=int,
    const=0,
    default=-1,
    choices=[0, 1, 2],
    help="Enable debug mode, optionally set the debug level")
  parser.add_argument("-o", "--output", metavar="OUTPUT", type=Path,
    help="path to the output json file to store the analysis results")
  parser.add_argument("-t", "--timeout", metavar="T", type=int_greater_equal(0),
    default=0,
    help="timeout the analysis after T seconds (0 to disable the timeout)"
  )
  parser.add_argument("--dev-no-exception-traceback", action="store_true",
    help="(DEVELOPER MODE) disable the logging of exception tracebacks when an error occurs, " + \
      "for folder analysis")
  parser.add_argument("--dev-stop-at-first-exception", action="store_true",
    help="(DEVELOPER MODE) stop at first program that runs into an exception, for folder analysis")

  args = parser.parse_args(raw_args + argv[1:] if raw_args else None)

  setup_log_levels(args.debug)
  debug(title("Debugging mode on") + f"level {args.debug}")

  show_settings(args)

  Interactive.set_interactive( args.interactive)

  Timeout.set_timeout(args.timeout)

  return args
