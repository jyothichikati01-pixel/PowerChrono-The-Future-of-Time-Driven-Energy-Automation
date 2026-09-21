#include <lpc21xx.h>
#include "lcd_defines.h"
#include "rtc.h"
#include "lcd.h"
#include "kpm.h"
#include "pin_function_defines.h"
#include "pin_connect_block.h"
#include "delay.h"
#define DEV 30
#define EINT0_VIC_CHNO 14
#define EINT0_STATUS_LED 16
extern u32 on_hour,on_min,on_sec,off_hour,off_min,off_sec;
 extern u32 hour,min,sec,date,month,year,day;
 void edit_RTC_SET_TIME(void);
 void edit_device_set_time(void);
s8 week1[][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
u32 KeyV;
void set_time(void)
{
 CmdLCD(CLEAR_LCD);
 //StrLCD("INTERRUPT RAISED");
 delay_s(1);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("1.EDIT RTC INFO");
 CmdLCD(GOTO_LINE2_POS0);
 StrLCD("2.DEVICE");
 CmdLCD(GOTO_LINE2_POS0+9);
 StrLCD("3.EXIT");
 KeyV=KeyScan();
 delay_ms(200);
 while(ColScan()==0);
 switch(KeyV)
 {
  case 1:
  CmdLCD(CLEAR_LCD);
  edit_RTC_SET_TIME();
  CmdLCD(CLEAR_LCD);
  return;
  case 2:
  CmdLCD(CLEAR_LCD);
  edit_device_set_time();
  CmdLCD(CLEAR_LCD);
  return;
  case 3:
  CmdLCD(CLEAR_LCD);
  CmdLCD(GOTO_LINE1_POS0);
  StrLCD("EXIT");
  return;
  default:
  StrLCD("INVALID");
  delay_s(1);
  break;
  }
  }
  void edit_RTC_SET_TIME(void)
  {
    menu:CmdLCD(CLEAR_LCD);
	 CmdLCD(GOTO_LINE1_POS0);
	 StrLCD("1.H 2.M 3.S");
	 CmdLCD(GOTO_LINE1_POS0+11);
	 StrLCD("4.Dy");
	 CmdLCD(GOTO_LINE2_POS0);
	 StrLCD("5.D 6.MN 7.YR");
	 CmdLCD(GOTO_LINE2_POS0+13);
	 StrLCD("8.E");
	 KeyV=KeyScan();
	 delay_ms(150);
	 while(ColScan()==0);
	 switch(KeyV)
	 { 
	 case 1:
     H:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit Hour");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&hour);
		 if(hour>23&&hour<1)
		 {
		  StrLCD("Invalid HR Enter Again");
		  goto H;
     	 }
		 HOUR=hour;
		 goto menu;
		 case 2:
     M:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit Min");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&min);
		 if(min>59&&min<1)
		 {
		  StrLCD("Invalid MIN Enter Again");
		  goto M;
     	 }
		 MIN=min;
		 goto menu;
		 case 3:
     S:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit Sec");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&sec);
		 if(sec>59&&sec<1)
		 {
		  StrLCD("Invalid SEC Enter Again");
		  goto S;
     	 }
		 SEC=sec;
		 goto menu;
		 case 4:
     Dy: CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit DAY");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&day);
		 if(day>6&&day<1)
		 {
		  StrLCD("Invalid day Enter Again");
		  goto Dy;
     	 }
		 DOW=day;
		 goto menu;
		 case 5:
     D:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit Date");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&date);
		 if(date>31&&date<1)
		 {
		  StrLCD("Invalid date Enter Again");
		  goto D;
     	 }
		 DOM=date;
		 goto menu;
		case 6:
     MN:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit Month");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&month);
		 if(month>12&&month<1)
		 {
		  StrLCD("Invalid month Enter Again");
		  goto MN;
     	 }
		 MONTH=month;
		 goto menu;
		 case 7:
     YR:  CmdLCD(CLEAR_LCD);
 		 CmdLCD(GOTO_LINE1_POS0);
		 StrLCD("Edit year");
		 CmdLCD(GOTO_LINE2_POS0);
		 ReadNum(&year);
		 if(year>4095&&year<1)
		 {
		  StrLCD("Invalid year Enter Again");
		  goto YR;
     	 }
		 YEAR=year;
		 goto menu;
		 case 8:
		 CmdLCD(CLEAR_LCD);
		 return;
		 default:
		 goto menu;
		 }		 
}
void edit_device_set_time(void)
{
 menu1:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("1.ONTIME");
 CmdLCD(GOTO_LINE2_POS0);
 StrLCD("2.OFFTIME 3.EXIT");
 KeyV=KeyScan();
 delay_ms(200);
 switch(KeyV)
 {
 case 1:
 devonhr:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV ONHR");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&on_hour);
 if(on_hour>23&&on_hour<1)
 {
 StrLCD("Invalid dev on hr ");
 goto devonhr;
 }
 devonmin:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV ONMIN");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&on_min);
 if(on_min>59&&on_min<1)
 {
 StrLCD("Invalid dev on min");
 goto devonmin;
 }
 devonsec:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV ONSEC");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&on_sec);
 if(on_sec>59&&on_sec<1)
 {
 StrLCD("Invalid dev on sec");
 goto devonsec;
 } 
 goto menu1;
 case 2:
 devofhr:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV OFFHR");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&off_hour);
 if(off_hour>23&&off_hour<1)
 {
 StrLCD("Invalid dev offhr");
 goto devofhr;
 }
 devofmin:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV off min");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&off_min);
 if(off_min>59&&off_min<1)
 {
 StrLCD("Invalid dev off-min");
 goto devofmin;
 }
 devofsec:CmdLCD(CLEAR_LCD);
 CmdLCD(GOTO_LINE1_POS0);
 StrLCD("DEV OffSEC");
 CmdLCD(GOTO_LINE2_POS0);
 ReadNum(&off_sec);
 if(off_sec>59&&off_sec<1)
 {
 StrLCD("Invalid dev off sec");
 goto devofsec;
 } 
 case 3:
 return;
 default:
 goto menu1;
 }
 }


