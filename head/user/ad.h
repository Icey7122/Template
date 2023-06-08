#ifndef __ADCMD_H__
#define __ADCMD_H__

#include"typedefine.h"

/*  AD转换命令  */

#define AIN0_X6_XP_8 0x9C   //滑动电阻X6
#define AIN1_Y7_YP_8 0xDC   //热敏电阻Y7
#define AIN2_VBAT_8 0xAC    //光敏电阻
#define AIN3_AUX_8 0xEC

#define AIN0_X6_XP_12 0x94  //滑动电阻X6
#define AIN1_Y7_YP_12 0xD4  //热敏电阻Y7
#define AIN2_VBAT_12 0xA4   //光敏电阻
#define AIN3_AUX_12 0xE4

uint16 ADtrans(uint8 cmd);

#endif // !




