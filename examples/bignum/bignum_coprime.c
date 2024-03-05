
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong *param_5)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  undefined auVar7 [16];
  undefined auVar8 [16];
  undefined auVar9 [16];
  undefined auVar10 [16];
  undefined auVar11 [16];
  bool bVar12;
  bool bVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  ulong uVar23;
  ulong uVar24;
  ulong uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  ulong uVar29;
  ulong uVar30;
  ulong uVar31;
  ulong uVar32;

  uVar3 = param_3;
  if (param_3 <= param_1) {
    uVar3 = param_1;
  }
  if (uVar3 != 0) {
    puVar1 = param_5 + uVar3;
    uVar20 = 0;
    if (param_1 != 0) {
      do {
        param_5[uVar20] = *(ulong *)(param_2 + uVar20 * 8);
        uVar20 = uVar20 + 1;
      } while (uVar20 < param_1);
      for (; uVar20 < uVar3; uVar20 = uVar20 + 1) {
        param_5[uVar20] = 0;
      }
    } else {
      param_5[uVar20] = 0;
      for (; uVar20 < uVar3; uVar20 = uVar20 + 1) {
        param_5[uVar20] = 0;
      }
    }
    uVar20 = 0;
    if (param_3 != 0) {
      do {
        puVar1[uVar20] = *(ulong *)(param_4 + uVar20 * 8);
        uVar20 = uVar20 + 1;
      } while (uVar20 < param_3);
      for (; uVar20 < uVar3; uVar20 = uVar20 + 1) {
        puVar1[uVar20] = 0;
      }
    } else {
      puVar1[uVar20] = 0;
      for (; uVar20 < uVar3; uVar20 = uVar20 + 1) {
        puVar1[uVar20] = 0;
      }
    }
    uVar16 = (param_1 * 0x40) + (param_3 * 0x40);
    uVar14 = *param_5;
    uVar17 = *puVar1;
    uVar20 = 0;
    do {
      uVar24 = puVar1[uVar20];
      uVar18 = (param_5[uVar20] ^ uVar24) & (uVar17 & 1) - 1;
      param_5[uVar20] = param_5[uVar20] ^ uVar18;
      puVar1[uVar20] = uVar24 ^ uVar18;
      uVar20 = uVar20 + 1;
    } while (uVar20 < uVar3);
    do {
      uVar18 = uVar16 + 0x3f >> 6;
      uVar20 = uVar3;
      if (uVar18 < uVar3) {
        uVar20 = uVar18;
      }
      uVar27 = 0;
      uVar24 = 0;
      uVar32 = 0;
      uVar18 = 0;
      uVar25 = 0;
      uVar15 = 0;
      do {
        bVar13 = (param_5[uVar18] | puVar1[uVar18]);
        uVar19 = uVar32 & uVar27;
        if (bVar13 == 0) {
          uVar19 = uVar15;
        }
        uVar30 = puVar1[uVar18];
        uVar15 = uVar32 & uVar25;
        uVar32 = param_5[uVar18];
        if (bVar13 == 0) {
          uVar30 = uVar25;
          uVar15 = uVar24;
          uVar32 = uVar27;
        }
        uVar27 = uVar32;
        uVar24 = uVar15;
        uVar32 = -(ulong)bVar13;
        uVar18 = uVar18 + 1;
        uVar25 = uVar30;
        uVar15 = uVar19;
      } while (uVar18 < uVar20);
      uVar25 = LZCOUNT(uVar27 | uVar30);
      uVar18 = -uVar25;
      if (uVar18 == 0) {
        uVar19 = 0;
      }
      if (uVar18 == 0) {
        uVar24 = 0;
      }
      uVar28 = uVar27 << (uVar25 & 0x3f) | uVar19 >> (uVar18 & 0x3f);
      uVar27 = uVar30 << (uVar25 & 0x3f) | uVar24 >> (uVar18 & 0x3f);
      uVar30 = *param_5;
      uVar25 = *puVar1;
      uVar18 = 1;
      uVar24 = 0;
      uVar19 = 0;
      uVar15 = 1;
      lVar21 = 0x3a;
      uVar32 = uVar30 & 1;
      do {
        bVar13 = uVar32;
        uVar2 = uVar19;
        uVar22 = uVar27;
        uVar32 = uVar25;
        uVar23 = uVar15;
        if (bVar13 == 0) {
          uVar2 = 0;
          uVar22 = 0;
          uVar32 = 0;
          uVar23 = 0;
        }
        bVar12_1 = uVar28;
        bVar12_2 = uVar27;
        uVar22 = uVar28 - uVar22;
        uVar32 = uVar30 - uVar32;
        if (bVar13 != 0 && bVar12_1 < bVar12_2) {
          uVar27 = uVar28;
        }
        if (bVar13 != 0 && bVar12_1 < bVar12_2) {
          uVar25 = uVar30;
          uVar22 = -uVar22;
        }
        uVar30 = uVar32;
        if (bVar13 != 0 && bVar12_1 < bVar12_2) {
          uVar15 = uVar24;
          uVar30 = -uVar32;
          uVar19 = uVar18;
        }
        uVar32 = uVar32 & 2;
        uVar18 = uVar18 + uVar2;
        uVar24 = uVar24 + uVar23;
        uVar28 = uVar22 >> 1;
        uVar30 = uVar30 >> 1;
        uVar19 = uVar19 * 2;
        uVar15 = uVar15 * 2;
        lVar21 = lVar21 + -1;
      } while (lVar21 != 0);
      uVar25 = 0;
      uVar32 = 0;
      uVar30 = 0;
      uVar28 = 0;
      uVar27 = 0;
      do {
        uVar23 = param_5[uVar27];
        uVar26 = puVar1[uVar27];
        uVar31 = uVar24 * uVar26;
        uVar2 = uVar18 * uVar23 + uVar25;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar18;
        auVar8._8_8_ = 0;
        auVar8._0_8_ = uVar23;
        uVar29 = SUB168(auVar4 * auVar8,8) + (ulong)CARRY8(uVar18 * uVar23,uVar25);
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar24;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = uVar26;
        uVar30 = SUB168(auVar5 * auVar9,8) - uVar30;
        param_5[uVar27] = uVar2 - uVar31;
        uVar22 = ~uVar30;
        uVar25 = uVar29 - (uVar30 + (uVar31 > uVar2));
        uVar30 = -(ulong)(!CARRY8(uVar29,uVar22) &&
                         !CARRY8(uVar29 + uVar22,(ulong)(uVar31 <= uVar2)));
        uVar29 = uVar15 * uVar26;
        uVar2 = uVar19 * uVar23 + uVar32;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = uVar19;
        auVar10._8_8_ = 0;
        auVar10._0_8_ = uVar23;
        uVar23 = SUB168(auVar6 * auVar10,8) + (ulong)CARRY8(uVar19 * uVar23,uVar32);
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar15;
        auVar11._8_8_ = 0;
        auVar11._0_8_ = uVar26;
        uVar28 = SUB168(auVar7 * auVar11,8) - uVar28;
        puVar1[uVar27] = uVar2 - uVar29;
        uVar22 = ~uVar28;
        uVar32 = uVar23 - (uVar28 + (uVar29 > uVar2));
        uVar28 = -(ulong)(!CARRY8(uVar23,uVar22) &&
                         !CARRY8(uVar23 + uVar22,(ulong)(uVar29 <= uVar2)));
        uVar27 = uVar27 + 1;
      } while (uVar27 < uVar20);
      lVar21 = 0;
      bVar13 = CARRY8(uVar30,uVar30);
      uVar18 = *param_5;
      uVar24 = uVar20;
      uVar24 = uVar24 - 1;
      while (uVar24 != 0) {
        uVar27 = *(ulong *)((long)param_5 + (lVar21 + 8));
        uVar18 = (uVar18 >> 0x3a | uVar27 << 6) ^ uVar30;
        *(ulong *)((long)param_5 + lVar21) = uVar18 + bVar13;
        lVar21 = lVar21 + 8;
        bVar13 = CARRY8(uVar18,(ulong)bVar13);
        uVar18 = uVar27;
        uVar24 = uVar24 - 1;
      }
      *(ulong *)((long)param_5 + lVar21) =
           ((uVar18 >> 0x3a | uVar25 * 0x40) ^ uVar30) + (ulong)bVar13;
      lVar21 = 0;
      bVar13 = CARRY8(uVar28,uVar28);
      uVar18 = *puVar1;
      uVar20 = uVar20 - 1;
      while (uVar20 != 0) {
        uVar24 = *(ulong *)((long)puVar1 + (lVar21 + 8));
        uVar18 = (uVar18 >> 0x3a | uVar24 << 6) ^ uVar28;
        *(ulong *)((long)puVar1 + lVar21) = uVar18 + bVar13;
        lVar21 = lVar21 + 8;
        bVar13 = CARRY8(uVar18,(ulong)bVar13);
        uVar18 = uVar24;
        uVar20 = uVar20 - 1;
      }
      *(ulong *)((long)puVar1 + lVar21) =
           ((uVar18 >> 0x3a | uVar32 * 0x40) ^ uVar28) + (ulong)bVar13;
      bVar13 = uVar16;
      uVar16 = uVar16 - 0x3a;
    } while (0x39 < bVar13 && uVar16 != 0);
    uVar20 = *puVar1 ^ 1;
    if (uVar3 != 1) {
      uVar16 = 1;
      do {
        uVar20 = uVar20 | puVar1[uVar16];
        uVar16 = uVar16 + 1;
      } while (uVar16 < uVar3);
    }
    param_1 = (uVar14 | uVar17) & (ulong)(uVar20 == 0);
  }
}
