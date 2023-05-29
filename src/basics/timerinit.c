#include<STC12C5A60S2.H>
#include"typedefine.h"

xdata uint8 time0H = 0,time0L = 0;
xdata uint8 time1H = 0,time1L = 0;

/**
 * @brief ���㶨ʱ����ֵ
 * 
 * @param time ����ʱ��ֵ
 * @param T 1Tģʽ�¶�ʱ��ÿ(1/12)us��1,12Tģʽ�¶�ʱ��ÿ(1)us��1
 * @param timer ѡ��Զ�ʱ��0���߶�ʱ��1(0:��ʱ��0,1:��ʱ��1)
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
		case 1:AUXR |= 0x80;break;			//��ʱ��ʱ��1Tģʽ
		case 12:AUXR &= 0x7F;break;			//��ʱ��ʱ��12Tģʽ
		default:break;
	}
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ

	TL0 = time0L;			//���ö�ʱ��ʼֵ
	TH0 = time0H;			//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
}


void Timer1_Init(uint16 time,uint8 T)		//1΢��@12.000MHz
{
	TimeCalcu(time,T,1);

	switch (T)
	{
		case 1:AUXR |= 0x40;break;			//��ʱ��ʱ��1Tģʽ
		case 12:AUXR &= 0xBF;break;			//��ʱ��ʱ��12Tģʽ
		default:break;
	}
	TMOD &= 0x0F;			//���ö�ʱ��ģʽ
	TMOD |= 0x10;			//���ö�ʱ��ģʽ

	TL1 = time1L;				//���ö�ʱ��ʼֵ
	TH1 = time1H;			//���ö�ʱ��ʼֵ
	TF1 = 0;				//���TF1��־
	TR1 = 1;				//��ʱ��1��ʼ��ʱ
	ET1 = 1;				//ʹ�ܶ�ʱ��1�ж�
}
