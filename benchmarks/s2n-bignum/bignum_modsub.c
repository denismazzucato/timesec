
#include "bignum_types.h"

void ltmp0(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;

  if (param_1 != 0) {
    bVar4 = true;
    lVar5 = 0;
    lVar6 = param_1;
    do {
      uVar7 = *(ulong *)(param_3 + lVar5);
      bVar3 = !bVar4;
      uVar8 = ~*(ulong *)(param_4 + lVar5);
      bVar1 = CARRY8(uVar7,uVar8);
      bVar2 = CARRY8(uVar7 + uVar8,(ulong)bVar4);
      bVar4 = bVar1 || bVar2;
      *(ulong *)(param_2 + lVar5) = uVar7 - (*(ulong *)(param_4 + lVar5) + (ulong)bVar3);
      lVar5 = lVar5 + 8;
      lVar6 = lVar6 + -1;
    } while (lVar6 != 0);
    lVar5 = 0;
    bVar4 = false;
    do {
      uVar8 = *(ulong *)(param_2 + lVar5);
      uVar7 = *(ulong *)(param_5 + lVar5) & -(ulong)(!bVar1 && !bVar2);
      *(ulong *)(param_2 + lVar5) = uVar8 + uVar7 + (ulong)bVar4;
      lVar5 = lVar5 + 8;
      param_1 = param_1 + -1;
      bVar4 = CARRY8(uVar8,uVar7) || CARRY8(uVar8 + uVar7,(ulong)bVar4);
    } while (param_1 != 0);
  }

}