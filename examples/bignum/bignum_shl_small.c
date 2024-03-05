
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4,ulong param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;

  uVar1 = param_1;
  if (param_3 < param_1) {
    uVar1 = param_3;
  }
  uVar3 = 0;
  uVar5 = 0;
  if (uVar1 != 0) {
    do {
      uVar4 = *(ulong *)(param_4 + uVar5 * 8);
      uVar2 = uVar4 << (param_5 & 0x3f) | uVar3;
      uVar3 = uVar4 >> (-param_5 & 0x3f) & -(ulong)((param_5 & 0x3f) != 0);
      *(ulong *)(param_2 + uVar5 * 8) = uVar2;
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar1);
  }
  if (uVar5 < param_1) {
    *(ulong *)(param_2 + uVar5 * 8) = uVar3;
    uVar3 = 0;
    uVar5 = uVar5 + 1;
    while (uVar5 < param_1) {
      *(undefined8 *)(param_2 + uVar5 * 8) = 0;
      uVar5 = uVar5 + 1;
    }
  }
}
