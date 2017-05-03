
#define LCD_D4_PORT_NUM         1
#define LCD_D4_PIN              16
#define LCD_D5_PORT_NUM         1
#define LCD_D5_PIN              17
#define LCD_D6_PORT_NUM         1
#define LCD_D6_PIN              18
#define LCD_D7_PORT_NUM         1
#define LCD_D7_PIN              19
#define LCD_RS_PORT_NUM         1
#define LCD_RS_PIN              8
#define LCD_EN_PORT_NUM         1               
#define LCD_EN_PIN              9
#define ManLed_Port             1
#define ManLed_Pin              28
#define AutoLed_Port            1
#define AutoLed_Pin             27
#define TripLed_Port            1
#define TripLed_Pin             25
#define RunLed_Port             1
#define RunLed_Pin              4
#define TxLed_Port              0
#define TxLed_Pin               20
#define RxLed_Port              0
#define RxLed_Pin               21
#define RelayTrig_Port          1
#define RelayTrig_Pin           1
#define RelayTrip_Port          1
#define RelayTrip_Pin           0
#define FanControl_Port         0
#define FanControl_Pin          22
#define Buzzer_Port             1
#define Buzzer_Pin              29
#define Backlite_Port           2
#define Backlite_Pin            3
#define MenuKey_Port            0
#define MenuKey_Pin             4
#define IncKey_Port             0
#define IncKey_Pin              5
#define DecKey_Port             0
#define DecKey_Pin              6
#define EnterKey_Port           0
#define EnterKey_Pin            7
#define ResetKey_Port           0
#define ResetKey_Pin            8
#define M1_Port                 0
#define M1_Pin                  30
#define M2_Port                 0
#define M2_Pin                  29
#define Plt_Port                0
#define Plt_Pin                 9
#define Trigger_Port            0
#define Trigger_Pin             10
#define DI1_Port                0
#define DI1_Pin                 11
#define DI2_Port                0
#define DI2_Pin                 19
#define RevIp_Port              2
#define RevIp_Pin               4
#define ClkMcp3204_Port         0
#define ClkMcp3204_Pin          15
#define CsMcp3204_Port          0
#define CsMcp3204_Pin           16
#define MisoMcp3204_Port        0
#define MisoMcp3204_Pin         17
#define MosiMcp3204_Port        0
#define MosiMcp3204_Pin         18
#define ClkMcp3208_Port         2
#define ClkMcp3208_Pin          9
#define CsMcp3208_Port          2
#define CsMcp3208_Pin           6
#define MisoMcp3208_Port        2
#define MisoMcp3208_Pin         5
#define MosiMcp3208_Port        2
#define MosiMcp3208_Pin         8

//lcd
void LCD_D4_Init(void)
{
    GPIO_SetDir(LCD_D4_PORT_NUM, (1 << LCD_D4_PIN), 1);
    GPIO_SetValue(LCD_D4_PORT_NUM, (1 << LCD_D4_PIN));
}
void LCD_D5_Init(void)
{
    GPIO_SetDir(LCD_D5_PORT_NUM, (1 << LCD_D5_PIN), 1);
    GPIO_SetValue(LCD_D5_PORT_NUM, (1 << LCD_D5_PIN));
}
void LCD_D6_Init(void)
{
    GPIO_SetDir(LCD_D6_PORT_NUM, (1 << LCD_D6_PIN), 1);
    GPIO_SetValue(LCD_D6_PORT_NUM, (1 << LCD_D6_PIN));
}
void LCD_D7_Init(void)
{
    GPIO_SetDir(LCD_D7_PORT_NUM, (1 << LCD_D7_PIN), 1);
    GPIO_SetValue(LCD_D7_PORT_NUM, (1 << LCD_D7_PIN));
}
void LCD_RS_Init(void)
{
    GPIO_SetDir(LCD_RS_PORT_NUM, (1 << LCD_RS_PIN), 1);
    GPIO_SetValue(LCD_RS_PORT_NUM, (1 << LCD_RS_PIN));
}
void LCD_EN_Init(void)
{
    GPIO_SetDir(LCD_EN_PORT_NUM, (1 << LCD_EN_PIN), 1);
    GPIO_SetValue(LCD_EN_PORT_NUM, (1 << LCD_EN_PIN));
}

void LCD4(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_D4_PORT_NUM, (1 << LCD_D4_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_D4_PORT_NUM, (1 << LCD_D4_PIN));
    }
}
void LCD5(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_D5_PORT_NUM, (1 << LCD_D5_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_D5_PORT_NUM, (1 << LCD_D5_PIN));
    }
}
void LCD6(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_D6_PORT_NUM, (1 << LCD_D6_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_D6_PORT_NUM, (1 << LCD_D6_PIN));
    }
}
void LCD7(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_D7_PORT_NUM, (1 << LCD_D7_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_D7_PORT_NUM, (1 << LCD_D7_PIN));
    }
}
void LCD_RS(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_RS_PORT_NUM, (1 << LCD_RS_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_RS_PORT_NUM, (1 << LCD_RS_PIN));
    }
}

