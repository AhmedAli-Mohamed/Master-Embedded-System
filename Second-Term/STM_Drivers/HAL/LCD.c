/*
 * LCD.c
 *
 *  Created on: 17 Sep 2023
 *      Author: ahmed
 */

/*
 * LCD.c
 *
 * Created: 2023/09/05 11:48:01
 *  Author: ahmed
 */
#include "LCD.h"
#include "GPIO.h"
#include<stdio.h>
void _delay_ms(uint32_t x)
{
	uint32_t i;
	for(i=0 ; i < 255 * x ; i++);
}

// counter to handle printing string on lcd
uint8_t counter;

void ENABLE_sig()
{
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_EN , 1 );
	_delay_ms(20);
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_EN , 0 );
	_delay_ms(20);

}
void LCD_INIT(void)
{
	uint8_t i ;
	// initialize control pins
	GPIO_PINCONFIG pinconf;
	pinconf.Pin_Number = LCD_EN ;
	pinconf.MODE = GPIO_MODE_OUTPUT_PP;
	pinconf.Speed = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRLPORT ,& pinconf);
	pinconf.Pin_Number = LCD_RS ;
	pinconf.MODE = GPIO_MODE_OUTPUT_PP;
	pinconf.Speed = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRLPORT , &pinconf);
	pinconf.Pin_Number = LCD_RW ;
	pinconf.MODE = GPIO_MODE_OUTPUT_PP;
	pinconf.Speed = GPIO_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRLPORT ,& pinconf);

#if defined EIGHTBIT_MODE
	for(i=0 ; i<=7 ; i++)
	{
		pinconf.Pin_Number = i;
		pinconf.MODE = GPIO_MODE_OUTPUT_PP;
		pinconf.Speed = GPIO_SPEED_10M;
		MCAL_GPIO_INIT(LCD_DATAPORT , &pinconf);

	}

	LCD_SEND_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_SEND_COMMAND(LCD_DISP_ON_CURSOR);
	LCD_CLEAR_SCREEN();
	LCD_SEND_COMMAND(LCD_ENTRY_MODE);

#elif defined FOURBIT_MODE
	uint8_t i;
	if (PIN_POS == LOW_Nible)
	{
		for(i=0 ; i<=3 ;i++)
		{
			SET_BIT(LCD_DATAPORT->DDR , i);

		}
	}
	else if (PIN_POS == HIGH_Nibble)
	{
		for(i=4 ; i<=7 ;i++)
		{
			SET_BIT(LCD_DATAPORT->DDR , i);

		}
	}
	LCD_SEND_COMMAND(0X02);
	LCD_SEND_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	LCD_SEND_COMMAND(LCD_DISP_ON_CURSOR);
	LCD_CLEAR_SCREEN();
	LCD_SEND_COMMAND(LCD_ENTRY_MODE);




#endif


}

void LCD_SEND_COMMAND(uint8_t comm)
{
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_RS , 0 );
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_RW , 0 );


#if defined EIGHTBIT_MODE
	LCD_DATAPORT->ODR &= ~(0xff);
	LCD_DATAPORT->ODR |= comm;
	ENABLE_sig();
	_delay_ms(1);


#elif defined FOURBIT_MODE
	MCAL_GPIO_WriteNibble(LCD_DATAPORT , comm >> 4 , PIN_POS);
	ENABLE_sig();
	_delay_ms(1);
	MCAL_GPIO_WriteNibble(LCD_DATAPORT , comm , PIN_POS);
	ENABLE_sig();
	_delay_ms(1);
#endif
}

void LCD_SEND_CHAR(uint8_t data)
{
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_RS , 1 );
	MCAL_GPIO_Writepin(LCD_CTRLPORT ,LCD_RW , 0 );
#if defined EIGHTBIT_MODE
	LCD_DATAPORT->ODR &= ~(0xff);
	LCD_DATAPORT->ODR |= data;
	ENABLE_sig();


#elif defined FOURBIT_MODE
	MCAL_GPIO_WriteNibble(LCD_DATAPORT , data >> 4 , PIN_POS);
	ENABLE_sig();
	MCAL_GPIO_WriteNibble(LCD_DATAPORT , data , PIN_POS);
	ENABLE_sig();

#endif
	counter ++;
	if (counter == 16)
	{
		LCD_MOVE_CURSOR(2,1);
	}
	if (counter == 32)
	{
		LCD_CLEAR_SCREEN();
		counter = 0;
	}
}

void LCD_SEND_STR(uint8_t * data)
{
	while(*data != 0)
	{
		LCD_SEND_CHAR(*data);
		data ++;


	}
}
void LCD_CLEAR_SCREEN(void)
{
	LCD_SEND_COMMAND(LCD_CLEAR);
	_delay_ms(10);
}
void LCD_MOVE_CURSOR(uint8_t row , uint8_t col)
{
	if (row <1 || row >2 || col < 1 || col >16)
	{
		LCD_SEND_COMMAND(0x80);
	}
	else if (row == 1)
	{
		LCD_SEND_COMMAND(0x80 + col -1);
		counter = col;
	}
	else if (row == 2)
	{
		LCD_SEND_COMMAND(0xc0 + col -1);
		counter = col + 16;
	}
}

void LCD_SEND_INT(unsigned int  data)
{
	unsigned char str[9];
	sprintf(str , "%d" , data);
	LCD_SEND_STR(str);
}
/*void LCD_SEND_FLOAT(float data)
{
	char str[9];
	sprintf(str , "%f" , data);
	LCD_SEND_STR(str);
}*/

