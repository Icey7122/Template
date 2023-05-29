#include<STC12C5A60S2.H>
#include"typedefine.h"
#include"eeprom.h"


/**
 * @brief �ⲿ�ж�0(P32)
 * 
 */
void Int0_Isr(void)	interrupt 0
{
    //add your code here!
}

/**
 * @brief ��ʱ��0�ж�
 * 
 */
void Timer0_Isr(void) interrupt 1
{
    //add your code here!
}

/**
 * @brief �ⲿ�ж�1(P33)
 * 
 */
void Int1_Isr(void)	interrupt 2
{
    //add your code here!
}

/**
 * @brief ��ʱ��1�ж�
 * 
 */
void Timer1_Isr(void) interrupt 3
{
    //add your code here!
}

/**
 * @brief ����1�ж�
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
 * @brief ADC�ж�
 * 
 */
void ADC_Isr(void) interrupt 5
{
    //add your code here!
}

/**
 * @brief ��ѹ����ж�
 * 
 */
void LVD_Isr(void) interrupt 6
{
    //add your code here!
}

/**
 * @brief PCA�ж�
 * 
 */
void PCA_Isr(void) interrupt 7
{
    //add your code here!
}

/**
 * @brief ����2�ж�
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
 * @brief SPI�ж�
 * 
 */
void SPI_Isr(void) interrupt 9
{
    //add your code here!
}