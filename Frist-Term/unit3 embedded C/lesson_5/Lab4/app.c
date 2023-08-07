#include<stdio.h>
#include"types.h"
#include<stdlib.h>
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *(volatile unsigned long int*) (RCC_BASE+0x18)
#define GPIOA_CRH *(volatile unsigned long int*) (GPIOA_BASE+0x04)
#define GPIOA_ODR *(volatile unsigned long int*) (GPIOA_BASE+0x0c)
#define RCC_IOPAEN 2

typedef union {
	vuint32 all_fields;
	struct{
		uint32  reserver:13;
		uint32  p_13:1;
	}bits;
}R_ODR;
uint32 data_test=50;
uint32 bss_test;





void* _sbrk( int incr )
{
	extern uint32 _heap_end ;
    extern uint32 E_bss ;
	static uint8 * heap_ptr = (uint8 *) &E_bss;
	uint8 * ret_ptr = heap_ptr;
	/*avoiding over flow*/
	if ((heap_ptr +incr) > (uint8 *)&_heap_end)
	{
		return NULL;
	}
	heap_ptr += incr ;
	return (void*)ret_ptr ;

}


int main ()
{
	uint32 *p =(uint32 *)malloc(200);
	volatile R_ODR *ODR=(volatile R_ODR*) (GPIOA_BASE+0x0c);
	RCC_APB2ENR |=1<<2;
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;
	while(1)
	{
		int i;
		ODR->bits.p_13=1;
		for(i=0;i<50000;i++);
		ODR->bits.p_13=0;
		for(i=0;i<50000;i++);
	}
}
void _write ()
{
	
}
void _read ()
{
	
}
void _lseek ()
{
	
}
void _close ()
{
	
}

