
#include "bignum_types.h"

void ltmp0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;

  if (param_1 != 0) {
    lVar2 = param_1;
    param_1 = 0;
    do {
      lVar2 = lVar2 + -1;
      uVar3 = *(ulong *)(param_2 + lVar2 * 8);
      uVar4 = uVar3 >> 0x1d | param_1 << 0x23;
      lVar1 = uVar4 * 0x3333333 + (uVar4 + (uVar3 >> 1 & 0xfffffff)) / 5;
      *(long *)(param_2 + lVar2 * 8) = lVar1;
      param_1 = uVar3 + lVar1 * -10;
    } while (lVar2 != 0);
  }
}
