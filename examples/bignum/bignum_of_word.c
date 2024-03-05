
#include "bignum_types.h"

void ltmp0(long param_1,undefined8 *param_2,undefined8 param_3)

{
  if (param_1 != 0) {
    *param_2 = param_3;
    for (param_1 = param_1 + -1; param_1 != 0; param_1 = param_1 + -1) {
      param_2[param_1] = 0;
    }
  }

}
