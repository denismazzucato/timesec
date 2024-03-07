
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,long param_3,long param_4,long param_5)

{
  bool bVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;

  if (param_1 != 0) {
    uVar2 = 0;
    uVar3 = 0;
    do {
      uVar3 = uVar3 | *(ulong *)(param_4 + uVar2 * 8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_1);
    if (uVar3 == 0) {
      param_3 = 0;
    }
    uVar3 = -(ulong)(param_3 != 0);
    uVar2 = 0;
    bVar1 = CARRY8(uVar3,uVar3);
    do {
      uVar4 = *(ulong *)(param_5 + uVar2 * 8) & uVar3;
      uVar5 = *(ulong *)(param_4 + uVar2 * 8) ^ uVar3;
      *(ulong *)(param_2 + uVar2 * 8) = uVar4 + uVar5 + (ulong)bVar1;
      uVar2 = uVar2 + 1;
      bVar1 = CARRY8(uVar4,uVar5) || CARRY8(uVar4 + uVar5,(ulong)bVar1);
    } while (uVar2 != param_1);
  }

}
