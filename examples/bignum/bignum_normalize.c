
#include "bignum_types.h"

void ltmp0(ulong param_1,long param_2)

{
  long lVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;

  lVar1 = param_1 - 1;
  uVar11 = param_1;
  if (param_1 != 0) {
    lVar8 = *(long *)(param_2 + lVar1 * 8);
    lVar3 = 0;
    for (; lVar1 != 0; lVar1 = lVar1 + -1) {
      uVar11 = 0;
      bVar2 = lVar8;
      if (bVar2 == 0) {
        lVar3 = lVar3 + 1;
      }
      lVar4 = 0;
      do {
        lVar5 = *(long *)(param_2 + uVar11 * 8);
        lVar8 = lVar4;
        if (bVar2 != 0) {
          lVar8 = lVar5;
        }
        *(long *)(param_2 + uVar11 * 8) = lVar8;
        uVar11 = uVar11 + 1;
        lVar4 = lVar5;
      } while (uVar11 != param_1);
    }
    uVar9 = LZCOUNT(lVar8);
    uVar11 = lVar3 * 0x40 + uVar9;
    uVar7 = 0;
    uVar10 = 0;
    do {
      uVar12 = *(ulong *)(param_2 + uVar10 * 8);
      uVar6 = uVar12 << (uVar9 & 0x3f) | uVar7;
      uVar7 = uVar12 >> (-uVar9 & 0x3f) & -(ulong)((uVar9 & 0x3f) != 0);
      *(ulong *)(param_2 + uVar10 * 8) = uVar6;
      uVar10 = uVar10 + 1;
    } while (uVar10 < param_1);
  }
}
