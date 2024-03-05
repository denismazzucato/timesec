
#include "bignum_types.h"

void ltmp0(ulong param_1)

{
  long lVar1;
  long lVar2;
  undefined auVar3 [16];
  undefined auVar4 [16];
  undefined auVar5 [16];
  undefined auVar6 [16];
  ulong uVar7;
  ulong uVar8;

  lVar1 = (param_1 >> 0x10) + 1;
  uVar7 = (param_1 >> 0x10 ^ 0x1ffffffffffff) >> 0x20;
  uVar8 = -(lVar1 * uVar7) >> 0x31;
  uVar8 = uVar8 * uVar8;
  uVar7 = uVar7 * 0x40000000 +
          uVar7 * ((uVar8 + (-(lVar1 * uVar7) >> 0x22)) * (uVar8 | 0x40000000) >> 0x1e) >> 0x1e;
  lVar2 = uVar7 * 0x10000 + ((-(lVar1 * uVar7) >> 0x18) * uVar7 >> 0x18);
  uVar7 = lVar2 * 0x80000000 + (((ulong)-(lVar1 * lVar2) >> 0x20) * lVar2 >> 0x11);
  auVar3._8_8_ = 0;
  auVar3._0_8_ = param_1;
  auVar5._8_8_ = 0;
  auVar5._0_8_ = uVar7;
  uVar8 = uVar7 * 2 +
          ((uVar7 >> 0x21) * ~(param_1 * uVar7 >> 0x3c | SUB168(auVar3 * auVar5,8) << 4) >> 0x21);
  uVar7 = uVar8 + 1;
  if (uVar7 == 0) {
    uVar7 = 0xffffffffffffffff;
  }
  auVar4._8_8_ = 0;
  auVar4._0_8_ = param_1;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = uVar7;
  if (!CARRY8(SUB168(auVar4 * auVar6,8),param_1)) {
    uVar8 = uVar7;
  }
}
