from collections import defaultdict


class Counter:
  counters: dict[str, int] = defaultdict(lambda: 0)

  def __init__(self) -> None:
    raise TypeError("Cannot instantiate Counter")

  @staticmethod
  def get_counter(key: str="") -> int:
    return Counter.counters[key]

  @staticmethod
  def incr(key: str="") -> int:
    current = Counter.counters[key]
    Counter.counters[key] += 1
    return current

  @staticmethod
  def reset() -> None:
    Counter.counters = defaultdict(lambda: 0)
