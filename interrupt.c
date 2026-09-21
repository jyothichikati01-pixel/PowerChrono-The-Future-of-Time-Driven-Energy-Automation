#include<lpc21xx.h>
#include "delay.h"
#include "kpm.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "rtc.h"
#include "types.h"
extern u32 hour,min,sec,on_hour,on_min,on_sec,off_hour,off_min,off_sec,date,month,year,day;
u32 flag;
void set_time(void);
void eint0_isr(void)__irq
{
 CmdLCD(CLEAR_LCD);
 StrLCD("Interrupt Raised");
 delay_s(1);
 flag=1;
 EXTINT=1<<0;
 VICVectAddr=0;
 }
