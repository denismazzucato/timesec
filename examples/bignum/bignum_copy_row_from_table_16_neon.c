
#include "bignum_types.h"

void ltmp0(undefined8 *param_1,undefined (*param_2) [16],long param_3,long param_4)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  undefined auVar8 [16];
  long lVar9;
  long lVar10;
  undefined auVar11 [16];
  undefined auVar12 [16];
  undefined auVar13 [16];
  undefined auVar14 [16];
  undefined auVar15 [16];
  undefined auVar16 [16];
  undefined auVar17 [16];
  undefined auVar18 [16];

  auVar11 = ZEXT816(0);
  auVar12 = ZEXT816(0);
  auVar13 = ZEXT816(0);
  auVar14 = ZEXT816(0);
  auVar15 = ZEXT816(0);
  auVar16 = ZEXT816(0);
  auVar17 = ZEXT816(0);
  auVar18 = ZEXT816(0);
  lVar10 = 0;
  do {
    lVar9 = -(ulong)(lVar10 == param_4);
    auVar1._8_8_ = lVar9;
    auVar1._0_8_ = lVar9;
    auVar11 = NEON_bit(auVar11,*param_2,auVar1,1);
    auVar2._8_8_ = lVar9;
    auVar2._0_8_ = lVar9;
    auVar12 = NEON_bit(auVar12,param_2[1],auVar2,1);
    auVar3._8_8_ = lVar9;
    auVar3._0_8_ = lVar9;
    auVar13 = NEON_bit(auVar13,param_2[2],auVar3,1);
    auVar4._8_8_ = lVar9;
    auVar4._0_8_ = lVar9;
    auVar14 = NEON_bit(auVar14,param_2[3],auVar4,1);
    auVar5._8_8_ = lVar9;
    auVar5._0_8_ = lVar9;
    auVar15 = NEON_bit(auVar15,param_2[4],auVar5,1);
    auVar6._8_8_ = lVar9;
    auVar6._0_8_ = lVar9;
    auVar16 = NEON_bit(auVar16,param_2[5],auVar6,1);
    auVar7._8_8_ = lVar9;
    auVar7._0_8_ = lVar9;
    auVar17 = NEON_bit(auVar17,param_2[6],auVar7,1);
    auVar8._8_8_ = lVar9;
    auVar8._0_8_ = lVar9;
    auVar18 = NEON_bit(auVar18,param_2[7],auVar8,1);
    param_2 = param_2 + 8;
    lVar10 = lVar10 + 1;
  } while (param_3 != lVar10);
  param_1[1] = auVar11._8_8_;
  *param_1 = auVar11._0_8_;
  param_1[3] = auVar12._8_8_;
  param_1[2] = auVar12._0_8_;
  param_1[5] = auVar13._8_8_;
  param_1[4] = auVar13._0_8_;
  param_1[7] = auVar14._8_8_;
  param_1[6] = auVar14._0_8_;
  param_1[9] = auVar15._8_8_;
  param_1[8] = auVar15._0_8_;
  param_1[0xb] = auVar16._8_8_;
  param_1[10] = auVar16._0_8_;
  param_1[0xd] = auVar17._8_8_;
  param_1[0xc] = auVar17._0_8_;
  param_1[0xf] = auVar18._8_8_;
  param_1[0xe] = auVar18._0_8_;

}
