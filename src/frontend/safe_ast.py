
from pycparser.c_ast import Decl, FuncDef


def get_function_name(function: FuncDef) -> str:
  if isinstance(function, FuncDef) and \
      hasattr(function, "decl") and \
      hasattr(function.decl, "name"):
    return function.decl.name
  return ""

def get_function_params(function: FuncDef) -> list[Decl]:
  if isinstance(function, FuncDef) and \
      hasattr(function, "decl") and \
      hasattr(function.decl, "type") and \
      hasattr(function.decl.type, "args") and \
      hasattr(function.decl.type.args, "params"):
    params = function.decl.type.args.params
    return params if params is not None else []
  return []

def get_function_return_type(function: FuncDef) -> str:
  if isinstance(function, FuncDef) and \
      hasattr(function, "decl") and \
      hasattr(function.decl, "type") and \
      hasattr(function.decl.type, "type") and \
      hasattr(function.decl.type.type, "type") and \
      hasattr(function.decl.type.type.type, "names"):
    return function.decl.type.type.type.names[0]
  return ""
