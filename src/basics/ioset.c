#include<STC12C5A60S2.H>
#include<STDIO.H>
#include"typedefine.h"


/**
 * @brief 获得I/O状态
 * 
 * @param io 选择I/O口
 * @return int8 返回设置信息值(失败:-1)
 */
int8 GetIO_Sta(uint8 io)
{
    switch(io)
    {
        case 00:return P00;
        case 01:return P01;
        case 02:return P02;
        case 03:return P03;
        case 04:return P04;
        case 05:return P05;
        case 06:return P06;
        case 07:return P07;
        case 10:return P10;
        case 11:return P11;
        case 12:return P12;
        case 13:return P13;
        case 14:return P14;
        case 15:return P15;
        case 16:return P16;
        case 17:return P17;
        case 20:return P20;
        case 21:return P21;
        case 22:return P22;
        case 23:return P23;
        case 24:return P24;
        case 25:return P25;
        case 26:return P26;
        case 27:return P27;
        case 30:return P30;
        case 31:return P31;
        case 32:return P32;
        case 33:return P33;
        case 34:return P34;
        case 35:return P35;
        case 36:return P36;
        case 37:return P37;
        case 40:return P40;
        case 41:return P41;
        case 42:return P42;
        case 43:return P43;
        case 44:return P44;
        case 45:return P45;
        case 46:return P46;
        case 47:return P47;
        case 50:return P50;
        case 51:return P51;
        case 52:return P52;
        case 53:return P53;

        default:return EOF;
    }
}

/**
 * @brief 设置I/O状态
 * 
 * @param io I/O口
 * @return int8 返回当前模式(失败:-1)
 */
