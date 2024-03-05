
#include "bignum_types.h"

void ltmp0(ulong param_1,long *param_2,ulong param_3,ulong param_4,ulong *param_5)

{
  long lVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  bool bVar6;
  bool bVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;

  uVar12 = param_1;
  if (param_4 < param_1) {
    uVar12 = param_4;
  }
  lVar8 = param_1 - uVar12;
  uVar11 = 0;
  lVar10 = 0;
  if (uVar12 != 0) {
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_3;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = *param_5;
    uVar11 = SUB168(auVar2 * auVar4,8);
    *param_2 = param_3 * *param_5;
    lVar10 = 8;
    lVar9 = uVar12 - 1;
    if (lVar9 != 0) {
      bVar6 = false;
      do {
        uVar12 = param_3 * *(ulong *)((long)param_5 + lVar10);
        bVar7 = CARRY8(uVar12,uVar11) || CARRY8(uVar12 + uVar11,(ulong)bVar6);
        lVar1 = uVar12 + uVar11;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = param_3;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = *(ulong *)((long)param_5 + lVar10);
        uVar11 = SUB168(auVar3 * auVar5,8);
        *(ulong *)((long)param_2 + lVar10) = lVar1 + (ulong)bVar6;
        lVar10 = lVar10 + 8;
        lVar9 = lVar9 + -1;
        bVar6 = bVar7;
      } while (lVar9 != 0);
      uVar11 = uVar11 + bVar7;
    }
  }
  if (lVar8 != 0) {
    *(ulong *)((long)param_2 + lVar10) = uVar11;
    uVar11 = 0;
    lVar8 = lVar8 + -1;
    while (lVar8 != 0) {
      lVar8 = lVar8 + -1;
      lVar10 = lVar10 + 8;
      *(undefined8 *)((long)param_2 + lVar10) = 0;
    }
  }
}
