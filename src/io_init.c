
#define LCD_D4_PORT_NUM		  1
#define LCD_D4_PIN         	  16

#define LCD_D5_PORT_NUM		  1
#define LCD_D5_PIN            17

#define LCD_D6_PORT_NUM		  1 
#define LCD_D6_PIN            18

#define LCD_D7_PORT_NUM		  1 
#define LCD_D7_PIN            19

#define LCD_RS_PORT_NUM		  1 
#define LCD_RS_PIN            8 

#define LCD_EN_PORT_NUM		  1
#define LCD_EN_PIN            9  


void LCD_D4_Init(void)
{
    GPIO_SetDir(LCD_D4_PORT_NUM, (1<<LCD_D4_PIN), 1);
    GPIO_SetValue(LCD_D4_PORT_NUM, (1<<LCD_D4_PIN));	
}
void LCD_D5_Init(void)
{
	GPIO_SetDir(LCD_D5_PORT_NUM, (1<<LCD_D5_PIN), 1);
    GPIO_SetValue(LCD_D5_PORT_NUM, (1<<LCD_D5_PIN));	
}
void LCD_D6_Init(void)
{
    GPIO_SetDir(LCD_D6_PORT_NUM, (1<<LCD_D6_PIN), 1);
    GPIO_SetValue(LCD_D6_PORT_NUM, (1<<LCD_D6_PIN));		
}
void LCD_D7_Init(void)
{
	GPIO_SetDir(LCD_D7_PORT_NUM, (1<<LCD_D7_PIN), 1);
    GPIO_SetValue(LCD_D7_PORT_NUM, (1<<LCD_D7_PIN));	
}
void LCD_RS_Init(void)
{
    GPIO_SetDir(LCD_RS_PORT_NUM, (1<<LCD_RS_PIN), 1);
    GPIO_SetValue(LCD_RS_PORT_NUM, (1<<LCD_RS_PIN));		
}
void LCD_EN_Init(void)
{
	GPIO_SetDir(LCD_EN_PORT_NUM, (1<<LCD_EN_PIN), 1);
    GPIO_SetValue(LCD_EN_PORT_NUM, (1<<LCD_EN_PIN));	
}

void LCD4(int8_t state)
{
	if (state)
	  {
		GPIO_SetValue(LCD_D4_PORT_NUM, (1<<LCD_D4_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_D4_PORT_NUM, (1<<LCD_D4_PIN));
	 }	
}
void LCD5(int8_t state)
{
	if (state)
	  {
		GPIO_SetValue(LCD_D5_PORT_NUM, (1<<LCD_D5_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_D5_PORT_NUM, (1<<LCD_D5_PIN));
	 }	
}
void LCD6(int8_t state)
{
	if (state)
	  {
		GPIO_SetValue(LCD_D6_PORT_NUM, (1<<LCD_D6_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_D6_PORT_NUM, (1<<LCD_D6_PIN));
	 }	
}
void LCD7(int8_t state)
{
	if (state)
	  {
		GPIO_SetValue(LCD_D7_PORT_NUM, (1<<LCD_D7_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_D7_PORT_NUM, (1<<LCD_D7_PIN));
	 }	
}
void LCD_RS(int8_t state)
{
	if (state)
	  {
		GPIO_SetValue(LCD_RS_PORT_NUM, (1<<LCD_RS_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_RS_PORT_NUM, (1<<LCD_RS_PIN));
	 }	
}

void LCD_EN(int8_t state)
{
    if (state)
	  {
		GPIO_SetValue(LCD_EN_PORT_NUM, (1<<LCD_EN_PIN));
	  }
	 else
	 {
		GPIO_ClearValue(LCD_EN_PORT_NUM, (1<<LCD_EN_PIN));
	 }	
}


void Port_Init(void)
 {
     PINSEL_CFG_Type PinCfg; 
     PinCfg.Portnum  = 1;	
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum     = 16;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum   = 17;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum   = 18;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum   = 19;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum   = 8;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 PinCfg.Pinmode = 0;
     PinCfg.Pinnum   = 9;
	 PINSEL_ConfigPin(&PinCfg);
	 
	 LCD_D4_Init();
	 LCD_D5_Init();
	 LCD_D6_Init();
	 LCD_D7_Init();
     LCD_RS_Init();
	 LCD_EN_Init();
 }	