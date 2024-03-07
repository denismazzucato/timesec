
#include "bignum_types.h"

void ltmp0(ulong param_1)

{
  ulong uVar1;
  ulong uVar2;

  uVar1 = (param_1 & 0xffff0000ffff0000) >> 0x20 | (param_1 & 0xffff0000ffff0000) << 0x20 |
          param_1 & 0xffff0000ffff;
  uVar2 = uVar1 & 0xff00ff00ff00ff00;
  uVar1 = uVar1 & 0xff00ff00ff00ff;
}
