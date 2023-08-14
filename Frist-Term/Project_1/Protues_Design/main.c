#include <stdint.h>
#include <stdio.h>


#include "PS.h"
#include"alarm.h"
extern void (*PS_STATE)();
extern void (*ALARM_STATE)();


int main ()
{
	// init PS & LED
	PS_init();
	LED_Init();
	
	// set initial states
	PS_STATE=PS_READ;
	ALARM_STATE = ALARM_OFF;
	
	while (1)
	{
		PS_STATE();
		ALARM_STATE();
	}

}