int8 GetIO_Model(uint8 io)
{
    uint8 M1 = 0,M0 = 0;
    switch (io)
    {
        case 00:M1=(P0M1 & 0x01)>>0;M0=(P0M0 & 0x01)>>0;break;
        case 01:M1=(P0M1 & 0x02)>>1;M0=(P0M0 & 0x02)>>1;break;
        case 02:M1=(P0M1 & 0x04)>>2;M0=(P0M0 & 0x04)>>2;break;
        case 03:M1=(P0M1 & 0x08)>>3;M0=(P0M0 & 0x08)>>3;break;
        case 04:M1=(P0M1 & 0x10)>>4;M0=(P0M0 & 0x10)>>4;break;
        case 05:M1=(P0M1 & 0x20)>>5;M0=(P0M0 & 0x20)>>5;break;
        case 06:M1=(P0M1 & 0x40)>>6;M0=(P0M0 & 0x40)>>6;break;
        case 07:M1=(P0M1 & 0x80)>>7;M0=(P0M0 & 0x80)>>7;break;
        case 10:M1=(P1M1 & 0x01)>>0;M0=(P1M0 & 0x01)>>0;break;
        case 11:M1=(P1M1 & 0x02)>>1;M0=(P1M0 & 0x02)>>1;break;
        case 12:M1=(P1M1 & 0x04)>>2;M0=(P1M0 & 0x04)>>2;break;
        case 13:M1=(P1M1 & 0x08)>>3;M0=(P1M0 & 0x08)>>3;break;
        case 14:M1=(P1M1 & 0x10)>>4;M0=(P1M0 & 0x10)>>4;break;
        case 15:M1=(P1M1 & 0x20)>>5;M0=(P1M0 & 0x20)>>5;break;
        case 16:M1=(P1M1 & 0x40)>>6;M0=(P1M0 & 0x40)>>6;break;
        case 17:M1=(P1M1 & 0x80)>>7;M0=(P1M0 & 0x80)>>7;break;
        case 20:M1=(P2M1 & 0x01)>>0;M0=(P2M0 & 0x01)>>0;break;
        case 21:M1=(P2M1 & 0x02)>>1;M0=(P2M0 & 0x02)>>1;break;
        case 22:M1=(P2M1 & 0x04)>>2;M0=(P2M0 & 0x04)>>2;break;
        case 23:M1=(P2M1 & 0x08)>>3;M0=(P2M0 & 0x08)>>3;break;
        case 24:M1=(P2M1 & 0x10)>>4;M0=(P2M0 & 0x10)>>4;break;
        case 25:M1=(P2M1 & 0x20)>>5;M0=(P2M0 & 0x20)>>5;break;
        case 26:M1=(P2M1 & 0x40)>>6;M0=(P2M0 & 0x40)>>6;break;
        case 27:M1=(P2M1 & 0x80)>>7;M0=(P2M0 & 0x80)>>7;break;
        case 30:M1=(P3M1 & 0x01)>>0;M0=(P3M0 & 0x01)>>0;break;
        case 31:M1=(P3M1 & 0x02)>>1;M0=(P3M0 & 0x02)>>1;break;
        case 32:M1=(P3M1 & 0x04)>>2;M0=(P3M0 & 0x04)>>2;break;
        case 33:M1=(P3M1 & 0x08)>>3;M0=(P3M0 & 0x08)>>3;break;
        case 34:M1=(P3M1 & 0x10)>>4;M0=(P3M0 & 0x10)>>4;break;
        case 35:M1=(P3M1 & 0x20)>>5;M0=(P3M0 & 0x20)>>5;break;
        case 36:M1=(P3M1 & 0x40)>>6;M0=(P3M0 & 0x40)>>6;break;
        case 37:M1=(P3M1 & 0x80)>>7;M0=(P3M0 & 0x80)>>7;break;
        case 40:M1=(P4M1 & 0x01)>>0;M0=(P4M0 & 0x01)>>0;break;
        case 41:M1=(P4M1 & 0x02)>>1;M0=(P4M0 & 0x02)>>1;break;
        case 42:M1=(P4M1 & 0x04)>>2;M0=(P4M0 & 0x04)>>2;break;
        case 43:M1=(P4M1 & 0x08)>>3;M0=(P4M0 & 0x08)>>3;break;
        case 44:M1=(P4M1 & 0x10)>>4;M0=(P4M0 & 0x10)>>4;break;
        case 45:M1=(P4M1 & 0x20)>>5;M0=(P4M0 & 0x20)>>5;break;
        case 46:M1=(P4M1 & 0x40)>>6;M0=(P4M0 & 0x40)>>6;break;
        case 47:M1=(P4M1 & 0x80)>>7;M0=(P4M0 & 0x80)>>7;break;
        case 50:M1=(P5M1 & 0x01)>>0;M0=(P5M0 & 0x01)>>0;break;
        case 51:M1=(P5M1 & 0x02)>>1;M0=(P5M0 & 0x02)>>1;break;
        case 52:M1=(P5M1 & 0x04)>>2;M0=(P5M0 & 0x04)>>2;break;
        case 53:M1=(P5M1 & 0x08)>>3;M0=(P5M0 & 0x08)>>3;break;

        default:return EOF;
    }

    return (M1<<1)|M0;
}

/**
 * @brief 设置I/O状态
 * 
 * @param io I/O口
 * @param status 设置状态
 * @return int8 返回设置后的状态(失败:-1)
 */
