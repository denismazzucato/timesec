
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong param_3,ulong param_4,ulong *param_5)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  bool bVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;

  uVar13 = param_1;
  if (param_4 < param_1) {
    uVar13 = param_4;
  }
  lVar7 = param_1 - uVar13;
  bVar6 = false;
  uVar9 = 0;
  if (uVar13 != 0) {
    uVar10 = param_3 * *param_5;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_3;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = *param_5;
    uVar9 = SUB168(auVar2 * auVar4,8);
    bVar6 = CARRY8(*param_2,uVar10);
    *param_2 = *param_2 + uVar10;
    lVar8 = 8;
    uVar13 = uVar13 - 1;
    while (uVar13 != 0) {
      uVar11 = *(ulong *)((long)param_2 + lVar8);
      uVar10 = param_3 * *(ulong *)((long)param_5 + lVar8);
      uVar12 = uVar11 + uVar9 + (ulong)bVar6;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = param_3;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = *(ulong *)((long)param_5 + lVar8);
      uVar9 = SUB168(auVar3 * auVar5,8) +
              (ulong)(CARRY8(uVar11,uVar9) || CARRY8(uVar11 + uVar9,(ulong)bVar6));
      bVar6 = CARRY8(uVar12,uVar10);
      *(ulong *)((long)param_2 + lVar8) = uVar12 + uVar10;
      lVar8 = lVar8 + 8;
      uVar13 = uVar13 - 1;
    }
    if (lVar7 != 0) {
      uVar10 = *(ulong *)((long)param_2 + lVar8);
      uVar13 = uVar10 + uVar9;
      bVar1 = CARRY8(uVar10,uVar9);
      *(ulong *)((long)param_2 + lVar8) = uVar10 + uVar9 + (ulong)bVar6;
      uVar9 = 0;
      bVar6 = bVar1 || CARRY8(uVar13,(ulong)bVar6);
      lVar7 = lVar7 + -1;
      while (lVar7 != 0) {
        lVar8 = lVar8 + 8;
        uVar13 = *(ulong *)((long)param_2 + lVar8);
        *(ulong *)((long)param_2 + lVar8) = uVar13 + bVar6;
        bVar6 = CARRY8(uVar13,(ulong)bVar6);
        lVar7 = lVar7 + -1;
      }
    }
  }

}
