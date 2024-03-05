
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,long param_3,ulong *param_4)

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
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;

  if (param_1 != 0) {
    uVar8 = *param_4 * -3 ^ 2;
    lVar9 = *param_4 * uVar8 + 1;
    lVar11 = lVar9 * lVar9;
    lVar9 = uVar8 + lVar9 * uVar8;
    lVar10 = lVar11 * lVar11;
    lVar9 = lVar9 + lVar11 * lVar9;
    lVar9 = lVar9 + lVar10 * lVar9;
    uVar8 = 0;
    do {
      param_2[uVar8] = *(ulong *)(param_3 + uVar8 * 8);
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_1);
    uVar8 = 0;
    do {
      uVar13 = *param_2 * (lVar9 + lVar10 * lVar10 * lVar9);
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar13;
      auVar4._8_8_ = 0;
      auVar4._0_8_ = *param_4;
      uVar14 = SUB168(auVar2 * auVar4,8);
      bVar6 = CARRY8(*param_2,uVar13 * *param_4);
      uVar12 = 1;
      if (param_1 != 1) {
        do {
          uVar15 = param_2[uVar12];
          uVar17 = uVar13 * param_4[uVar12];
          uVar16 = uVar15 + uVar14 + (ulong)bVar6;
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar13;
          auVar5._8_8_ = 0;
          auVar5._0_8_ = param_4[uVar12];
          uVar14 = SUB168(auVar3 * auVar5,8) +
                   (ulong)(CARRY8(uVar15,uVar14) || CARRY8(uVar15 + uVar14,(ulong)bVar6));
          bVar6 = CARRY8(uVar16,uVar17);
          param_2[uVar12 - 1] = uVar16 + uVar17;
          uVar12 = uVar12 + 1;
        } while (uVar12 != param_1);
      }
      param_2[uVar12 - 1] = uVar14 + bVar6;
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_1);
    bVar6 = true;
    uVar8 = 0;
    do {
      bVar6 = CARRY8(param_2[uVar8],~param_4[uVar8]) ||
              CARRY8(param_2[uVar8] + ~param_4[uVar8],(ulong)bVar6);
      uVar8 = uVar8 + 1;
    } while (uVar8 != param_1);
    bVar7 = true;
    uVar8 = 0;
    do {
      uVar13 = param_2[uVar8];
      bVar1 = !bVar7;
      uVar12 = ~(param_4[uVar8] & -(ulong)bVar6);
      bVar7 = CARRY8(uVar13,uVar12) || CARRY8(uVar13 + uVar12,(ulong)bVar7);
      param_2[uVar8] = uVar13 - ((param_4[uVar8] & -(ulong)bVar6) + (ulong)bVar1);
      uVar8 = uVar8 + 1;
    } while (uVar8 != param_1);
  }

}
