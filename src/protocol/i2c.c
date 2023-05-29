#include"serialport.h"
#include"ioset.h"
#include"delay.h"

/**
 * @brief IIC��ʼ�ź�
 * 
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱʱ��(΢��)
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
 * @brief IICֹͣ�ź�
 * 
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱʱ��(΢��)
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
 * @brief IICӦ���ź�
 * 
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱʱ��(΢��)
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
            SendString('1',"Error:IIC NACK\n");//���������Ϣ
            SendString('1',"Failed to call\n");
            break;            
        }
    }

    SetIO_Sta(SCL_io,0);
    Delay_us(delay);
}

/**
 * @brief IIC��Ӧ���ź�
 * 
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱʱ��(΢��)
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
 * @brief IIC��ȡһ���ֽ�
 * 
 * @param dat ����
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱʱ��(΢��)
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
 * @brief IIC��ȡһ���ֽ�
 * 
 * @param SDA_io SDA���
 * @param SCL_io SCL���
 * @param delay ��ʱ(΢��)
 * @return uint8 ����ֵ
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