#ifndef __INTFLT__
#define __INTFLT__

#include"typedefine.h"


#define TAIL 0x807F         //尾部标志

union uintFloat
{
    flt32 Flt;
    uint32 uintFlt;
};   


void VofaSendFloat(uint8 port,flt32 Flt);   //发送浮点数

#endif // !__INTFLT__
