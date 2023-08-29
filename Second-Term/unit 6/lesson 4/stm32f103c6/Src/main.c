/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */



#include<stdio.h>
#define set(reg,bit)      reg|=(1<<bit)
#define clr(reg,bit)      reg&=~(1<<bit)
#define toggle(reg,bit)   reg^=(1<<bit)



#define AFIO_BASE 0x40010000
//GPIO registers
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *((volatile unsigned int*)(GPIOA_BASE+0x04))
#define GPIOA_CRL *((volatile unsigned int*)(GPIOA_BASE+0x00))
#define GPIOA_ODR *((volatile unsigned int*)(GPIOA_BASE+0x0c))

//RCC registers
#define RCC_BASE 0x40021000
#define RCC_CR *((volatile unsigned int*)(RCC_BASE+0x00))
#define RCC_CFGR *((volatile unsigned int*)(RCC_BASE+0x04))
#define RCC_APB2ENR *((volatile unsigned int*) (RCC_BASE+0x18))

//EXTI registers
#define EXTI_BASE 0x40010400
#define EXTI_IMR *((volatile unsigned int*)(EXTI_BASE+0x00))
#define EXTI_RTSR *((volatile unsigned int*)(EXTI_BASE+0x08))
#define EXTI_PR *((volatile unsigned int*)(EXTI_BASE+0x14))
#define NVIC_ISER *((volatile unsigned int*)(0xE000E100))



void clock_init()
{

	RCC_APB2ENR |= (1<<0) ;
	RCC_APB2ENR |= (1<<2) ;
}
void EXTI_init()
{
	//Configure the mask bits of the 20 Interrupt lines (EXTI_IMR)
	EXTI_IMR |= (1<<0);
	//Configure the Trigger Selection bits of the Interrupt lines (EXTI_RTSR andEXTI_FTSR)
	EXTI_RTSR |= (1<<0);
	//Configure the enable and mask bits that control the NVIC IRQ
	NVIC_ISER |= (1<<6);

}
int main ()
{
	clock_init();
	EXTI_init();
// GPIOA init
	GPIOA_CRL |= (1<<2);
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=0x00200000;

	while(1);
}

void EXTI0_IRQHandler(void)
{
	GPIOA_ODR ^= (1<<13) ;
	EXTI_PR |=(1<<0);
}
