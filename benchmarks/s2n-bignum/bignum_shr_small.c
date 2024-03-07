
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5)

{
  ulong uVar1;
  bool bVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;

  lVar4 = 0;
  if (param_3 < param_1) {
    do {
      param_1 = param_1 - 1;
      *(undefined8 *)(param_2 + param_1 * 8) = 0;
    } while (param_3 < param_1);
  }
  if (param_3 != param_1) {
    lVar4 = *(long *)(param_4 + param_1 * 8);
  }
  uVar3 = -param_5;
  uVar5 = lVar4 << (uVar3 & 0x3f);
  uVar1 = uVar5 & -(ulong)((param_5 & 0x3f) != 0);
  while (param_1 != 0) {
    param_1 = param_1 - 1;
    uVar6 = *(ulong *)(param_4 + param_1 * 8);
    uVar5 = uVar6 << (uVar3 & 0x3f);
    *(ulong *)(param_2 + param_1 * 8) = uVar6 >> (param_5 & 0x3f) | uVar1;
    uVar1 = uVar5 & -(ulong)((param_5 & 0x3f) != 0);
  }
}
