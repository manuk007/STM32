/*
 * I2C.h
 *
 *  Created on: Jul 21, 2019
 *      Author: manu
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stdint.h"
#include "RCC.h"
#include "STM32F4xx.h"

#define I2C_SPEED_SM 1000000
#define I2C_SPEED_FM 4000000

typedef struct
{
	uint8_t I2C_Mode; 		/* (where x =A..I/J/K) */
	uint8_t DutyCyle; 		/* (where x =A..I/J/K) */
	uint8_t ACKEN; 		/* (where x =A..I/J/K) */
	uint8_t ADDRESS; 		/* (where x =A..I/J/K) */
	uint32_t Speed; 		/* (where x =A..I/J/K) */

}I2C_CONFIG_ST;

typedef struct
{
	I2C_REG_ST *pI2Cx;
	I2C_CONFIG_ST I2C_Config_Data;
}I2C_HANDLE_ST;

void I2C_Init(I2C_HANDLE_ST*);
void I2C_MasterSend(I2C_HANDLE_ST* I2C_xhandle, uint32_t SAddr,
						uint32_t * Data ,uint32_t size);
void I2C_Clk_Cntl(I2C_REG_ST *pI2Cx, uint8_t EN_DI);
void I2C_Enable(I2C_HANDLE_ST* I2C_xhandle);


#endif /* INC_I2C_H_ */
