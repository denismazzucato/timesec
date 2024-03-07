
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4)

{
  bool bVar1;
  ulong uVar2;

  uVar2 = 0;
  bVar1_1 = param_1;
  bVar1_2 = param_3;
  if (param_1 < param_3) {
    do {
      param_3 = param_3 - 1;
      uVar2 = uVar2 | *(ulong *)(param_4 + param_3 * 8);
    } while (param_1 != param_3);
  }
  else {
    while (bVar1_1 != bVar1_2) {
      param_1 = param_1 - 1;
      uVar2 = uVar2 | *(ulong *)(param_2 + param_1 * 8);
      bVar1_1 = param_1;
      bVar1_2 = param_3;
    }
  }
  while (param_1 != 0) {
    param_1 = param_1 - 1;
    uVar2 = uVar2 | *(ulong *)(param_2 + param_1 * 8) ^ *(ulong *)(param_4 + param_1 * 8);
  }
}
