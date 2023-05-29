#include<STC12C5A60S2.H>
#include"typedefine.h"


/**
 * @brief �����ж����ȼ�
 * @brief ��ͬһ���ȼ����ж�,����ѯ����0-9,���ж�һ������,���޷���ͬһ\
 * @brief ���ȼ����жϴ��,�����Ա��������ȼ����жϴ��
 * @param isr ѡ���ж�(0-9)
 * @param priority �������ȼ�(0:���ȼ�0(���);1:���ȼ�1;2:���ȼ�2;3:���ȼ�3(���))
 */
void ISRp_Set(uint8 isr,uint8 priority)
{
    bit H,L;
    H = (priority & 0x02) >> 1;
    L = priority & 0x01;
    switch (isr)
    {
        case 0:if(H){IPH |= 1<<0;}else{IPH &= ~(1<<0);}if(L){PX0 = 1;}else{PX0 = 0;}break;                //�����ⲿ�ж�0���ȼ�
        case 1:if(H){IPH |= 1<<1;}else{IPH &= ~(1<<1);}if(L){PT0 = 1;}else{PT0 = 0;}break;                //���ö�ʱ��0�ж����ȼ�
        case 2:if(H){IPH |= 1<<2;}else{IPH &= ~(1<<2);}if(L){PX1 = 1;}else{PX1 = 0;}break;                //�����ⲿ�ж�1���ȼ�
        case 3:if(H){IPH |= 1<<3;}else{IPH &= ~(1<<3);}if(L){PT1 = 1;}else{PT1 = 0;}break;                //���ö�ʱ��1�ж����ȼ�
        case 4:if(H){IPH |= 1<<4;}else{IPH &= ~(1<<4);}if(L){PS = 1;}else{PS = 0;}break;                  //���ô���1�ж����ȼ�
        case 5:if(H){IPH |= 1<<5;}else{IPH &= ~(1<<5);}if(L){PADC = 1;}else{PADC = 0;}break;              //����ADC�ж����ȼ�
        case 6:if(H){IPH |= 1<<6;}else{IPH &= ~(1<<6);}if(L){PLVD = 1;}else{PLVD = 0;}break;              //���õ�ѹ����ж����ȼ�
        case 7:if(H){IPH |= 1<<7;}else{IPH &= ~(1<<7);}if(L){PPCA = 1;}else{PPCA = 0;}break;              //����PCA�ж����ȼ�
        case 8:if(H){IPH2 |= 1<<0;}else{IPH2 &= ~(1<<0);}if(L){IP2 |= 1<<0;}else{IP2 &= ~(1<<0);}break;   //���ô���2�ж����ȼ�
        case 9:if(H){IPH2 |= 1<<1;}else{IPH2 &= ~(1<<1);}if(L){IP2 |= 1<<1;}else{IP2 &= ~(1<<1);}break;   //����SPI�ж����ȼ�

        default:break;
    }
}

/**
 * @brief �����ж�
 * 
 * @param isr �ж�ѡ��(10:�ж��ܿ���)
 * @param status �ж�״̬(PCA�ж���3���ж�Դ:CF,CCF0,CCF1.
 * status 0:CF(PCA/PWMʱ������ж�)�ر� status 1:����CF�ж� 
 * status 2:CCF0(�����ƥ���ж�)�ر� status 3:����CCF0�ж�
 * status 4:CCF1(�����ƥ���ж�)�ر� status 5:����CCF1�ж�)
 * 
 * status 0-5����PCA�о�ȷ����,�����ж�ֻ�п����͹ر�����״̬
 */
void ISR_Sw(uint8 isr,uint8 status)
{
    switch(isr)
    {
        case 0:if(status){EX0 = 1;}else{EX0 = 0;}break;         //�ⲿ�ж�0
        case 1:if(status){ET0 = 1;}else{ET0 = 0;}break;         //��ʱ��0�ж�
        case 2:if(status){EX1 = 1;}else{EX1 = 0;}break;         //�ⲿ�ж�1
        case 3:if(status){ET1 = 1;}else{ET1 = 0;}break;         //��ʱ��1�ж�
        case 4:if(status){ES = 1;}else{ES = 0;}break;           //�����ж�
        case 5:if(status){EADC = 1;}else{EADC = 0;}break;       //ADC�ж�
        case 6:if(status){ELVD = 1;}else{ELVD = 0;}break;       //��ѹ����ж�
        case 7:switch(status){case 0:CMOD &= 0xFE;break;        //PCA�ж�
                              case 1:CMOD |= 0x01;break;
                              case 2:CCF0 = 0;break;
                              case 3:CCF0 = 1;break;
                              case 4:CCF1 = 0;break;
                              case 5:CCF1 = 1;break;
                              default:break;}break;
        case 8:if(status){IE2 |= 0x01;}else{IE2 &= 0xFE;}break; //����2�ж�
        case 9:if(status){IE2 |= 0x02;}else{IE2 &= 0xFD;}break; //SPI�ж�
        case 10:if(status){EA = 1;}else{EA = 0;}break;          //���ж�
        default:break;
    }
}

/**
 * @brief �ⲿ�ж�0��ʼ��
 * 
 */
void ExterInterruptInit0(void)   
{
	EX0 = 1;	//���ж�0
	IT0 = 1;	//���÷�ʽΪ�����ж�
}

/**
 * @brief �ⲿ�ж�1��ʼ��
 * 
 */
void ExterInterruptInit1(void)
{
	EX1 = 1;	//���ж�1
	IT1 = 1;	//���÷�ʽΪ�����ж�
}