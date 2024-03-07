
#include "bignum_types.h"

void ltmp0(long param_1,long param_2,long param_3,long param_4,long param_5)

{
  undefined8 uVar1;

  if (param_2 != 0) {
    do {
      param_2 = param_2 + -1;
      uVar1 = *(undefined8 *)(param_4 + param_2 * 8);
      if (param_1 == 0) {
        uVar1 = *(undefined8 *)(param_5 + param_2 * 8);
      }
      *(undefined8 *)(param_3 + param_2 * 8) = uVar1;
    } while (param_2 != 0);
  }

}
