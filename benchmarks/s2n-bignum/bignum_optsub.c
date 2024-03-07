
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ulong uVar4;
  bool bVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;

  if (param_1 != 0) {
    bVar5 = true;
    lVar8 = 0;
    do {
      uVar6 = *(ulong *)(param_3 + lVar8);
      uVar7 = *(ulong *)(param_5 + lVar8) & -(ulong)(param_4 != 0);
      bVar3 = !bVar5;
      uVar4 = ~uVar7;
      bVar1 = CARRY8(uVar6,uVar4);
      bVar2 = CARRY8(uVar6 + uVar4,(ulong)bVar5);
      bVar5 = bVar1 || bVar2;
      *(ulong *)(param_2 + lVar8) = uVar6 - (uVar7 + bVar3);
      lVar8 = lVar8 + 8;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
    param_1 = (ulong)(!bVar1 && !bVar2);
  }
}
