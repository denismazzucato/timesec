
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;

  if (param_1 != 0) {
    uVar6 = param_3 & 0x3f;
    uVar1 = (param_3 >> 6) + 1;
    uVar4 = 0;
    uVar3 = 0;
    do {
      uVar5 = *(ulong *)(param_2 + uVar4 * 8);
      uVar2 = uVar5;
      if (uVar1 <= uVar4) {
        uVar2 = param_5;
      }
      if (uVar4 != uVar1) {
        uVar5 = uVar3;
      }
      uVar4 = uVar4 + 1;
      param_5 = uVar2;
      uVar3 = uVar5;
    } while (uVar4 < param_1);
    uVar3 = 0;
    if (uVar1 <= uVar4) {
      uVar3 = uVar2;
    }
    uVar1 = 0;
    if (uVar6 != 0) {
      uVar1 = uVar5;
    }
    param_1 = (uVar3 >> uVar6 | uVar1 << (-uVar6 & 0x3f)) &
              ((ulong)(param_4 < 0x40) << (param_4 & 0x3f)) - 1;
  }

}
