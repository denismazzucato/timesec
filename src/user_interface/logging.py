
"""
This module provides functions for setting up logging configuration and log levels.
"""

from logging import DEBUG, INFO, StreamHandler, basicConfig, debug, getLogger

from colorlog import ColoredFormatter


def setup_logs() -> None:
  """
  Set up logging configuration.

  This function configures the logging module to use a colored formatter
  and a stream handler. The log colors are defined for different log levels.
  """
  formatter = ColoredFormatter(
    "%(log_color)s%(levelname)s:%(reset)s %(message)s",
    log_colors={
      "DEBUG": "cyan",
      "INFO": "green",
      "WARNING": "red",
      "ERROR": "red",
      "CRITICAL": "red,bg_white",
    },
    reset=True,
    style="%"
  )
  handler = StreamHandler()
  handler.setFormatter(formatter)
  basicConfig(handlers=[handler])


def setup_log_levels(level: int) -> None:
  """
  Set up the log levels for the application.

  Args:
    level (int): debugging level, -1 no logs, 0 up to 2 for increasing verbosity.
  """
  assert level in [-1, 0, 1, 2], "Invalid log level"
  if level == -1:
    getLogger().setLevel(INFO)
  else:
    getLogger().setLevel(DEBUG - level)

def debug1(msg: str) -> None:
  if getLogger().isEnabledFor(DEBUG - 1):
    debug(msg)

def debug2(msg: str) -> None:
  if getLogger().isEnabledFor(DEBUG - 2):
    debug(msg)
