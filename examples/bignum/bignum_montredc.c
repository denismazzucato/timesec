
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong param_3,long param_4,ulong *param_5,ulong param_6)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  bool bVar6;
  bool bVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;

  if (param_1 != 0) {
    uVar8 = *param_5 * -3 ^ 2;
    lVar9 = *param_5 * uVar8 + 1;
    lVar12 = lVar9 * lVar9;
    lVar9 = uVar8 + lVar9 * uVar8;
    lVar10 = lVar12 * lVar12;
    lVar9 = lVar9 + lVar12 * lVar9;
    lVar9 = lVar9 + lVar10 * lVar9;
    uVar8 = param_1;
    if (param_3 < param_1) {
      uVar8 = param_3;
    }
    uVar11 = 0;
    if (uVar8 != 0) {
      do {
        param_2[uVar11] = *(ulong *)(param_4 + uVar11 * 8);
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar8);
      for (; uVar11 < param_1; uVar11 = uVar11 + 1) {
        param_2[uVar11] = 0;
      }
    } else {
      param_2[uVar11] = 0;
      for (; uVar11 < param_1; uVar11 = uVar11 + 1) {
        param_2[uVar11] = 0;
      }
    }
    uVar8 = 0;
    if (param_6 != 0) {
      uVar11 = 0;
      do {
        uVar14 = *param_2 * (lVar9 + lVar10 * lVar10 * lVar9);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar14;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = *param_5;
        uVar15 = SUB168(auVar2 * auVar4,8);
        bVar6 = CARRY8(*param_2,uVar14 * *param_5);
        uVar13 = 1;
        if (param_1 != 1) {
          do {
            uVar16 = param_2[uVar13];
            uVar18 = uVar14 * param_5[uVar13];
            uVar17 = uVar16 + uVar15 + (ulong)bVar6;
            auVar3._8_8_ = 0;
            auVar3._0_8_ = uVar14;
            auVar5._8_8_ = 0;
            auVar5._0_8_ = param_5[uVar13];
            uVar15 = SUB168(auVar3 * auVar5,8) +
                     (ulong)(CARRY8(uVar16,uVar15) || CARRY8(uVar16 + uVar15,(ulong)bVar6));
            bVar6 = CARRY8(uVar17,uVar18);
            param_2[uVar13 - 1] = uVar17 + uVar18;
            uVar13 = uVar13 + 1;
          } while (uVar13 != param_1);
        }
        uVar14 = uVar15 + uVar8 + (ulong)bVar6;
        uVar8 = (ulong)(CARRY8(uVar15,uVar8) || CARRY8(uVar15 + uVar8,(ulong)bVar6));
        if (uVar13 + uVar11 < param_3) {
          uVar13 = *(ulong *)(param_4 + (uVar13 + uVar11) * 8);
          bVar6 = CARRY8(uVar14,uVar13);
          uVar14 = uVar14 + uVar13;
          uVar8 = uVar8 + bVar6;
        }
        param_2[param_1 - 1] = uVar14;
        uVar11 = uVar11 + 1;
      } while (uVar11 < param_6);
    }
    bVar6 = true;
    uVar11 = 0;
    do {
      bVar6 = CARRY8(param_2[uVar11],~param_5[uVar11]) ||
              CARRY8(param_2[uVar11] + ~param_5[uVar11],(ulong)bVar6);
      uVar11 = uVar11 + 1;
    } while (uVar11 != param_1);
    bVar7 = true;
    uVar11 = 0;
    do {
      uVar15 = param_2[uVar11];
      uVar14 = param_5[uVar11] & -(ulong)(uVar8 != 0 || CARRY8(uVar8 - 1,(ulong)bVar6));
      bVar1 = !bVar7;
      uVar13 = ~uVar14;
      bVar7 = CARRY8(uVar15,uVar13) || CARRY8(uVar15 + uVar13,(ulong)bVar7);
      param_2[uVar11] = uVar15 - (uVar14 + bVar1);
      uVar11 = uVar11 + 1;
    } while (uVar11 != param_1);
  }

}
