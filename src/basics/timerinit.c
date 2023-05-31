#include<STC12C5A60S2.H>
#include"typedefine.h"


/**
 * @brief 计算定时器初值
 * 
 * @param time 输入时间值(1T:(1/12)us,12T:1us)
 * @param timer 选择对定时器0或者定时器1(0:定时器0,1:定时器1)
 * @param model 0:13位定时器,1:16位定时器,2:8位自动重装载,3:8位定时器(定时器0会使用定时器1的中断标志)
 */
void TimerCalcu(uint16 time,bit timer,uint8 model)
{
	switch(model)
	{
		case '0':						//13位定时器
		{
			if(timer)
			{
				TH1 = (uint8)(((8192-time) & 0x1FE0)>>5);
				TL1 = (uint8)((8192-time) & 0x001F);		
			}
			else
			{
				TH0 = (uint8)(((8192-time) & 0x1FE0)>>5);
				TL0 = (uint8)((8192-time) & 0x001F);	
			}
			break;
		}
		case '1':						//16位定时器
		{
			if(timer)
			{
				TH1 = (uint8)(((65536-time) & 0xFF00)>>8);
				TL1 = (uint8)((65536-time) & 0x00FF);		
			}
			else
			{
				TH0 = (uint8)(((65536-time) & 0xFF00)>>8);
				TL0 = (uint8)((65536-time) & 0x00FF);	
			}
			break;			
		}
		case '2':						//8位自动重装载定时器
		{
			if(timer)
			{TH1 = TL1 = (uint8)(256-time);}
			else
			{TH0 = TL0 = (uint8)(256-time);}
			break;
		}
		case '3':						//2个8位定时器
		{
			if(timer)
			{TH0 = (uint8)(256-time);}
			else
			{TL0 = (uint8)(256-time);}
			break;
		}
		default:break;
	}

}

/**
 * @brief 定时器开关
 * 
 * @param timer 选择定时器
 * @param Sw 开关
 */
void Timer_Sw(bit timer,bit Sw)
{
	if(timer)
	{if(Sw){TR1 = 1;}else{TR1 = 0;}}
	else
	{if(Sw){TR0 = 1;}else{TR0 = 0;}}
}

/**
 * @brief 定时器0初始化
 * 
 * @param timer 选择定时器
 * @param time 定时时间
 * @param T 分频模式(1T/12T)
 * @param isr 中断开关
 * @param CT 定时器或者计数器(0:定时器,1:计数器(定时器1:P3.5,定时器0:P3.4))
 * @param gate 连锁开关(gate为1时,只有TR0为1和INT0为高时才能计数/定时)
 * @param model 定时器模式(0:13位定时器,1:16位定时器,2:8位自动重装定时器,3:2个8位定时器)
 */
void Timer_Init(bit timer,uint16 time,uint8 T,bit isr,bit CT,bit gate,uint8 model)
{
	TimerCalcu(time,timer,model);

	if(timer)
	{
		switch (T)
		{
			case 1:AUXR |= 0x40;break;			//定时器时钟1T模式
			case 12:AUXR &= 0xBF;break;			//定时器时钟12T模式
			default:break;
		}

		if(gate){TMOD |= 0x80;}else{TMOD &= 0x7F;}
		if(CT){TMOD |= 0x40;}else{TMOD &= 0xBF;}

		TMOD &= 0xCF;							//设置定时器模式
		TMOD |= (model << 4);					//设置定时器模式 
		TF1 = 0;								//清除TF1溢出标志
		ET1 = isr;								//使能定时器1中断
	}
	else
	{
		switch (T)
		{
			case 1:AUXR |= 0x80;break;			//定时器时钟1T模式
			case 12:AUXR &= 0x7F;break;			//定时器时钟12T模式
			default:break;
		}
		if(gate){TMOD |= 0x08;}else{TMOD &= 0xF7;}
		if(CT){TMOD |= 0x04;}else{TMOD &= 0xFB;}

		TMOD &= 0xFC;							//设置定时器模式
		TMOD |= model;							//设置定时器模式 
		TF0 = 0;								//清除TF0溢出标志
		ET0 = isr;								//使能定时器0中断		
	}

	Timer_Sw(timer,1);							//定时器0开始计时
}