#ifndef __ISRSET_H__
#define __ISRSET_H__

#include"typedefine.h"


void ISRp_Set(uint8 isr,uint8 priority);
void ISR_Sw(uint8 isr,uint8 status);
void ExterIsrInit(bit exint,bit set);

#endif // !


