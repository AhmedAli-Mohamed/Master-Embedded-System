#include <stdio.h>
#define UART_DR *((volatile unsigned int *)0x101f1000)
void UART_SEND_STR (unsigned char * ptr)
{
	while (*ptr!=0)
	{
		UART_DR= (unsigned int)*ptr;
		ptr++;
	}

}