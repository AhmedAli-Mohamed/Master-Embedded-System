#include<stdio.h>
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *(volatile unsigned long int*) (RCC_BASE+0x18)
#define GPIOA_CRH *(volatile unsigned long int*) (GPIOA_BASE+0x04)
#define GPIOA_ODR *(volatile unsigned long int*) (GPIOA_BASE+0x0c)
#define RCC_IOPAEN 2
typedef union {
	volatile unsigned long int all_fields;
	struct{
		unsigned long  reserver:13;
		unsigned long  p_13:1;
	}bits;
}R_ODR;

int main ()
{
	volatile R_ODR *ODR=(volatile R_ODR*) (GPIOA_BASE+0x0c);
	RCC_APB2ENR |=1<<2;
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;
	while(1)
	{
		ODR->bits.p_13=1;
		for(int i=0;i<50000;i++);
		ODR->bits.p_13=0;
		for(int i=0;i<50000;i++);
	}
}
