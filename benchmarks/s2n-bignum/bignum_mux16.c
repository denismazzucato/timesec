
#include "bignum_types.h"

void ltmp0(long param_1,undefined8 *param_2,undefined8 *param_3,long param_4)

{
  undefined8 uVar1;
  undefined8 uVar2;
  long lVar3;

  if (param_1 != 0) {
    param_4 = param_4 * param_1;
    lVar3 = param_1;
    do {
      uVar2 = param_3[param_1];
      if (param_1 != param_4) {
        uVar2 = *param_3;
      }
      uVar1 = param_3[param_1 * 2];
      if (param_1 * 2 != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 3];
      if (param_1 * 3 != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 4];
      if (param_1 * 4 != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 5];
      if (param_1 * 5 != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 6];
      if (param_1 * 6 != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 7];
      if (param_1 * 7 != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 8];
      if (param_1 * 8 != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 9];
      if (param_1 * 9 != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 10];
      if (param_1 * 10 != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 0xb];
      if (param_1 * 0xb != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 0xc];
      if (param_1 * 0xc != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 0xd];
      if (param_1 * 0xd != param_4) {
        uVar2 = uVar1;
      }
      uVar1 = param_3[param_1 * 0xe];
      if (param_1 * 0xe != param_4) {
        uVar1 = uVar2;
      }
      uVar2 = param_3[param_1 * 0xf];
      if (param_1 * 0xf != param_4) {
        uVar2 = uVar1;
      }
      *param_2 = uVar2;
      param_2 = param_2 + 1;
      param_3 = param_3 + 1;
      lVar3 = lVar3 + -1;
    } while (lVar3 != 0);
  }

}
