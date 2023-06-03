#include<STC12C5A60S2.H>
#include<stdio.h>
#include"typedefine.h"

void Simu_TXD(uint8 dat);


/**
 * @brief 串口发送n字节
 * 
 * @param port 串口端口('1','2')
 * @param uart 发送数据位数('8'位,'9'位)
 * @param dat 发送的数据
 * @param bytes 一个数据的字节数
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
        else if(port == '3')
        {
            Simu_TXD((uint8)(dat & 0xFF));
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
 * @brief 发送字符串
 * 
 * @param s 字符串地址
 * @param port 串口端口端口
 */
void SendString(uint8 port,uint8 *s)
{
	while(*s)
	{
		SendnBytes(port,'8',*s++,1);
	}
}

/**
 * @brief 发送数字
 * 
 * @param Num 输入数字
 * @param port 串口端口
 */
void SendNum_Ascllc(uint8 port,float Num)
{
    xdata uint8 str[12];
    sprintf(str,"%f",Num);
    SendString(port,str);
}
