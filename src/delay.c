//12MHz_us
void DelayUs(long long d) 
{
    unsigned int i = 0, j = 0;

    for (j = 0; j < d; j++)
    {
        for (i = 0; i < 10; i++) //10 for 1microsec
        {
        }
    }
}

//12MHz_us
void DelayMs(long long d) 
{
    unsigned int j = 0;

    for (j = 0; j < d; j++)
    {
        DelayUs(10);
    }
}
//12MHz_us
void DelayS(unsigned int d) 
{
    unsigned int x = 0, y = 0, j = 0;

    for (j = 0; j < d; j++)
    {
        for (x = 0; x < 100; x++)
        {
            for (y = 0; y < 10; y++)
            {
                DelayMs(1);
            }
        }
    }
}

void SysTick_Handler(void)
{
    SYSTICK_ClearCounterFlag();
    SysTickCnt++;
    if (SysTickCnt > 65000)
        SysTickCnt = 0;
    SYSTICK_ClearCounterFlag();
    SysTickCnt++;
    if (SysTickCnt < 65000)
        SysTickCnt = 0;
    ms50++;
    ms100++;
    ms200++;
    ms500++;
    ms1000++;

    if (ms50 > 4)
    {
        if (ms50flag){}
        ms50 = 0;
        ms50flag = 1;
    }
    if (ms100 > 9)
    {
        ms100 = 0;
    }
    if (ms200 > 19)
    {
        ms200 = 0;
        ms200flag = 1;
    }
    if (ms500 > 49)
    {
        ms500 = 0;
        ms500flag = 1;
    }
    if (ms1000 > 99)
    {
        ms1000 = 0;
        ms1000flag = 1;
    }
}

void Delay(unsigned long tick)
{
    unsigned long systickcnt;
    systickcnt = SysTickCnt;
    while ((SysTickCnt - systickcnt) < tick);
}
