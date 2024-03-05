

from re import sub

GREEN = "\033[92m"
YELLOW = "\033[93m"
ORANGE = "\033[33m"
CYAN = "\033[96m"
RED = "\033[91m"
PURPLE = "\033[0;35m"
GRAY = "\033[30m"
ENDC = "\033[0m"

def red(string):
  return f"{RED}{string}{ENDC}"

def green(string):
  return f"{GREEN}{string}{ENDC}"

def yellow(string):
  return f"{YELLOW}{string}{ENDC}"

def orange(string):
  return f"{ORANGE}{string}{ENDC}"

def cyan(string):
  return f"{CYAN}{string}{ENDC}"

def gray(string):
  return f"{GRAY}{string}{ENDC}"

def purple(string):
  return f"{PURPLE}{string}{ENDC}"

def remove_color(string):
  return sub(r"\033\[[0-9;]*m", "", string)

def underline_text(text):
  return f"\033[4m{text}\033[0m"

def bold_text(text):
  return f"\033[1m{text}\033[0m"

def title(string):
  return underline_text(bold_text(string)) + ": "
