
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,ulong *param_4,ulong param_5)

{
  undefined auVar1 [16];
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
  undefined auVar14 [16];
  bool bVar15;
  ulong *puVar16;
  ulong uVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  ulong uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;

  uVar17 = 0;
  if (param_3 != 0) {
    uVar24 = param_5 << (LZCOUNT(param_5) & 0x3fU);
    lVar19 = (uVar24 >> 0x10) + 1;
    uVar17 = (uVar24 >> 0x10 ^ 0x1ffffffffffff) >> 0x20;
    uVar23 = -(lVar19 * uVar17) >> 0x31;
    uVar23 = uVar23 * uVar23;
    uVar17 = uVar17 * 0x40000000 +
             uVar17 * ((uVar23 + (-(lVar19 * uVar17) >> 0x22)) * (uVar23 | 0x40000000) >> 0x1e) >>
             0x1e;
    lVar20 = uVar17 * 0x10000 + ((-(lVar19 * uVar17) >> 0x18) * uVar17 >> 0x18);
    uVar17 = lVar20 * 0x80000000 + (((ulong)-(lVar19 * lVar20) >> 0x20) * lVar20 >> 0x11);
    auVar1._8_8_ = 0;
    auVar1._0_8_ = uVar24;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar17;
    uVar23 = uVar17 * 2 +
             ((uVar17 >> 0x21) * ~(uVar24 * uVar17 >> 0x3c | SUB168(auVar1 * auVar8,8) << 4) >> 0x21
             );
    uVar17 = uVar23 + 1;
    if (uVar17 == 0) {
      uVar17 = 0xffffffffffffffff;
    }
    auVar2._8_8_ = 0;
    auVar2._0_8_ = uVar24;
    auVar9._8_8_ = 0;
    auVar9._0_8_ = uVar17;
    if (!CARRY8(SUB168(auVar2 * auVar9,8),uVar24)) {
      uVar23 = uVar17;
    }
    uVar28 = -(uVar23 * uVar24);
    uVar25 = 0;
    uVar17 = 0;
    uVar18 = param_3;
    do {
      uVar18 = uVar18 - 1;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar28;
      auVar10._8_8_ = 0;
      auVar10._0_8_ = uVar25;
      uVar26 = SUB168(auVar3 * auVar10,8);
      bVar15 = CARRY8(uVar28 * uVar25,param_4[uVar18]);
      uVar25 = uVar28 * uVar25 + param_4[uVar18];
      lVar19 = uVar26 + uVar17;
      uVar22 = uVar28;
      if (!CARRY8(uVar26,uVar17) && !CARRY8(uVar26 + uVar17,(ulong)bVar15)) {
        uVar22 = 0;
      }
      uVar17 = uVar22 + uVar25;
      uVar25 = lVar19 + (ulong)bVar15 + (ulong)CARRY8(uVar22,uVar25);
    } while (uVar18 != 0);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar23;
    auVar11._8_8_ = 0;
    auVar11._0_8_ = uVar25;
    uVar22 = SUB168(auVar4 * auVar11,8);
    uVar18 = uVar22 + uVar25;
    uVar28 = uVar24;
    if (!CARRY8(uVar22,uVar25)) {
      uVar28 = 0;
    }
    uVar26 = uVar18 * uVar24;
    auVar5._8_8_ = 0;
    auVar5._0_8_ = uVar18;
    auVar12._8_8_ = 0;
    auVar12._0_8_ = uVar24;
    uVar22 = uVar17 - uVar26;
    uVar18 = SUB168(auVar5 * auVar12,8) + uVar28 + (ulong)(uVar17 < uVar26);
    uVar17 = uVar24;
    if (uVar25 == uVar18) {
      uVar17 = 0;
    }
    if (uVar25 - uVar18 == (ulong)(uVar22 < uVar17)) {
      uVar24 = 0;
    }
    uVar24 = (uVar22 - uVar17) - uVar24;
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar23;
    auVar13._8_8_ = 0;
    auVar13._0_8_ = uVar24;
    uVar17 = SUB168(auVar6 * auVar13,8);
    uVar24 = uVar24 - ((uVar17 + uVar24 >> 1 | (ulong)CARRY8(uVar17,uVar24) << 0x3f) >>
                      ((LZCOUNT(param_5) ^ 0x3fU) & 0x3f)) * param_5;
    uVar17 = uVar24 - param_5;
    if (uVar24 < param_5) {
      uVar17 = uVar24;
    }
  }
  if (param_1 != 0) {
    uVar25 = LZCOUNT(-param_5 & param_5) ^ 0x3f;
    uVar28 = 0xffffffffffffffff >> (uVar25 & 0x3f);
    param_5 = param_5 >> (uVar25 & 0x3f);
    uVar23 = param_5 * -3 ^ 2;
    lVar19 = param_5 * uVar23 + 1;
    lVar21 = lVar19 * lVar19;
    lVar19 = uVar23 + lVar19 * uVar23;
    lVar20 = lVar21 * lVar21;
    lVar19 = lVar19 + lVar21 * lVar19;
    lVar19 = lVar19 + lVar20 * lVar19;
    uVar24 = param_5 - (uVar17 >> (uVar25 & 0x3f));
    uVar23 = 0;
    uVar18 = 0;
    puVar16 = param_4;
    if (param_3 != 0) {
      puVar16 = param_4 + 1;
      uVar18 = *param_4 >> (uVar25 & 0x3f);
      param_3 = param_3 - 1;
    }
    do {
      uVar22 = 0;
      if (uVar23 < param_3) {
        uVar22 = puVar16[uVar23];
      }
      uVar22 = uVar22 >> (uVar25 & 0x3f) | uVar22 << 0x40 - (uVar25 & 0x3f);
      uVar26 = uVar18 | uVar22 & (uVar28 ^ 0xffffffffffffffff);
      uVar18 = uVar22 & uVar28;
      uVar22 = uVar26 + uVar24;
      uVar27 = uVar22 * (lVar19 + lVar20 * lVar20 * lVar19);
      *(ulong *)(param_2 + uVar23 * 8) = ~uVar27;
      auVar7._8_8_ = 0;
      auVar7._0_8_ = uVar27;
      auVar14._8_8_ = 0;
      auVar14._0_8_ = param_5;
      uVar24 = SUB168(auVar7 * auVar14,8) + (ulong)CARRY8(uVar26,uVar24) +
               (ulong)CARRY8(uVar27 * param_5,uVar22);
      uVar23 = uVar23 + 1;
    } while (uVar23 < param_1);
  }

}
