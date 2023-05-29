#include<STC12C5A60S2.H>
#include"typedefine.h"

xdata uint8 time0H = 0,time0L = 0;
xdata uint8 time1H = 0,time1L = 0;

/**
 * @brief 计算定时器初值
 * 
 * @param time 输入时间值
 * @param T 1T模式下定时器每(1/12)us加1,12T模式下定时器每(1)us加1
 * @param timer 选择对定时器0或者定时器1(0:定时器0,1:定时器1)
 */
void TimeCalcu(uint16 time,uint8 T,bit timer)
{
	if(65536-(time*(13-T)) < 0){time = 0;}

	if(timer == 0)
	{
		time0H = (uint8)(((65536-(time*(13-T))) & 0xff00)>>8);
		time0L = (uint8)((65536-(time*(13-T))) & 0x00ff);		
	}
	else
	{
		time1H = (uint8)(((65536-(time*(13-T))) & 0xff00)>>8);
		time1L = (uint8)((65536-(time*(13-T))) & 0x00ff);	
	}

}

void Timer0_Init(uint16 time,uint8 T)
{
	TimeCalcu(time,T,0);

	switch (T)
	{
		case 1:AUXR |= 0x80;break;			//定时器时钟1T模式
		case 12:AUXR &= 0x7F;break;			//定时器时钟12T模式
		default:break;
	}
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式

	TL0 = time0L;			//设置定时初始值
	TH0 = time0H;			//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
}


void Timer1_Init(uint16 time,uint8 T)		//1微秒@12.000MHz
{
	TimeCalcu(time,T,1);

	switch (T)
	{
		case 1:AUXR |= 0x40;break;			//定时器时钟1T模式
		case 12:AUXR &= 0xBF;break;			//定时器时钟12T模式
		default:break;
	}
	TMOD &= 0x0F;			//设置定时器模式
	TMOD |= 0x10;			//设置定时器模式

	TL1 = time1L;				//设置定时初始值
	TH1 = time1H;			//设置定时初始值
	TF1 = 0;				//清除TF1标志
	TR1 = 1;				//定时器1开始计时
	ET1 = 1;				//使能定时器1中断
}
