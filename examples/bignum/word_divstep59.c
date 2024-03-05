
#include "bignum_types.h"

void ltmp0(long *param_1,long param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  bool bVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long lVar16;
  long lVar17;
  long lVar18;

  uVar7 = param_3 & 0xfffff | 0xfffffe0000000000;
  uVar9 = param_4 & 0xfffff | 0xc000000000000000;
  bVar4 = (param_4 & 1);
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -param_2;
  if (bVar4 == 0 || param_2 < 0) {
    lVar16 = param_2;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || param_2 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar16 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar16 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar16 = lVar16 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar16;
  if (bVar4 == 0 || lVar16 < 0) {
    lVar1 = lVar16;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar16 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  lVar1 = lVar1 + 2;
  lVar10 = (long)(uVar9 + uVar8) >> 1;
  lVar16 = (long)((uVar7 + 0x100000) * 0x400000) >> 0x2b;
  lVar14 = (long)(uVar7 + 0x20000100000) >> 0x2a;
  lVar17 = (lVar10 + 0x100000) * 0x400000 >> 0x2b;
  lVar10 = lVar10 + 0x20000100000 >> 0x2a;
  uVar7 = (long)(lVar16 * param_3 + lVar14 * param_4) >> 0x14;
  uVar5 = (long)(lVar17 * param_3 + lVar10 * param_4) >> 0x14;
  uVar8 = uVar7 & 0xfffff | 0xfffffe0000000000;
  uVar9 = uVar5 & 0xfffff | 0xc000000000000000;
  bVar4 = (uVar5 & 1);
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar8;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar15 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar15 = lVar1;
  }
  uVar2 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar2 = uVar8;
    uVar3 = uVar6;
  }
  uVar9 = uVar9 + uVar3;
  lVar15 = lVar15 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar2;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar15;
  if (bVar4 == 0 || lVar15 < 0) {
    lVar1 = lVar15;
  }
  uVar8 = uVar9;
  uVar3 = -uVar6;
  if (bVar4 == 0 || lVar15 < 0) {
    uVar8 = uVar2;
    uVar3 = uVar6;
  }
  lVar1 = lVar1 + 2;
  lVar11 = (long)(uVar9 + uVar3) >> 1;
  lVar15 = (long)((uVar8 + 0x100000) * 0x400000) >> 0x2b;
  lVar18 = (long)(uVar8 + 0x20000100000) >> 0x2a;
  lVar12 = (lVar11 + 0x100000) * 0x400000 >> 0x2b;
  lVar11 = lVar11 + 0x20000100000 >> 0x2a;
  uVar6 = (long)(lVar12 * uVar7 + lVar11 * uVar5) >> 0x14;
  uVar7 = (long)(lVar15 * uVar7 + lVar18 * uVar5) >> 0x14 & 0xfffffU | 0xfffffe0000000000;
  uVar9 = uVar6 & 0xfffff | 0xc000000000000000;
  bVar4 = (uVar6 & 1);
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar13 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar13 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar13 = lVar13 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar13;
  if (bVar4 == 0 || lVar13 < 0) {
    lVar1 = lVar13;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar13 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar13 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar13 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar13 = lVar13 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar13;
  if (bVar4 == 0 || lVar13 < 0) {
    lVar1 = lVar13;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar13 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar13 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar13 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar13 = lVar13 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar13;
  if (bVar4 == 0 || lVar13 < 0) {
    lVar1 = lVar13;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar13 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar13 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar13 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar13 = lVar13 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar13;
  if (bVar4 == 0 || lVar13 < 0) {
    lVar1 = lVar13;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar13 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar13 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar13 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar13 = lVar13 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar13;
  if (bVar4 == 0 || lVar13 < 0) {
    lVar1 = lVar13;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar13 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  lVar13 = lVar15 * lVar16 + lVar18 * lVar17;
  lVar15 = lVar15 * lVar14 + lVar18 * lVar10;
  lVar16 = lVar12 * lVar16 + lVar11 * lVar17;
  lVar17 = lVar12 * lVar14 + lVar11 * lVar10;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar10 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar10 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar10 = lVar10 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar10;
  if (bVar4 == 0 || lVar10 < 0) {
    lVar1 = lVar10;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar10 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar10 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar10 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar10 = lVar10 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar10;
  if (bVar4 == 0 || lVar10 < 0) {
    lVar1 = lVar10;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar10 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar10 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar10 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar10 = lVar10 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar10;
  if (bVar4 == 0 || lVar10 < 0) {
    lVar1 = lVar10;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar10 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar10 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar10 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar10 = lVar10 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar5;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar1 = -lVar10;
  if (bVar4 == 0 || lVar10 < 0) {
    lVar1 = lVar10;
  }
  uVar7 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar10 < 0) {
    uVar7 = uVar5;
    uVar8 = uVar6;
  }
  uVar9 = uVar9 + uVar8;
  lVar1 = lVar1 + 2;
  bVar4 = (uVar9 & 2);
  uVar9 = (long)uVar9 >> 1;
  uVar6 = uVar7;
  if (bVar4 == 0) {
    uVar6 = 0;
  }
  lVar10 = -lVar1;
  if (bVar4 == 0 || lVar1 < 0) {
    lVar10 = lVar1;
  }
  uVar5 = uVar9;
  uVar8 = -uVar6;
  if (bVar4 == 0 || lVar1 < 0) {
    uVar5 = uVar7;
    uVar8 = uVar6;
  }
  lVar12 = (long)(uVar9 + uVar8) >> 1;
  lVar1 = (long)((uVar5 + 0x100000) * 0x200000) >> 0x2b;
  lVar11 = (long)(uVar5 + 0x20000100000) >> 0x2b;
  lVar14 = (lVar12 + 0x100000) * 0x200000 >> 0x2b;
  lVar12 = lVar12 + 0x20000100000 >> 0x2b;
  *param_1 = -(lVar11 * lVar16) - lVar1 * lVar13;
  param_1[1] = -(lVar11 * lVar17) - lVar1 * lVar15;
  param_1[2] = -(lVar12 * lVar16) - lVar14 * lVar13;
  param_1[3] = -(lVar12 * lVar17) - lVar14 * lVar15;
}
