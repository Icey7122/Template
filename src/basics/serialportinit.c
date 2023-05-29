#include<STC12C5A60S2.H>
#include"typedefine.h"

#define SYSclk 12000000L		//Ƶ��12Mhz

/**
 * @brief ����1��ʼ��(�����ʼӱ�)
 * 
 * @param rate ������
 * @param uart ����λ��
 * @param T ��ʱ��ģʽ(12T/1T)
 * @param indrate �Ƿ����ö��������ʷ����� 1:����,0:ʹ�ö�ʱ��1
 * @param isr �Ƿ����ô���1�ж�1:����,0:������
 */
void Uartprot1Init(uint16 rate,uint8 uart,uint8 T,bit indrate,bit isr)		
{
	PCON |= 0x80;		//ʹ�ܲ����ʱ���λSMOD

    switch (uart)
    {
    	case '8': SCON = 0x50; 	break; 	//8λ����,�ɱ䲨����
        case '9': SCON = 0xD0; 	break;	//9λ����,�ɱ䲨����		
		default: break;
    }

	if(indrate)				//ѡ���Ƿ����ö��������ʷ���������ʹ�ö�ʱ��1
	{
		switch (T)
		{
			case 1:AUXR |= 0x04;break;		//��ʱ��ʱ��1Tģʽ
			case 12:AUXR &= 0xFB;break;		//��ʱ��ʱ��12Tģʽ
			default:break;
		}		
		BRT = 256U - (uint16)(SYSclk/16/T/rate);	//���ö�ʱ����ֵ
		AUXR |= 0x01;		//����1ʹ�ö��������ʷ�����Ϊ�����ʷ�����
		AUXR |= 0x10;		//�������������ʷ�����
	}
	else
	{
		switch (T)
		{
			case 1:AUXR |= 0x40;break;		//��ʱ��ʱ��1Tģʽ
			case 12:AUXR &= 0xBF;break;		//��ʱ��ʱ��12Tģʽ
			default:break;
		}
		AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
		TMOD &= 0x0F;		//���ö�ʱ��ģʽ
		TMOD |= 0x20;		//���ö�ʱ��ģʽ
		TL1 = TH1 = 256U - (uint16)(SYSclk/16/T/rate);	//���ö�ʱ��ʼֵ,���ö�ʱ����ֵ
		ET1 = 0;			//��ֹ��ʱ���ж�
		TR1 = 1;			//��ʱ��1��ʼ��ʱ		
	}

	if(isr)
	{
		ES = 1;				//ʹ�ܴ������ж�
	}
	else
	{
		ES = 0;				//��ֹ�������ж�
	}
}

/**
 * @brief ����2��ʼ��(�����ʼӱ�)
 * 
 * @param rate ������
 * @param uart ����λ��
 * @param T ��ʱ��ģʽ(12T/1T)
 */
void Uartprot2Init(uint16 rate,uint8 uart,uint8 T,bit isr)
{
	AUXR |= 0x08;		//ʹ�ܲ����ʱ���λS2SMOD

	switch (uart)
	{
		case '8':S2CON = 0x50;break;		//8λ����,�ɱ䲨����
		case '9':S2CON = 0xD0;break;		//9λ����,�ɱ䲨����
		default:break;
	}
	switch (T)
	{
		case 1:AUXR |= 0x04;break;		//��ʱ��ʱ��1Tģʽ
		case 12:AUXR &= 0xFB;break;		//��ʱ��ʱ��12Tģʽ
		default:break;
	}
	
	BRT = 256U - (uint16)(SYSclk/16/T/rate);	//���ö�ʱ����ֵ
	AUXR |= 0x10;						//�������������ʷ�����
	
	if(isr)
	{
		IE2 |= 0x01;					//ʹ�ܴ���2�ж�
	}
	else
	{
		IE2 &= 0xFE;					//��ֹ����2�ж�
	}
}








