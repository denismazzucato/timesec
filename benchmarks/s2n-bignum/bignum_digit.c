
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;

  uVar1 = param_1;
  if (param_1 != 0) {
    uVar3 = 0;
    uVar2 = 0;
    do {
      uVar1 = *(ulong *)(param_2 + uVar3 * 8);
      if (uVar3 != param_3) {
        uVar1 = uVar2;
      }
      uVar3 = uVar3 + 1;
      uVar2 = uVar1;
    } while (uVar3 < param_1);
  }
}
