#ifndef __I2C_H__
#define __I2C_H__

#include"typedefine.h"


void IIC_Start(uint8 SDA_io,uint8 SCL_io,uint8 delay);
void IIC_Stop(uint8 SDA_io,uint8 SCL_io,uint8 delay);
void IIC_Ack(uint8 SDA_io,uint8 SCL_io,uint8 delay);
void IIC_NAck(uint8 SDA_io,uint8 SCL_io,uint8 delay);
void IIC_Write(uint8 dat,uint8 SDA_io,uint8 SCL_io,uint8 delay);
uint8 IIC_Read(uint8 SDA_io,uint8 SCL_io,uint8 delay);


#endif // !


