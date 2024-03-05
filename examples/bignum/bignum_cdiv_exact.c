
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,ulong *param_4,ulong param_5)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  ulong *puVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;

  if (param_1 != 0) {
    uVar11 = LZCOUNT(-param_5 & param_5) ^ 0x3f;
    uVar12 = 0xffffffffffffffff >> (uVar11 & 0x3f);
    param_5 = param_5 >> (uVar11 & 0x3f);
    uVar4 = param_5 * -3 ^ 2;
    lVar5 = param_5 * uVar4 + 1;
    lVar7 = lVar5 * lVar5;
    lVar5 = uVar4 + lVar5 * uVar4;
    lVar6 = lVar7 * lVar7;
    lVar5 = lVar5 + lVar7 * lVar5;
    lVar5 = lVar5 + lVar6 * lVar5;
    uVar4 = 0;
    uVar10 = 0;
    puVar3 = param_4;
    uVar9 = param_5;
    if (param_3 != 0) {
      puVar3 = param_4 + 1;
      uVar10 = *param_4 >> (uVar11 & 0x3f);
      param_3 = param_3 - 1;
    }
    do {
      uVar13 = 0;
      if (uVar4 < param_3) {
        uVar13 = puVar3[uVar4];
      }
      uVar13 = uVar13 >> (uVar11 & 0x3f) | uVar13 << 0x40 - (uVar11 & 0x3f);
      uVar8 = uVar10 | uVar13 & (uVar12 ^ 0xffffffffffffffff);
      uVar10 = uVar13 & uVar12;
      uVar13 = uVar8 + uVar9;
      uVar14 = uVar13 * (lVar5 + lVar6 * lVar6 * lVar5);
      *(ulong *)(param_2 + uVar4 * 8) = ~uVar14;
      auVar1._8_8_ = 0;
      auVar1._0_8_ = uVar14;
      auVar2._8_8_ = 0;
      auVar2._0_8_ = param_5;
      uVar9 = SUB168(auVar1 * auVar2,8) + (ulong)CARRY8(uVar8,uVar9) +
              (ulong)CARRY8(uVar14 * param_5,uVar13);
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_1);
  }

}
