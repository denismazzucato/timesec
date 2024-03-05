
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,long param_3,long param_4,ulong *param_5)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  bool bVar7;
  bool bVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;

  if (param_1 != 0) {
    uVar9 = *param_5 * -3 ^ 2;
    lVar10 = *param_5 * uVar9 + 1;
    lVar13 = lVar10 * lVar10;
    lVar10 = uVar9 + lVar10 * uVar9;
    lVar11 = lVar13 * lVar13;
    lVar10 = lVar10 + lVar13 * lVar10;
    lVar10 = lVar10 + lVar11 * lVar10;
    uVar9 = 0;
    do {
      param_2[uVar9] = 0;
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_1);
    uVar12 = 0;
    uVar9 = 0;
    do {
      uVar14 = *(ulong *)(param_3 + uVar9 * 8);
      uVar15 = 0;
      bVar7 = false;
      uVar16 = 0;
      do {
        uVar21 = *(ulong *)(param_4 + uVar15 * 8);
        uVar17 = param_2[uVar15];
        uVar19 = uVar14 * uVar21;
        uVar18 = uVar17 + uVar16 + (ulong)bVar7;
        auVar1._8_8_ = 0;
        auVar1._0_8_ = uVar14;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar21;
        uVar16 = SUB168(auVar1 * auVar4,8) +
                 (ulong)(CARRY8(uVar17,uVar16) || CARRY8(uVar17 + uVar16,(ulong)bVar7));
        bVar7 = CARRY8(uVar18,uVar19);
        param_2[uVar15] = uVar18 + uVar19;
        uVar15 = uVar15 + 1;
      } while (uVar15 != param_1);
      uVar14 = uVar12 + uVar16 + (ulong)bVar7;
      uVar17 = *param_2 * (lVar10 + lVar11 * lVar11 * lVar10);
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar17;
      auVar5._8_8_ = 0;
      auVar5._0_8_ = *param_5;
      uVar18 = SUB168(auVar2 * auVar5,8);
      bVar8 = CARRY8(*param_2,uVar17 * *param_5);
      uVar15 = 1;
      if (param_1 != 1) {
        do {
          uVar19 = param_2[uVar15];
          uVar20 = uVar17 * param_5[uVar15];
          uVar21 = uVar19 + uVar18 + (ulong)bVar8;
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar17;
          auVar6._8_8_ = 0;
          auVar6._0_8_ = param_5[uVar15];
          uVar18 = SUB168(auVar3 * auVar6,8) +
                   (ulong)(CARRY8(uVar19,uVar18) || CARRY8(uVar19 + uVar18,(ulong)bVar8));
          bVar8 = CARRY8(uVar21,uVar20);
          param_2[uVar15 - 1] = uVar21 + uVar20;
          uVar15 = uVar15 + 1;
        } while (uVar15 != param_1);
      }
      uVar12 = (ulong)(CARRY8(uVar12,uVar16) || CARRY8(uVar12 + uVar16,(ulong)bVar7)) +
               (ulong)(CARRY8(uVar14,uVar18) || CARRY8(uVar14 + uVar18,(ulong)bVar8));
      param_2[uVar15 - 1] = uVar14 + uVar18 + (ulong)bVar8;
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_1);
    bVar7 = true;
    uVar9 = 0;
    do {
      uVar16 = param_2[uVar9];
      bVar8 = !bVar7;
      uVar15 = ~(param_5[uVar9] & -uVar12);
      bVar7 = CARRY8(uVar16,uVar15) || CARRY8(uVar16 + uVar15,(ulong)bVar7);
      param_2[uVar9] = uVar16 - ((param_5[uVar9] & -uVar12) + (ulong)bVar8);
      uVar9 = uVar9 + 1;
    } while (uVar9 != param_1);
  }

}