int8 SetIO_Sta(uint8 io,bit status)
{
    switch (io)
    {
        case 00:P00 = status;break;
        case 01:P01 = status;break;
        case 02:P02 = status;break;
        case 03:P03 = status;break;
        case 04:P04 = status;break;
        case 05:P05 = status;break;
        case 06:P06 = status;break;
        case 07:P07 = status;break;
        case 10:P10 = status;break;
        case 11:P11 = status;break;
        case 12:P12 = status;break;
        case 13:P13 = status;break;
        case 14:P14 = status;break;
        case 15:P15 = status;break;
        case 16:P16 = status;break;
        case 17:P17 = status;break;
        case 20:P20 = status;break;
        case 21:P21 = status;break;
        case 22:P22 = status;break;
        case 23:P23 = status;break;
        case 24:P24 = status;break;
        case 25:P25 = status;break;
        case 26:P26 = status;break;
        case 27:P27 = status;break;
        case 30:P30 = status;break;
        case 31:P31 = status;break;
        case 32:P32 = status;break;
        case 33:P33 = status;break;
        case 34:P34 = status;break;
        case 35:P35 = status;break;
        case 36:P36 = status;break;
        case 37:P37 = status;break;
        case 40:P40 = status;break;
        case 41:P41 = status;break;
        case 42:P42 = status;break;
        case 43:P43 = status;break;
        case 44:P44 = status;break;
        case 45:P45 = status;break;
        case 46:P46 = status;break;
        case 47:P47 = status;break;
        case 50:P50 = status;break;
        case 51:P51 = status;break;
        case 52:P52 = status;break;
        case 53:P53 = status;break;

        default:return EOF;
    }

    return GetIO_Sta(io);
}

/**
 * @brief 单个I/O设置
 * 
 * @param io 选择I/O
 * @param model 选择模式(0:准双向口,1:强推挽输出,2:高阻输入,3:开漏(P1口具有A/D功能)
 * @return int8 返回设置后的状态(失败:-1)
 */
