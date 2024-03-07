
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  bool bVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;

  if (param_1 != 0) {
    lVar5 = 0;
    bVar1 = false;
    do {
      uVar3 = *(ulong *)(param_3 + lVar5);
      uVar4 = *(ulong *)(param_5 + lVar5) & -(ulong)(param_4 != 0);
      bVar2 = CARRY8(uVar3,uVar4) || CARRY8(uVar3 + uVar4,(ulong)bVar1);
      *(ulong *)(param_2 + lVar5) = uVar3 + uVar4 + (ulong)bVar1;
      lVar5 = lVar5 + 8;
      param_1 = param_1 - 1;
      bVar1 = bVar2;
    } while (param_1 != 0);
    param_1 = (ulong)bVar2;
  }
}
