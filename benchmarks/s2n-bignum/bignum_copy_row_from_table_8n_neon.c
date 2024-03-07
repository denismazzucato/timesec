
#include "bignum_types.h"

void ltmp0(undefined (*param_1) [16],undefined (*param_2) [16],long param_3,long param_4,
          long param_5)

{
  undefined auVar1 [16];
  undefined auVar2 [16];
  undefined auVar3 [16];
  long lVar4;
  undefined (*pauVar5) [16];
  long lVar6;
  long lVar7;
  undefined auVar8 [16];

  lVar4 = param_4;
  pauVar5 = param_1;
  if ((param_3 != 0) && (param_4 != 0)) {
    do {
      *(undefined8 *)(*pauVar5 + 8) = 0;
      *(undefined8 *)*pauVar5 = 0;
      *(undefined8 *)(pauVar5[1] + 8) = 0;
      *(undefined8 *)pauVar5[1] = 0;
      *(undefined8 *)(pauVar5[2] + 8) = 0;
      *(undefined8 *)pauVar5[2] = 0;
      *(undefined8 *)(pauVar5[3] + 8) = 0;
      *(undefined8 *)pauVar5[3] = 0;
      lVar4 = lVar4 + -8;
      pauVar5 = pauVar5 + 4;
    } while (lVar4 != 0);
    lVar4 = 0;
    do {
      lVar6 = -(ulong)(lVar4 == param_5);
      lVar7 = param_4;
      pauVar5 = param_1;
      do {
        auVar8._8_8_ = lVar6;
        auVar8._0_8_ = lVar6;
        auVar8 = NEON_bit(*pauVar5,*param_2,auVar8,1);
        *(long *)(*pauVar5 + 8) = auVar8._8_8_;
        *(long *)*pauVar5 = auVar8._0_8_;
        auVar1._8_8_ = lVar6;
        auVar1._0_8_ = lVar6;
        auVar8 = NEON_bit(pauVar5[1],param_2[1],auVar1,1);
        *(long *)(pauVar5[1] + 8) = auVar8._8_8_;
        *(long *)pauVar5[1] = auVar8._0_8_;
        auVar2._8_8_ = lVar6;
        auVar2._0_8_ = lVar6;
        auVar8 = NEON_bit(pauVar5[2],param_2[2],auVar2,1);
        *(long *)(pauVar5[2] + 8) = auVar8._8_8_;
        *(long *)pauVar5[2] = auVar8._0_8_;
        auVar3._8_8_ = lVar6;
        auVar3._0_8_ = lVar6;
        auVar8 = NEON_bit(pauVar5[3],param_2[3],auVar3,1);
        *(long *)(pauVar5[3] + 8) = auVar8._8_8_;
        *(long *)pauVar5[3] = auVar8._0_8_;
        param_2 = param_2 + 4;
        pauVar5 = pauVar5 + 4;
        lVar7 = lVar7 + -8;
      } while (lVar7 != 0);
      lVar4 = lVar4 + 1;
    } while (lVar4 != param_3);
  }

}
