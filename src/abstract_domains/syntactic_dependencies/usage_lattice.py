from copy import deepcopy
from enum import Enum

from src.engine.points_to_analysis import PointsTo
from src.frontend.symbolic import MyArrayVariable, MyEnvironment, MyVariable
from src.proto.abstract_value_domain import AbstractValueDomain, AnalysisDirection
from src.proto.poset import Poset


class MyMetaClass(type(Enum), type(Poset)):
  """
    Custom metaclass inheriting from Enum and Poset types.
  """
  pass

class UsageLattice(Poset, Enum, metaclass=MyMetaClass):
  """
    Enum defining lattice elements for usage analysis.
  """
  USED = 4
  BELOW = 3
  OVERWRITTEN = 2
  UNUSED = 1

  @staticmethod
  def top() -> "UsageLattice":
    return UsageLattice.USED

  @staticmethod
  def bottom() -> "UsageLattice":
    return UsageLattice.UNUSED

  def _less_equal(self, other: "UsageLattice") -> bool:
    match self.value, other.value:
      case (UsageLattice.UNUSED.value, _) | (_, UsageLattice.USED.value):
        return True
      case x, y if x == y:
        return True
      case (UsageLattice.BELOW.value, UsageLattice.OVERWRITTEN.value) | \
        (UsageLattice.OVERWRITTEN.value, UsageLattice.BELOW.value):
        return False
      case x, y:
        return x <= y

  def join(self, other: "UsageLattice") -> "UsageLattice":
    if self >= other:
      return self
    if other >= self:
      return other
    return UsageLattice.USED

  def meet(self, other: "UsageLattice") -> "UsageLattice":
    if self <= other:
      return self
    if other <= self:
      return other
    return UsageLattice.UNUSED

  def __str__(self) -> str:
    match self:
      case UsageLattice.USED:
        return "U"
      case UsageLattice.BELOW:
        return "B"
      case UsageLattice.OVERWRITTEN:
        return "W"
      case UsageLattice.UNUSED:
        return "N"
    return ""

class UsageAbstractDomain(AbstractValueDomain):
  """
    Abstract domain for usage analysis.
  """

  def __init__(self, variables: set[MyVariable], initials:set[MyVariable]) -> None:
    self.map: dict[MyVariable, UsageLattice] = {x: UsageLattice.UNUSED for x in variables}
    self.map.update({x: UsageLattice.USED for x in initials})
    self.points_to: dict[MyVariable, set[MyVariable]] = PointsTo.get_shared_regions()

  @staticmethod
  def bottom() -> "UsageAbstractDomain":
    return UsageAbstractDomain(MyEnvironment.my_variables(), set())

  @staticmethod
  def top() -> "UsageAbstractDomain":
    return UsageAbstractDomain(set(), MyEnvironment.my_variables())

  def _widening(self, other: "UsageAbstractDomain") -> "UsageAbstractDomain":
    return self._join(other)

  def __hash__(self) -> int:
    return hash(frozenset(self.map.items()))

  def __str__(self) -> str:
    return ",".join(f"{k}({v})" for k, v in self.map.items() if v != UsageLattice.UNUSED)

  def __deepcopy__(self, memodict=None) -> "UsageAbstractDomain":
    new_domain = UsageAbstractDomain(set(), set())
    new_domain.map = deepcopy(self.map)
    return new_domain

  def _join(self, other: "UsageAbstractDomain") -> "UsageAbstractDomain":
    new_state = deepcopy(self)
    for k in new_state.map.keys():
      new_state.map[k] = self.map[k].join(other.map[k])
    return new_state

  def _meet(self, other: "UsageAbstractDomain") -> "UsageAbstractDomain":
    new_state = deepcopy(self)
    for k in new_state.map.keys():
      new_state.map[k] = self.map[k].meet(other.map[k])
    return new_state

  def assign(self, lhs, rhs, direction) -> "UsageAbstractDomain":
    if direction == AnalysisDirection.FORWARD:
      raise NotImplementedError("Forward analysis not implemented.")
    new_state = deepcopy(self)
    lhs_base = lhs.base
    if self.map[lhs_base] in (UsageLattice.USED, UsageLattice.BELOW):
      if lhs_base not in rhs.variables and not isinstance(lhs, MyArrayVariable):
        new_state.map[lhs_base] = UsageLattice.OVERWRITTEN
      for y in rhs.variables:
        new_state.map[y] = UsageLattice.USED
        for connected_var in self.points_to[y]:
          new_state.map[connected_var] = UsageLattice.USED
    return new_state

  def filter(self, cond, direction) -> "UsageAbstractDomain":
    if direction == AnalysisDirection.FORWARD:
      raise NotImplementedError("Forward analysis not implemented.")
    new_state = deepcopy(self)
    if any(v in (UsageLattice.USED, UsageLattice.OVERWRITTEN) for v in self.map.values()):
      for y in cond.variables:
        new_state.map[y] = UsageLattice.USED
        for connected_var in self.points_to[y]:
          new_state.map[connected_var] = UsageLattice.USED
    return new_state

  def inc(self) -> "UsageAbstractDomain":
    new_state = deepcopy(self)
    for k in new_state.map.keys():
      if self.map[k] == UsageLattice.USED:
        new_state.map[k] = UsageLattice.BELOW
      elif self.map[k] == UsageLattice.OVERWRITTEN:
        new_state.map[k] = UsageLattice.UNUSED
    return new_state

  def dec(self, other: "UsageAbstractDomain") -> "UsageAbstractDomain":
    new_state = deepcopy(self)
    for k in new_state.map.keys():
      if self.map[k] in (UsageLattice.UNUSED, UsageLattice.BELOW):
        new_state.map[k] = other.map[k]
    return new_state

  def _less_equal(self, other: "UsageAbstractDomain") -> bool:
    return all(self.map[k] <= other.map[k] for k in self.map.keys() & other.map.keys())

  def may_used_variables(self) -> set[MyVariable]:
    return {k for k, v in self.map.items() if v in (UsageLattice.USED, UsageLattice.BELOW)}

  def taint(self, variable: MyVariable):
    self.map[variable] = UsageLattice.USED