void LCD_EN(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(LCD_EN_PORT_NUM, (1 << LCD_EN_PIN));
    }
    else
    {
        GPIO_ClearValue(LCD_EN_PORT_NUM, (1 << LCD_EN_PIN));
    }
}

//LED
void ManLed_Init(void)
{
    GPIO_SetDir(ManLed_Port, (1 << ManLed_Pin), 1);
    GPIO_SetValue(ManLed_Port, (1 << ManLed_Pin));
}

void AutoLed_Init(void)
{
    GPIO_SetDir(AutoLed_Port, (1 << AutoLed_Pin), 1);
    GPIO_SetValue(AutoLed_Port, (1 << AutoLed_Pin));
}

void TripLed_Init(void)
{
    GPIO_SetDir(TripLed_Port, (1 << TripLed_Pin), 1);
    GPIO_SetValue(TripLed_Port, (1 << TripLed_Pin));
}

void RunLed_Init(void)
{
    GPIO_SetDir(RunLed_Port, (1 << RunLed_Pin), 1);
    GPIO_SetValue(RunLed_Port, (1 << RunLed_Pin));
}

void TxLed_Init(void)
{
    GPIO_SetDir(TxLed_Port, (1 << TxLed_Pin), 1);
    GPIO_SetValue(TxLed_Port, (1 << TxLed_Pin));
}

void RxLed_Init(void)
{
    GPIO_SetDir(RxLed_Port, (1 << RxLed_Pin), 1);
    GPIO_SetValue(RxLed_Port, (1 << RxLed_Pin));
}

//RelayTrig & RelayTrip

void RelayTrig_Init(void)
{
    GPIO_SetDir(RelayTrig_Port, (1 << RelayTrig_Pin), 1);
    GPIO_SetValue(RelayTrig_Port, (1 << RelayTrig_Pin));
}
void RelayTrip_Init(void)
{
    GPIO_SetDir(RelayTrip_Port, (1 << RelayTrip_Pin), 1);
    GPIO_SetValue(RelayTrip_Port, (1 << RelayTrip_Pin));
}

//Buzzer
void Buzzer_Init(void)
{
    GPIO_SetDir(Buzzer_Port, (1 << Buzzer_Pin), 1);
    GPIO_SetValue(Buzzer_Port, (1 << Buzzer_Pin));
}

//LCD Backlite
void Backlite_Init(void)
{
    GPIO_SetDir(Backlite_Port, (1 << Backlite_Pin), 1);
    GPIO_SetValue(Backlite_Port, (1 << Backlite_Pin));
}

//Fan Control
void FanControl_Init(void)
{
    GPIO_SetDir(FanControl_Port, (1 << FanControl_Pin), 1);
    GPIO_SetValue(FanControl_Port, (1 << FanControl_Pin));
}

// Keys
void Keys_Init(void)
{
    GPIO_SetDir(MenuKey_Port, (1 << MenuKey_Pin), 0);
    GPIO_SetDir(IncKey_Port, (1 << IncKey_Pin), 0);
    GPIO_SetDir(DecKey_Port, (1 << DecKey_Pin), 0);
    GPIO_SetDir(EnterKey_Port, (1 << EnterKey_Pin), 0);
    GPIO_SetDir(ResetKey_Port, (1 << ResetKey_Pin), 0);
}

void M1_Init(void)
{
    GPIO_SetDir(M1_Port, (1 << M1_Pin), 1);
    GPIO_SetValue(M1_Port, (1 << M1_Pin));
}
void M2_Init(void)
{
    GPIO_SetDir(M2_Port, (1 << M2_Pin), 1);
    GPIO_SetValue(M2_Port, (1 << M2_Pin));
}

void DI_Init(void)
{
    GPIO_SetDir(Plt_Port, (1 << Plt_Pin), 0);
    GPIO_SetDir(Trigger_Port, (1 << Trigger_Pin), 0);
    GPIO_SetDir(DI1_Port, (1 << DI1_Pin), 0);
    GPIO_SetDir(DI2_Port, (1 << DI2_Pin), 0);
    GPIO_SetDir(RevIp_Port, (1 << RevIp_Pin), 0);
}
void Mcp3204_Init(void)
{
    //FIO_ByteSetMask(0,2,0xfd,0xfd);
    GPIO_SetDir(CsMcp3204_Port, (1 << CsMcp3204_Pin), 1);
    GPIO_SetValue(CsMcp3204_Port, (1 << CsMcp3204_Pin));
    GPIO_SetDir(ClkMcp3204_Port, (1 << ClkMcp3204_Pin), 1);
    GPIO_SetValue(ClkMcp3204_Port, (1 << ClkMcp3204_Pin));
    GPIO_SetDir(MisoMcp3204_Port, (1 << MisoMcp3204_Pin), 0);
    GPIO_SetValue(MisoMcp3204_Port, (1 << MisoMcp3204_Pin));
    GPIO_SetDir(MosiMcp3204_Port, (1 << MosiMcp3204_Pin), 1);
    GPIO_SetValue(MosiMcp3204_Port, (1 << MosiMcp3204_Pin));
}
void Mcp3208_Init(void)
{
    //FIO_ByteSetMask(0,2,0xfd,0xfd);
    GPIO_SetDir(CsMcp3208_Port, (1 << CsMcp3208_Pin), 1);
    GPIO_SetValue(CsMcp3208_Port, (1 << CsMcp3208_Pin));
    GPIO_SetDir(ClkMcp3208_Port, (1 << ClkMcp3208_Pin), 1);
    GPIO_SetValue(ClkMcp3208_Port, (1 << ClkMcp3208_Pin));
    GPIO_SetDir(MisoMcp3208_Port, (1 << MisoMcp3208_Pin), 0);
    GPIO_SetValue(MisoMcp3208_Port, (1 << MisoMcp3208_Pin));
    GPIO_SetDir(MosiMcp3208_Port, (1 << MosiMcp3208_Pin), 1);
    GPIO_SetValue(MosiMcp3208_Port, (1 << MosiMcp3208_Pin));
}

