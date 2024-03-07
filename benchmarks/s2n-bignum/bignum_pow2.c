
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;

  if (param_1 != 0) {
    uVar2 = 0;
    do {
      lVar1 = 1L << (param_3 & 0x3f);
      if (uVar2 != param_3 >> 6) {
        lVar1 = 0;
      }
      *(long *)(param_2 + uVar2 * 8) = lVar1;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1);
  }

}
