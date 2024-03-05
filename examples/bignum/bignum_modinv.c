
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,long param_3,ulong *param_4,ulong *param_5)

{
  ulong *puVar1;
  ulong *puVar2;
  bool bVar3;
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
  undefined auVar15 [16];
  undefined auVar16 [16];
  undefined auVar17 [16];
  undefined auVar18 [16];
  undefined auVar19 [16];
  undefined auVar20 [16];
  undefined auVar21 [16];
  undefined auVar22 [16];
  undefined auVar23 [16];
  undefined auVar24 [16];
  undefined auVar25 [16];
  undefined auVar26 [16];
  undefined auVar27 [16];
  bool bVar28;
  bool bVar29;
  ulong uVar30;
  ulong uVar31;
  ulong uVar32;
  ulong uVar33;
  long lVar34;
  ulong uVar35;
  ulong uVar36;
  ulong uVar37;
  long lVar38;
  ulong uVar39;
  ulong uVar40;
  ulong uVar41;
  ulong uVar42;
  ulong uVar43;
  ulong uVar44;
  ulong uVar45;
  ulong uVar46;
  ulong uVar47;
  ulong uVar48;
  long lVar49;

  if (param_1 != 0) {
    puVar1 = param_5 + param_1;
    puVar2 = puVar1 + param_1;
    uVar33 = 0;
    do {
      uVar37 = param_4[uVar33];
      puVar1[uVar33] = *(ulong *)(param_3 + uVar33 * 8);
      puVar2[uVar33] = uVar37;
      param_5[uVar33] = uVar37;
      param_2[uVar33] = 0;
      uVar33 = uVar33 + 1;
    } while (uVar33 < param_1);
    uVar33 = *param_5;
    *param_5 = uVar33 - 1;
    uVar37 = uVar33 * -3 ^ 2;
    lVar38 = uVar33 * uVar37 + 1;
    lVar34 = lVar38 * lVar38;
    lVar49 = uVar37 + lVar38 * uVar37;
    lVar38 = lVar34 * lVar34;
    lVar49 = lVar49 + lVar34 * lVar49;
    lVar49 = lVar49 + lVar38 * lVar49;
    lVar49 = lVar49 + lVar38 * lVar38 * lVar49;
    uVar33 = param_1 << 7;
    do {
      uVar30 = uVar33 + 0x3f >> 6;
      uVar37 = param_1;
      if (uVar30 < param_1) {
        uVar37 = uVar30;
      }
      uVar42 = 0;
      uVar46 = 0;
      uVar48 = 0;
      uVar30 = 0;
      uVar39 = 0;
      uVar32 = 0;
      do {
        bVar29 = (puVar1[uVar30] | puVar2[uVar30]);
        uVar31 = uVar48 & uVar42;
        if (bVar29 == 0) {
          uVar31 = uVar32;
        }
        uVar45 = puVar2[uVar30];
        uVar32 = uVar48 & uVar39;
        uVar48 = puVar1[uVar30];
        if (bVar29 == 0) {
          uVar45 = uVar39;
          uVar32 = uVar46;
          uVar48 = uVar42;
        }
        uVar42 = uVar48;
        uVar46 = uVar32;
        uVar48 = -(ulong)bVar29;
        uVar30 = uVar30 + 1;
        uVar39 = uVar45;
        uVar32 = uVar31;
      } while (uVar30 < uVar37);
      uVar39 = LZCOUNT(uVar42 | uVar45);
      uVar30 = -uVar39;
      if (uVar30 == 0) {
        uVar31 = 0;
      }
      if (uVar30 == 0) {
        uVar46 = 0;
      }
      uVar43 = uVar42 << (uVar39 & 0x3f) | uVar31 >> (uVar30 & 0x3f);
      uVar42 = uVar45 << (uVar39 & 0x3f) | uVar46 >> (uVar30 & 0x3f);
      uVar45 = *puVar1;
      uVar39 = *puVar2;
      uVar30 = 1;
      uVar46 = 0;
      uVar31 = 0;
      uVar32 = 1;
      lVar34 = 0x3a;
      uVar48 = uVar45 & 1;
      do {
        bVar29 = uVar48;
        uVar41 = uVar31;
        uVar35 = uVar42;
        uVar48 = uVar39;
        uVar36 = uVar32;
        if (bVar29 == 0) {
          uVar41 = 0;
          uVar35 = 0;
          uVar48 = 0;
          uVar36 = 0;
        }
        bVar28_1 = uVar43;
        bVar28_2 = uVar42;
        uVar35 = uVar43 - uVar35;
        uVar48 = uVar45 - uVar48;
        if (bVar29 != 0 && bVar28_1 < bVar28_2) {
          uVar42 = uVar43;
        }
        if (bVar29 != 0 && bVar28_1 < bVar28_2) {
          uVar39 = uVar45;
          uVar35 = -uVar35;
        }
        uVar45 = uVar48;
        if (bVar29 != 0 && bVar28_1 < bVar28_2) {
          uVar32 = uVar46;
          uVar45 = -uVar48;
          uVar31 = uVar30;
        }
        uVar48 = uVar48 & 2;
        uVar30 = uVar30 + uVar41;
        uVar46 = uVar46 + uVar36;
        uVar43 = uVar35 >> 1;
        uVar45 = uVar45 >> 1;
        uVar31 = uVar31 * 2;
        uVar32 = uVar32 * 2;
        lVar34 = lVar34 + -1;
      } while (lVar34 != 0);
      uVar45 = 0;
      uVar43 = 0;
      uVar42 = 0;
      uVar39 = 0;
      uVar48 = 0;
      do {
        uVar36 = param_5[uVar42];
        uVar40 = param_2[uVar42];
        uVar41 = uVar30 * uVar36 + uVar45;
        auVar4._8_8_ = 0;
        auVar4._0_8_ = uVar30;
        auVar16._8_8_ = 0;
        auVar16._0_8_ = uVar36;
        uVar35 = uVar41 + uVar46 * uVar40;
        param_5[uVar42] = uVar39 >> 0x3a | uVar35 * 0x40;
        auVar5._8_8_ = 0;
        auVar5._0_8_ = uVar46;
        auVar17._8_8_ = 0;
        auVar17._0_8_ = uVar40;
        uVar45 = SUB168(auVar4 * auVar16,8) + (ulong)CARRY8(uVar30 * uVar36,uVar45) +
                 SUB168(auVar5 * auVar17,8) + (ulong)CARRY8(uVar41,uVar46 * uVar40);
        uVar39 = uVar31 * uVar36 + uVar43;
        auVar6._8_8_ = 0;
        auVar6._0_8_ = uVar31;
        auVar18._8_8_ = 0;
        auVar18._0_8_ = uVar36;
        uVar41 = uVar39 + uVar32 * uVar40;
        param_2[uVar42] = uVar48 >> 0x3a | uVar41 * 0x40;
        auVar7._8_8_ = 0;
        auVar7._0_8_ = uVar32;
        auVar19._8_8_ = 0;
        auVar19._0_8_ = uVar40;
        uVar43 = SUB168(auVar6 * auVar18,8) + (ulong)CARRY8(uVar31 * uVar36,uVar43) +
                 SUB168(auVar7 * auVar19,8) + (ulong)CARRY8(uVar39,uVar32 * uVar40);
        uVar42 = uVar42 + 1;
        uVar39 = uVar35;
        uVar48 = uVar41;
      } while (uVar42 < param_1);
      uVar39 = uVar35 >> 0x3a | uVar45 * 0x40;
      uVar48 = uVar41 >> 0x3a | uVar43 * 0x40;
      uVar43 = *param_5 * lVar49;
      auVar8._8_8_ = 0;
      auVar8._0_8_ = uVar43;
      auVar20._8_8_ = 0;
      auVar20._0_8_ = *param_4;
      uVar45 = SUB168(auVar8 * auVar20,8);
      bVar29 = CARRY8(*param_5,uVar43 * *param_4);
      uVar42 = 1;
      if (param_1 != 1) {
        do {
          uVar41 = param_5[uVar42];
          uVar36 = uVar43 * param_4[uVar42];
          uVar35 = uVar41 + uVar45 + (ulong)bVar29;
          auVar9._8_8_ = 0;
          auVar9._0_8_ = uVar43;
          auVar21._8_8_ = 0;
          auVar21._0_8_ = param_4[uVar42];
          uVar45 = SUB168(auVar9 * auVar21,8) +
                   (ulong)(CARRY8(uVar41,uVar45) || CARRY8(uVar41 + uVar45,(ulong)bVar29));
          bVar29 = CARRY8(uVar35,uVar36);
          param_5[uVar42 - 1] = uVar35 + uVar36;
          uVar42 = uVar42 + 1;
        } while (uVar42 != param_1);
      }
      uVar43 = (ulong)(CARRY8(uVar45,uVar39) || CARRY8(uVar45 + uVar39,(ulong)bVar29));
      param_5[uVar42 - 1] = uVar45 + uVar39 + (ulong)bVar29;
      bVar29 = true;
      uVar42 = 0;
      do {
        bVar29 = CARRY8(param_5[uVar42],~param_4[uVar42]) ||
                 CARRY8(param_5[uVar42] + ~param_4[uVar42],(ulong)bVar29);
        uVar42 = uVar42 + 1;
      } while (uVar42 != param_1);
      bVar28 = true;
      uVar42 = 0;
      do {
        uVar45 = param_5[uVar42];
        uVar41 = param_4[uVar42] & -(ulong)(uVar43 != 0 || CARRY8(uVar43 - 1,(ulong)bVar29));
        bVar3 = !bVar28;
        uVar39 = ~uVar41;
        bVar28 = CARRY8(uVar45,uVar39) || CARRY8(uVar45 + uVar39,(ulong)bVar28);
        param_5[uVar42] = uVar45 - (uVar41 + bVar3);
        uVar42 = uVar42 + 1;
      } while (uVar42 != param_1);
      uVar45 = *param_2 * lVar49;
      auVar10._8_8_ = 0;
      auVar10._0_8_ = uVar45;
      auVar22._8_8_ = 0;
      auVar22._0_8_ = *param_4;
      uVar39 = SUB168(auVar10 * auVar22,8);
      bVar29 = CARRY8(*param_2,uVar45 * *param_4);
      uVar42 = 1;
      if (param_1 != 1) {
        do {
          uVar43 = param_2[uVar42];
          uVar35 = uVar45 * param_4[uVar42];
          uVar41 = uVar43 + uVar39 + (ulong)bVar29;
          auVar11._8_8_ = 0;
          auVar11._0_8_ = uVar45;
          auVar23._8_8_ = 0;
          auVar23._0_8_ = param_4[uVar42];
          uVar39 = SUB168(auVar11 * auVar23,8) +
                   (ulong)(CARRY8(uVar43,uVar39) || CARRY8(uVar43 + uVar39,(ulong)bVar29));
          bVar29 = CARRY8(uVar41,uVar35);
          param_2[uVar42 - 1] = uVar41 + uVar35;
          uVar42 = uVar42 + 1;
        } while (uVar42 != param_1);
      }
      uVar45 = (ulong)(CARRY8(uVar39,uVar48) || CARRY8(uVar39 + uVar48,(ulong)bVar29));
      param_2[uVar42 - 1] = uVar39 + uVar48 + (ulong)bVar29;
      bVar29 = true;
      uVar42 = 0;
      do {
        bVar29 = CARRY8(param_2[uVar42],~param_4[uVar42]) ||
                 CARRY8(param_2[uVar42] + ~param_4[uVar42],(ulong)bVar29);
        uVar42 = uVar42 + 1;
      } while (uVar42 != param_1);
      bVar28 = true;
      uVar42 = 0;
      do {
        uVar48 = param_2[uVar42];
        uVar43 = param_4[uVar42] & -(ulong)(uVar45 != 0 || CARRY8(uVar45 - 1,(ulong)bVar29));
        bVar3 = !bVar28;
        uVar39 = ~uVar43;
        bVar28 = CARRY8(uVar48,uVar39) || CARRY8(uVar48 + uVar39,(ulong)bVar28);
        param_2[uVar42] = uVar48 - (uVar43 + bVar3);
        uVar42 = uVar42 + 1;
      } while (uVar42 != param_1);
      uVar39 = 0;
      uVar48 = 0;
      uVar45 = 0;
      uVar43 = 0;
      uVar42 = 0;
      do {
        uVar36 = puVar1[uVar42];
        uVar40 = puVar2[uVar42];
        uVar47 = uVar46 * uVar40;
        uVar41 = uVar30 * uVar36 + uVar39;
        auVar12._8_8_ = 0;
        auVar12._0_8_ = uVar30;
        auVar24._8_8_ = 0;
        auVar24._0_8_ = uVar36;
        uVar44 = SUB168(auVar12 * auVar24,8) + (ulong)CARRY8(uVar30 * uVar36,uVar39);
        puVar1[uVar42] = uVar41 - uVar47;
        auVar13._8_8_ = 0;
        auVar13._0_8_ = uVar46;
        auVar25._8_8_ = 0;
        auVar25._0_8_ = uVar40;
        uVar45 = SUB168(auVar13 * auVar25,8) - uVar45;
        uVar35 = ~uVar45;
        uVar39 = uVar44 - (uVar45 + (uVar47 > uVar41));
        uVar45 = -(ulong)(!CARRY8(uVar44,uVar35) &&
                         !CARRY8(uVar44 + uVar35,(ulong)(uVar47 <= uVar41)));
        uVar44 = uVar32 * uVar40;
        uVar41 = uVar31 * uVar36 + uVar48;
        auVar14._8_8_ = 0;
        auVar14._0_8_ = uVar31;
        auVar26._8_8_ = 0;
        auVar26._0_8_ = uVar36;
        uVar36 = SUB168(auVar14 * auVar26,8) + (ulong)CARRY8(uVar31 * uVar36,uVar48);
        puVar2[uVar42] = uVar41 - uVar44;
        auVar15._8_8_ = 0;
        auVar15._0_8_ = uVar32;
        auVar27._8_8_ = 0;
        auVar27._0_8_ = uVar40;
        uVar43 = SUB168(auVar15 * auVar27,8) - uVar43;
        uVar35 = ~uVar43;
        uVar48 = uVar36 - (uVar43 + (uVar44 > uVar41));
        uVar43 = -(ulong)(!CARRY8(uVar36,uVar35) &&
                         !CARRY8(uVar36 + uVar35,(ulong)(uVar44 <= uVar41)));
        uVar42 = uVar42 + 1;
      } while (uVar42 < uVar37);
      lVar34 = 0;
      bVar29 = CARRY8(uVar45,uVar45);
      uVar30 = *puVar1;
      uVar46 = uVar37;
      uVar46 = uVar46 - 1;
      while (uVar46 != 0) {
        uVar42 = *(ulong *)((long)puVar1 + (lVar34 + 8));
        uVar30 = (uVar30 >> 0x3a | uVar42 << 6) ^ uVar45;
        *(ulong *)((long)puVar1 + lVar34) = uVar30 + bVar29;
        lVar34 = lVar34 + 8;
        bVar29 = CARRY8(uVar30,(ulong)bVar29);
        uVar30 = uVar42;
        uVar46 = uVar46 - 1;
      }
      *(ulong *)((long)puVar1 + lVar34) =
           ((uVar30 >> 0x3a | uVar39 * 0x40) ^ uVar45) + (ulong)bVar29;
      lVar34 = 0;
      bVar29 = CARRY8(uVar43,uVar43);
      uVar30 = *puVar2;
      uVar37 = uVar37 - 1;
      while (uVar37 != 0) {
        uVar46 = *(ulong *)((long)puVar2 + (lVar34 + 8));
        uVar30 = (uVar30 >> 0x3a | uVar46 << 6) ^ uVar43;
        *(ulong *)((long)puVar2 + lVar34) = uVar30 + bVar29;
        lVar34 = lVar34 + 8;
        bVar29 = CARRY8(uVar30,(ulong)bVar29);
        uVar30 = uVar46;
        uVar37 = uVar37 - 1;
      }
      *(ulong *)((long)puVar2 + lVar34) =
           ((uVar30 >> 0x3a | uVar48 * 0x40) ^ uVar43) + (ulong)bVar29;
      uVar37 = 0;
      bVar29 = CARRY8(uVar45,uVar45);
      do {
        uVar30 = param_4[uVar37] & uVar45;
        uVar46 = param_5[uVar37] ^ uVar45;
        param_5[uVar37] = uVar30 + uVar46 + (ulong)bVar29;
        uVar37 = uVar37 + 1;
        bVar29 = CARRY8(uVar30,uVar46) || CARRY8(uVar30 + uVar46,(ulong)bVar29);
      } while (uVar37 != param_1);
      uVar43 = ~uVar43;
      uVar37 = 0;
      bVar29 = CARRY8(uVar43,uVar43);
      do {
        uVar30 = param_4[uVar37] & uVar43;
        uVar46 = param_2[uVar37] ^ uVar43;
        param_2[uVar37] = uVar30 + uVar46 + (ulong)bVar29;
        uVar37 = uVar37 + 1;
        bVar29 = CARRY8(uVar30,uVar46) || CARRY8(uVar30 + uVar46,(ulong)bVar29);
      } while (uVar37 != param_1);
      bVar29 = uVar33;
      uVar33 = uVar33 - 0x3a;
    } while (0x39 < bVar29 && uVar33 != 0);
  }

}
