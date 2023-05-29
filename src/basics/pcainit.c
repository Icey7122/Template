#include<STC12C5A60S2.H>
#include"typedefine.h"


void PCAInit0(void)
{
    CMOD = 0x81;            //空闲状态下继续工作,SYSclk/12,允许中断
    CCON = 0x40;            //启动PCA0定时器
    CCAPM0 = 0x39;          //16位捕获模式,启用中断CCF0
    CCAP0L = 0;             //初始化PCA计数寄存器
    CCAP0H = 0;             //初始化PCA计数寄存器
    CL = 0;                 //清零PCA计数器
    CH = 0;                 //清零PCA计数器

    EA = 1;                 //开总中断
}

void PCAInit1(void)
{
    CMOD = 0x81;            //空闲状态下继续工作,针脚输出外部时钟,禁止中断
    CCON = 0x40;            //启动PCA定时器
    CCAPM1 = 0x39;          //16位捕获模式,启用中断CCF1
    CCAP1L = 0;             //初始化PCA计数寄存器
    CCAP1H = 0;             //初始化PCA计数寄存器
    CL = 0;                 //清零PCA计数器
    CH = 0;                 //清零PCA计数器

    EA = 1;                 //开总中断
}


