/*
 * I2C.h
 *
 *  Created on: 30 Oct 2023
 *      Author: ahmed
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

//-----------------------------
//Includes

#include"stm32f103x6.h"
#include"GPIO.h"
#include"RCC.h"
//-----------------------------
//-----------------------------
//User type definitions (structures)
typedef enum
{
	EV_START,
	EV_STOP,
	EV_ADDR,
	EV_BTF,
	EV_RXNE,
	EV_TXE
}IRQ_STATUS;
typedef struct
{
	uint16_t ADD_MODE;					//Specifies slave address length to be 7 or 10 bir
										// this parameter can be value of @ref I2C_SLAVE_ADDRESS_LENGTH

	uint16_t ENDUAL_ADD;				//determine if dual address for slave is enabled or not
										// this parameter can be value of @ref I2C_SLAVE_DUAL_ADDRESS_ENABLE

	uint16_t  PRIMARY_ADD;				//specifies primary address for slave

	uint16_t  SECONDARY_ADD;			//specifies secondary address for slave
										//[NOTE] only enable in 7_ADD_MODE
}SLAVE_CONF;



typedef struct
{
	uint16_t CLCK_Freq; 				//Specifies clock frequecy
										// this parameter can be value of @ref I2C_CLCK_FREQ_SELECT

	uint16_t MODE;						//specifies MODE to be I2C or SMBUS
										//this parameter can be value of @ref I2C_MODE

	uint16_t CLCK_STRETCH;				//determine if enable or disable clock stretching
										//this parameter can be value of @ref I2C_CLCK_STRTCH

	uint16_t GEN_CALL;					//determine if enable or disable general calling
										//this parameter can be value of @ref I2C_GEN_CALL

	uint16_t ACK_CTRL;					//determine if enable or disable auto acknowledge
										//this parameter can be value of @ref I2C_ACK_CTRL

	SLAVE_CONF slave;

	void(*P_IRQ_SLAVE_CALLBACK)(IRQ_STATUS src);


}I2C_PINCONFIG;


//-----------------------------
//-----------------------------
//Macros Configuration References
//-----------------------------------------

//-------------------------------
//@ref I2C_CLCK_FREQ_SELECT
#define I2C_CLCK_Freq_SM_100k							(1)
#define I2C_CLCK_Freq_SM_50k							50000
#define I2C_CLCK_Freq_FM_200k							200000
#define I2C_CLCK_Freq_FM_400k							400000

//----------------------------------
//@ref I2C_SLAVE_ADDRESS_LENGTH
#define I2C_SLAVE_ADD_MODE_7BIT						0				//OAR1_reg
#define I2C_SLAVE_ADD_MODE_10BIT					(1<<15)

//--------------------------------------
//@ref I2C_SLAVE_DUAL_ADDRESS_ENABLE
#define I2C_SLAVE_DUAL_ADD_DIS						0   			//OAR2_reg
#define I2C_SLAVE_DUAL_ADD_EN						(1<<0)

//----------------------------------------
//@ref I2C_MODE
#define I2C_MODE_I2C								0				//CR1_reg
#define I2C_MODE_SMBUS								(1<<1)

//---------------------------------------
//@ref I2C_CLCK_STRTCH
#define I2C_CLCK_STRTCH_EN							0				//CR1_reg
#define I2C_CLCK_STRTCH_DIS							(1<<7)

//--------------------------------------
//@ref I2C_GEN_CALL
#define I2C_GEN_CALL_DIS							0   			//CR1_reg
#define I2C_GEN_CALL_EN								(1<<6)

//-------------------------------------
//@ref I2C_ACK_CTRL
#define I2C_ACK_DIS									0				//CR1_reg
#define I2C_ACK_EN									(1<<10)


//******************************************************************

typedef enum
{

	without_stop,
	with_stop
}STOP_STATUS;

typedef enum
{
	START,
	repeated_START
}START_STATUS;

typedef enum
{
	RESET,
	SET
}FLAG_STATUS;

typedef enum
{
	BUSY,
	EV_5,
	EV_6,
	EV_8,
	EV_7,
MASTER_BYTE_TRANSMISSION = ( (uint32_t)0x00070080)
}EVENT_SRC;

typedef enum
{
	WRITE,
	READ
}I2C_DIRECTION;
/*
 * ==============================================================================
 *                            APIs
 * ==============================================================================
 */
void MCAL_I2C_INIT(I2C_TYPEDEF* I2CX , I2C_PINCONFIG* pin_conf);
void MCAL_I2C_DEINIT(I2C_TYPEDEF* I2CX );


void MCAL_I2C_GPIO_SET_PINS(I2C_TYPEDEF* I2CX );


void MCAL_I2C_MASTER_TX(I2C_TYPEDEF* I2CX ,uint16_t dev_add, uint8_t * data , uint16_t data_len ,START_STATUS start,STOP_STATUS stop );
void MCAL_I2C_MASTER_RX(I2C_TYPEDEF* I2CX ,uint16_t dev_add, uint8_t * data , uint16_t data_len ,START_STATUS start,STOP_STATUS stop );

#endif /* INC_I2C_H_ */
