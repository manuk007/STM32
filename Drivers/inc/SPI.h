/*
 * SPI.h
 *
 *  Created on: Apr 18, 2019
 *      Author: manu
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "stdint.h"
#include "STM32F4xx.h"

typedef struct
{
	uint8_t SPI_MSMode; 		/* (where x =A..I/J/K) */
	uint8_t BusConfigMode; 		/* (where x =A..I/J/K) */
	uint8_t DFF; 		/* (where x =A..I/J/K) */
	uint8_t LSBFIRST; 	/* (where x =A..I/J/K) */
	uint8_t SSM;
	uint8_t SSI; 		/* (where x =A..I/J/K) High Low Combine */
	uint8_t BaudRate; 	/* (where x =A..I/J/K) */
	uint8_t CPOL; 		/* (where x =A..I/J/K) High Low Combine */
	uint8_t CPHA; 		/* (where x =A..I/J/K) High Low Combine */
}SPI_CONFIG_ST;

typedef struct
{
	SPI_REG_ST *pSPIx;
	SPI_CONFIG_ST SPI_Config_Data;

}SPI_HANDLE_ST;

#endif /* INC_SPI_H_ */

#define SPI_SLAVE 0
#define SPI_MASTER 1

#define SPI_FULL_DUPLEX 0 /*2 lines MISO, MOSI*/
#define SPI_HALF_DUPLEX 1 /*1 lines MOSI, MOSI*/
#define SPI_SIMPLEX 2 /*1 lines RX ONLY*/

#define SPI_8_BIT_DFF 0
#define SPI_16_BIT_DFF 1

#define SPI_BR_FPCLK_BY_2 0
#define SPI_BR_FPCLK_BY_4 1
#define SPI_BR_FPCLK_BY_8 2
#define SPI_BR_FPCLK_BY_16 3
#define SPI_BR_FPCLK_BY_32 4
#define SPI_BR_FPCLK_BY_64 5
#define SPI_BR_FPCLK_BY_128 6
#define SPI_BR_FPCLK_BY_256 7

#define SPI_TX_MSB_FIRST 0
#define SPI_TX_LSB_FIRST 1

#define SPI_SSM_SW 1
#define SPI_SSM_HW 0

#define SPI_TX_NOT_DEF 0
#define SPI_TX_BUSY 1
#define SPI_TX_SUCESS 2

#define SPI_RX_NO_NEW_DATA 0
#define SPI_RX_NEW_DATA_WITH_ERR 1
#define SPI_RX_GOOD_NEW_DATA 2

void SPI_Clk_Cntl(SPI_REG_ST *pSPIx, uint8_t EN_DI);
void SPI_Init(SPI_HANDLE_ST *pHandle);
void SPI_DeInit(SPI_REG_ST *pSPIx);

void SPI_Enable(SPI_REG_ST *pSPIx);
void SPI_Disable(SPI_REG_ST *pSPIx);

void SPI_SSOE_ctl(SPI_REG_ST *pSPIx);

uint8_t SPI_SendData(SPI_REG_ST *pSPIx, char *Data, uint32_t Len);
uint8_t SPI_RecieveData(SPI_REG_ST *pSPIx, uint16_t *Data);

uint8_t SPI_Busy(SPI_REG_ST *pSPIx);
