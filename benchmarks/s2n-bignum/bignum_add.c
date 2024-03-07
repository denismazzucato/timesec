
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5,long param_6)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;

  uVar7 = param_1;
  if (param_3 < param_1) {
    uVar7 = param_3;
  }
  uVar5 = param_1;
  if (param_5 < param_1) {
    uVar5 = param_5;
  }
  if (uVar7 < uVar5) {
    lVar3 = param_1 - uVar5;
    lVar4 = uVar5 - uVar7;
    lVar6 = 0;
    bVar1 = false;
    for (; uVar7 != 0; uVar7 = uVar7 - 1) {
      uVar5 = *(ulong *)(param_4 + lVar6 * 8);
      uVar8 = *(ulong *)(param_6 + lVar6 * 8);
      *(ulong *)(param_2 + lVar6 * 8) = uVar5 + uVar8 + (ulong)bVar1;
      lVar6 = lVar6 + 1;
      bVar1 = CARRY8(uVar5,uVar8) || CARRY8(uVar5 + uVar8,(ulong)bVar1);
    }
    do {
      uVar7 = *(ulong *)(param_6 + lVar6 * 8);
      bVar2 = CARRY8(uVar7,(ulong)bVar1);
      *(ulong *)(param_2 + lVar6 * 8) = uVar7 + bVar1;
      lVar6 = lVar6 + 1;
      lVar4 = lVar4 + -1;
      bVar1 = bVar2;
    } while (lVar4 != 0);
  }
  else {
    lVar3 = param_1 - uVar7;
    lVar4 = uVar7 - uVar5;
    lVar6 = 0;
    bVar2 = false;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar7 = *(ulong *)(param_4 + lVar6 * 8);
      uVar8 = *(ulong *)(param_6 + lVar6 * 8);
      *(ulong *)(param_2 + lVar6 * 8) = uVar7 + uVar8 + (ulong)bVar2;
      lVar6 = lVar6 + 1;
      bVar2 = CARRY8(uVar7,uVar8) || CARRY8(uVar7 + uVar8,(ulong)bVar2);
    }
    for (; lVar4 != 0; lVar4 = lVar4 + -1) {
      uVar7 = *(ulong *)(param_4 + lVar6 * 8);
      *(ulong *)(param_2 + lVar6 * 8) = uVar7 + bVar2;
      lVar6 = lVar6 + 1;
      bVar2 = CARRY8(uVar7,(ulong)bVar2);
    }
  }

  if (lVar3 != 0) {
    *(ulong *)(param_2 + lVar6 * 8) = (ulong)bVar2;

    while(lVar3 != 0) {
      lVar6 = lVar6 + 1;
      lVar3 = lVar3 + -1;
      if (lVar3 != 0) {
        *(undefined8 *)(param_2 + lVar6 * 8) = 0;
      }
    }
  }
}
