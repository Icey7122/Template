#include<INTRINS.H>
#include"typedefine.h"

void Delay1us()		//@12.000MHz
{
	_nop_();
	_nop_();
}

void Delay1ms()		//@12.000MHz
{
	uint8 i, j;

	_nop_();
	_nop_();
	i = 12;
	j = 168;
	do
	{
		while (--j);
	} while (--i);
}

void Delay_us(uint16 time)
{
    uint16 i;
    for(i=0;i < time; i++)
    {
        Delay1us();
    }
}

void Delay_ms(uint16 time)
{
    uint16 i;
    for(i=0;i < time; i++)
    {
        Delay1ms();
    }
}