#include<STC12C5A60S2.H>
#include"typedefine.h"


void PCAInit0(void)
{
    CMOD = 0x81;            //����״̬�¼�������,SYSclk/12,�����ж�
    CCON = 0x40;            //����PCA0��ʱ��
    CCAPM0 = 0x39;          //16λ����ģʽ,�����ж�CCF0
    CCAP0L = 0;             //��ʼ��PCA�����Ĵ���
    CCAP0H = 0;             //��ʼ��PCA�����Ĵ���
    CL = 0;                 //����PCA������
    CH = 0;                 //����PCA������

    EA = 1;                 //�����ж�
}

void PCAInit1(void)
{
    CMOD = 0x81;            //����״̬�¼�������,�������ⲿʱ��,��ֹ�ж�
    CCON = 0x40;            //����PCA��ʱ��
    CCAPM1 = 0x39;          //16λ����ģʽ,�����ж�CCF1
    CCAP1L = 0;             //��ʼ��PCA�����Ĵ���
    CCAP1H = 0;             //��ʼ��PCA�����Ĵ���
    CL = 0;                 //����PCA������
    CH = 0;                 //����PCA������

    EA = 1;                 //�����ж�
}


