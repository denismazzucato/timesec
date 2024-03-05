
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5,long param_6)

{
  bool bVar1;
  ulong uVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
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

  if (param_1 != 0) {
    uVar9 = 0;
    uVar6 = 0;
    uVar7 = 0;
    do {
      uVar8 = 0;
      uVar12 = uVar9 + 1;
      uVar2 = uVar12;
      if (param_3 <= uVar12) {
        uVar2 = param_3;
      }
      uVar11 = uVar12 - param_5;
      if (uVar12 < param_5) {
        uVar11 = 0;
      }
      lVar10 = uVar2 - uVar11;
      if (uVar11 <= uVar2 && lVar10 != 0) {
        puVar14 = (ulong *)(uVar11 * 8 + param_4);
        do {
          uVar12 = *(ulong *)(param_6 + ((uVar9 - uVar2) * 8 + lVar10 * 8));
          uVar13 = *puVar14 * uVar12;
          auVar3._8_8_ = 0;
          auVar3._0_8_ = *puVar14;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = uVar12;
          uVar11 = SUB168(auVar3 * auVar4,8);
          bVar5 = CARRY8(uVar6,uVar13);
          uVar6 = uVar6 + uVar13;
          uVar12 = uVar7 + uVar11;
          bVar1 = CARRY8(uVar7,uVar11);
          uVar7 = uVar7 + uVar11 + (ulong)bVar5;
          uVar8 = uVar8 + (bVar1 || CARRY8(uVar12,(ulong)bVar5));
          lVar10 = lVar10 + -1;
          puVar14 = puVar14 + 1;
        } while (lVar10 != 0);
      }
      *(ulong *)(param_2 + uVar9 * 8) = uVar6;
      uVar9 = uVar9 + 1;
      uVar6 = uVar7;
      uVar7 = uVar8;
    } while (uVar9 < param_1);
  }

}
