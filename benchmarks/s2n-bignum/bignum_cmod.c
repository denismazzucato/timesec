
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
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
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  ulong uVar22;
  ulong uVar23;

  if (param_1 != 0) {
    uVar16 = param_3 << (LZCOUNT(param_3) & 0x3fU);
    lVar1 = (uVar16 >> 0x10) + 1;
    uVar17 = (uVar16 >> 0x10 ^ 0x1ffffffffffff) >> 0x20;
    uVar22 = -(lVar1 * uVar17) >> 0x31;
    uVar22 = uVar22 * uVar22;
    uVar17 = uVar17 * 0x40000000 +
             uVar17 * ((uVar22 + (-(lVar1 * uVar17) >> 0x22)) * (uVar22 | 0x40000000) >> 0x1e) >>
             0x1e;
    lVar2 = uVar17 * 0x10000 + ((-(lVar1 * uVar17) >> 0x18) * uVar17 >> 0x18);
    uVar17 = lVar2 * 0x80000000 + (((ulong)-(lVar1 * lVar2) >> 0x20) * lVar2 >> 0x11);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = uVar16;
    auVar9._8_8_ = 0;
    auVar9._0_8_ = uVar17;
    uVar22 = uVar17 * 2 +
             ((uVar17 >> 0x21) * ~(uVar16 * uVar17 >> 0x3c | SUB168(auVar3 * auVar9,8) << 4) >> 0x21
             );
    uVar17 = uVar22 + 1;
    if (uVar17 == 0) {
      uVar17 = 0xffffffffffffffff;
    }
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar16;
    auVar10._8_8_ = 0;
    auVar10._0_8_ = uVar17;
    if (!CARRY8(SUB168(auVar4 * auVar10,8),uVar16)) {
      uVar22 = uVar17;
    }
    uVar18 = -(uVar22 * uVar16);
    uVar19 = 0;
    uVar17 = 0;
    do {
      param_1 = param_1 - 1;
      uVar23 = *(ulong *)(param_2 + param_1 * 8);
      auVar5._8_8_ = 0;
      auVar5._0_8_ = uVar18;
      auVar11._8_8_ = 0;
      auVar11._0_8_ = uVar19;
      uVar20 = SUB168(auVar5 * auVar11,8);
      bVar15 = CARRY8(uVar18 * uVar19,uVar23);
      uVar23 = uVar18 * uVar19 + uVar23;
      lVar1 = uVar20 + uVar17;
      uVar19 = uVar18;
      if (!CARRY8(uVar20,uVar17) && !CARRY8(uVar20 + uVar17,(ulong)bVar15)) {
        uVar19 = 0;
      }
      uVar17 = uVar19 + uVar23;
      uVar19 = lVar1 + (ulong)bVar15 + (ulong)CARRY8(uVar19,uVar23);
    } while (param_1 != 0);
    auVar6._8_8_ = 0;
    auVar6._0_8_ = uVar22;
    auVar12._8_8_ = 0;
    auVar12._0_8_ = uVar19;
    uVar20 = SUB168(auVar6 * auVar12,8);
    uVar18 = uVar20 + uVar19;
    uVar23 = uVar16;
    if (!CARRY8(uVar20,uVar19)) {
      uVar23 = 0;
    }
    uVar21 = uVar18 * uVar16;
    auVar7._8_8_ = 0;
    auVar7._0_8_ = uVar18;
    auVar13._8_8_ = 0;
    auVar13._0_8_ = uVar16;
    uVar20 = uVar17 - uVar21;
    uVar18 = SUB168(auVar7 * auVar13,8) + uVar23 + (ulong)(uVar17 < uVar21);
    uVar17 = uVar16;
    if (uVar19 == uVar18) {
      uVar17 = 0;
    }
    if (uVar19 - uVar18 == (ulong)(uVar20 < uVar17)) {
      uVar16 = 0;
    }
    uVar16 = (uVar20 - uVar17) - uVar16;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar22;
    auVar14._8_8_ = 0;
    auVar14._0_8_ = uVar16;
    uVar17 = SUB168(auVar8 * auVar14,8);
    uVar16 = uVar16 - ((uVar17 + uVar16 >> 1 | (ulong)CARRY8(uVar17,uVar16) << 0x3f) >>
                      ((LZCOUNT(param_3) ^ 0x3fU) & 0x3f)) * param_3;
    param_1 = uVar16 - param_3;
    if (uVar16 < param_3) {
      param_1 = uVar16;
    }
  }
}
