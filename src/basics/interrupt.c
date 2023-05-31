#include<STC12C5A60S2.H>
#include"typedefine.h"
#include"timerinit.h"
#include"serialport.h"

uint8 time = 0;

/**
 * @brief 外部中断0(P32)
 * 
 */
void Int0_Isr(void)	interrupt 0
{
    //add your code here!
}

/**
 * @brief 定时器0中断
 * 
 */
void Timer0_Isr(void) interrupt 1
{
    //add your code here!
}

/**
 * @brief 外部中断1(P33)
 * 
 */
void Int1_Isr(void)	interrupt 2
{
    //add your code here!
}

/**
 * @brief 定时器1中断
 * 
 */
void Timer1_Isr(void) interrupt 3
{
    //add your code here!
}

/**
 * @brief 串口1中断
 * 
 */
void UART_Isr(void) interrupt 4
{
    uint8 c;
    if(RI)
    {
        RI = 0;
        c = SBUF;
        //add your code here!
    }
    else
    {
        TI = 0;
    }
}

/**
 * @brief ADC中断
 * 
 */
void ADC_Isr(void) interrupt 5
{
    //add your code here!
}

/**
 * @brief 低压检测中断
 * 
 */
void LVD_Isr(void) interrupt 6
{
    //add your code here!
}

/**
 * @brief PCA中断
 * 
 */
void PCA_Isr(void) interrupt 7
{
    //add your code here!
}

/**
 * @brief 串口2中断
 * 
 */
void UART2_Isr(void) interrupt 8
{
    uint8 c;
    if(S2CON & 0x01)
    {
        S2CON &= 0xFE;
        c = S2BUF;
        //add your code here!
    }
    else
    {
        S2CON &= 0xFD;
    }
}

/**
 * @brief SPI中断
 * 
 */
void SPI_Isr(void) interrupt 9
{
    //add your code here!
}