int8 SetIO_Model(uint8 io,uint8 model)
{
    bit M1 = (model & 0x02) >> 1;
    bit M0 = model & 0x01;
    switch (io)
    {
        case 00:if(M1){P0M1 |= 1<<0;}else{P0M1 &= ~(1<<0);}if(M0){P0M0 |= 1<<0;}else{P0M0 &= ~(1<<0);}break;
        case 01:if(M1){P0M1 |= 1<<1;}else{P0M1 &= ~(1<<1);}if(M0){P0M0 |= 1<<1;}else{P0M0 &= ~(1<<1);}break;
        case 02:if(M1){P0M1 |= 1<<2;}else{P0M1 &= ~(1<<2);}if(M0){P0M0 |= 1<<2;}else{P0M0 &= ~(1<<2);}break;
        case 03:if(M1){P0M1 |= 1<<3;}else{P0M1 &= ~(1<<3);}if(M0){P0M0 |= 1<<3;}else{P0M0 &= ~(1<<3);}break;
        case 04:if(M1){P0M1 |= 1<<4;}else{P0M1 &= ~(1<<4);}if(M0){P0M0 |= 1<<4;}else{P0M0 &= ~(1<<4);}break;
        case 05:if(M1){P0M1 |= 1<<5;}else{P0M1 &= ~(1<<5);}if(M0){P0M0 |= 1<<5;}else{P0M0 &= ~(1<<5);}break;
        case 06:if(M1){P0M1 |= 1<<6;}else{P0M1 &= ~(1<<6);}if(M0){P0M0 |= 1<<6;}else{P0M0 &= ~(1<<6);}break;
        case 07:if(M1){P0M1 |= 1<<7;}else{P0M1 &= ~(1<<7);}if(M0){P0M0 |= 1<<7;}else{P0M0 &= ~(1<<7);}break;
        case 10:if(M1){P1M1 |= 1<<0;}else{P1M1 &= ~(1<<0);}if(M0){P1M0 |= 1<<0;}else{P1M0 &= ~(1<<0);}break;
        case 11:if(M1){P1M1 |= 1<<1;}else{P1M1 &= ~(1<<1);}if(M0){P1M0 |= 1<<1;}else{P1M0 &= ~(1<<1);}break;
        case 12:if(M1){P1M1 |= 1<<2;}else{P1M1 &= ~(1<<2);}if(M0){P1M0 |= 1<<2;}else{P1M0 &= ~(1<<2);}break;
        case 13:if(M1){P1M1 |= 1<<3;}else{P1M1 &= ~(1<<3);}if(M0){P1M0 |= 1<<3;}else{P1M0 &= ~(1<<3);}break;
        case 14:if(M1){P1M1 |= 1<<4;}else{P1M1 &= ~(1<<4);}if(M0){P1M0 |= 1<<4;}else{P1M0 &= ~(1<<4);}break;
        case 15:if(M1){P1M1 |= 1<<5;}else{P1M1 &= ~(1<<5);}if(M0){P1M0 |= 1<<5;}else{P1M0 &= ~(1<<5);}break;
        case 16:if(M1){P1M1 |= 1<<6;}else{P1M1 &= ~(1<<6);}if(M0){P1M0 |= 1<<6;}else{P1M0 &= ~(1<<6);}break;
        case 17:if(M1){P1M1 |= 1<<7;}else{P1M1 &= ~(1<<7);}if(M0){P1M0 |= 1<<7;}else{P1M0 &= ~(1<<7);}break;
        case 20:if(M1){P2M1 |= 1<<0;}else{P2M1 &= ~(1<<0);}if(M0){P2M0 |= 1<<0;}else{P2M0 &= ~(1<<0);}break;
        case 21:if(M1){P2M1 |= 1<<1;}else{P2M1 &= ~(1<<1);}if(M0){P2M0 |= 1<<1;}else{P2M0 &= ~(1<<1);}break;
        case 22:if(M1){P2M1 |= 1<<2;}else{P2M1 &= ~(1<<2);}if(M0){P2M0 |= 1<<2;}else{P2M0 &= ~(1<<2);}break;
        case 23:if(M1){P2M1 |= 1<<3;}else{P2M1 &= ~(1<<3);}if(M0){P2M0 |= 1<<3;}else{P2M0 &= ~(1<<3);}break;
        case 24:if(M1){P2M1 |= 1<<4;}else{P2M1 &= ~(1<<4);}if(M0){P2M0 |= 1<<4;}else{P2M0 &= ~(1<<4);}break;
        case 25:if(M1){P2M1 |= 1<<5;}else{P2M1 &= ~(1<<5);}if(M0){P2M0 |= 1<<5;}else{P2M0 &= ~(1<<5);}break;
        case 26:if(M1){P2M1 |= 1<<6;}else{P2M1 &= ~(1<<6);}if(M0){P2M0 |= 1<<6;}else{P2M0 &= ~(1<<6);}break;
        case 27:if(M1){P2M1 |= 1<<7;}else{P2M1 &= ~(1<<7);}if(M0){P2M0 |= 1<<7;}else{P2M0 &= ~(1<<7);}break;
        case 30:if(M1){P3M1 |= 1<<0;}else{P3M1 &= ~(1<<0);}if(M0){P3M0 |= 1<<0;}else{P3M0 &= ~(1<<0);}break;
        case 31:if(M1){P3M1 |= 1<<1;}else{P3M1 &= ~(1<<1);}if(M0){P3M0 |= 1<<1;}else{P3M0 &= ~(1<<1);}break;
        case 32:if(M1){P3M1 |= 1<<2;}else{P3M1 &= ~(1<<2);}if(M0){P3M0 |= 1<<2;}else{P3M0 &= ~(1<<2);}break;
        case 33:if(M1){P3M1 |= 1<<3;}else{P3M1 &= ~(1<<3);}if(M0){P3M0 |= 1<<3;}else{P3M0 &= ~(1<<3);}break;
        case 34:if(M1){P3M1 |= 1<<4;}else{P3M1 &= ~(1<<4);}if(M0){P3M0 |= 1<<4;}else{P3M0 &= ~(1<<4);}break;
        case 35:if(M1){P3M1 |= 1<<5;}else{P3M1 &= ~(1<<5);}if(M0){P3M0 |= 1<<5;}else{P3M0 &= ~(1<<5);}break;
        case 36:if(M1){P3M1 |= 1<<6;}else{P3M1 &= ~(1<<6);}if(M0){P3M0 |= 1<<6;}else{P3M0 &= ~(1<<6);}break;
        case 37:if(M1){P3M1 |= 1<<7;}else{P3M1 &= ~(1<<7);}if(M0){P3M0 |= 1<<7;}else{P3M0 &= ~(1<<7);}break;
        case 40:if(M1){P4M1 |= 1<<0;}else{P4M1 &= ~(1<<0);}if(M0){P4M0 |= 1<<0;}else{P4M0 &= ~(1<<0);}break;
        case 41:if(M1){P4M1 |= 1<<1;}else{P4M1 &= ~(1<<1);}if(M0){P4M0 |= 1<<1;}else{P4M0 &= ~(1<<1);}break;
        case 42:if(M1){P4M1 |= 1<<2;}else{P4M1 &= ~(1<<2);}if(M0){P4M0 |= 1<<2;}else{P4M0 &= ~(1<<2);}break;
        case 43:if(M1){P4M1 |= 1<<3;}else{P4M1 &= ~(1<<3);}if(M0){P4M0 |= 1<<3;}else{P4M0 &= ~(1<<3);}break;
        case 44:if(M1){P4M1 |= 1<<4;}else{P4M1 &= ~(1<<4);}if(M0){P4M0 |= 1<<4;}else{P4M0 &= ~(1<<4);}break;
        case 45:if(M1){P4M1 |= 1<<5;}else{P4M1 &= ~(1<<5);}if(M0){P4M0 |= 1<<5;}else{P4M0 &= ~(1<<5);}break;
        case 46:if(M1){P4M1 |= 1<<6;}else{P4M1 &= ~(1<<6);}if(M0){P4M0 |= 1<<6;}else{P4M0 &= ~(1<<6);}break;
        case 47:if(M1){P4M1 |= 1<<7;}else{P4M1 &= ~(1<<7);}if(M0){P4M0 |= 1<<7;}else{P4M0 &= ~(1<<7);}break;
        case 50:if(M1){P5M1 |= 1<<0;}else{P5M1 &= ~(1<<0);}if(M0){P5M0 |= 1<<0;}else{P5M0 &= ~(1<<0);}break;
        case 51:if(M1){P5M1 |= 1<<1;}else{P5M1 &= ~(1<<1);}if(M0){P5M0 |= 1<<1;}else{P5M0 &= ~(1<<1);}break;
        case 52:if(M1){P5M1 |= 1<<2;}else{P5M1 &= ~(1<<2);}if(M0){P5M0 |= 1<<2;}else{P5M0 &= ~(1<<2);}break;
        case 53:if(M1){P5M1 |= 1<<3;}else{P5M1 &= ~(1<<3);}if(M0){P5M0 |= 1<<3;}else{P5M0 &= ~(1<<3);}break;
    
        default:return EOF;
    }

    return GetIO_Model(io);
}

/**
 * @brief 设置整个I/O状态
 * PnM1:1100,0000
 * PnM0:1010,0000
 * Pn.7:开漏输出,Pn.6:高阻输入,Pn.5:强推挽输出,Pn.4:准双向口
 * 
 * @param bitPort 总端口位置
 * @param M1 寄存器PnM1的值
 * @param M0 寄存器PnM0的值
 * @return int8 返回设置后的状态(失败:-1)
 */
int8 SetIOs_Model(uint8 bitPort,uint8 M1,uint8 M0)
{
    switch(bitPort)
    {
        case 0:P0M1 = M1;P0M0 = M0;return 1;
        case 1:P1M1 = M1;P1M0 = M0;return 1;
        case 2:P2M1 = M1;P2M0 = M0;return 1;
        case 3:P3M1 = M1;P3M0 = M0;return 1;
        case 4:P4M1 = M1;P4M0 = M0;return 1;
        case 5:P5M1 = M1;P5M0 = M0;return 1;

        default:return EOF;
    }
}

