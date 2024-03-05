
#include "bignum_types.h"

void ltmp0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;

  if (param_1 != 0) {
    lVar2 = param_1;
    uVar3 = 1;
    do {
      param_1 = param_1 + -1;
      uVar4 = *(ulong *)(param_2 + param_1 * 8);
      lVar1 = param_1;
      if (uVar4 == 0) {
        uVar4 = uVar3;
        lVar1 = lVar2;
      }
      lVar2 = lVar1;
      uVar3 = uVar4;
    } while (param_1 != 0);
    param_1 = (lVar2 + 1) * 0x40 - LZCOUNT(uVar4 - 1 & ~uVar4);
  }
}
