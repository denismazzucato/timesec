
#include "bignum_types.h"

void ltmp0(ulong *param_1,ulong *param_2,long param_3,long param_4,long param_5)

{
  long lVar1;
  ulong *puVar2;
  long lVar3;
  lVar1 = param_4;
  puVar2 = param_1;
  if ((param_3 != 0) && (param_4 != 0)) {
    do {
      *puVar2 = 0;
      lVar1 = lVar1 + -1;
      puVar2 = puVar2 + 1;
    } while (lVar1 != 0);
    lVar1 = 0;
    do {
      lVar3 = param_4;
      puVar2 = param_1;
      do {
        *puVar2 = *puVar2 | *param_2 & -(ulong)(lVar1 == param_5);
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
        lVar3 = lVar3 + -1;
      } while (lVar3 != 0);
      lVar1 = lVar1 + 1;
    } while (lVar1 != param_3);
  }

}
