
from copy import deepcopy
from logging import warning
from typing import Callable

from apronpy.polka import PyPolka
from apronpy.tcons1 import PyTcons1Array

from src.abstract_domains.polka import Polka
from src.frontend.symbolic_to_apron import (
  SymbolicToApronError,
  arithmetic_to_apron,
  condition_to_apron,
  variable_to_apron,
)
from src.proto.abstract_value_domain import AnalysisDirection


def resolve_input_streams(expr, direction):
  def inner(func):
    def wrapper(core):
      randoms = expr.contains_randoms()
      if not randoms:
        return func(core)

      core_without_input_streams = core.forget(
        [variable_to_apron(stream) for stream in randoms])
      if core_without_input_streams == core:
        new_core = func(core)
      else:
        new_core = func(core_without_input_streams)
        new_core = core_without_input_streams.join(new_core)

      return new_core
    return wrapper
  return inner

def top_if_error(error_type):
  def inner(func):
    def wrapper(core):
      try:
        return func(core)
      except error_type as e:
        warning(f"raised SymbolicToApronError: {e}")
        return PolkaWithStreams.top().core
    return wrapper
  return inner

class PolkaWithStreams(Polka):

  def __deepcopy__(self, memodict=None) -> "PolkaWithStreams":
    new_polka = PolkaWithStreams([])
    new_polka.core = deepcopy(self.core)
    return new_polka

  def _compute_new(self, operation: "Callable[[PyPolka], PyPolka]") -> "PolkaWithStreams":
    new_polka = deepcopy(self)
    new_polka.core = operation(new_polka.core)
    return new_polka

  def _join(self, other: "PolkaWithStreams") -> "PolkaWithStreams":
    return self._compute_new(
      lambda x: x.join(other.core)
    )

  def _meet(self, other: "PolkaWithStreams") -> "PolkaWithStreams":
    return self._compute_new(
      lambda x: x.meet(other.core)
    )

  def _less_equal(self, other: "PolkaWithStreams") -> bool:
    return self.core <= other.core

  def _widening(self, other: "PolkaWithStreams") -> "PolkaWithStreams":
    return self._compute_new(
      lambda x: x.widening(other.core)
    )

  def assign(self, lhs, rhs, direction) -> "PolkaWithStreams":
    @resolve_input_streams(rhs, direction)
    @top_if_error(SymbolicToApronError)
    def _assign(x):
      if direction == AnalysisDirection.FORWARD:
        return x.assign(variable_to_apron(lhs), arithmetic_to_apron(rhs))
      return x.substitute(variable_to_apron(lhs), arithmetic_to_apron(rhs))
    return self._compute_new(_assign)

  def filter(self, cond, direction) -> "PolkaWithStreams":
    @resolve_input_streams(cond, direction)
    @top_if_error(SymbolicToApronError)
    def _filter(x):
      return x.meet(PyTcons1Array(condition_to_apron(cond)))
    return self._compute_new(_filter)

  @staticmethod
  def bottom() -> "PolkaWithStreams":
    self = PolkaWithStreams([])
    self.core = PyPolka.bottom(PolkaWithStreams.man, self.env)
    return self

  @staticmethod
  def top() -> "PolkaWithStreams":
    self = PolkaWithStreams([])
    self.core = PyPolka.top(PolkaWithStreams.man, self.env)
    return self
