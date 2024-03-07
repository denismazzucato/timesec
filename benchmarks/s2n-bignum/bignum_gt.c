
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;

  lVar3 = 0;
  bVar2_1 = param_1;
  bVar2_2 = param_3;
  param_3 = param_3 - param_1;
  if (bVar2_1 <= bVar2_2) {
    if (param_1 != 0) {
      do {
        uVar4 = *(ulong *)(param_4 + lVar3 * 8);
        uVar1 = ~*(ulong *)(param_2 + lVar3 * 8);
        bVar2 = CARRY8(uVar4,uVar1) || CARRY8(uVar4 + uVar1,(ulong)bVar2);
        lVar3 = lVar3 + 1;
        param_1 = param_1 - 1;
      } while (param_1 != 0);
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      lVar5 = *(long *)(param_4 + lVar3 * 8);
      bVar2 = lVar5 != 0 || CARRY8(lVar5 - 1,(ulong)bVar2);
      lVar3 = lVar3 + 1;
    }
  } else {
    bVar2 = CARRY8(param_3,param_1);
    lVar5 = param_3 + param_1;
    if (lVar5 != 0) {
      param_1 = param_1 - lVar5;
      do {
        uVar4 = *(ulong *)(param_4 + lVar3 * 8);
        uVar1 = ~*(ulong *)(param_2 + lVar3 * 8);
        bVar2 = CARRY8(uVar4,uVar1) || CARRY8(uVar4 + uVar1,(ulong)bVar2);
        lVar3 = lVar3 + 1;
        lVar5 = lVar5 + -1;
      } while (lVar5 != 0);
    }
    do {
      bVar2 = CARRY8(~(*(long *)(param_2 + lVar3 * 8) + (ulong)!bVar2),(ulong)bVar2);
      lVar3 = lVar3 + 1;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
}
