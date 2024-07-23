/*
 * SPI.h
 *
 *  Created on: 26 Sep 2023
 *      Author: ahmed
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

//-----------------------------
//Includes

#include"stm32f103x6.h"
#include"GPIO.h"
//-----------------------------
//-----------------------------
//User type definitions (structures)

typedef struct
{
	uint8_t TXE:1 ;
	uint8_t RXNE:1 ;
	uint8_t RESERVED:6 ;

}S_IRQ_SRC;




typedef struct
{
	uint16_t polarity;			//Specifies pin number to be configured
								// this parameter can be value of @ref SPI_POLARITY_SELECT

	uint16_t phase;     		//Specifies Phase to be ideal high or ideal low
								// this parameter can be value of @ref SPI_PHASE_SELECT

	uint16_t DATA_SIZE;		 	//Specifies size of Data to be 8 or 16 bit
								// this parameter can be value of @ref SPI_DATA_SIZE

	uint16_t FRAME_FORMAT;		//specifies data format to shift MSB first or LSB
								//this parameter can be value of @ref SPI_DATA_FORMAT

	uint16_t CLCK;				//specifies CLCK frequency by choosing appropriate prescaler
								//this parameter can be value of @ref SPI_CLCK_SELECT

	uint16_t Device_MODE;		//specifies MODE of device to be master or slave
								//this parameter can be value of @ref SPI_DEVICE_MODE

	uint16_t COMM_MODE;			//specifies COMM_MODE to be fullduplex or half or simplex
								//this parameter can be value of @ref SPI_COMM_MODE

	uint16_t NSS;				//slave select configuration
								//this parameter can be value of @ref SPI_NSS_CONFIGURATION

	uint16_t IRQ_ENABLE;		//Specifies IRQ_ENABLE to be configured
								// this parameter can be value of @ref IRQ_ENABLE

	void(*P_IRQ_CALLBACK)(S_IRQ_SRC irq_src);

}SPI_PINCONFIG;

//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------------------

//-------------------------------
//@ref SPI_POLARITY_SELECT
#define SPI_POLARITY_0_IDLE						0				//can be configured in CR1
#define SPI_POLARITY_1_IDLE						(1<<1)


//-------------------------------
//@ref SPI_PHASE_SELECT
#define SPI_PHASE_1ST_TRANSITION_CAP				0			//can be configured in CR1
#define SPI_PHASE_2ND_TRANSITION_CAP				(1<<0)


//-------------------------------
//@ref SPI_DATA_SIZE
#define SPI_DATA_SIZE_8b						0  				//can be configured in CR1
#define SPI_DATA_SIZE_16b						(1<<11)


//------------------------------
//@ref SPI_DATA_FORMAT
#define SPI_FRAME_FORMAT_MSB_FIRST				0				//can be configured in CR1
#define SPI_FRAME_FORMAT_LSB_FIRST				(1<<7)


//-------------------------------
// @ref SPI_CLCK_SELECT
#define SPI_CLCK_PRESCALER_2					(0b000<<3)		//can be configured in CR1
#define SPI_CLCK_PRESCALER_4					(0b001<<3)
#define SPI_CLCK_PRESCALER_8					(0b010<<3)
#define SPI_CLCK_PRESCALER_16					(0b011<<3)
#define SPI_CLCK_PRESCALER_32					(0b100<<3)
#define SPI_CLCK_PRESCALER_64					(0b101<<3)
#define SPI_CLCK_PRESCALER_128					(0b110<<3)
#define SPI_CLCK_PRESCALER_256					(0b111<<3)


//-------------------------------
//@ref SPI_DEVICE_MODE
#define SPI_DEVICE_MODE_SLAVE					0				//can be configured in CR1
#define SPI_DEVICE_MODE_MASTER					(1<<2)


//--------------------------------
//@ref SPI_COMM_MODE
#define SPI_COMM_MODE_FULL_DUPLEX				0
#define SPI_COMM_MODE_HALF_DUPLEX				(1<<15)			//to transmit set BIDIOE  in CR1
																//to receive  reset BIDIOE  in CR1

#define SPI_COMM_MODE_SIMPLEX_RXONLY			(1<<10)			//RXONLY canbe set also in multi slave as the output from the accessed slave is not corrupted


//----------------------------------
//@ref SPI_NSS_CONFIGURATION

//HARDWARE
#define SPI_NSS_HARD_SLAVE						0
#define SPI_NSS_HARD_MASTER_SS_OUTPUT			(1<<2)			//can be configured in CR2
#define SPI_NSS_HARD_MASTER_SS_INPUT			0				//can be configured in CR2

//SOFTWARE
#define SPI_NSS_SOFT_SET						((1<<8) | (1<<9))//can be configured in CR1
#define SPI_NSS_SOFT_RESET						(1<<9)

//-----------------------------------
//@ref IRQ_ENABLE
#define SPI_IRQ_NONE							0
#define SPI_IRQ_TXE								(1<<7)			//can be configured in CR2
#define SPI_IRQ_RXNE							(1<<6)




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
void MCAL_SPI_INIT(SPI_TYPEDEF* SPIX , SPI_PINCONFIG* pin_conf);
void MCAL_SPI_DEINIT(SPI_TYPEDEF* SPIX );


void MCAL_SPI_GPIO_SET_PINS(SPI_TYPEDEF* SPIX );


void MCAL_SPI_SEND_DATA(SPI_TYPEDEF* SPIX , uint16_t *pTx_Buffer , enum polling_mechanism pollen);
void MCAL_SPI_RECIEVE_DATA(SPI_TYPEDEF* SPIX , uint16_t *pRx_Buffer , enum polling_mechanism pollen);
void MCAL_SPI_SEND_RECIEVE_DATA(SPI_TYPEDEF* SPIX , uint16_t *pRx_Buffer , enum polling_mechanism pollen);
#endif /* INC_SPI_H_ */
