
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5,long param_6)

{
  ulong uVar1;
  undefined auVar2 [16];
  undefined auVar3 [16];
  bool bVar4;
  bool bVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong *puVar14;

  uVar6 = param_1;
  if (param_1 != 0) {
    uVar6 = 0;
    uVar7 = 0;
    uVar9 = 0;
    do {
      uVar8 = *(ulong *)(param_2 + uVar9 * 8);
      bVar4 = CARRY8(uVar6,uVar8);
      uVar8 = uVar6 + uVar8;
      uVar6 = uVar7 + bVar4;
      uVar7 = (ulong)CARRY8(uVar7,(ulong)bVar4);
      uVar12 = uVar9 + 1;
      uVar1 = uVar12;
      if (param_3 <= uVar12) {
        uVar1 = param_3;
      }
      uVar11 = uVar12 - param_5;
      if (uVar12 < param_5) {
        uVar11 = 0;
      }
      lVar10 = uVar1 - uVar11;
      if (uVar11 <= uVar1 && lVar10 != 0) {
        puVar14 = (ulong *)(uVar11 * 8 + param_4);
        do {
          uVar12 = *(ulong *)(param_6 + ((uVar9 - uVar1) * 8 + lVar10 * 8));
          uVar13 = *puVar14 * uVar12;
          auVar2._8_8_ = 0;
          auVar2._0_8_ = *puVar14;
          auVar3._8_8_ = 0;
          auVar3._0_8_ = uVar12;
          uVar11 = SUB168(auVar2 * auVar3,8);
          bVar5 = CARRY8(uVar8,uVar13);
          uVar8 = uVar8 + uVar13;
          uVar12 = uVar6 + uVar11;
          bVar4 = CARRY8(uVar6,uVar11);
          uVar6 = uVar6 + uVar11 + (ulong)bVar5;
          uVar7 = uVar7 + (bVar4 || CARRY8(uVar12,(ulong)bVar5));
          lVar10 = lVar10 + -1;
          puVar14 = puVar14 + 1;
        } while (lVar10 != 0);
      }
      *(ulong *)(param_2 + uVar9 * 8) = uVar8;
      uVar9 = uVar9 + 1;
    } while (uVar9 < param_1);
  }
}
