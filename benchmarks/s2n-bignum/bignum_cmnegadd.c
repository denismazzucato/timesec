
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong param_3,ulong param_4,ulong *param_5)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  ulong uVar6;
  bool bVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;

  uVar6 = param_1;
  if (param_4 < param_1) {
    uVar6 = param_4;
  }
  lVar8 = param_1 - uVar6;
  uVar10 = 0;
  if (uVar6 != 0) {
    uVar11 = param_3 * ~*param_5;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = param_3;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = ~*param_5;
    uVar10 = uVar11 + param_3;
    uVar11 = SUB168(auVar2 * auVar4,8) + (ulong)CARRY8(uVar11,param_3);
    bVar7 = CARRY8(*param_2,uVar10);
    *param_2 = *param_2 + uVar10;
    lVar9 = 8;
    uVar6 = uVar6 - 1;
    while (uVar6 != 0) {
      uVar12 = *(ulong *)((long)param_2 + lVar9);
      uVar10 = param_3 * ~*(ulong *)((long)param_5 + lVar9);
      uVar13 = uVar12 + uVar11 + (ulong)bVar7;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = param_3;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = ~*(ulong *)((long)param_5 + lVar9);
      uVar11 = SUB168(auVar3 * auVar5,8) +
               (ulong)(CARRY8(uVar12,uVar11) || CARRY8(uVar12 + uVar11,(ulong)bVar7));
      bVar7 = CARRY8(uVar13,uVar10);
      *(ulong *)((long)param_2 + lVar9) = uVar13 + uVar10;
      lVar9 = lVar9 + 8;
      uVar6 = uVar6 - 1;
    }
    uVar10 = param_3 - (uVar11 + bVar7);
    if (lVar8 != 0) {
      bVar7 = uVar10 <= *(ulong *)((long)param_2 + lVar9);
      *(ulong *)((long)param_2 + lVar9) = *(ulong *)((long)param_2 + lVar9) - uVar10;
      lVar8 = lVar8 + -1;
      while (lVar8 != 0) {
        lVar9 = lVar9 + 8;
        lVar14 = *(long *)((long)param_2 + lVar9);
        bVar1 = !bVar7;
        bVar7 = lVar14 != 0 || CARRY8(lVar14 - 1,(ulong)bVar7);
        *(ulong *)((long)param_2 + lVar9) = lVar14 - (ulong)bVar1;
        lVar8 = lVar8 + -1;
      }
      uVar10 = (ulong)!bVar7;
    }
  }
}
