
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5,long param_6)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;

  uVar5 = param_1;
  if (param_3 < param_1) {
    uVar5 = param_3;
  }
  uVar6 = param_1;
  if (param_5 < param_1) {
    uVar6 = param_5;
  }
  if (uVar5 < uVar6) {
    lVar3 = param_1 - uVar6;
    lVar4 = uVar6 - uVar5;
    bVar2 = true;
    lVar7 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar8 = *(ulong *)(param_4 + lVar7 * 8);
      uVar10 = *(ulong *)(param_6 + lVar7 * 8);
      bVar1 = !bVar2;
      uVar6 = ~uVar10;
      bVar2 = CARRY8(uVar8,uVar6) || CARRY8(uVar8 + uVar6,(ulong)bVar2);
      *(ulong *)(param_2 + lVar7 * 8) = uVar8 - (uVar10 + bVar1);
      lVar7 = lVar7 + 1;
    }
    do {
      uVar5 = *(long *)(param_6 + lVar7 * 8) + (ulong)!bVar2;
      bVar2 = CARRY8(~uVar5,(ulong)bVar2);
      *(ulong *)(param_2 + lVar7 * 8) = -uVar5;
      lVar7 = lVar7 + 1;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  else {
    lVar3 = param_1 - uVar5;
    lVar4 = uVar5 - uVar6;
    bVar2 = true;
    lVar7 = 0;
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      uVar8 = *(ulong *)(param_4 + lVar7 * 8);
      uVar10 = *(ulong *)(param_6 + lVar7 * 8);
      bVar1 = !bVar2;
      uVar5 = ~uVar10;
      bVar2 = CARRY8(uVar8,uVar5) || CARRY8(uVar8 + uVar5,(ulong)bVar2);
      *(ulong *)(param_2 + lVar7 * 8) = uVar8 - (uVar10 + bVar1);
      lVar7 = lVar7 + 1;
    }
    for (; lVar4 != 0; lVar4 = lVar4 + -1) {
      lVar9 = *(long *)(param_4 + lVar7 * 8);
      bVar1 = !bVar2;
      bVar2 = lVar9 != 0 || CARRY8(lVar9 - 1,(ulong)bVar2);
      *(ulong *)(param_2 + lVar7 * 8) = lVar9 - (ulong)bVar1;
      lVar7 = lVar7 + 1;
    }
  }
  if (lVar3 != 0) {
    do {
      *(ulong *)(param_2 + lVar7 * 8) = -(ulong)!bVar2;
      lVar7 = lVar7 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }
}
