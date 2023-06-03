#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#include"typedefine.h"


void Uartprot1Init(uint16 rate,uint8 uart,uint8 T,bit indrate,bit isr);
void Uartprot2Init(uint16 rate,uint8 uart,uint8 T,bit isr);
void UartprotSimuInit(uint8 io,bit timer,uint16 rate);
void ChgSumi_Port(uint8 io);
void Simu_TXD(uint8 dat);
void SendnBytes(uint8 port,uint8 uart,uint32 dat,uint8 bytes);
void SendString(uint8 port,uint8 *s);
void SendNum_Ascllc(uint8 port,float Num);

#endif // !


