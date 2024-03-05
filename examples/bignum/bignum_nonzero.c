
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2)

{
  ulong uVar1;

  uVar1 = 0;
  if (param_1 != 0) {
    do {
      param_1 = param_1 - 1;
      uVar1 = uVar1 | *(ulong *)(param_2 + param_1 * 8);
    } while (param_1 != 0);
    param_1 = (ulong)(uVar1 != 0);
  }
}
