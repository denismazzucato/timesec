from copy import deepcopy
from queue import LifoQueue

from src.abstract_domains.syntactic_dependencies.usage_lattice import (
  UsageAbstractDomain,
)
from src.frontend.symbolic import MyVariable
from src.proto.abstract_value_domain import AbstractValueDomain, AnalysisDirection


class SyntacticDependencies(AbstractValueDomain):

  def __init__(self) -> None:
    self.stack: LifoQueue[UsageAbstractDomain] = LifoQueue()

  def __deepcopy__(self, memodict=None) -> "SyntacticDependencies":
    new_domain = SyntacticDependencies()
    new_domain.stack.queue = deepcopy(self.stack.queue)
    return new_domain

  @staticmethod
  def initialize(tainted_variables: set[MyVariable]) -> "SyntacticDependencies":
    state = SyntacticDependencies.bottom()
    for variable in tainted_variables:
      state.stack.queue[-1].taint(variable)
    return state

  def _join(self, other: "SyntacticDependencies") -> "SyntacticDependencies":
    new_state = deepcopy(self)
    new_queue = [x.join(y) for x, y in zip(self.stack.queue, other.stack.queue)]
    new_state.stack.queue = new_queue # type: ignore
    return new_state

  def _meet(self, other: "SyntacticDependencies") -> "SyntacticDependencies":
    new_state = deepcopy(self)
    new_queue = [x.meet(y) for x, y in zip(self.stack.queue, other.stack.queue)]
    new_state.stack.queue = new_queue # type: ignore
    return new_state

  def __str__(self) -> str:
    return " | ".join("<" + str(x) + ">" for x in reversed(self.stack.queue))

  def last(self) -> UsageAbstractDomain:
    # get the last in without removing it
    return self.stack.queue[-1]

  def _less_equal(self, other: "SyntacticDependencies") -> bool:
    if len(self.stack.queue) != len(other.stack.queue):
      return False
    return all(x <= y for x, y in zip(self.stack.queue, other.stack.queue))

  def _widening(self, other: "SyntacticDependencies") -> "SyntacticDependencies":
    return self._join(other)

  def assign(self, lhs, rhs, direction) -> "SyntacticDependencies":
    if direction == AnalysisDirection.FORWARD:
      raise NotImplementedError("Forward analysis not implemented.")
    if len(self.stack.queue) == 0:
      raise ValueError("Empty stack during assignment.")
    new_state = deepcopy(self)
    new_state.stack.put(new_state.stack.get().assign(lhs, rhs, direction))
    return new_state

  def filter(self, cond, direction) -> "SyntacticDependencies":
    if direction == AnalysisDirection.FORWARD:
      raise NotImplementedError("Forward analysis not implemented.")
    if len(self.stack.queue) == 0:
      raise ValueError("Empty stack during filter.")
    new_state = deepcopy(self)
    new_state.stack.put(new_state.stack.get().filter(cond, direction))
    return new_state

  def push(self) -> "SyntacticDependencies":
    if len(self.stack.queue) == 0:
      raise ValueError("Empty stack during push.")
    new_state = deepcopy(self)
    m0 = new_state.stack.get()
    new_state.stack.put(m0)
    new_state.stack.put(m0.inc())
    return new_state

  def pop(self) -> "SyntacticDependencies":
    if len(self.stack.queue) <= 1:
      raise ValueError("Less than two stacks during pop.")
    new_state = deepcopy(self)
    m0 = new_state.stack.get()
    m1 = new_state.stack.get()
    new_state.stack.put(m0.dec(m1))
    return new_state

  @staticmethod
  def bottom() -> "SyntacticDependencies":
    self = SyntacticDependencies()
    self.stack.put(UsageAbstractDomain.bottom())
    return self

  @staticmethod
  def top() -> "SyntacticDependencies":
    self = SyntacticDependencies()
    self.stack.put(UsageAbstractDomain.top())
    return self

  def __hash__(self) -> int:
    return hash(self.stack.queue)
