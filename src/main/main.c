#include<STC12C5A60S2.H>
#include"serialport.h"
#include"ioset.h"
#include"delay.h"

void main()
{
    UartprotSimuInit(00,0,57600);
    while(1)
    {
        Delay_ms(100);
        SendString('3',"Hello world!\n");
    }
}