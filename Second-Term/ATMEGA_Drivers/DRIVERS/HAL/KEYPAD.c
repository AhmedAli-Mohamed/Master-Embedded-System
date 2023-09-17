/*
 * KEYPAD.c
 *
 * Created: 2023/09/05 23:33:05
 *  Author: ahmed
 */ 
#include "KEYPAD.h"

void KEYPAD_INIT()
{
	uint8_t i;
	GPIO_PINCONFIG pinconf;
	for(i=0 ; i<=3 ; i++)
	{
		pinconf.Pin_Number = i;
		pinconf.MODE = GPIO_MODE_OUTPUT;
		MCAL_GPIO_INIT(KEYPAD_DATAPORT , &pinconf);
	}
	for(i=4 ; i<=7 ; i++)
	{
		pinconf.Pin_Number = i;
		pinconf.MODE = GPIO_MODE_INPUT_PU;
		MCAL_GPIO_INIT(KEYPAD_DATAPORT ,& pinconf);
	}
	
}

uint8_t KEYPAD_READ()
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	uint8_t row,col,return_val = 0xff;
	
	for(row = 0 ;row <= 3 ; row++)
	{
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , GPIO_PIN_0 , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , GPIO_PIN_1 , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , GPIO_PIN_2 , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , GPIO_PIN_3 , 1);
		MCAL_GPIO_Writepin(KEYPAD_DATAPORT , row , 0);
		
		for(col =4 ; col <= 7 ; col++)
		{
			
			if(MCAL_GPIO_Readpin(KEYPAD_DATAPORT , col) == 0)
			{
				return_val = arr[row][col-4];
				break;
			}
		}
		if(return_val != 0xff)
		break;
		
	}
	
	return return_val;				
}