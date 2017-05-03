
//void lcd_write(char c);
#define LCD_STROBE (LCD_EN(1), DelayUs(1000), LCD_EN(0))

static void WriteNibble(char nibble)
{
    nibble = nibble >> 4;
    if (nibble & 0x01)
        LCD4(1);
    else
        LCD4(0);
    nibble = nibble >> 1;
    if (nibble & 0x01)
        LCD5(1);
    else
        LCD5(0);
    nibble = nibble >> 1;
    if (nibble & 0x01)
        LCD6(1);
    else
        LCD6(0);
    nibble = nibble >> 1;
    if (nibble & 0x01)
        LCD7(1);
    else
        LCD7(0);
}
void LcdWrite(char c)
{
    WriteNibble(c & 0xf0);
    LCD_STROBE;
    WriteNibble(c << 4);
    LCD_STROBE;
    //  DelayUs(40);    //40 delay    7-8-2016 for testing
}

void LcdPutch(char c)
{
    LCD_RS(1); // write characters
    WriteNibble(c & 0xf0);
    LCD_STROBE;
    WriteNibble(c << 4);
    LCD_STROBE;
    DelayUs(40);
}
void LcdGoto(unsigned char pos)
{
    LCD_RS(0);
    LcdWrite(0x80 + pos);
}

/* initialise the LCD - put into 4 bit mode */

void LcdInit(void)
{

    LCD_RS(0);   // write control bytes
    DelayMs(50); // power on delay
    LCD4(1);
    LCD5(1);
    LCD_STROBE;
    DelayMs(50);
    LCD_STROBE;
    DelayUs(500);
    LCD_STROBE;
    DelayMs(50);
    LCD5(1);
    LCD4(0);
    LCD_STROBE;
    DelayMs(400);   //us delay
    LcdWrite(0x28); // 4 bit mode, 1/16 duty, 5x8 font
    LcdWrite(0x08); // display off
    LcdWrite(0x0c); // 0x0f for cursor on and blink
    LcdWrite(0x06); // entry mode
}

void LcdClear(void)
{
    LCD_RS(0);
    LcdWrite(0x1);
    DelayMs(2);
}

void LcdPuts(char *s)
{

/*
    lcd_goto(0);
    LCD_RS = 1;      // write characters
    if(line ==1)
    {
        LCD_RS = 0;
        lcd_write(0x80);
        LCD_RS = 1;
    }
    if(line ==2)
    {
        LCD_RS = 0;
        lcd_write(0xC0);
        LCD_RS = 1;
    }
    while(*s)
    {
        lcd_write(*s++);
    }
*/
    LcdGoto(0);
    LCD_RS(1);      // write characters
    if (line == 1)
    {
        LCD_RS(0);
        LcdWrite(0x80);
        LCD_RS(1);
    }
    if (line == 2)
    {
        LCD_RS(0);
        LcdWrite(0xC0);
        LCD_RS(1);
    }
    if (line == 3)
    {
        LCD_RS(0);
        LcdWrite(0x90);
        LCD_RS(1);
    }
    if (line == 4)
    {
        LCD_RS(0);
        LcdWrite(0xd0);
        LCD_RS(1);
    }
    while (*s)
    {
        LcdWrite(*s++);
    }
}