void CsMcp3204(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(CsMcp3204_Port, (1 << CsMcp3204_Pin));
    }
    else
    {
        GPIO_ClearValue(CsMcp3204_Port, (1 << CsMcp3204_Pin));
    }
}
void ClkMcp3204(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(ClkMcp3204_Port, (1 << ClkMcp3204_Pin));
    }
    else
    {
        GPIO_ClearValue(ClkMcp3204_Port, (1 << ClkMcp3204_Pin));
    }
}
void MosiMcp3204(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(MosiMcp3204_Port, (1 << MosiMcp3204_Pin));
    }
    else
    {
        GPIO_ClearValue(MosiMcp3204_Port, (1 << MosiMcp3204_Pin));
    }
}

void CsMcp3208(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(CsMcp3208_Port, (1 << CsMcp3208_Pin));
    }
    else
    {
        GPIO_ClearValue(CsMcp3208_Port, (1 << CsMcp3208_Pin));
    }
}
void ClkMcp3208(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(ClkMcp3208_Port, (1 << ClkMcp3208_Pin));
    }
    else
    {
        GPIO_ClearValue(ClkMcp3208_Port, (1 << ClkMcp3208_Pin));
    }
}
void MosiMcp3208(int8_t state)
{
    if (state)
    {
        GPIO_SetValue(MosiMcp3208_Port, (1 << MosiMcp3208_Pin));
    }
    else
    {
        GPIO_ClearValue(MosiMcp3208_Port, (1 << MosiMcp3208_Pin));
    }
}

void Port_Init(void)
{
    // PINSEL_CFG_Type PinCfg0;
    // Port 1
    PINSEL_CFG_Type PinCfg;
    PinCfg.Portnum = 1;

    //LCD
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 16;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 17;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 18;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 19;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 8;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 9;
    PINSEL_ConfigPin(&PinCfg);

    //Buzzer
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 29;
    PINSEL_ConfigPin(&PinCfg);

    //LEDS
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 28;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 27;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 25;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 4;
    PINSEL_ConfigPin(&PinCfg);

    // Relay-trig & Relay-trip
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 0;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 1;
    PINSEL_ConfigPin(&PinCfg);

    // Port 0
    PinCfg.Portnum = 0;
    //Tx & Rx LED
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 20;
    PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 21;
    PINSEL_ConfigPin(&PinCfg);
    //Fan Control
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 22;
    PINSEL_ConfigPin(&PinCfg);
    //M1 and M2
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 29;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 30;
    PINSEL_ConfigPin(&PinCfg);

    //Keys (Menu,Inc,Dec,Enter,Reset)

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 4;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 5;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 6;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 7;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 8;
    PINSEL_ConfigPin(&PinCfg);
    // Digital Inputs
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 10;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 9;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 11;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 19;
    PINSEL_ConfigPin(&PinCfg);
    PinCfg.Portnum = 2;
    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 4;
    PINSEL_ConfigPin(&PinCfg);

    // PinCfg.Pinmode    = 0;
    //  PinCfg.Pinnum     = 7;
    // PINSEL_ConfigPin(&PinCfg);

    PinCfg.Pinmode = 0;
    PinCfg.Pinnum = 3;
    PINSEL_ConfigPin(&PinCfg);

    LCD_D4_Init();
    LCD_D5_Init();
    LCD_D6_Init();
    LCD_D7_Init();
    LCD_RS_Init();
    LCD_EN_Init();

    ManLed_Init();
    AutoLed_Init();
    TripLed_Init();
    RunLed_Init();
    TxLed_Init();
    RxLed_Init();

    RelayTrig_Init();
    RelayTrip_Init();
    FanControl_Init();
    Buzzer_Init();
    Backlite_Init();

    Keys_Init();
    M1_Init();
    M2_Init();
    DI_Init();
    Mcp3204_Init();
    Mcp3208_Init();
    //
}
