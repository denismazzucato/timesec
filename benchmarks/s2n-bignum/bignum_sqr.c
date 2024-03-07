
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  bool bVar5;
  bool bVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong *puVar16;
  ulong uVar17;
  ulong uVar18;

  if (param_1 != 0) {
    uVar18 = 0;
    uVar17 = 0;
    uVar10 = 0;
    do {
      uVar7 = uVar10 + 1;
      uVar13 = uVar7 >> 1;
      if (param_3 <= uVar7 >> 1) {
        uVar13 = param_3;
      }
      uVar14 = uVar7 - param_3;
      if (uVar7 < param_3) {
        uVar14 = 0;
      }
      uVar7 = 0;
      uVar8 = 0;
      lVar9 = 0;
      if (uVar14 < uVar13) {
        puVar16 = (ulong *)(param_4 + (uVar10 - uVar14) * 8);
        do {
          uVar11 = *(ulong *)(param_4 + uVar14 * 8);
          uVar15 = uVar11 * *puVar16;
          auVar1._8_8_ = 0;
          auVar1._0_8_ = uVar11;
          auVar3._8_8_ = 0;
          auVar3._0_8_ = *puVar16;
          uVar12 = SUB168(auVar1 * auVar3,8);
          bVar5 = CARRY8(uVar7,uVar15);
          uVar7 = uVar7 + uVar15;
          uVar11 = uVar8 + uVar12;
          bVar6 = CARRY8(uVar8,uVar12);
          uVar8 = uVar8 + uVar12 + (ulong)bVar5;
          lVar9 = lVar9 + (ulong)(bVar6 || CARRY8(uVar11,(ulong)bVar5));
          uVar14 = uVar14 + 1;
          puVar16 = puVar16 + -1;
        } while (uVar14 != uVar13);
        bVar5 = CARRY8(uVar7,uVar7);
        uVar7 = uVar7 * 2;
        uVar13 = uVar8 * 2;
        bVar6 = CARRY8(uVar8,uVar8);
        uVar8 = uVar8 * 2 + (ulong)bVar5;
        lVar9 = lVar9 * 2 + (ulong)(bVar6 || CARRY8(uVar13,(ulong)bVar5));
      }
      if (((uVar10 & 1) == 0) && (uVar14 < param_3)) {
        uVar13 = *(ulong *)(param_4 + uVar14 * 8);
        auVar2._8_8_ = 0;
        auVar2._0_8_ = uVar13;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar13;
        uVar14 = SUB168(auVar2 * auVar4,8);
        bVar5 = CARRY8(uVar18,uVar13 * uVar13);
        uVar18 = uVar18 + uVar13 * uVar13;
        uVar13 = uVar17 + uVar14;
        bVar6 = CARRY8(uVar17,uVar14);
        uVar17 = uVar17 + uVar14 + (ulong)bVar5;
        lVar9 = lVar9 + (ulong)(bVar6 || CARRY8(uVar13,(ulong)bVar5));
      }
      bVar6 = CARRY8(uVar7,uVar18);
      *(ulong *)(param_2 + uVar10 * 8) = uVar7 + uVar18;
      uVar18 = uVar8 + uVar17 + (ulong)bVar6;
      uVar17 = lVar9 + (ulong)(CARRY8(uVar8,uVar17) || CARRY8(uVar8 + uVar17,(ulong)bVar6));
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_1);
  }

}
