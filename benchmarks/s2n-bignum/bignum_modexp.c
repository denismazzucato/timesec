#include "bignum_types.h"


void ltmp0(long param_1,undefined8 param_2,undefined8 param_3,long param_4,undefined8 param_5,
          long param_6)

{
  ulong uVar1;

  if (param_1 != 0) {
    local_amontifier(param_1,param_6 + param_1 * 0x10,param_5,param_6 + param_1 * 8);
    local_amontmul(param_1,param_6,param_6 + param_1 * 0x10,param_3,param_5);
    local_demont(param_1,param_6 + param_1 * 0x10,param_6 + param_1 * 0x10,param_5);
    uVar1 = param_1 << 6;
    do {
      uVar1 = uVar1 - 1;
      local_amontmul(param_1,param_6 + param_1 * 8,param_6 + param_1 * 0x10,param_6 + param_1 * 0x10
                     ,param_5);
      local_amontmul(param_1,param_6 + param_1 * 0x10,param_6,param_6 + param_1 * 8,param_5);
      local_mux(*(ulong *)(param_4 + (uVar1 >> 6) * 8) >> (uVar1 & 0x3f) & 1,param_1,
                param_6 + param_1 * 0x10,param_6 + param_1 * 0x10,param_6 + param_1 * 8);
    } while (uVar1 != 0);
    local_demont(param_1,param_6 + param_1 * 0x10,param_6 + param_1 * 0x10,param_5);
    local_mux(0,param_1,param_2,param_6 + param_1 * 0x10,param_6 + param_1 * 0x10);
  }
}


