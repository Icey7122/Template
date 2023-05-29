#include<STC12C5A60S2.H>
#include<stdio.h>
#include"typedefine.h"


/**
 * @brief ���ڷ���n�ֽ�
 * 
 * @param port ���ڶ˿�('1','2')
 * @param uart ��������λ��('8'λ,'9'λ)
 * @param dat ���͵�����
 * @param bytes һ�����ݵ��ֽ���
 */
void SendnBytes(uint8 port,uint8 uart,uint32 dat,uint8 bytes)
{
	uint8 i;
	for(i = 0;i < bytes; i++)
	{
        if(port == '1')
        {
            switch(uart)
            {
                case '8':SBUF = (uint8)(dat & 0xFF);break;
                case '9':SBUF = (uint16)(dat & 0x1FF);break;
                default:break;
            }            
        }
        else if(port == '2')
        {
            switch (uart)
            {
                case '8':S2BUF = (uint8)(dat & 0xFF);break;
                case '9':S2BUF = (uint16)(dat & 0x1FF);break;
                default:break;
            }
        }
		dat >>= (uart - 48);   
        switch (port)
        {
            case '1':while(!TI);TI = 0;break;
            case '2':while(!(S2CON & 0x02));S2CON &= 0xFD;break;
            default:break;
        }     
		
		
	}
}

/**
 * @brief �����ַ���
 * 
 * @param s �ַ�����ַ
 * @param port ���ڶ˿ڶ˿�
 */
void SendString(uint8 port,uint8 *s)
{
	while(*s)
	{
		SendnBytes(port,'8',*s++,1);
	}
}

/**
 * @brief ��������
 * 
 * @param Num ��������
 * @param port ���ڶ˿�
 */
void SendNum_Ascllc(uint8 port,float Num)
{
    xdata uint8 str[12];
    sprintf(str,"%f",Num);
    SendString(port,str);
}
