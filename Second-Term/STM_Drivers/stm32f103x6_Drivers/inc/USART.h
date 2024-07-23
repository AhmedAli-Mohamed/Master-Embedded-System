/*
 * USART.h
 *
 *  Created on: 18 Sep 2023
 *      Author: ahmed
 */

#ifndef INC_USART_H_
#define INC_USART_H_

//-----------------------------
//Includes

#include"stm32f103x6.h"
#include"GPIO.h"
//-----------------------------
//-----------------------------
//User type definitions (structures)
//-----------------------------
//-----------------------------
typedef struct
{
	uint8_t mode;				//Specifies COMM.MODE to be configured
	                    		// this parameter can be value of @ref COMM.MODE

	uint16_t stop_bit; 			//Specifies stopbit Mode to be configured
								// this parameter can be value of @ref STOP_BIT_MODE

	uint16_t payload_length; 	//Specifies payload_length to be configured
								// this parameter can be value of @ref payload_length

	uint16_t parity; 			//Specifies parity to be configured
								// this parameter can be value of @ref parity_MODE

	uint32_t Baud_Rate; 		//Specifies Baud_Rate to be configured
								 // this parameter can be value of @ref Baud_Rate

	uint16_t FW_control;		//Specifies FW_control to be configured
								// this parameter can be value of @ref FW_control

	uint16_t IRQ_ENABLE;		//Specifies IRQ_ENABLE to be configured
								// this parameter can be value of @ref IRQ_ENABLE

	void(*P_IRQ_CALLBACK)(void);

}USART_PINCONFIG;
//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------------------

//@ref STOP_BIT_MODE
#define USART_STOP_BIT_1					0
#define USART_STOP_BIT_hlaf					(1<<12)				// configured from CR2 reg
#define USART_STOP_BIT_2					(1<<13)				// configured from CR2 reg
#define USART_STOP_BIT_onehlaf				(1<<12) | ((1<<13))


//-----------------------------------------
//@ref payload_length
#define USART_WORD_LEN_8b					0
#define USART_WORD_LEN_9b					(1<<12) 			// configured from CR1 reg

//-----------------------------------------
//@ref parity_MODE
#define USART_PARITY_NONE					0
#define USART_PARITY_EVEN					(1<<10)   			// configured from CR1 reg
#define USART_PARITY_ODD					(1<<10) | (1<<9)    // configured from CR1 reg

//------------------------------------------
//@ref COMM.MODE
#define USART_MODE_TR						(1<<3)				// configured from CR1 reg
#define USART_MODE_RE						(1<<2)				// configured from CR1 reg
#define USART_MODE_TR_RE					(1<<3) | (1<<2)     // configured from CR1 reg

//------------------------------------------
//@ref Baud_Rate
#define USART_BaudRate_2400							2400
#define USART_BaudRate_9600							9600
#define USART_BaudRate_19200						19200
#define USART_BaudRate_57600						57600
#define USART_BaudRate_115200						115200
#define USART_BaudRate_230400						230400
#define USART_BaudRate_460800						460800
#define USART_BaudRate_921600						921600
#define USART_BaudRate_2250000						2250000
#define USART_BaudRate_4500000						4500000

//-------------------------------------------
//@ref FW_control
#define USART_FW_CONTROL_NONE						0
#define USART_FW_CONTROL_CTSE						(1<<9)
#define USART_FW_CONTROL_RTSE						(1<<8)
#define USART_FW_CONTROL_CTSE_RTSE					(1<<9) | (1<<8)

//------------------------------------------
//@ref IRQ_ENABLE
#define USART_IRQ_NONE								0
#define USART_IRQ_TDR_EMPTY							(1<<7)
#define USART_IRQ_RDR_READY							(1<<5)
#define USART_IRQ_TC								(1<<6)


#ifndef ENABEL_MECHA
#define ENABEL_MECHA
enum polling_mechanism
{
	enable,
	disable
};
#endif
/*
* ==============================================================================
*                            APIs
* ==============================================================================
*/

void MCAL_USART_INIT(USART_TYPEDEF* USARTX , USART_PINCONFIG* pin_conf);
void MCAL_USART_DEINIT(USART_TYPEDEF* USARTX );
void MCAL_USART_GPIO_SET_PINS(USART_TYPEDEF* USARTX );
void MCAL_USART_SEND_DATA(USART_TYPEDEF* USARTX , uint16_t *pTx_Buffer , enum polling_mechanism pollen);
void MCAL_USART_RECIEVE_DATA(USART_TYPEDEF* USARTX , uint16_t *pRx_Buffer , enum polling_mechanism pollen);




#endif /* INC_USART_H_ */
