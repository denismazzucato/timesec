


from collections import defaultdict
from logging import warning

from src.frontend.abstract_syntax_tree import (
  MyAssign,
  MyComposedASTNode,
  MyFunction,
  MyIf,
  MySequence,
  MyStatement,
  MyWhile,
)
from src.frontend.symbolic import BehavesLikeArrays, MyVariable, MyVariableExpression
from src.user_interface.logging import debug1
from src.utils.colors import title
from src.utils.time import Timeit


class PointsTo:
  """
    Class for performing points-to analysis.

    Attributes:
        _shared_pointers (defaultdict): Dictionary to store shared pointers.
  """
  _shared_pointers = defaultdict(set)

  @staticmethod
  def get_shared_regions() -> dict[MyVariable, set[MyVariable]]:
    return PointsTo._shared_pointers

  @staticmethod
  def gather_all_simple_assignments(ast: MyComposedASTNode) -> set[tuple[MyVariable, MyVariable]]:
    """
        Gather all simple assignments from the AST.

        Args:
            ast (MyComposedASTNode): The root of the AST.

        Returns:
            set[tuple[MyVariable, MyVariable]]: Set of simple assignments as tuples (lhs, rhs).
      """
    match ast:
      case MyStatement(MyAssign(MyVariable(lhs_name), MyVariableExpression(MyVariable(rhs_name)))):
        return { (MyVariable(lhs_name), MyVariable(rhs_name)) }
      case MySequence(first, second):
        return PointsTo.gather_all_simple_assignments(first) | PointsTo.gather_all_simple_assignments(second)
      case MyWhile(_, body):
        return PointsTo.gather_all_simple_assignments(body)
      case MyIf(_, then_branch, else_branch):
        return PointsTo.gather_all_simple_assignments(then_branch) | PointsTo.gather_all_simple_assignments(else_branch)
    return set()

  @staticmethod
  def points_to_analysis(function: MyFunction) -> None:
    """
        Perform points-to analysis on the given function.

        Args:
            function (MyFunction): The function to analyze.
    """
    assignments = PointsTo.gather_all_simple_assignments(function.body)
    array_variables = BehavesLikeArrays.variables()
    PointsTo._shared_pointers = defaultdict(set)
    for lhs, rhs in assignments:
      if lhs in array_variables or rhs in array_variables:
        PointsTo._shared_pointers[lhs].add(rhs)
        PointsTo._shared_pointers[rhs].add(lhs)


@Timeit("points_to_analysis")
def points_to_analysis(function: MyFunction) -> dict[MyVariable, set[MyVariable]]:
  """
    Perform points-to analysis on the given function.

    Args:
        function (MyFunction): The function to analyze.

    Returns:
        dict[MyVariable, set[MyVariable]]: Dictionary mapping pointers to their shared regions.
  """
  PointsTo.points_to_analysis(function)
  points_to = PointsTo.get_shared_regions()
  if any(len(xs) > 0 for xs in points_to.values()):
    warning("Found shared regions among pointers. This may lead to unsoundness (please add --debug 1 to see the regions).")
  debug1(title("Points-to analysis") + ", ".join(f"{k} -> ({",".join(map(str, v))})" for k, v in points_to.items()))
  return points_to
