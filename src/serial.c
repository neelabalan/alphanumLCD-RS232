void UART0_IRQHandler(void)
{
    //uint8_t x = 0;
    uint32_t intsrc, tmp, tmp1;
    uint8_t StartLog = 0;
    uint8_t SerialCount = 0;
    extern uint8_t SerialData[17];
    extern uint8_t NewData;
    // Determine the interrupt source
    intsrc = UART_GetIntId(LPC_UART0);
    tmp = intsrc & UART_IIR_INTID_MASK;

    // Receive Line Status
    if (tmp == UART_IIR_INTID_RLS)
    {
        // Check line status
        tmp1 = UART_GetLineStatus(LPC_UART0);
        // Mask out the Receive Ready and Transmit Holding empty status
        tmp1 &= (UART_LSR_OE | UART_LSR_PE | UART_LSR_FE | UART_LSR_BI | UART_LSR_RXFE);

        if (tmp1)
        {
            UART_IntErr(tmp1);
        }
    }

    if ((tmp == UART_IIR_INTID_RDA) || (tmp == UART_IIR_INTID_CTI))
    {

        c = UART_ReceiveByte(LPC_UART0);

        if ((c == @) && (!NewInput) && (SerialCount < 16))
        {
            StartLog = 1;
        }
        if((StartLog)&&((c!='@')&&(SerialCount==0))
        {
            SerialData[SerialCount] = c;
            SerialCount++;
            if (SerialCount >= 16)
            {
                NewInput = 1;
                SerialCount = 0;
                StartLog = 0;
            }
        }
    }
}
