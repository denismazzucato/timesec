
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  bool bVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;

  if (param_1 != 0) {
    uVar3 = -(ulong)(param_4 < 0);
    lVar6 = 0;
    bVar1 = CARRY8(uVar3,uVar3);
    do {
      uVar4 = *(ulong *)(param_3 + lVar6);
      uVar5 = (*(ulong *)(param_5 + lVar6) ^ uVar3) & -(ulong)(param_4 != 0);
      bVar2 = CARRY8(uVar4,uVar5) || CARRY8(uVar4 + uVar5,(ulong)bVar1);
      *(ulong *)(param_2 + lVar6) = uVar4 + uVar5 + (ulong)bVar1;
      lVar6 = lVar6 + 8;
      param_1 = param_1 - 1;
      bVar1 = bVar2;
    } while (param_1 != 0);
    param_1 = (ulong)(bVar2 != param_4 < 0);
  }
}
