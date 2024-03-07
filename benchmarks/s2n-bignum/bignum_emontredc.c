
#include "bignum_types.h"

void ltmp0(ulong param_1,ulong *param_2,ulong *param_3,long param_4)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  undefined auVar4 [16];
  bool bVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;

  uVar8 = param_1;
  if (param_1 != 0) {
    uVar8 = 0;
    uVar6 = 0;
    do {
      uVar10 = *param_2;
      uVar7 = uVar10 * param_4;
      uVar13 = *param_3;
      auVar1._8_8_ = 0;
      auVar1._0_8_ = uVar7;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = uVar13;
      uVar9 = SUB168(auVar1 * auVar3,8);
      *param_2 = uVar7;
      bVar5 = CARRY8(uVar10,uVar7 * uVar13);
      uVar10 = 1;
      if (param_1 != 1) {
        do {
          uVar13 = param_2[uVar10];
          uVar12 = uVar7 * param_3[uVar10];
          uVar11 = uVar13 + uVar9 + (ulong)bVar5;
          auVar2._8_8_ = 0;
          auVar2._0_8_ = uVar7;
          auVar4._8_8_ = 0;
          auVar4._0_8_ = param_3[uVar10];
          uVar9 = SUB168(auVar2 * auVar4,8) +
                  (ulong)(CARRY8(uVar13,uVar9) || CARRY8(uVar13 + uVar9,(ulong)bVar5));
          bVar5 = CARRY8(uVar11,uVar12);
          param_2[uVar10] = uVar11 + uVar12;
          uVar10 = uVar10 + 1;
        } while (uVar10 != param_1);
      }
      uVar10 = uVar9 + uVar8 + (ulong)bVar5;
      uVar8 = (ulong)(CARRY8(uVar9,uVar8) || CARRY8(uVar9 + uVar8,(ulong)bVar5)) +
              (ulong)CARRY8(uVar10,param_2[param_1]);
      param_2[param_1] = uVar10 + param_2[param_1];
      param_2 = param_2 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_1);
  }
}
