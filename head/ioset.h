#ifndef __GETIO_H__
#define __GETIO_H__

#include"typedefine.h"


int8 GetIO_Sta(uint8 io);
int8 GetIO_Model(uint8 io);
int8 SetIO_Sta(uint8 io,bit status);
int8 SetIO_Model(uint8 io,uint8 model);
int8 SetIOs_Model(uint8 bitPort,uint8 M1,uint8 M0);


#endif // !


