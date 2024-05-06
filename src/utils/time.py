
from collections import defaultdict
from logging import warning
from signal import SIGALRM, alarm, signal
from time import perf_counter


class Timer:
  """
    A context manager for measuring time elapsed during execution.

    Usage:
    ```python
    with Timer() as t:
        # Code block to measure execution time for
    print(f"Elapsed time: {t.elapsed} seconds")
    ```

    Attributes:
        _start (float): The start time of the timer.
        elapsed (float): The elapsed time in seconds.
  """
  def __init__(self):
    self._start: float = 0
    self.elapsed: float = 0

  def __enter__(self):
    self._start = perf_counter()
    return self

  def __exit__(self, ctx_type, value, traceback):
    self.elapsed = perf_counter() - self._start

class Timeit:
  """
    Decorator for measuring the execution time of functions.

    Usage:
    ```python
    @Timeit("function_name")
    def my_function():
        # Function implementation
    ```

    Attributes:
        _running_times (dict): A dictionary to store running times of functions.
  """

  _running_times: dict[str, float] = defaultdict(float)
  def __init__(self, func_name):
    self.func_name = func_name

  def __call__(self, func):
    def wrapper(*args, **kwargs):
      with Timer() as t:
        result = func(*args, **kwargs)
      Timeit._running_times[self.func_name] = t.elapsed
      return result
    return wrapper

  @staticmethod
  def get_running_time(func_name: str) -> float:
    return Timeit._running_times[func_name]

  @staticmethod
  def get_running_times() -> dict[str, float]:
    return Timeit._running_times

  @staticmethod
  def clear_running_times() -> None:
    Timeit._running_times = defaultdict(float)

class Timeout:
  """
    Decorator for setting a timeout limit on function execution.

    Usage:
    ```python
    @Timeout(10)
    def my_function():
        # Function implementation
    ```

    Attributes:
        _timeout (int): The timeout limit in seconds.
  """
  _timeout: int = 0

  @staticmethod
  def set_timeout(timeout: int) -> None:
    Timeout._timeout = timeout

  @staticmethod
  def get_timeout() -> int:
    return Timeout._timeout

  def __init__(self, default):
    self.default = default

  def _handle_timeout(self, func):
    def handler(signum, frame):
      raise TimeoutError(f"Function {func.__name__} timed out after {Timeout._timeout} seconds.")
    return handler

  def __call__(self, func):
    def wrapper(*args, **kwargs):
      try:
        if Timeout._timeout <= 0:
          return func(*args, **kwargs)
        signal(SIGALRM, self._handle_timeout(func))
        alarm(Timeout._timeout)
        result = func(*args, **kwargs)
        alarm(0)
        return result
      except TimeoutError as e:
        alarm(0)
        warning(e)
        return self.default
    return wrapper
