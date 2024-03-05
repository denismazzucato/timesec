
#include "bignum_types.h"

void ltmp0(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;

  uVar2 = param_1 * -3 ^ 2;
  lVar3 = param_1 * uVar2 + 1;
  lVar1 = lVar3 * lVar3;
  lVar3 = uVar2 + lVar3 * uVar2;
  lVar4 = lVar1 * lVar1;
  lVar3 = lVar3 + lVar1 * lVar3;
  lVar3 = lVar3 + lVar4 * lVar3;
}
