void config_pins(void)
{
    extern uint8_t TxIntStat;
    UART_CFG_Type UARTConfigStruct;
    UART_FIFO_CFG_Type UARTFIFOConfigStruct;
    PINSEL_CFG_Type PinCfg;

    // Initialize UART0 pin connect
    PinCfg.Funcnum   = 1;
    PinCfg.OpenDrain = 0;
    PinCfg.Pinmode   = 0;
    PinCfg.Pinnum    = 2;
    PinCfg.Portnum   = 0;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinnum = 3;
    PINSEL_ConfigPin(&PinCfg);
    GPIO_SetDir(2, 0x04000004, 1);
    GPIO_SetDir(0, 0x00000004, 1);
    GPIO_SetDir(0, 0x00000008, 0);
    /* 
        Initialize UART Configuration parameter structure to default state:
            Baudrate = 9600bps
            8 data bit
            1 Stop bit
            None parity
    */
    UART_ConfigStructInit(&UARTConfigStruct);
    SysTick_Config(SystemCoreClock / 10000 - 1);     // Generate interrupt each 0.1 ms   

    UART_Init((LPC_UART_TypeDef *)LPC_UART0, &UARTConfigStruct);
    UART_FIFOConfigStructInit(&UARTFIFOConfigStruct);
    UART_FIFOConfig((LPC_UART_TypeDef *)LPC_UART0, &UARTFIFOConfigStruct);
    UART_TxCmd((LPC_UART_TypeDef *)LPC_UART0, ENABLE);
    UART_IntConfig((LPC_UART_TypeDef *)LPC_UART0, UART_INTCFG_RBR, ENABLE);
    UART_IntConfig((LPC_UART_TypeDef *)LPC_UART0, UART_INTCFG_RLS, ENABLE);
    TxIntStat = RESET;
    NVIC_EnableIRQ(UART0_IRQn);

    SysTick_Config(SystemCoreClock / 1000 - 1);     // Generate interrupt each 1 ms   

    SystemCoreClockUpdate();
    SYSTICK_InternalInit(10);
    SYSTICK_IntCmd(ENABLE);
    SYSTICK_Cmd(ENABLE);

    // To start timer 0
    //  TIM_Cmd(LPC_TIM0,ENABLE);

    TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;
    TIM_ConfigStruct.PrescaleValue = 1;
    TIM_MatchConfigStruct.MatchChannel = 1;

    // Enable interrupt when MR0 matches the value in TC register
    TIM_MatchConfigStruct.IntOnMatch = TRUE;

    //Enable reset on MR0: TIMER will reset if MR0 matches it
    TIM_MatchConfigStruct.ResetOnMatch = TRUE;

    //Stop on MR0 if MR0 matches it
    TIM_MatchConfigStruct.StopOnMatch = FALSE;

    //Toggle MR0.0 pin if MR0 matches it
    TIM_MatchConfigStruct.ExtMatchOutputType = 0; //TIM_EXTMATCH_TOGGLE;

    // Set Match value, count value of 1000 (10000 * 1uS = 1000us = 1ms --> 1 KHz)
    TIM_MatchConfigStruct.MatchValue = 50000;
    // Set configuration for Tim_config and Tim_MatchConfig

    TIM_Init(LPC_TIM1, TIM_TIMER_MODE, &TIM_ConfigStruct);
    TIM_ConfigMatch(LPC_TIM1, &TIM_MatchConfigStruct);
    TIM_MatchConfigStruct.MatchChannel = 1;
    TIM_MatchConfigStruct.MatchValue = 50000;
    TIM_ConfigMatch(LPC_TIM1, &TIM_MatchConfigStruct);
    NVIC_EnableIRQ(TIMER1_IRQn);
    TIM_Cmd(LPC_TIM1, ENABLE);

}
