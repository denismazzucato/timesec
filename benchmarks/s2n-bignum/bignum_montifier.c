
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong *param_3,ulong *param_4)

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
  undefined auVar10 [16];
  undefined auVar11 [16];
  undefined auVar12 [16];
  undefined auVar13 [16];
  bool bVar14;
  bool bVar15;
  bool bVar16;
  ulong uVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  long lVar25;
  ulong uVar26;

  if (param_1 != 0) {
    uVar17 = 0;
    do {
      uVar20 = param_3[uVar17];
      param_4[uVar17] = uVar20;
      uVar17 = uVar17 + 1;
    } while (uVar17 < param_1);
    for (lVar18 = param_1 - 1; lVar18 != 0; lVar18 = lVar18 + -1) {
      uVar17 = 0;
      bVar16 = uVar20;
      uVar22 = 0;
      do {
        uVar19 = param_4[uVar17];
        uVar20 = uVar22;
        if (bVar16 != 0) {
          uVar20 = uVar19;
        }
        param_4[uVar17] = uVar20;
        uVar17 = uVar17 + 1;
        uVar22 = uVar19;
      } while (uVar17 != param_1);
    }
    uVar20 = LZCOUNT(uVar20);
    uVar22 = 0;
    uVar17 = 0;
    do {
      uVar19 = param_4[uVar17] << (uVar20 & 0x3f) | uVar22;
      uVar22 = param_4[uVar17] >> (-uVar20 & 0x3f) & -(ulong)((uVar20 & 0x3f) != 0);
      param_4[uVar17] = uVar19;
      uVar17 = uVar17 + 1;
    } while (uVar17 < param_1);
    uVar20 = param_4[param_1 - 1];
    uVar17 = 1;
    uVar22 = -uVar20;
    lVar18 = 0x3e;
    do {
      uVar19 = (ulong)(uVar20 - uVar22 <= uVar22);
      uVar17 = uVar17 * 2 + uVar19;
      uVar22 = uVar22 * 2 - (-uVar19 & uVar20);
      lVar18 = lVar18 + -1;
    } while (lVar18 != 0);
    if (uVar22 == uVar20) {
      uVar17 = uVar17 + 1;
    }
    uVar22 = 0;
    uVar20 = 0;
    bVar16 = false;
    do {
      uVar19 = uVar17 * param_4[uVar20];
      bVar14 = CARRY8(uVar19,uVar22) || CARRY8(uVar19 + uVar22,(ulong)bVar16);
      lVar18 = uVar19 + uVar22;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar17;
      auVar8._8_8_ = 0;
      auVar8._0_8_ = param_4[uVar20];
      uVar22 = SUB168(auVar2 * auVar8,8);
      param_2[uVar20] = lVar18 + (ulong)bVar16;
      uVar20 = uVar20 + 1;
      bVar16 = bVar14;
    } while (uVar20 != param_1);
    bVar16 = true;
    uVar17 = 0;
    do {
      uVar19 = param_4[uVar17] & -(ulong)(0x3fffffffffffffff < uVar22 + bVar14);
      bVar15 = !bVar16;
      uVar20 = ~param_2[uVar17];
      bVar16 = CARRY8(uVar19,uVar20) || CARRY8(uVar19 + uVar20,(ulong)bVar16);
      param_2[uVar17] = uVar19 - (param_2[uVar17] + (ulong)bVar15);
      uVar17 = uVar17 + 1;
    } while (uVar17 != param_1);
    bVar16 = true;
    uVar17 = 0;
    uVar20 = 0;
    do {
      uVar22 = param_2[uVar17];
      uVar19 = uVar20 >> 0x3f | uVar22 << 1;
      bVar1 = !bVar16;
      uVar20 = ~param_4[uVar17];
      bVar14 = CARRY8(uVar19,uVar20);
      bVar15 = CARRY8(uVar19 + uVar20,(ulong)bVar16);
      bVar16 = bVar14 || bVar15;
      param_2[uVar17] = uVar19 - (param_4[uVar17] + (ulong)bVar1);
      uVar17 = uVar17 + 1;
      uVar20 = uVar22;
    } while (uVar17 != param_1);
    uVar17 = 0;
    bVar16 = false;
    do {
      uVar20 = param_2[uVar17];
      uVar19 = param_4[uVar17] & -(ulong)(!bVar14 && !bVar15) - ((long)uVar22 >> 0x3f);
      param_2[uVar17] = uVar20 + uVar19 + (ulong)bVar16;
      uVar17 = uVar17 + 1;
      bVar16 = CARRY8(uVar20,uVar19) || CARRY8(uVar20 + uVar19,(ulong)bVar16);
    } while (uVar17 != param_1);
    bVar16 = true;
    uVar17 = 0;
    uVar20 = 0;
    do {
      uVar22 = param_2[uVar17];
      uVar19 = uVar20 >> 0x3f | uVar22 << 1;
      bVar1 = !bVar16;
      uVar20 = ~param_4[uVar17];
      bVar14 = CARRY8(uVar19,uVar20);
      bVar15 = CARRY8(uVar19 + uVar20,(ulong)bVar16);
      bVar16 = bVar14 || bVar15;
      param_2[uVar17] = uVar19 - (param_4[uVar17] + (ulong)bVar1);
      uVar17 = uVar17 + 1;
      uVar20 = uVar22;
    } while (uVar17 != param_1);
    uVar17 = 0;
    bVar16 = false;
    do {
      uVar20 = param_2[uVar17];
      uVar23 = param_4[uVar17] & -(ulong)(!bVar14 && !bVar15) - ((long)uVar22 >> 0x3f);
      uVar19 = uVar20 + uVar23 + (ulong)bVar16;
      param_2[uVar17] = uVar19;
      param_4[uVar17] = uVar19;
      uVar17 = uVar17 + 1;
      bVar16 = CARRY8(uVar20,uVar23) || CARRY8(uVar20 + uVar23,(ulong)bVar16);
    } while (uVar17 != param_1);
    uVar17 = 0;
    lVar18 = param_1 * 2;
    do {
      uVar20 = 0;
      uVar19 = 0;
      bVar16 = false;
      uVar22 = 0;
      do {
        uVar23 = uVar17 * param_2[uVar20];
        uVar24 = uVar19 + uVar22 + (ulong)bVar16;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar17;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = param_2[uVar20];
        uVar22 = SUB168(auVar3 * auVar9,8) +
                 (ulong)(CARRY8(uVar19,uVar22) || CARRY8(uVar19 + uVar22,(ulong)bVar16));
        bVar16 = CARRY8(uVar24,uVar23);
        uVar19 = param_4[uVar20];
        param_4[uVar20] = uVar24 + uVar23;
        uVar20 = uVar20 + 1;
      } while (uVar20 != param_1);
      uVar17 = 0;
      bVar14 = false;
      do {
        uVar20 = param_4[uVar17];
        uVar23 = param_2[uVar17] &
                 -(ulong)(CARRY8(uVar19,uVar22) || CARRY8(uVar19 + uVar22,(ulong)bVar16));
        bVar15 = CARRY8(uVar20,uVar23) || CARRY8(uVar20 + uVar23,(ulong)bVar14);
        param_4[uVar17] = uVar20 + uVar23 + (ulong)bVar14;
        uVar17 = uVar17 + 1;
        bVar14 = bVar15;
      } while (uVar17 != param_1);
      uVar17 = uVar19 + uVar22 + (ulong)bVar16 + (ulong)bVar15;
      lVar18 = lVar18 + -1;
    } while (lVar18 != 0);
    uVar22 = *param_3;
    uVar20 = uVar22 * -3 ^ 2;
    lVar18 = uVar22 * uVar20 + 1;
    lVar25 = lVar18 * lVar18;
    lVar18 = uVar20 + lVar18 * uVar20;
    lVar21 = lVar25 * lVar25;
    lVar18 = lVar18 + lVar25 * lVar18;
    lVar18 = lVar18 + lVar21 * lVar18;
    lVar18 = lVar18 + lVar21 * lVar21 * lVar18;
    uVar23 = *param_4 * lVar18;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar23;
    auVar10._8_8_ = 0;
    auVar10._0_8_ = uVar22;
    uVar19 = SUB168(auVar4 * auVar10,8);
    uVar20 = 1;
    bVar16 = CARRY8(*param_4,uVar23 * uVar22);
    if (param_1 != 1) {
      do {
        uVar24 = param_4[uVar20];
        uVar22 = uVar23 * param_3[uVar20];
        uVar26 = uVar24 + uVar19 + (ulong)bVar16;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar23;
        auVar11._8_8_ = 0;
        auVar11._0_8_ = param_3[uVar20];
        uVar19 = SUB168(auVar5 * auVar11,8) +
                 (ulong)(CARRY8(uVar24,uVar19) || CARRY8(uVar24 + uVar19,(ulong)bVar16));
        bVar16 = CARRY8(uVar26,uVar22);
        param_4[uVar20 - 1] = uVar26 + uVar22;
        uVar20 = uVar20 + 1;
      } while (uVar20 != param_1);
    }
    param_4[param_1 - 1] = uVar17 + uVar19 + (ulong)bVar16;
    bVar14 = true;
    uVar20 = 0;
    do {
      uVar23 = param_4[uVar20];
      uVar24 = param_3[uVar20] &
               -(ulong)(CARRY8(uVar17,uVar19) || CARRY8(uVar17 + uVar19,(ulong)bVar16));
      bVar15 = !bVar14;
      uVar22 = ~uVar24;
      bVar14 = CARRY8(uVar23,uVar22) || CARRY8(uVar23 + uVar22,(ulong)bVar14);
      param_2[uVar20] = uVar23 - (uVar24 + bVar15);
      uVar20 = uVar20 + 1;
      uVar22 = param_1;
    } while (uVar20 != param_1);
    do {
      uVar19 = *param_2 * lVar18;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = uVar19;
      auVar12._8_8_ = 0;
      auVar12._0_8_ = *param_3;
      uVar20 = SUB168(auVar6 * auVar12,8);
      uVar17 = 1;
      bVar16 = CARRY8(*param_2,uVar19 * *param_3);
      if (param_1 != 1) {
        do {
          uVar24 = param_2[uVar17];
          uVar23 = uVar19 * param_3[uVar17];
          uVar26 = uVar24 + uVar20 + (ulong)bVar16;
          auVar7._8_8_ = 0;
          auVar7._0_8_ = uVar19;
          auVar13._8_8_ = 0;
          auVar13._0_8_ = param_3[uVar17];
          uVar20 = SUB168(auVar7 * auVar13,8) +
                   (ulong)(CARRY8(uVar24,uVar20) || CARRY8(uVar24 + uVar20,(ulong)bVar16));
          bVar16 = CARRY8(uVar26,uVar23);
          param_2[uVar17 - 1] = uVar26 + uVar23;
          uVar17 = uVar17 + 1;
        } while (uVar17 != param_1);
      }
      param_2[param_1 - 1] = uVar20 + bVar16;
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
    bVar16 = true;
    uVar17 = 0;
    do {
      bVar16 = CARRY8(param_2[uVar17],~param_3[uVar17]) ||
               CARRY8(param_2[uVar17] + ~param_3[uVar17],(ulong)bVar16);
      uVar17 = uVar17 + 1;
    } while (uVar17 != param_1);
    bVar14 = true;
    uVar17 = 0;
    do {
      uVar22 = param_2[uVar17];
      bVar15 = !bVar14;
      uVar20 = ~(param_3[uVar17] & -(ulong)bVar16);
      bVar14 = CARRY8(uVar22,uVar20) || CARRY8(uVar22 + uVar20,(ulong)bVar14);
      param_2[uVar17] = uVar22 - ((param_3[uVar17] & -(ulong)bVar16) + (ulong)bVar15);
      uVar17 = uVar17 + 1;
    } while (uVar17 != param_1);
  }
}
