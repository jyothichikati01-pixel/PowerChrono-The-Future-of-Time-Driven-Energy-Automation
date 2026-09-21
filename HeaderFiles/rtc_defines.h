#ifndef RTC_DEFINES_H
#define RTC_DEFINES_H
//system clock and peripheral clk macros
 #define FOSC 12000000
 #define CCLK (5*FOSC)
 #define PCLK  (CCLK/4)
 //RTC macros
 #define PREINT_VAL ((PCLK/32768)-1)
 #define PREFRAC_VAL (PCLK-(PREINT_VAL+1)*32768)
 //CCr reg bits
 #define RTC_ENABLE (1<<0)
 #define RTC_RESET (1<<1)
 #define RTC_CLKSRC (1<<4)
#endif
                              
