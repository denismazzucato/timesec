
#include "bignum_types.h"

void ltmp0(long param_1,ulong *param_2,ulong *param_3)

{
  bool bVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  bool bVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;

  if (param_1 != 0) {
    uVar12 = *param_3;
    uVar11 = uVar12 * -3 ^ 2;
    lVar13 = uVar12 * uVar11 + 1;
    lVar16 = lVar13 * lVar13;
    lVar13 = uVar11 + lVar13 * uVar11;
    lVar14 = lVar16 * lVar16;
    lVar13 = lVar13 + lVar16 * lVar13;
    lVar13 = lVar13 + lVar14 * lVar13;
    uVar11 = lVar13 + lVar14 * lVar14 * lVar13;
    *param_2 = uVar11;
    if (param_1 != 1) {
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar12;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar11;
      uVar12 = SUB168(auVar2 * auVar6,8);
      lVar13 = 1;
      bVar10 = param_1 != 0;
      do {
        uVar17 = param_3[lVar13] * uVar11;
        uVar15 = uVar17 + uVar12;
        bVar1 = CARRY8(uVar17,uVar12);
        lVar14 = uVar17 + uVar12;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = param_3[lVar13];
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar11;
        uVar12 = SUB168(auVar3 * auVar7,8);
        param_2[lVar13] = lVar14 + (ulong)bVar10;
        lVar13 = lVar13 + 1;
        bVar10 = bVar1 || CARRY8(uVar15,(ulong)bVar10);
      } while (param_1 != lVar13);
      for (param_1 = param_1 + -2; param_1 != 0; param_1 = param_1 + -1) {
        param_2 = param_2 + 1;
        uVar17 = *param_2;
        uVar12 = uVar17 * uVar11;
        *param_2 = uVar12;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = *param_3;
        auVar8._8_8_ = 0;
        auVar8._0_8_ = uVar12;
        uVar15 = SUB168(auVar4 * auVar8,8);
        bVar10 = uVar17 != 0;
        lVar13 = 1;
        do {
          uVar18 = param_2[lVar13];
          uVar17 = param_3[lVar13] * uVar12;
          uVar19 = uVar18 + uVar15 + (ulong)bVar10;
          auVar5._8_8_ = 0;
          auVar5._0_8_ = param_3[lVar13];
          auVar9._8_8_ = 0;
          auVar9._0_8_ = uVar12;
          uVar15 = SUB168(auVar5 * auVar9,8) +
                   (ulong)(CARRY8(uVar18,uVar15) || CARRY8(uVar18 + uVar15,(ulong)bVar10));
          bVar10 = CARRY8(uVar19,uVar17);
          param_2[lVar13] = uVar19 + uVar17;
          bVar1_1 = lVar13;
          bVar1_2 = param_1;
          lVar13 = lVar13 + 1;
        } while (bVar1_1 != bVar_2);
      }
      param_2[1] = param_2[1] * uVar11;
    }
  }

}
