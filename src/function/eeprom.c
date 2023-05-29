#include"serialport.h"
#include"delay.h"
#include"i2c.h"


#define ADDRESS_WRITE 0xA0
#define ADDRESS_READ 0xA1

/**
 * @brief д���ַ�����eeprom
 * 
 * @param p �ַ���ָ��
 * @param start ��ʼ��ַ
 * @param SDA_io SDA����
 * @param SCL_io SCL����
 * @param delay ��ʱ
 */
void EEPR_WriteCs(uint8 *p,uint8 start,uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    uint8 i = 0;
    while(*p != '\0')
    {
        IIC_Start(SDA_io,SCL_io,delay);
        IIC_Write(ADDRESS_WRITE,SDA_io,SCL_io,delay);
        IIC_Write(start+i,SDA_io,SCL_io,delay);
        IIC_Write(*p++,SDA_io,SCL_io,delay);
        IIC_Stop(SDA_io,SCL_io,delay);
        i++;
        Delay_ms(10);
    }

    
}

/**
 * @brief ��ȡeeprom�е��ַ���
 * 
 * @param startread ��ʼ��ַ
 * @param longth ��ȡ����
 * @param SDA_io SDA����
 * @param SCL_io SCL����
 * @param delay ��ʱ
 */
void EEPR_ReadCs(uint8 startread,uint8 longth,uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    uint8 p = startread,x = 0;
    
    IIC_Start(SDA_io,SCL_io,delay);
    IIC_Write(ADDRESS_WRITE,SDA_io,SCL_io,delay);
    IIC_Write(startread,SDA_io,SCL_io,delay);

    for(;p < (longth+startread); p++)
    {
        IIC_Start(SDA_io,SCL_io,delay);
        IIC_Write(ADDRESS_READ,SDA_io,SCL_io,delay);
        SendnBytes('1','8',IIC_Read(SDA_io,SCL_io,delay),1);
        IIC_Stop(SDA_io,SCL_io,delay);
    }

    SendString('1',"\n");
    
}