
#include "bignum_types.h"

void ltmp0(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;

  if (param_1 != 0) {
    lVar6 = 0;
    bVar5 = false;
    lVar7 = param_1;
    do {
      uVar8 = *(ulong *)(param_3 + lVar6);
      uVar9 = *(ulong *)(param_4 + lVar6);
      bVar4 = CARRY8(uVar8,uVar9) || CARRY8(uVar8 + uVar9,(ulong)bVar5);
      *(ulong *)(param_2 + lVar6) = uVar8 + uVar9 + (ulong)bVar5;
      lVar6 = lVar6 + 8;
      lVar7 = lVar7 + -1;
      bVar5 = bVar4;
    } while (lVar7 != 0);
    bVar5 = true;
    lVar6 = 0;
    lVar7 = param_1;
    do {
      bVar1 = CARRY8(*(ulong *)(param_2 + lVar6),~*(ulong *)(param_5 + lVar6));
      bVar2 = CARRY8(*(ulong *)(param_2 + lVar6) + ~*(ulong *)(param_5 + lVar6),(ulong)bVar5);
      bVar5 = bVar1 || bVar2;
      lVar6 = lVar6 + 8;
      lVar7 = lVar7 + -1;
    } while (lVar7 != 0);
    bVar5 = true;
    lVar6 = 0;
    do {
      uVar9 = *(ulong *)(param_2 + lVar6);
      uVar10 = *(ulong *)(param_5 + lVar6) & ~((ulong)bVar4 - (ulong)(!bVar1 && !bVar2));
      bVar3 = !bVar5;
      uVar8 = ~uVar10;
      bVar5 = CARRY8(uVar9,uVar8) || CARRY8(uVar9 + uVar8,(ulong)bVar5);
      *(ulong *)(param_2 + lVar6) = uVar9 - (uVar10 + bVar3);
      lVar6 = lVar6 + 8;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }

}
