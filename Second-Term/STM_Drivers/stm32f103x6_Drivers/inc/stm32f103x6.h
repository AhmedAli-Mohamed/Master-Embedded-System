/*
 * stm32f103x6.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Ahmed Ali
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

//-----------------------------
//Includes
#include<stdlib.h>
#include<stdint.h>

//===============================================================
//Base addresses for Memories
#define FLASH_MEMORY_BASE	 0x08000000
#define SRAM_MEMORY_BASE	 0x20000000
#define Peripherals_BASE	 0x40000000
#define NVIC_BASE			 0xE000E100
#define NVIC_ISER0			*(volatile unsigned int* )(NVIC_BASE + 0x000)
#define NVIC_ISER1			*(volatile unsigned int* )(NVIC_BASE + 0x004)
#define NVIC_ICER0			*(volatile unsigned int* )(NVIC_BASE + 0x080)
#define NVIC_ICER1			*(volatile unsigned int* )(NVIC_BASE + 0x084)

//===========================================================
//Base addresses for BUS Peripherals


//GPIO
//A,B fully included in LQFP48
#define GPIOA_BASE 	0x40010800UL
#define GPIOB_BASE 	0x40010C00UL

//C,D partially included in LQFP48
#define GPIOC_BASE 	0x40011000UL
#define GPIOD_BASE 	0x40011400UL

//E,F,G not included in LQFP48
#define GPIOE_BASE 	0x40011800UL
#define GPIOF_BASE 	0x40011C00UL
#define GPIOG_BASE 	0x40012000UL

//AFIO
#define AFIO_BASE 	0x40010000UL


//EXTI
#define EXTI_BASE 	0x40010400UL

//RCC
#define RCC_BASE 	0x40021000UL



//-------------------------------------------------
// IVT

#define       EXTI0_IRQ				6
#define       EXTI1_IRQ				7
#define       EXTI2_IRQ				8
#define       EXTI3_IRQ				9
#define       EXTI4_IRQ				10
#define       EXTI5_IRQ				23
#define       EXTI6_IRQ				23
#define       EXTI7_IRQ				23
#define       EXTI8_IRQ				23
#define       EXTI9_IRQ			    23
#define       EXTI10_IRQ			40
#define       EXTI11_IRQ			40
#define       EXTI12_IRQ			40
#define       EXTI13_IRQ			40
#define       EXTI14_IRQ			40
#define       EXTI15_IRQ			40

//==================================================
//Peripheral register:

//-*-*-*-*-*-*-*-*-*-*-*
//  GPIO REGISTERS
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
}GPIO_TYPEDEF;

//-*-*-*-*-*-*-*-*-*-*-*
//   AFIO REGISTERS
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	uint32_t EVCR;
	uint32_t MAPR;
	uint32_t EXTICR[4];
	uint32_t RESERVED;
	uint32_t MAPR2;
}AFIO_TYPEDEF;

//-*-*-*-*-*-*-*-*-*-*-*
//  EXTI REGISTERS
//-*-*-*-*-*-*-*-*-*-*-*-

typedef struct
{
	uint32_t IMR;
	uint32_t EMR;
	uint32_t RTSR;
	uint32_t FTSR;
	uint32_t SWIER;
	uint32_t PR;

}EXTI_TYPEDEF;

//-*-*-*-*-*-*-*-*-*-*-*
//  RCC REGISTERS
//-*-*-*-*-*-*-*-*-*-*-*-
typedef struct
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
}RCC_TYPEDEF;

//==================================================
//Peripheral Instants:
//GPIO
#define GPIOA 		((GPIO_TYPEDEF *) GPIOA_BASE )
#define GPIOB 		((GPIO_TYPEDEF *) GPIOB_BASE )
#define GPIOC 		((GPIO_TYPEDEF *) GPIOC_BASE )
#define GPIOD 		((GPIO_TYPEDEF *) GPIOD_BASE )
//AFIO
#define AFIO 		((AFIO_TYPEDEF *) AFIO_BASE  )
//EXTI
#define EXTI		((EXTI_TYPEDEF *) EXTI_BASE  )

//RCC
#define RCC			((RCC_TYPEDEF *)  RCC_BASE   )


//============================================================
//clock enable Macros:

#define CLOCK_ENABLE_GPIOA  (RCC->APB2ENR |= (1<<2))
#define CLOCK_ENABLE_GPIOB  (RCC->APB2ENR |= (1<<3))
#define CLOCK_ENABLE_GPIOC  (RCC->APB2ENR |= (1<<4))
#define CLOCK_ENABLE_GPIOD  (RCC->APB2ENR |= (1<<5))
#define CLOCK_ENABLE_GPIOE  (RCC->APB2ENR |= (1<<6))
#define CLOCK_ENABLE_GPIOF  (RCC->APB2ENR |= (1<<7))
#define CLOCK_ENABLE_GPIOG  (RCC->APB2ENR |= (1<<8))

#define CLOCK_ENABLE_AFIO   RCC->APB2ENR |= (1<<0)



//-*-*-*-*-*-*-*-*-*-*-*
// NVIC ENABLE / DISABLE MACROS
//-*-*-*-*-*-*-*-*-*-*-*-

#define NVIC_EXTI0_ENABLE				(NVIC_ISER0 |= (1<<6))
#define NVIC_EXTI1_ENABLE				(NVIC_ISER0 |= (1<<7))
#define NVIC_EXTI2_ENABLE				(NVIC_ISER0 |= (1<<8))
#define NVIC_EXTI3_ENABLE				(NVIC_ISER0 |= (1<<9))
#define NVIC_EXTI4_ENABLE				(NVIC_ISER0 |= (1<<10))
#define NVIC_EXTI5_EXTI9_ENABLE			(NVIC_ISER0 |= (1<<23))
#define NVIC_EXTI10_EXTI15_ENABLE	    (NVIC_ISER1 |= (1<<8))

#define NVIC_EXTI0_DISABLE				(NVIC_ICER0 |= (1<<6))
#define NVIC_EXTI1_DISABLE				(NVIC_ICER0 |= (1<<7))
#define NVIC_EXTI2_DISABLE				(NVIC_ICER0 |= (1<<8))
#define NVIC_EXTI3_DISABLE				(NVIC_ICER0 |= (1<<9))
#define NVIC_EXTI4_DISABLE				(NVIC_ICER0 |= (1<<10))
#define NVIC_EXTI5_EXTI9_DISABLE		(NVIC_ICER0 |= (1<<23))
#define NVIC_EXTI10_EXTI15_DISABLE	    (NVIC_ICER1 |= (1<<8))

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define READ_BIT(REG,BIT)     ((REG & (1<<BIT))>>BIT)
#define TOGGLE_BIT(REG,BIT)   (REG ^= (1<<BIT))
#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define RESET_BIT(REG,BIT)    (REG &= ~(1<<BIT))









#endif /* INC_STM32F103X6_H_ */
