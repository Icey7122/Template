#include<STC12C5A60S2.H>
#include"typedefine.h"
#include"ioset.h"


#define AD_DIN 34
#define AD_CS 35
#define AD_DCLK 36
#define AD_DOUT 37

/**
 * @brief AD转换函数
 * 
 * @param cmd 输入命令
 * @return uint16 返回数据
 */
uint16 ADtrans(uint8 cmd)
{
    uint8 i;
    uint16 dat = 0;

    SetIO_Sta(AD_CS,0);
    SetIO_Sta(AD_DCLK,0);

    for(i = 0;i < 8;i++)
    {
        SetIO_Sta(AD_DIN,cmd >> 7); 
        cmd <<= 1;
        SetIO_Sta(AD_DCLK,1);
        SetIO_Sta(AD_DCLK,0);
    }

    SetIO_Sta(AD_DCLK,1);
    SetIO_Sta(AD_DCLK,0);

    for(i=0;i < 16;i++)
    {        
        SetIO_Sta(AD_DCLK,1);
        SetIO_Sta(AD_DCLK,0);
        dat <<= 1;
        dat |= GetIO_Sta(AD_DOUT);
    }

    SetIO_Sta(AD_CS,1);

    return dat;
}
