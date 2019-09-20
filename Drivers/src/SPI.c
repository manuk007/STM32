/*
 * SPI.c
 *
 *  Created on: Apr 23, 2019
 *      Author: manu
 */
/*
 *
 *  Created on: Apr 18, 2019
 *      Author: manu
 */

#include "SPI.h"

void SPI_Clk_Cntl(SPI_REG_ST *pSPIx, uint8_t EN_DI)
{
	if(EN_DI)
	{
		if(pSPIx==SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx==SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx==SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if(pSPIx==SPI4)
		{
			SPI4_PCLK_EN();
		}
		else
		{
		}
	}
	else
	{
		if(pSPIx==SPI1)
		{
			SPI1_PCLK_EN();
		}
		else if(pSPIx==SPI2)
		{
			SPI2_PCLK_EN();
		}
		else if(pSPIx==SPI3)
		{
			SPI3_PCLK_EN();
		}
		else if(pSPIx==SPI4)
		{
			SPI4_PCLK_EN();
		}}
}
void SPI_Init(SPI_HANDLE_ST *pHandle)
{
	if(pHandle->SPI_Config_Data.BusConfigMode == SPI_FULL_DUPLEX)
	{
		pHandle->pSPIx->CR1.BIDIMODE = 0;
	}
	else if(pHandle->SPI_Config_Data.BusConfigMode == SPI_HALF_DUPLEX)
	{
		pHandle->pSPIx->CR1.BIDIMODE = 1;
	}
	else
	{
		pHandle->pSPIx->CR1.BIDIMODE = 0;
		pHandle->pSPIx->CR1.RXONLY = 1;
	}
	pHandle->pSPIx->CR1.CPHA = pHandle->SPI_Config_Data.CPHA;
	pHandle->pSPIx->CR1.CPOL = pHandle->SPI_Config_Data.CPOL;
	pHandle->pSPIx->CR1.MSTR = pHandle->SPI_Config_Data.SPI_MSMode;
	pHandle->pSPIx->CR1.BR = pHandle->SPI_Config_Data.BaudRate;
	pHandle->pSPIx->CR1.LSBFIRST |= pHandle->SPI_Config_Data.LSBFIRST;
	pHandle->pSPIx->CR1.SSI = pHandle->SPI_Config_Data.SSI;
	pHandle->pSPIx->CR1.SSM = pHandle->SPI_Config_Data.SSM;
	pHandle->pSPIx->CR1.DFF = pHandle->SPI_Config_Data.DFF;

}
void SPI_DeInit(SPI_REG_ST *pSPIx)
{

}
void SPI_SSOE_ctl(SPI_REG_ST *pSPIx)
{
	/*LSB FIRST B7*/
	pSPIx->CR2.SSOE = 1;
}
void SPI_Enable(SPI_REG_ST *pSPIx)
{
	/*LSB FIRST B7*/
	pSPIx->CR1.SPE = 1;
}
void SPI_Disable(SPI_REG_ST *pSPIx)
{
	/*LSB FIRST B7*/
	pSPIx->CR1.SPE = 0;
}
uint8_t SPI_Busy(SPI_REG_ST *pSPIx)
{
	/*LSB FIRST B7*/
	return((uint8_t)(pSPIx->SR.BSY));
}
uint8_t SPI_SendData(SPI_REG_ST *pSPIx, char *Data, uint32_t Len)
{
	/*Blocking Type Call*/

	uint8_t status = SPI_TX_BUSY;
	uint8_t timeout = 0;

	uint32_t i = 65535;

	while( (Len > 0) & (timeout < 20))
	{
		if( pSPIx->SR.TXE == 1 )
		{
			if(pSPIx->CR1.DFF == SPI_8_BIT_DFF)
			{
				//i=65535; while(i>0){	i--;}

				pSPIx->DR = (uint32_t)(255 & (*Data));
			}
			else
			{
				pSPIx->DR = (uint32_t)(65535 & *((uint16_t*)Data));
				Len--;
				Data++;
			}
			Len--;
			Data++;
		}
		else
		{
			//timeout++;
		}
	}
	if(Len==0)
	{
		status = SPI_TX_SUCESS;
	}
	return(status);
}

uint8_t SPI_RecieveData(SPI_REG_ST *pSPIx, uint16_t *Data)
{

	uint8_t newdata = SPI_RX_NO_NEW_DATA;
	if( pSPIx->SR.RXNE == 1 )
	{
		*Data = (uint16_t)pSPIx->DR;
		newdata = SPI_RX_GOOD_NEW_DATA;
	}
	return(newdata);
};
