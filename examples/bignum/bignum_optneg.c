
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,long param_3,long param_4)

{
  bool bVar1;
  bool bVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;

  if (param_1 != 0) {
    uVar3 = -(ulong)(param_3 != 0);
    lVar5 = 0;
    bVar2 = CARRY8(uVar3,uVar3);
    do {
      uVar4 = *(ulong *)(param_4 + lVar5) ^ uVar3;
      bVar1 = CARRY8(uVar4,(ulong)bVar2);
      *(ulong *)(param_2 + lVar5) = uVar4 + bVar2;
      lVar5 = lVar5 + 8;
      param_1 = param_1 - 1;
      bVar2 = bVar1;
    } while (param_1 != 0);
    param_1 = (ulong)(byte)(bVar1 ^ param_3 != 0);
  }
}
