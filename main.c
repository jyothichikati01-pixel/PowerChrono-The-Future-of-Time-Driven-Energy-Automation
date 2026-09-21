#include<lpc21xx.h>
#include "lcd.h"
#include "lcd_defines.h"
#include "types.h"
#include "pin_function_defines.h"
#include "pin_connect_block.h"
#include "rtc.h"
#include "kpm.h"
#include "delay.h"
#include"defines.h"
#include "set_time.c"
#define LED 30
#define SW 5
#define EINT0_VIC_CHNO 14
#define EINT0_STATUS_LED 16
u8 cgramLUT1[16]={0x0E,0X1F,0X1F,0X1F,0X1F,0X0E,0X0A,0X0A,0x0E,0X11,0X11,0X11,0X1F,0X0E,0X0A,0X0A};
u32 hour,min,sec,on_hour,on_min,on_sec,off_hour,off_min,off_sec,date,month,year,day;
extern u32 flag;
void eint0_isr(void)__irq;
void edit_RTC_SET_TIME(void);
void edit_device_set_time(void);
void Init_interrupt(void);
void set_time(void);
int main()
{
IODIR1|=1<<LED;
InitLCD();
Init_KPM();
RTC_Init();
Init_interrupt();
while(1)
{
   GetRTCTimeInfo(&hour,&min,&sec);
   DisplayRTCTime(hour,min,sec);
   GetRTCDay(&day);
   DisplayRTCDay(day);
   GetRTCDateInfo(&date,&month,&year);
   DisplayRTCDate(date,month,year);
   if(READBIT(IOPIN0,SW)==0)
   {
   CmdLCD(CLEAR_LCD);
   CmdLCD(GOTO_LINE1_POS0);
   StrLCD("OT:");
   CmdLCD(GOTO_LINE1_POS0+4);
   U32LCD(on_hour);
   CmdLCD(GOTO_LINE1_POS0+6);
   CharLCD(':');
   CmdLCD(GOTO_LINE1_POS0+7);
   U32LCD(on_min);
   CmdLCD(GOTO_LINE1_POS0+9);
   CharLCD(':');
   CmdLCD(GOTO_LINE1_POS0+11);
   U32LCD(on_sec);

   CmdLCD(GOTO_LINE2_POS0);
   StrLCD("OF:");
   CmdLCD(GOTO_LINE2_POS0+4);
   U32LCD(off_hour);
   CmdLCD(GOTO_LINE2_POS0+6);
   CharLCD(':');
   CmdLCD(GOTO_LINE2_POS0+7);
   U32LCD(off_min);
   CmdLCD(GOTO_LINE2_POS0+9);
   CharLCD(':');
   CmdLCD(GOTO_LINE2_POS0+11);
   U32LCD(off_sec);
   delay_s(1);
   CmdLCD(CLEAR_LCD);
   while(READBIT(IOPIN0,SW)==0);
   CmdLCD(CLEAR_LCD);
 }
 if(flag==1)
 {
   flag=0;
   set_time();
 }
 //if(((HOUR>=on_hour)&&(MIN>=on_min)&&(SEC>=on_sec))&&((HOUR<=off_hour)&&(MIN<=off_min)&&(SEC<=off_sec)))
 if((HOUR>=on_hour)&&(MIN>=on_min)&&(off_hour==0)&&(on_hour!=0))
 {
   IOSET1=1<<LED;
	CmdLCD(GOTO_LINE2_POS0+12);
	StrLCD("D");
	BuildCGRAM(cgramLUT1,16);
	CmdLCD(GOTO_LINE2_POS0+14);
	CharLCD(0);
	}
	else
	{
 if(((HOUR>=on_hour)&&(MIN>=on_min))&&(HOUR<=off_hour)&&(MIN<off_min))
 {
    IOSET1=1<<LED;
	CmdLCD(GOTO_LINE2_POS0+12);
	StrLCD("D");
	BuildCGRAM(cgramLUT1,16);
	CmdLCD(GOTO_LINE2_POS0+14);
	CharLCD(0);
}
else
{
 IOCLR1=1<<LED;
 CmdLCD(GOTO_LINE2_POS0+12);
 StrLCD("D");
 BuildCGRAM(cgramLUT1,16);
 CmdLCD(GOTO_LINE2_POS0+14);
 CharLCD(1);
}
}
}
}
void Init_interrupt()
{
//cfg p0.1 pin as EINT0 i/p pin
CfgPortPinFunc(0,1,PIN_FUNC4);
//cfg VIC peripheral
//cfg EINT0 as irq types,default all are irq type
//VICIntSelect=0;
//enable EINT0 via VIC
VICIntEnable=1<<EINT0_VIC_CHNO;
//cfg EINT0 as virq with highest priority
//allow to load eint0_isr addr
VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;
//load eint0 isr addr
VICVectAddr0=(u32)eint0_isr;
//cfg external interrupt peripheral
//allow/enable EINT0,default all are enabled
//EXTINT=0;
//cfg EINT0 as falling edge triggerd 
EXTMODE=1<<0;
//def all are falling edge
//EXTPOLAR=0;
//cfg EINT0 status LED pin as gpio out
}
