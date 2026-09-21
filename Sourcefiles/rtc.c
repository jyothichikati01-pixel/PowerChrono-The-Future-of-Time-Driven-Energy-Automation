#include<LPC21xx.h>
#include "rtc_defines.h"
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"
char week[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
void RTC_Init(void)
{
CCR=RTC_RESET;
#ifdef LPC2148
CCR=RTC_ENABLE|RTC_CLKSRC;
#else
PREINT=PREINT_VAL;
PREFRAC=PREFRAC_VAL;
CCR=RTC_ENABLE;
#endif
}
void GetRTCTimeInfo(s32 *hour,s32 *minute,s32 *second)
{
*hour =HOUR;
* minute=MIN;
* second=SEC;
}
void DisplayRTCTime(u32 hour,u32 minute,u32 second)
{
 CmdLCD(GOTO_LINE1_POS0);
 CharLCD((hour/10)+48);
 CharLCD((hour%10)+48);
 CharLCD(':');
 CharLCD((minute/10)+48);
 CharLCD((minute%10)+48);
 CharLCD(':');
 CharLCD((second/10)+48);
 CharLCD((second%10)+48);
 }
 void GetRTCDateInfo(s32 *date,s32 *month,s32 *year)
 {
 * date=DOM;
 * month=MONTH;
 * year=YEAR;
 }
 void DisplayRTCDate(u32 date,u32 month,u32 year)
 {
 CmdLCD(GOTO_LINE2_POS0);
 CharLCD((date/10)+48);
 CharLCD((date%10)+48);
 CharLCD('/');
 CharLCD((month/10)+48);
 CharLCD((month%10)+48);
 CharLCD('/');
 U32LCD(year);
 }
 void SetRTCTimeInfo(u32 hour,u32 minute,u32 second)
 {
 HOUR=hour;
 MIN=minute;
 SEC=second;
 }
 void SetRTCDateInfo(u32 date,u32 month,u32 year)
 {
  DOM=date;
  MONTH=month;
  YEAR=year;
  }
  void GetRTCDay(s32 *day)
  {
  *day=DOW;
  }
  void DisplayRTCDay(u32 dow)
  {
  CmdLCD(GOTO_LINE1_POS0+10);
  StrLCD(week[dow]);
  }
  void SetRTCDay(u32 day)
  {
  DOW=day;
  }



 

