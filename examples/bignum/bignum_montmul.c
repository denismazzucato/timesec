
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,long param_3,long param_4,ulong *param_5)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  bool bVar8;
  bool bVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;

  if (param_1 != 0) {
    uVar10 = *param_5 * -3 ^ 2;
    lVar11 = *param_5 * uVar10 + 1;
    lVar14 = lVar11 * lVar11;
    lVar11 = uVar10 + lVar11 * uVar10;
    lVar12 = lVar14 * lVar14;
    lVar11 = lVar11 + lVar14 * lVar11;
    lVar11 = lVar11 + lVar12 * lVar11;
    uVar10 = 0;
    do {
      param_2[uVar10] = 0;
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_1);
    uVar13 = 0;
    uVar10 = 0;
    do {
      uVar15 = *(ulong *)(param_3 + uVar10 * 8);
      uVar16 = 0;
      bVar8 = false;
      uVar17 = 0;
      do {
        uVar22 = *(ulong *)(param_4 + uVar16 * 8);
        uVar18 = param_2[uVar16];
        uVar20 = uVar15 * uVar22;
        uVar19 = uVar18 + uVar17 + (ulong)bVar8;
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar15;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar22;
        uVar17 = SUB168(auVar2 * auVar5,8) +
                 (ulong)(CARRY8(uVar18,uVar17) || CARRY8(uVar18 + uVar17,(ulong)bVar8));
        bVar8 = CARRY8(uVar19,uVar20);
        param_2[uVar16] = uVar19 + uVar20;
        uVar16 = uVar16 + 1;
      } while (uVar16 != param_1);
      uVar15 = uVar13 + uVar17 + (ulong)bVar8;
      uVar18 = *param_2 * (lVar11 + lVar12 * lVar12 * lVar11);
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar18;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = *param_5;
      uVar19 = SUB168(auVar3 * auVar6,8);
      bVar9 = CARRY8(*param_2,uVar18 * *param_5);
      uVar16 = 1;
      if (param_1 != 1) {
        do {
          uVar20 = param_2[uVar16];
          uVar21 = uVar18 * param_5[uVar16];
          uVar22 = uVar20 + uVar19 + (ulong)bVar9;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar18;
          auVar7._8_8_ = 0;
          auVar7._0_8_ = param_5[uVar16];
          uVar19 = SUB168(auVar4 * auVar7,8) +
                   (ulong)(CARRY8(uVar20,uVar19) || CARRY8(uVar20 + uVar19,(ulong)bVar9));
          bVar9 = CARRY8(uVar22,uVar21);
          param_2[uVar16 - 1] = uVar22 + uVar21;
          uVar16 = uVar16 + 1;
        } while (uVar16 != param_1);
      }
      uVar13 = (ulong)(CARRY8(uVar13,uVar17) || CARRY8(uVar13 + uVar17,(ulong)bVar8)) +
               (ulong)(CARRY8(uVar15,uVar19) || CARRY8(uVar15 + uVar19,(ulong)bVar9));
      param_2[uVar16 - 1] = uVar15 + uVar19 + (ulong)bVar9;
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_1);
    bVar8 = true;
    uVar10 = 0;
    do {
      bVar8 = CARRY8(param_2[uVar10],~param_5[uVar10]) ||
              CARRY8(param_2[uVar10] + ~param_5[uVar10],(ulong)bVar8);
      uVar10 = uVar10 + 1;
    } while (uVar10 != param_1);
    bVar9 = true;
    uVar10 = 0;
    do {
      uVar15 = param_2[uVar10];
      uVar17 = param_5[uVar10] & -(ulong)(uVar13 != 0 || CARRY8(uVar13 - 1,(ulong)bVar8));
      bVar1 = !bVar9;
      uVar16 = ~uVar17;
      bVar9 = CARRY8(uVar15,uVar16) || CARRY8(uVar15 + uVar16,(ulong)bVar9);
      param_2[uVar10] = uVar15 - (uVar17 + bVar1);
      uVar10 = uVar10 + 1;
    } while (uVar10 != param_1);
  }

}
