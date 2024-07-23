/*
 * LCD.h
 *
 *  Created on: 17 Sep 2023
 *      Author: ahmed
 */

#ifndef INCLUDES_LCD_H_
#define INCLUDES_LCD_H_
//-----------------------------
//Includes
#include "GPIO.h"

/* ===============================================
* LCD CONFIGRATION
===============================================*/

#define EIGHTBIT_MODE		            //you can choose mode to be (EIGHTBIT_MODE , FOURBIT_MODE )
#define LCD_DATAPORT	 GPIOA          //GPIOX , X can be (A....D)
#define LCD_CTRLPORT     GPIOA          //GPIOX , X can be (A....D)
#define LCD_RS		      (8)           //choose pin to connected register selected pin in lcd
#define LCD_RW			  (9)			//choose pin to connected read & write pin in lcd
#define LCD_EN         	  (10)			//choose pin to connected enable pin in lcd


// if using FOURBIT_MODE
#define PIN_POS      HIGH_Nibble			//you can choose on which Nibble you want to connect LCD from ( LOW_Nible , HIGH_Nibble )





/* ===============================================
* PREDEFIND COMMANDS
===============================================*/

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_RAW						(0x80)
#define LCD_BEGIN_AT_SECOND_RAW						(0xC0)
#define LCD_CLEAR        							(0x01)
#define LCD_ENTRY_MODE								(0x06)


/* ===============================================
* APIs Supported by "HAL LCD DRIVER"
===============================================*/
void LCD_INIT(void);
void LCD_SEND_COMMAND(uint8_t comm);
void LCD_SEND_CHAR(uint8_t data);
void LCD_SEND_STR(uint8_t * data);
void LCD_MOVE_CURSOR(uint8_t row , uint8_t col);
void LCD_CLEAR_SCREEN(void);
void LCD_SEND_INT(unsigned int  data);
void LCD_SEND_FLOAT(float data);




#endif /* INCLUDES_LCD_H_ */
