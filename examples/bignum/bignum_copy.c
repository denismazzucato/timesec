
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  ulong uVar2;

  uVar1 = param_1;
  if (param_3 <= param_1) {
    uVar1 = param_3;
  }
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      *(undefined8 *)(param_2 + uVar2 * 8) = *(undefined8 *)(param_4 + uVar2 * 8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  for (; uVar2 < param_1; uVar2 = uVar2 + 1) {
    *(undefined8 *)(param_2 + uVar2 * 8) = 0;
  }

}
