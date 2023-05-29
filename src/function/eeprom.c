#include"serialport.h"
#include"delay.h"
#include"i2c.h"


#define ADDRESS_WRITE 0xA0
#define ADDRESS_READ 0xA1

/**
 * @brief 写入字符串到eeprom
 * 
 * @param p 字符串指针
 * @param start 起始地址
 * @param SDA_io SDA引脚
 * @param SCL_io SCL引脚
 * @param delay 延时
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
 * @brief 读取eeprom中的字符串
 * 
 * @param startread 起始地址
 * @param longth 读取长度
 * @param SDA_io SDA引脚
 * @param SCL_io SCL引脚
 * @param delay 延时
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