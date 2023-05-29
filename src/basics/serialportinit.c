#include<STC12C5A60S2.H>
#include"typedefine.h"

#define SYSclk 12000000L		//频率12Mhz

/**
 * @brief 串口1初始化(波特率加倍)
 * 
 * @param rate 波特率
 * @param uart 数据位数
 * @param T 定时器模式(12T/1T)
 * @param indrate 是否启用独立波特率发生器 1:启用,0:使用定时器1
 * @param isr 是否启用串口1中断1:启用,0:不启用
 */
void Uartprot1Init(uint16 rate,uint8 uart,uint8 T,bit indrate,bit isr)		
{
	PCON |= 0x80;		//使能波特率倍速位SMOD

    switch (uart)
    {
    	case '8': SCON = 0x50; 	break; 	//8位数据,可变波特率
        case '9': SCON = 0xD0; 	break;	//9位数据,可变波特率		
		default: break;
    }

	if(indrate)				//选择是否启用独立波特率发生器或者使用定时器1
	{
		switch (T)
		{
			case 1:AUXR |= 0x04;break;		//定时器时钟1T模式
			case 12:AUXR &= 0xFB;break;		//定时器时钟12T模式
			default:break;
		}		
		BRT = 256U - (uint16)(SYSclk/16/T/rate);	//设置定时重载值
		AUXR |= 0x01;		//串口1使用独立波特率发射器为波特率发生器
		AUXR |= 0x10;		//启动独立波特率发射器
	}
	else
	{
		switch (T)
		{
			case 1:AUXR |= 0x40;break;		//定时器时钟1T模式
			case 12:AUXR &= 0xBF;break;		//定时器时钟12T模式
			default:break;
		}
		AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
		TMOD &= 0x0F;		//设置定时器模式
		TMOD |= 0x20;		//设置定时器模式
		TL1 = TH1 = 256U - (uint16)(SYSclk/16/T/rate);	//设置定时初始值,设置定时重载值
		ET1 = 0;			//禁止定时器中断
		TR1 = 1;			//定时器1开始计时		
	}

	if(isr)
	{
		ES = 1;				//使能串口总中断
	}
	else
	{
		ES = 0;				//禁止串口总中断
	}
}

/**
 * @brief 串口2初始化(波特率加倍)
 * 
 * @param rate 波特率
 * @param uart 数据位数
 * @param T 定时器模式(12T/1T)
 */
void Uartprot2Init(uint16 rate,uint8 uart,uint8 T,bit isr)
{
	AUXR |= 0x08;		//使能波特率倍速位S2SMOD

	switch (uart)
	{
		case '8':S2CON = 0x50;break;		//8位数据,可变波特率
		case '9':S2CON = 0xD0;break;		//9位数据,可变波特率
		default:break;
	}
	switch (T)
	{
		case 1:AUXR |= 0x04;break;		//定时器时钟1T模式
		case 12:AUXR &= 0xFB;break;		//定时器时钟12T模式
		default:break;
	}
	
	BRT = 256U - (uint16)(SYSclk/16/T/rate);	//设置定时重载值
	AUXR |= 0x10;						//启动独立波特率发射器
	
	if(isr)
	{
		IE2 |= 0x01;					//使能串口2中断
	}
	else
	{
		IE2 &= 0xFE;					//禁止串口2中断
	}
}








