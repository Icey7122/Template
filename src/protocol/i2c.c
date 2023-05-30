#include"serialport.h"
#include"ioset.h"
#include"delay.h"

/**
 * @brief IIC开始信号
 * 
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时时间(微秒)
 */
void IIC_Start(uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    SetIO_Sta(SDA_io,1);
    Delay_us(delay);

    SetIO_Sta(SCL_io,1);
    Delay_us(delay);

    SetIO_Sta(SDA_io,0);
    Delay_us(delay);

    SetIO_Sta(SCL_io,0);
    Delay_us(delay);
}

/**
 * @brief IIC停止信号
 * 
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时时间(微秒)
 */
void IIC_Stop(uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    SetIO_Sta(SDA_io,0);
    Delay_us(delay);

    SetIO_Sta(SCL_io,1);
    Delay_us(delay);

    SetIO_Sta(SDA_io,1);
    Delay_us(delay);
}

/**
 * @brief IIC应答信号
 * 
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时时间(微秒)
 */
void IIC_Ack(uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    uint8 ErrTime = 0;

    SetIO_Sta(SDA_io,1);
    Delay_us(delay);
    SetIO_Sta(SCL_io,1);
    Delay_us(delay);

    while(GetIO_Sta(SDA_io))
    {
        ErrTime++;
        if(ErrTime > 200)
        {
            IIC_Stop(SDA_io,SCL_io,delay);
            SendString('1',"Error:IIC NACK\n");//输出错误信息
            SendString('1',"Failed to call\n");
            break;            
        }
    }

    SetIO_Sta(SCL_io,0);
    Delay_us(delay);
}

/**
 * @brief IIC不应答信号
 * 
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时时间(微秒)
 */
void IIC_NAck(uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    SetIO_Sta(SDA_io,1);
    Delay_us(delay);
    SetIO_Sta(SCL_io,1);
    Delay_us(delay);
    SetIO_Sta(SCL_io,0);
    Delay_us(delay);
}

/**
 * @brief IIC读取一个字节
 * 
 * @param dat 数据
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时时间(微秒)
 */
void IIC_Write(uint8 dat,uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    uint8 i;

    SetIO_Sta(SCL_io,0);
    Delay_us(delay);

    for(i = 0;i < 8; i++)
    {
        SetIO_Sta(SDA_io,dat>>7);
        Delay_us(delay);
        dat <<= 1;

        SetIO_Sta(SCL_io,1);
        Delay_us(delay);
        SetIO_Sta(SCL_io,0);
        Delay_us(delay);
    }

    IIC_Ack(SDA_io,SCL_io,delay);
}

/**
 * @brief IIC读取一个字节
 * 
 * @param SDA_io SDA针脚
 * @param SCL_io SCL针脚
 * @param delay 延时(微秒)
 * @return uint8 返回值
 */
uint8 IIC_Read(uint8 SDA_io,uint8 SCL_io,uint8 delay)
{
    uint8 i;
    uint8 dat = 0;

    SetIO_Sta(SCL_io,0);
    Delay_us(delay);

    for(i = 0;i < 8; i++)
    {
        SetIO_Sta(SCL_io,1);
        Delay_us(delay);
        dat <<= 1;
        dat |= GetIO_Sta(SDA_io);
        SetIO_Sta(SCL_io,0);
        Delay_us(delay);
    }

    IIC_NAck(SDA_io,SCL_io,delay);

    return dat;
}