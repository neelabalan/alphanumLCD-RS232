#include "lpc17xx_timer.h"

#include "init.h"
#include "math.h"
#include "stdlib.h"
#include "float.h"
#include "gpio_init.c"
#include "delay.c"
#include "16x2lcd.c"
#include "config.c"

TIM_TIMERCFG_Type TIM_ConfigStruct;
TIM_MATCHCFG_Type TIM_MatchConfigStruct;
UART_CFG_Type UARTConfigStruct;
void modcomm_check(void);

void SysTick_Handler(void);
void Delay(unsigned long tick);
void TIMER0_IRQHandler(void);
UART_FIFO_CFG_Type UARTFIFOConfigStruct;
__IO FlagStatus exitflag;

void TIMER1_IRQHandler(void)
{
    if (TIM_GetIntStatus(LPC_TIM1, TIM_MR1_INT) == SET)
    {
        Ms50Toggle = Ms50Toggle ^ 1;

        if (Ms50Toggle)
        {
            ms100flag = 1;
        }
        TIM_ResetCounter(LPC_TIM1);
    }
    TIM_ClearIntPending(LPC_TIM1, TIM_MR1_INT);
}

int c_entry(void)
{
    config_pins(); // CONFIG.C
    Port_Init();   // port_init.c
    TIM_Cmd(LPC_TIM1, DISABLE);

    LcdInit();
    LcdPuts(ary_line1);
    LcdPuts(ary_line1);
    LcdInit();
    line = 1;
    sprintf(ary_line1, "                ");
    LcdPuts(ary_line1);
    line = 2;
    LcdPuts(ary_line1);
    line = 1;
    LcdPuts(blank);
    line = 2;
    sprintf(ary_line1, "   neelabalan   ");
    LcdPuts(ary_line1);
    line = 3;
    sprintf(ary_line1, "    lpc test    ");
    LcdPuts(ary_line1);
    line = 4;
    LcdPuts(blank);
    DelayS(1000);
    exitflag = RESET;
    DelayMs(100);
    // change_time(3,21,40,pm);
    // change_date(11,8,15);

    DelayMs(50);
    // register for squarewave enable for 32.768khz
    // write_ds1338(0x07,0x33);      
    DelayMs(50);

    TIM_Cmd(LPC_TIM1, ENABLE);

    UARTConfigStruct.Baud_rate = 9600;

    UART_ConfigStructInit(&UARTConfigStruct);
    UART_Init((LPC_UART_TypeDef *)LPC_UART3, &UARTConfigStruct);
    UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);
    UART_FIFOConfig((LPC_UART_TypeDef *)LPC_UART3, &UARTFIFOConfigStruct);
    UART_TxCmd((LPC_UART_TypeDef *)LPC_UART3, ENABLE);
    UART_IntConfig((LPC_UART_TypeDef *)LPC_UART3, UART_INTCFG_RBR, ENABLE);
    UART_IntConfig((LPC_UART_TypeDef *)LPC_UART3, UART_INTCFG_RLS, ENABLE);
    TxIntStat = RESET;
    NVIC_EnableIRQ(UART3_IRQn);

    while (1)
    {
        if (NewInput)
        {
            NewInput = 0;
            line = 1;
            sprintf(ary_line1, SerialData);
            LcdPuts(ary_line1);
        }
    }
}

int main(void)
{
    return c_entry();
}

#ifdef DEBUG
void check_failed(uint8_t *file, uint32_t line)
{
    while (1)
        ;
}
#endif
