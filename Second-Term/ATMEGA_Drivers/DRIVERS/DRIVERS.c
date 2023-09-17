/*
 * DRIVERS.c
 *
 * Created: 2023/09/02 18:11:20
 *  Author: ahmed
 */ 


#include"Atmega32.h"
#include "GPIO.h"
#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "KEYPAD.h"

int main(void)
{
	LCD_INIT();
	KEYPAD_INIT();
	
	
	
    while(1)
    {
		
		  
	}		  
    
}