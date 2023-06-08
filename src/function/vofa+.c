#include"serialport.h"
#include"intFlt.h"

/**
 * @brief 发送浮点数
 * 
 * @param port 选择串口
 * @param Flt 浮点数
 */
void VofaSendFloat(uint8 port,flt32 Flt)
{
    union uintFloat VofaFlt;
    VofaFlt.Flt = Flt;
    SendnBytes(port,'8',VofaFlt.uintFlt,4);
    SendnBytes(port,'8',TAIL,4);
}