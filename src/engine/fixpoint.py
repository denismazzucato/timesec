

from logging import debug, warning

from src.frontend.abstract_syntax_tree import (
  AnnotationKey,
  MyAssign,
  MyAssume,
  MyAtomicASTNode,
  MyComposedASTNode,
  MyFunction,
  MyIf,
  MySequence,
  MyStatement,
  MyWhile,
  cached_is_relevant,
)
from src.frontend.symbolic_to_apron import SymbolicToApronError
from src.proto.abstract_value_domain import AbstractValueDomain, AnalysisDirection
from src.user_interface.interactive import Interactive
from src.user_interface.logging import debug2
from src.utils.colors import title
from src.utils.time import Timeit, Timeout


class FixpointIterator:

  def __init__(
      self,
      direction: AnalysisDirection,
      k_widening: int,
      decreasing_chain: int):
    self.direction = direction
    self.k_widening = k_widening
    self.decreasing_chain = decreasing_chain

  def meet_with_precursory(
      self,
      ast: MyComposedASTNode | MyAtomicASTNode,
      state: AbstractValueDomain) -> AbstractValueDomain:
    key = AnnotationKey.from_analysis_direction(self.direction)
    precursory_state = ast.annotations[key]
    assert isinstance(precursory_state, AbstractValueDomain)
    new_state = precursory_state.meet(state)
    return new_state

  def update_annotations(
      self,
      ast: MyComposedASTNode | MyAtomicASTNode,
      new_state: AbstractValueDomain):
    key = AnnotationKey.from_analysis_direction(self.direction)
    ast.annotations[AnnotationKey.for_future_iterations(key)] = new_state

  def fixpoint_iterator_for_atomic(
      self,
      ast: MyAtomicASTNode,
      state: AbstractValueDomain) -> AbstractValueDomain:
    new_state = state
    match ast:
      case MyAssign(lhs, rhs):
        new_state = state.assign(lhs, rhs, self.direction)
      case MyAssume(condition):
        new_state = state.filter(condition, self.direction)

    new_state = self.meet_with_precursory(ast, new_state)
    self.update_annotations(ast, new_state)
    return new_state

  def fixpoint_iterator_for_composed(
      self,
      ast: MyComposedASTNode,
      state: AbstractValueDomain) -> AbstractValueDomain:
    new_state = state

    if not cached_is_relevant(ast):
      return new_state

    match ast:
      case MyStatement(statement):
        new_state = self.fixpoint_iterator_for_atomic(statement, state)

      case MyIf(condition, then_branch, else_branch) \
          if self.direction == AnalysisDirection.FORWARD:
        state_then = self.fixpoint_iterator_for_composed(
          then_branch,
          state.filter(condition, self.direction))
        state_else = self.fixpoint_iterator_for_composed(
          else_branch,
          state.filter(condition.logical_negate, self.direction))
        new_state = state_then.join(state_else)

      case MyIf(condition, then_branch, else_branch) \
          if self.direction == AnalysisDirection.BACKWARD:
        state_then = self.fixpoint_iterator_for_composed(
          then_branch,
          state).filter(condition, self.direction)
        state_else = self.fixpoint_iterator_for_composed(
          else_branch,
          state).filter(condition.logical_negate, self.direction)
        new_state = state_then.join(state_else)

      case MyWhile(condition, body) if self.direction == AnalysisDirection.FORWARD:
        counter = 0
        while True:
          counter += 1
          filtered_state = new_state.filter(condition, self.direction)
          body_state = self.fixpoint_iterator_for_composed(body, filtered_state)

          if counter < self.k_widening:
            invariant = body_state.join(new_state)
          else:
            invariant = body_state.widening(new_state)
            if counter - self.k_widening < self.decreasing_chain:
              invariant = self.fixpoint_iterator_for_composed(
                body,
                invariant.filter(condition, self.direction))

          post_state = state.join(invariant)

          if post_state <= new_state:
            new_state = post_state
            break
          new_state = post_state
        new_state = new_state.filter(condition.logical_negate, self.direction)

      case MyWhile(condition, body) if self.direction == AnalysisDirection.BACKWARD:
        counter = 0
        negated_state = state.filter(condition.logical_negate, self.direction)
        new_state = negated_state
        while True:
          counter += 1
          body_state = self.fixpoint_iterator_for_composed(
            body,
            new_state).filter(condition, self.direction)

          if counter < self.k_widening:
            invariant = body_state.join(new_state)
          else:
            invariant = body_state.widening(new_state)
            if counter - self.k_widening < self.decreasing_chain:
              invariant = self.fixpoint_iterator_for_composed(
                body,
                invariant).filter(condition, self.direction)

          post_state = negated_state.join(invariant)

          if post_state <= new_state:
            new_state = post_state
            break
          new_state = post_state

      case MySequence(first, second):
        if self.direction == AnalysisDirection.FORWARD:
          scheduled_first, scheduled_second = first, second
        else:
          scheduled_first, scheduled_second = second, first
        new_state = self.fixpoint_iterator_for_composed(
          scheduled_second,
          self.fixpoint_iterator_for_composed(
            scheduled_first,
            state))

    new_state = self.meet_with_precursory(ast, new_state)
    self.update_annotations(ast, new_state)
    return new_state

@Timeit("fixpoint_iterator")
@Timeout(None)
def iterator(
    domain: type[AbstractValueDomain],
    function: MyFunction,
    k_widening: int,
    decreasing_chain: int,
    repeat: int) -> AbstractValueDomain:

  function.set_annotations(AnnotationKey.ABS_PRE, domain.top())
  function.set_annotations(AnnotationKey.ABS_POST, domain.top())
  function.set_annotations(AnnotationKey.FUTURE_ABS_PRE, domain.top())
  function.set_annotations(AnnotationKey.FUTURE_ABS_POST, domain.top())

  forward_iterator = FixpointIterator(AnalysisDirection.FORWARD, k_widening, decreasing_chain)
  backward_iterator = FixpointIterator(AnalysisDirection.BACKWARD, k_widening, decreasing_chain)
  invariant = domain.top()
  assert isinstance(invariant, AbstractValueDomain)
  for i in range(repeat):
    try:
      invariant = forward_iterator.fixpoint_iterator_for_composed(
        function.body,
        invariant)
      function.body.update_annotations(AnalysisDirection.FORWARD)
      debug2(f"Forward iteration {i + 1}/{repeat}:")
      debug2(function.str_with_abstract_values(AnalysisDirection.FORWARD))
      Interactive.stop_user()

      invariant = backward_iterator.fixpoint_iterator_for_composed(
        function.body,
        invariant)
      function.body.update_annotations(AnalysisDirection.BACKWARD)
      debug2(f"Backward iteration {i + 1}/{repeat}:")
      debug2(function.str_with_abstract_values(AnalysisDirection.BACKWARD))
      Interactive.stop_user()
    except SymbolicToApronError as e:
      warning(f"raised SymbolicToApronError: {e}")
      invariant = domain.top()
      break

  debug(title("Invariant") + str(invariant))

  assert isinstance(invariant, AbstractValueDomain)
  return invariant
