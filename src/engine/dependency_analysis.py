



from logging import debug

from src.abstract_domains.syntactic_dependencies.syntactic_dependencies import (
  SyntacticDependencies,
)
from src.abstract_domains.syntactic_dependencies.usage_lattice import (
  UsageAbstractDomain,
)
from src.frontend.abstract_syntax_tree import (
  AnnotationKey,
  MyAssign,
  MyAssume,
  MyAtomicASTNode,
  MyComposedASTNode,
  MyFunction,
  MyIf,
  MySequence,
  MySkip,
  MyStatement,
  MyWhile,
)
from src.frontend.symbolic import MyEnvironment, MyFunctionCallExpression, MyVariable
from src.proto.abstract_value_domain import AnalysisDirection
from src.user_interface.logging import debug1
from src.utils.colors import title
from src.utils.globals import SYMBOLIC_VARIABLE_NAME, IsDependencyAnalysis
from src.utils.time import Timeit


class Iterator:
  """
    Class for performing fixpoint iteration for dependency analysis.
  """
  def __init__(self):
    pass

  def fixpoint_iterator_for_atomic(
      self,
      ast: MyAtomicASTNode,
      post_deps: SyntacticDependencies) -> SyntacticDependencies:
    """
        Perform fixpoint iteration for atomic AST nodes.

        Args:
            ast (MyAtomicASTNode): The atomic AST node.
            post_deps (SyntacticDependencies): The dependencies after the node.

        Returns:
            SyntacticDependencies: The dependencies before the node.
    """
    pre_deps = post_deps
    match ast:
      case MyAssign(MyVariable("_"), MyFunctionCallExpression("__print_deps", args, coord=coord)):
        keyword = " " + str(args[0]) if args else ""
        debug(title(f"Dependencies{keyword} at l{coord[0]} c{coord[1]}") + str(post_deps))
      case MyAssign(lhs, rhs):
        pre_deps = post_deps.assign(lhs, rhs, AnalysisDirection.BACKWARD)
      case MyAssume(condition):
        if condition.variables & post_deps.last().may_used_variables():
          pre_deps = post_deps.filter(condition, AnalysisDirection.BACKWARD)
    ast.annotations[AnnotationKey.DEPS_PRE] = pre_deps.last()
    ast.annotations[AnnotationKey.DEPS_POST] = post_deps.last()
    return pre_deps

  def fixpoint_iterator_for_composed(
      self,
      ast: MyComposedASTNode,
      post_deps: SyntacticDependencies) -> SyntacticDependencies:
    """
        Perform fixpoint iteration for composed AST nodes.

        Args:
            ast (MyComposedASTNode): The composed AST node.
            post_deps (SyntacticDependencies): The dependencies after the node.

        Returns:
            SyntacticDependencies: The dependencies before the node.
    """
    pre_deps = post_deps
    match ast:
      case MyStatement(statement):
        pre_deps = self.fixpoint_iterator_for_atomic(statement, post_deps)
      case MyIf(condition, then_branch, else_branch):
        pushed_deps = post_deps.push()
        deps_then = self.fixpoint_iterator_for_composed(
          then_branch,
          pushed_deps). \
            filter(condition, AnalysisDirection.BACKWARD). \
              pop()
        deps_else = self.fixpoint_iterator_for_composed(
          else_branch,
          pushed_deps). \
            filter(condition, AnalysisDirection.BACKWARD). \
              pop()
        pre_deps = deps_then.join(deps_else)
        assert isinstance(pre_deps, SyntacticDependencies)
      case MyWhile(condition, loop_body):
        while True:
          body_as_if = MyIf(condition, loop_body, MyStatement(MySkip()))
          deps_loop = self.fixpoint_iterator_for_composed(
            body_as_if,
            post_deps)
          # pre_deps = post_deps.join(deps_loop)
          pre_deps = deps_loop
          assert isinstance(pre_deps, SyntacticDependencies)
          if pre_deps <= post_deps:
            break
          post_deps = pre_deps
      case MySequence(first, second):
        # backward analysis
        pre_deps = self.fixpoint_iterator_for_composed(
          first,
          self.fixpoint_iterator_for_composed(
            second,
            post_deps))
    return pre_deps

@Timeit("dependency_analysis")
def dependency_analysis(function: MyFunction) -> UsageAbstractDomain:
  """
    Perform dependency analysis for the given function.

    Args:
        function (MyFunction): The function to analyze.

    Returns:
        UsageAbstractDomain: The computed dependencies.
  """
  if not IsDependencyAnalysis.active():
    return SyntacticDependencies.initialize(MyEnvironment.my_variables()).last()

  initial_deps = SyntacticDependencies.initialize({
    MyVariable(SYMBOLIC_VARIABLE_NAME)
  })
  iterator = Iterator()
  input_deps = iterator.fixpoint_iterator_for_composed(function.body, initial_deps).last()
  debug1(function.str_with_dependencies())
  debug(title("(May) Used Variables") + \
        ", ".join(map(str, input_deps.may_used_variables())))
  return input_deps
