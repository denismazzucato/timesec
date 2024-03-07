
#include "bignum_types.h"

void ltmp0(long param_1,long param_2)

{
  long lVar1;
  long lVar2;

  lVar1 = param_1;
  lVar2 = param_1;
  if (param_1 != 0) {
    do {
      lVar1 = lVar1 + -1;
      param_1 = lVar1;
      if (*(long *)(param_2 + lVar1 * 8) == 0) {
        param_1 = lVar2;
      }
      lVar2 = param_1;
    } while (lVar1 != 0);
  }
}
