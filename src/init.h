#include "lpc17xx_gpio.h"
// #include "lpc17xx_libcfg_default.h"
// #include "lpc17xx_i2c.h"
// #include "lpc17xx_pwm.h"
// #include "lpc17xx_adc.h"
#include "lpc17xx_systick.h"




#include "lpc17xx_uart.h"
#include "lpc17xx_libcfg.h"
#include "lpc17xx_pinsel.h"
#include "stdio.h"
#include "stdlib.h"

char line = 0;
char ary_line1[17] = {0};
char ary_line2[17] = {0};
char blank[17]     = {"                "};
unsigned long SysTickCnt = 0;
float q = 0;
uint8_t Ms50Toggle = 0;
char SerialData[17] = {0};
uint8_t NewInput = 0;
uint8_t NewData  = 0;
uint8_t data_ok = 0;
uint8_t ms50 = 0;uint8_t ms100 = 0;
uint8_t ms200 = 0;uint8_t ms500 = 0;uint8_t ms1000 = 0;
uint8_t ms50flag           = 0;
uint8_t ms100flag          = 0;
uint8_t ms200flag          = 0;
uint8_t ms500flag          = 0;
uint8_t ms1000flag         = 0;

uint8_t toggle             = 0; // toggle

uint8_t TxIntStat;










