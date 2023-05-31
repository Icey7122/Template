#ifndef __EEPROM_H__
#define __EEPROM_H__

#include"typedefine.h"


void EEPR_WriteCs(uint8 *p,uint8 start,uint8 SDA_io,uint8 SCL_io,uint8 delay);
void EEPR_ReadCs(uint8 startread,uint8 longth,uint8 SDA_io,uint8 SCL_io,uint8 delay);

#endif // !


