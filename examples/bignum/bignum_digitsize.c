
#include "bignum_types.h"

void ltmp0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;

  lVar2 = param_1;
  if (param_1 != 0) {
    lVar4 = 0;
    lVar3 = 0;
    do {
      lVar1 = lVar4 * 8;
      lVar4 = lVar4 + 1;
      lVar2 = lVar4;
      if (*(long *)(param_2 + lVar1) == 0) {
        lVar2 = lVar3;
      }
      lVar3 = lVar2;
    } while (lVar4 != param_1);
  }
}
