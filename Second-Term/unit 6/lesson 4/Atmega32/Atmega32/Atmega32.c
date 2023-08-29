/*
 * Atmega32.c
 *
 * Created: 2023/08/28 01:35:58
 *  Author: ahmed
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	//Gpio init
	DDRD |= (1<<5);
	DDRD |= (1<<6);
	DDRD |= (1<<7);
	//INT0_INIT
	MCUCR |=(1<<ISC00);
	GICR |= (1<<INT0);
	//INT1_INIT
	MCUCR |=(1<<ISC10);
	GICR |= (1<<INT1);
	//INT2_INIT
	MCUCSR |=(1<<ISC2);
	GICR |= (1<<INT2);
	sei();
    while(1)
    {
		PORTD &= ~(1<<5);
        PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
    }
}
ISR(INT0_vect)
{
	PORTD |= (1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	PORTD |= (1<<6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	PORTD |= (1<<7);
	_delay_ms(1000);
}