void local_amontifier(ulong param_1,long param_2,ulong *param_3,ulong *param_4)

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
  bool bVar11;
  bool bVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  ulong uVar19;
  ulong uVar20;
  ulong uVar21;
  long lVar22;
  long lVar23;

  if (param_1 != 0) {
    uVar13 = 0;
    do {
      uVar18 = param_3[uVar13];
      param_4[uVar13] = uVar18;
      uVar13 = uVar13 + 1;
    } while (uVar13 < param_1);
    for (lVar14 = param_1 - 1; lVar14 != 0; lVar14 = lVar14 + -1) {
      uVar13 = 0;
      bVar12 = uVar18 != 0;
      uVar19 = 0;
      do {
        uVar15 = param_4[uVar13];
        uVar18 = uVar19;
        if (bVar12) {
          uVar18 = uVar15;
        }
        param_4[uVar13] = uVar18;
        uVar13 = uVar13 + 1;
        uVar19 = uVar15;
      } while (uVar13 != param_1);
    }
    uVar18 = LZCOUNT(uVar18);
    uVar19 = 0;
    uVar13 = 0;
    do {
      uVar15 = param_4[uVar13] << (uVar18 & 0x3f) | uVar19;
      uVar19 = param_4[uVar13] >> (-uVar18 & 0x3f) & -(ulong)((uVar18 & 0x3f) != 0);
      param_4[uVar13] = uVar15;
      uVar13 = uVar13 + 1;
    } while (uVar13 < param_1);
    uVar18 = param_4[param_1 - 1];
    uVar13 = 1;
    uVar19 = -uVar18;
    lVar14 = 0x3e;
    do {
      uVar15 = (ulong)(uVar18 - uVar19 <= uVar19);
      uVar13 = uVar13 * 2 + uVar15;
      uVar19 = uVar19 * 2 - (-uVar15 & uVar18);
      lVar14 = lVar14 + -1;
    } while (lVar14 != 0);
    if (uVar19 == uVar18) {
      uVar13 = uVar13 + 1;
    }
    uVar19 = 0;
    uVar18 = 0;
    bVar12 = false;
    do {
      uVar15 = uVar13 * param_4[uVar18];
      bVar10 = CARRY8(uVar15,uVar19) || CARRY8(uVar15 + uVar19,(ulong)bVar12);
      lVar14 = uVar15 + uVar19;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = uVar13;
      auVar6._8_8_ = 0;
      auVar6._0_8_ = param_4[uVar18];
      uVar19 = SUB168(auVar2 * auVar6,8);
      *(ulong *)(param_2 + uVar18 * 8) = lVar14 + (ulong)bVar12;
      uVar18 = uVar18 + 1;
      bVar12 = bVar10;
    } while (uVar18 != param_1);
    bVar12 = true;
    uVar13 = 0;
    do {
      uVar20 = *(ulong *)(param_2 + uVar13 * 8);
      uVar15 = param_4[uVar13] & -(ulong)(0x3fffffffffffffff < uVar19 + bVar10);
      bVar11 = !bVar12;
      uVar18 = ~uVar20;
      bVar12 = CARRY8(uVar15,uVar18) || CARRY8(uVar15 + uVar18,(ulong)bVar12);
      *(ulong *)(param_2 + uVar13 * 8) = uVar15 - (uVar20 + bVar11);
      uVar13 = uVar13 + 1;
    } while (uVar13 != param_1);
    bVar12 = true;
    uVar13 = 0;
    uVar18 = 0;
    do {
      uVar19 = *(ulong *)(param_2 + uVar13 * 8);
      uVar15 = uVar18 >> 0x3f | uVar19 << 1;
      bVar1 = !bVar12;
      uVar18 = ~param_4[uVar13];
      bVar10 = CARRY8(uVar15,uVar18);
      bVar11 = CARRY8(uVar15 + uVar18,(ulong)bVar12);
      bVar12 = bVar10 || bVar11;
      *(ulong *)(param_2 + uVar13 * 8) = uVar15 - (param_4[uVar13] + (ulong)bVar1);
      uVar13 = uVar13 + 1;
      uVar18 = uVar19;
    } while (uVar13 != param_1);
    uVar13 = 0;
    bVar12 = false;
    do {
      uVar18 = *(ulong *)(param_2 + uVar13 * 8);
      uVar15 = param_4[uVar13] & -(ulong)(!bVar10 && !bVar11) - ((long)uVar19 >> 0x3f);
      *(ulong *)(param_2 + uVar13 * 8) = uVar18 + uVar15 + (ulong)bVar12;
      uVar13 = uVar13 + 1;
      bVar12 = CARRY8(uVar18,uVar15) || CARRY8(uVar18 + uVar15,(ulong)bVar12);
    } while (uVar13 != param_1);
    bVar12 = true;
    uVar13 = 0;
    uVar18 = 0;
    do {
      uVar19 = *(ulong *)(param_2 + uVar13 * 8);
      uVar15 = uVar18 >> 0x3f | uVar19 << 1;
      bVar1 = !bVar12;
      uVar18 = ~param_4[uVar13];
      bVar10 = CARRY8(uVar15,uVar18);
      bVar11 = CARRY8(uVar15 + uVar18,(ulong)bVar12);
      bVar12 = bVar10 || bVar11;
      *(ulong *)(param_2 + uVar13 * 8) = uVar15 - (param_4[uVar13] + (ulong)bVar1);
      uVar13 = uVar13 + 1;
      uVar18 = uVar19;
    } while (uVar13 != param_1);
    uVar13 = 0;
    bVar12 = false;
    do {
      uVar18 = *(ulong *)(param_2 + uVar13 * 8);
      uVar20 = param_4[uVar13] & -(ulong)(!bVar10 && !bVar11) - ((long)uVar19 >> 0x3f);
      uVar15 = uVar18 + uVar20 + (ulong)bVar12;
      *(ulong *)(param_2 + uVar13 * 8) = uVar15;
      param_4[uVar13] = uVar15;
      uVar13 = uVar13 + 1;
      bVar12 = CARRY8(uVar18,uVar20) || CARRY8(uVar18 + uVar20,(ulong)bVar12);
    } while (uVar13 != param_1);
    uVar18 = 0;
    uVar13 = param_1;
    do {
      uVar19 = 0;
      uVar20 = 0;
      bVar12 = false;
      uVar15 = 0;
      do {
        uVar16 = *(ulong *)(param_2 + uVar19 * 8);
        uVar17 = uVar18 * uVar16;
        uVar21 = uVar20 + uVar15 + (ulong)bVar12;
        auVar3._8_8_ = 0;
        auVar3._0_8_ = uVar18;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar16;
        uVar15 = SUB168(auVar3 * auVar7,8) +
                 (ulong)(CARRY8(uVar20,uVar15) || CARRY8(uVar20 + uVar15,(ulong)bVar12));
        bVar12 = CARRY8(uVar21,uVar17);
        uVar20 = param_4[uVar19];
        param_4[uVar19] = uVar21 + uVar17;
        uVar19 = uVar19 + 1;
      } while (uVar19 != param_1);
      uVar18 = 0;
      bVar10 = false;
      do {
        uVar19 = param_4[uVar18];
        uVar16 = *(ulong *)(param_2 + uVar18 * 8) &
                 -(ulong)(CARRY8(uVar20,uVar15) || CARRY8(uVar20 + uVar15,(ulong)bVar12));
        bVar11 = CARRY8(uVar19,uVar16) || CARRY8(uVar19 + uVar16,(ulong)bVar10);
        param_4[uVar18] = uVar19 + uVar16 + (ulong)bVar10;
        uVar18 = uVar18 + 1;
        bVar10 = bVar11;
      } while (uVar18 != param_1);
      uVar18 = uVar20 + uVar15 + (ulong)bVar12 + (ulong)bVar11;
      uVar13 = uVar13 - 1;
    } while (uVar13 != 0);
    uVar19 = *param_3;
    uVar13 = uVar19 * -3 ^ 2;
    lVar14 = uVar19 * uVar13 + 1;
    lVar22 = lVar14 * lVar14;
    lVar23 = uVar13 + lVar14 * uVar13;
    lVar14 = lVar22 * lVar22;
    lVar23 = lVar23 + lVar22 * lVar23;
    lVar23 = lVar23 + lVar14 * lVar23;
    uVar20 = *param_4 * (lVar23 + lVar14 * lVar14 * lVar23);
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar20;
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar19;
    uVar15 = SUB168(auVar4 * auVar8,8);
    uVar13 = 1;
    bVar12 = CARRY8(*param_4,uVar20 * uVar19);
    if (param_1 != 1) {
      do {
        uVar16 = param_4[uVar13];
        uVar19 = uVar20 * param_3[uVar13];
        uVar17 = uVar16 + uVar15 + (ulong)bVar12;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar20;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = param_3[uVar13];
        uVar15 = SUB168(auVar5 * auVar9,8) +
                 (ulong)(CARRY8(uVar16,uVar15) || CARRY8(uVar16 + uVar15,(ulong)bVar12));
        bVar12 = CARRY8(uVar17,uVar19);
        param_4[uVar13 - 1] = uVar17 + uVar19;
        uVar13 = uVar13 + 1;
      } while (uVar13 != param_1);
    }
    param_4[param_1 - 1] = uVar18 + uVar15 + (ulong)bVar12;
    bVar10 = true;
    uVar13 = 0;
    do {
      uVar20 = param_4[uVar13];
      uVar16 = param_3[uVar13] &
               -(ulong)(CARRY8(uVar18,uVar15) || CARRY8(uVar18 + uVar15,(ulong)bVar12));
      bVar11 = !bVar10;
      uVar19 = ~uVar16;
      bVar10 = CARRY8(uVar20,uVar19) || CARRY8(uVar20 + uVar19,(ulong)bVar10);
      *(ulong *)(param_2 + uVar13 * 8) = uVar20 - (uVar16 + bVar11);
      uVar13 = uVar13 + 1;
    } while (uVar13 != param_1);
  }
  return;
}


void local_amontmul(ulong param_1,ulong *param_2,long param_3,long param_4,ulong *param_5)

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
  return;
}


void local_demont(ulong param_1,ulong *param_2,long param_3,ulong *param_4)

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
  return;
}


void local_mux(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  undefined8 uVar1;

  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      uVar1 = *(undefined8 *)(param_4 + param_2 * 8);
      if (param_1 == 0) {
        uVar1 = *(undefined8 *)(param_5 + param_2 * 8);
      }
      *(undefined8 *)(param_3 + param_2 * 8) = uVar1;
    } while (param_2 != 0);
  }
  return;
}
