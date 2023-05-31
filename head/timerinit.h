#ifndef __TIMER_H__
#define __TIMER_H__

#include"typedefine.h"


void Timer_Sw(bit timer,bit Sw);
void TimerCalcu(uint16 time,bit timer,uint8 model);
void Timer_Init(bit timer,uint16 time,uint8 T,bit isr,bit CT,bit gate,uint8 model);

#endif // !__TIMER_H__
