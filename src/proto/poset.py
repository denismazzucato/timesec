

from abc import ABC, abstractmethod


class Poset(ABC):
  @staticmethod
  @abstractmethod
  def bottom() -> "Poset":
    pass

  @staticmethod
  @abstractmethod
  def top() -> "Poset":
    pass

  def is_bottom(self) -> bool:
    return self == self.bottom()

  def is_top(self) -> bool:
    return self == self.top()

  @abstractmethod
  def _less_equal(self, other: "Poset") -> bool:
    pass

  def __le__(self, other: "Poset") -> bool:
    return self._less_equal(other)

  def __lt__(self, other: "Poset") -> bool:
    return self <= other and self != other

  def __eq__(self, other: "Poset") -> bool:
    return self <= other <= self

  def __ne__(self, other: "Poset") -> bool:
    return not self == other
