/*
 * Atmega32.h
 *
 * Created: 2023/09/02 18:12:58
 *  Author: Ahmed Ali
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

//-----------------------------
//Includes
#include<stdlib.h>
#include <stdint.h>


//-----------------------------
//-----------------------------
//Base addresses for Memories

#define SRAM_BASE			0X0060
#define Peripheral_BASE		0x0020


//-----------------------------
//-----------------------------
//Base addresses for BUS Peripherals
#define GPIOA_BASE		0X39
#define GPIOB_BASE		0X36
#define GPIOC_BASE		0X33
#define GPIOD_BASE		0X30


//-----------------------------
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:
typedef struct
{
	uint8_t PIN;
	uint8_t DDR;
	uint8_t PORT;
	
}GPIO_TYPEDEF;


//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
#define GPIOA			((GPIO_TYPEDEF *) 0X39)
#define GPIOB			((GPIO_TYPEDEF *) 0X36)
#define GPIOC			((GPIO_TYPEDEF *) 0X33)
#define GPIOD			((GPIO_TYPEDEF *) 0X30)


//-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:

#define READ_BIT(REG,BIT)     ((REG & (1<<BIT))>>BIT)
#define TOGGLE_BIT(REG,BIT)   (REG ^= (1<<BIT))
#define SET_BIT(REG,BIT)      (REG |= (1<<BIT))
#define RESET_BIT(REG,BIT)    (REG &= ~(1<<BIT))

//-*-*-*-*-*-*-*-*-*-*-*





#endif /* ATMEGA32_H_ */