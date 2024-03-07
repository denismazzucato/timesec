
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong param_3,long param_4,ulong *param_5,ulong param_6)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  bool bVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;

  if (param_1 != 0) {
    uVar7 = *param_5 * -3 ^ 2;
    lVar8 = *param_5 * uVar7 + 1;
    lVar11 = lVar8 * lVar8;
    lVar8 = uVar7 + lVar8 * uVar7;
    lVar9 = lVar11 * lVar11;
    lVar8 = lVar8 + lVar11 * lVar8;
    lVar8 = lVar8 + lVar9 * lVar8;
    uVar7 = param_1;
    if (param_3 < param_1) {
      uVar7 = param_3;
    }
    uVar10 = 0;
    if (uVar7 != 0) {
      do {
        param_2[uVar10] = *(ulong *)(param_4 + uVar10 * 8);
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar7);
      for (; uVar10 < param_1; uVar10 = uVar10 + 1) {
        param_2[uVar10] = 0;
      }
    } else {
      param_2[uVar10] = 0;
      for (; uVar10 < param_1; uVar10 = uVar10 + 1) {
        param_2[uVar10] = 0;
      }
    }
    uVar7 = 0;
    if (param_6 != 0) {
      uVar10 = 0;
      do {
        uVar13 = *param_2 * (lVar8 + lVar9 * lVar9 * lVar8);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar13;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = *param_5;
        uVar14 = SUB168(auVar2 * auVar4,8);
        bVar6 = CARRY8(*param_2,uVar13 * *param_5);
        uVar12 = 1;
        if (param_1 != 1) {
          do {
            uVar15 = param_2[uVar12];
            uVar17 = uVar13 * param_5[uVar12];
            uVar16 = uVar15 + uVar14 + (ulong)bVar6;
            auVar3._8_8_ = 0;
            auVar3._0_8_ = uVar13;
            auVar5._8_8_ = 0;
            auVar5._0_8_ = param_5[uVar12];
            uVar14 = SUB168(auVar3 * auVar5,8) +
                     (ulong)(CARRY8(uVar15,uVar14) || CARRY8(uVar15 + uVar14,(ulong)bVar6));
            bVar6 = CARRY8(uVar16,uVar17);
            param_2[uVar12 - 1] = uVar16 + uVar17;
            uVar12 = uVar12 + 1;
          } while (uVar12 != param_1);
        }
        uVar13 = uVar14 + uVar7 + (ulong)bVar6;
        uVar7 = (ulong)(CARRY8(uVar14,uVar7) || CARRY8(uVar14 + uVar7,(ulong)bVar6));
        if (uVar12 + uVar10 < param_3) {
          uVar12 = *(ulong *)(param_4 + (uVar12 + uVar10) * 8);
          bVar6 = CARRY8(uVar13,uVar12);
          uVar13 = uVar13 + uVar12;
          uVar7 = uVar7 + bVar6;
        }
        param_2[param_1 - 1] = uVar13;
        uVar10 = uVar10 + 1;
      } while (uVar10 < param_6);
      bVar6 = true;
      uVar10 = 0;
      do {
        uVar13 = param_2[uVar10];
        bVar1 = !bVar6;
        uVar12 = ~(param_5[uVar10] & -uVar7);
        bVar6 = CARRY8(uVar13,uVar12) || CARRY8(uVar13 + uVar12,(ulong)bVar6);
        param_2[uVar10] = uVar13 - ((param_5[uVar10] & -uVar7) + (ulong)bVar1);
        uVar10 = uVar10 + 1;
      } while (uVar10 != param_1);
    }
  }

}
