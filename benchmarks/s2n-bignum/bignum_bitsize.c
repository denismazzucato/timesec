
#include "bignum_types.h"

void ltmp0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;

  if (param_1 != 0) {
    lVar2 = 0;
    lVar5 = 0;
    lVar3 = -1;
    do {
      lVar4 = *(long *)(param_2 + lVar5 * 8);
      lVar5 = lVar5 + 1;
      lVar1 = lVar5;
      if (lVar4 == 0) {
        lVar4 = lVar3;
        lVar1 = lVar2;
      }
      lVar2 = lVar1;
      lVar3 = lVar4;
    } while (lVar5 != param_1);
    param_1 = lVar2 * 0x40 - LZCOUNT(lVar4);
  }

}
