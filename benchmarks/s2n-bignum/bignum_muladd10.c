
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  ulong uVar2;

  if (param_1 != 0) {
    uVar1 = 0;
    do {
      uVar2 = *(ulong *)(param_2 + uVar1 * 8);
      *(ulong *)(param_2 + uVar1 * 8) = uVar2 * 10 + param_3;
      param_3 = ((uVar2 >> 0x3d) - ((long)uVar2 >> 0x3f)) + (ulong)CARRY8(uVar2 * 2,uVar2 * 8) +
                (ulong)CARRY8(uVar2 * 10,param_3);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_1);
  }
}
