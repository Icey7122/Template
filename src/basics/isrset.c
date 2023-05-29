#include<STC12C5A60S2.H>
#include"typedefine.h"


/**
 * @brief 设置中断优先级
 * @brief 在同一优先级的中断,按查询次序0-9,且中断一旦进入,就无法被同一\
 * @brief 优先级的中断打断,但可以被更高优先级的中断打断
 * @param isr 选择中断(0-9)
 * @param priority 设置优先级(0:优先级0(最低);1:优先级1;2:优先级2;3:优先级3(最高))
 */
void ISRp_Set(uint8 isr,uint8 priority)
{
    bit H,L;
    H = (priority & 0x02) >> 1;
    L = priority & 0x01;
    switch (isr)
    {
        case 0:if(H){IPH |= 1<<0;}else{IPH &= ~(1<<0);}if(L){PX0 = 1;}else{PX0 = 0;}break;                //设置外部中断0优先级
        case 1:if(H){IPH |= 1<<1;}else{IPH &= ~(1<<1);}if(L){PT0 = 1;}else{PT0 = 0;}break;                //设置定时器0中断优先级
        case 2:if(H){IPH |= 1<<2;}else{IPH &= ~(1<<2);}if(L){PX1 = 1;}else{PX1 = 0;}break;                //设置外部中断1优先级
        case 3:if(H){IPH |= 1<<3;}else{IPH &= ~(1<<3);}if(L){PT1 = 1;}else{PT1 = 0;}break;                //设置定时器1中断优先级
        case 4:if(H){IPH |= 1<<4;}else{IPH &= ~(1<<4);}if(L){PS = 1;}else{PS = 0;}break;                  //设置串口1中断优先级
        case 5:if(H){IPH |= 1<<5;}else{IPH &= ~(1<<5);}if(L){PADC = 1;}else{PADC = 0;}break;              //设置ADC中断优先级
        case 6:if(H){IPH |= 1<<6;}else{IPH &= ~(1<<6);}if(L){PLVD = 1;}else{PLVD = 0;}break;              //设置低压检测中断优先级
        case 7:if(H){IPH |= 1<<7;}else{IPH &= ~(1<<7);}if(L){PPCA = 1;}else{PPCA = 0;}break;              //设置PCA中断优先级
        case 8:if(H){IPH2 |= 1<<0;}else{IPH2 &= ~(1<<0);}if(L){IP2 |= 1<<0;}else{IP2 &= ~(1<<0);}break;   //设置串口2中断优先级
        case 9:if(H){IPH2 |= 1<<1;}else{IPH2 &= ~(1<<1);}if(L){IP2 |= 1<<1;}else{IP2 &= ~(1<<1);}break;   //设置SPI中断优先级

        default:break;
    }
}

/**
 * @brief 开启中断
 * 
 * @param isr 中断选择(10:中断总开关)
 * @param status 中断状态(PCA中断有3个中断源:CF,CCF0,CCF1.
 * status 0:CF(PCA/PWM时钟溢出中断)关闭 status 1:开启CF中断 
 * status 2:CCF0(捕获或匹配中断)关闭 status 3:开启CCF0中断
 * status 4:CCF1(捕获或匹配中断)关闭 status 5:开启CCF1中断)
 * 
 * status 0-5仅对PCA有精确控制,其他中断只有开启和关闭两种状态
 */
void ISR_Sw(uint8 isr,uint8 status)
{
    switch(isr)
    {
        case 0:if(status){EX0 = 1;}else{EX0 = 0;}break;         //外部中断0
        case 1:if(status){ET0 = 1;}else{ET0 = 0;}break;         //定时器0中断
        case 2:if(status){EX1 = 1;}else{EX1 = 0;}break;         //外部中断1
        case 3:if(status){ET1 = 1;}else{ET1 = 0;}break;         //定时器1中断
        case 4:if(status){ES = 1;}else{ES = 0;}break;           //串口中断
        case 5:if(status){EADC = 1;}else{EADC = 0;}break;       //ADC中断
        case 6:if(status){ELVD = 1;}else{ELVD = 0;}break;       //低压检测中断
        case 7:switch(status){case 0:CMOD &= 0xFE;break;        //PCA中断
                              case 1:CMOD |= 0x01;break;
                              case 2:CCF0 = 0;break;
                              case 3:CCF0 = 1;break;
                              case 4:CCF1 = 0;break;
                              case 5:CCF1 = 1;break;
                              default:break;}break;
        case 8:if(status){IE2 |= 0x01;}else{IE2 &= 0xFE;}break; //串口2中断
        case 9:if(status){IE2 |= 0x02;}else{IE2 &= 0xFD;}break; //SPI中断
        case 10:if(status){EA = 1;}else{EA = 0;}break;          //总中断
        default:break;
    }
}

/**
 * @brief 外部中断0初始化
 * 
 */
void ExterInterruptInit0(void)   
{
	EX0 = 1;	//打开中断0
	IT0 = 1;	//设置方式为下行中断
}

/**
 * @brief 外部中断1初始化
 * 
 */
void ExterInterruptInit1(void)
{
	EX1 = 1;	//打开中断1
	IT1 = 1;	//设置方式为下行中断
}