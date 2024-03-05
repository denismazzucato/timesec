
import sys
from logging import DEBUG, getLogger, warning

from src.user_interface.logging import debug2


class Interactive:
  activated = False

  @staticmethod
  def set_interactive(flag: bool):
    if flag:
      if getLogger().isEnabledFor(DEBUG - 2):
        Interactive.activated = flag
        debug2(f"Interactive mode is {"activated" if flag else "deactivated"}")
      else:
        warning("Interactive mode is not available when the debug level is not set to 2")

  @staticmethod
  def is_interactive() -> bool:
    return Interactive.activated

  @staticmethod
  def stop_user():
    if Interactive.is_interactive():
      user_input = input("Press Enter to continue...")

      if user_input != "":
        sys.exit(0)
