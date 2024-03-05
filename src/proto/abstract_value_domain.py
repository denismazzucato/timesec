
from abc import ABC, abstractmethod
from enum import Enum

from src.frontend.symbolic import MyExpression, MyVariable
from src.proto.poset import Poset


class AnalysisDirection(Enum):
  FORWARD = "FORWARD"
  BACKWARD = "BACKWARD"

class AbstractValueDomain(Poset, ABC):

  @abstractmethod
  def _join(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    pass

  @abstractmethod
  def _meet(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    pass

  @abstractmethod
  def _widening(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    pass

  @abstractmethod
  def assign(
      self,
      lhs: MyVariable,
      rhs: MyExpression,
      direction: AnalysisDirection) -> "AbstractValueDomain":
    pass

  @abstractmethod
  def filter(
      self,
      cond: MyExpression,
      direction: AnalysisDirection) -> "AbstractValueDomain":
    pass

  def join(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    if self.is_bottom() or other.is_top():
      return other
    if other.is_bottom() or self.is_top():
      return self
    return self._join(other)

  def meet(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    if self.is_bottom() or other.is_top():
      return self
    if other.is_bottom() or self.is_top():
      return other
    return self._meet(other)

  def widening(self, other: "AbstractValueDomain") -> "AbstractValueDomain":
    if self.is_bottom() or other.is_top():
      return other
    if other.is_bottom() or self.is_top():
      return self
    return self._widening(other)

  @abstractmethod
  def __hash__(self) -> int:
    pass
