/*
 * GPIO.c
 *
 *  Created on: Apr 18, 2019
 *      Author: manu
 */

#include "GPIO.h"
#include "STM32F4xx.h"

void GPIO_Clk_Cntl(GPIO_REG_ST *pGPIOx, uint8_t EN_DI)
{
	if(EN_DI == ENABLE)/*Reset GPIO Clock*/
	{
		GPIO_PCLK_EN(PORTNAME(pGPIOx));
	}
	else
	{
		GPIO_PCLK_DI(PORTNAME(pGPIOx));
	}
}

void GPIO_Init(GPIO_HANDLE_ST *pHandle)
{

	//pHandle->pGPIOx->MODER = SetBits(1,1,1,1);
	uint32_t AltIndex=0;

	if(pHandle->GPIO_Config_Data.Direction <= GPIO_MODE_ANLG)
	{

		/*Speed*/
		pHandle->pGPIOx->OSPEEDR=SetBits(pHandle->pGPIOx->OSPEEDR,
				(uint32_t)(2 * pHandle->GPIO_Config_Data.Pinx),
				(uint32_t)(pHandle->GPIO_Config_Data.Speed),
				(uint32_t)3);

		/*outputType*/
		if((pHandle->GPIO_Config_Data.Direction == GPIO_MODE_OUT)
				|| (pHandle->GPIO_Config_Data.Direction == GPIO_MODE_ALT))
		{
			pHandle->pGPIOx->OTYPER=SetBits(pHandle->pGPIOx->OTYPER,
					(uint32_t)(1 * pHandle->GPIO_Config_Data.Pinx),
					(uint32_t)(pHandle->GPIO_Config_Data.OutputType),
					(uint32_t)1);
		}
		/*Pull-up-PullDown*/
		pHandle->pGPIOx->PUPDR=SetBits(pHandle->pGPIOx->PUPDR,
				(uint32_t)(1 * pHandle->GPIO_Config_Data.Pinx),
				(uint32_t)(pHandle->GPIO_Config_Data.PullUpPullDn),
				(uint32_t)1);

		/*Alternate Function*/
		if(pHandle->GPIO_Config_Data.Direction == GPIO_MODE_ALT)
		{
			AltIndex = ((pHandle->GPIO_Config_Data.Pinx)>7)?1:0;
			pHandle->pGPIOx->AFR[AltIndex]=
					SetBits(pHandle->pGPIOx->AFR[AltIndex],
							(uint32_t)(4 * (pHandle->GPIO_Config_Data.Pinx % 8)),
							(uint32_t)(pHandle->GPIO_Config_Data.AltFunction),
							(uint32_t)15);
		}

		/*MOde*/
		pHandle->pGPIOx->MODER = SetBits(pHandle->pGPIOx->MODER,
				(uint32_t)(2 * pHandle->GPIO_Config_Data.Pinx),
				(uint32_t)(pHandle->GPIO_Config_Data.Direction),
				(uint32_t)3);

	}
	else
	{
		SYSCFG_PCLK_EN();
		SYSCFG->EXTICR[pHandle->GPIO_Config_Data.Pinx/4] =
				SetBits(SYSCFG->EXTICR[pHandle->GPIO_Config_Data.Pinx/4] ,
						(uint32_t)(2 * pHandle->GPIO_Config_Data.Pinx%4),
						0,15);

		if(pHandle->GPIO_Config_Data.Direction == GPIO_MODE_INT_RET)
		{
			EXTI->RTSR|=(1<<pHandle->GPIO_Config_Data.Pinx);
		}
		if(pHandle->GPIO_Config_Data.Direction == GPIO_MODE_INT_FET)
		{
			EXTI->FTSR|=(1<<pHandle->GPIO_Config_Data.Pinx);
		}
		if(pHandle->GPIO_Config_Data.Direction == GPIO_MODE_INT_REFET)
		{
			EXTI->RTSR|=(1<<pHandle->GPIO_Config_Data.Pinx);
			EXTI->FTSR|=(1<<pHandle->GPIO_Config_Data.Pinx);
		}
		EXTI->IMR|=(1<<pHandle->GPIO_Config_Data.Pinx);
	}
}
void GPIO_DeInit(GPIO_REG_ST *pGPIOx)
{
	GPIO_REG_RESET(PORTNAME(pGPIOx));
}

uint8_t GPIO_ReadPin(GPIO_REG_ST *pGPIOx, uint8_t Pinx)
{
	uint8_t val=0;
	val = (uint8_t)((pGPIOx->IDR >> Pinx) & 1);
	return val;
}

uint16_t GPIO_ReadPort(GPIO_REG_ST *pGPIOx)
{
	uint16_t val=0;
	val = (uint16_t)(pGPIOx->IDR);
	return val;
}

void GPIO_WritePin(GPIO_REG_ST *pGPIOx, uint8_t Pinx, uint8_t Value)
{
	if(Value)
	{
		pGPIOx->ODR |= (1 << Pinx);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << Pinx);
	}/*Reset GPIO Clock*/
}
void GPIO_WritePort(GPIO_REG_ST *pGPIOx, uint32_t Value)
{
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutPin(GPIO_REG_ST *pGPIOx, uint8_t Pinx)
{
	pGPIOx->ODR ^= (1 << Pinx);
}

void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t EN_DI)
{
	uint32_t *pICSER;
	if(EN_DI)
	{
		pICSER = NVIC_ISER + (4* (uint32_t)(IRQ_Number/32));
		*(pICSER) |= (1<<(IRQ_Number%32));
	}
	else
	{
		pICSER = NVIC_ICER + (4* (uint32_t)(IRQ_Number/32));
		*(pICSER) &= ~(1<<IRQ_Number%32);
	}
}
void GPIO_IRQPRQConfig(uint8_t IRQ_Number, uint8_t Priority)
{
	uint32_t *pIRQPRI;
	pIRQPRI = IRQ_PRIORITY + (4 * (IRQ_Number / 4));
	*pIRQPRI = SetBits(*pIRQPRI,(8*(IRQ_Number%4)+4),Priority,(uint32_t)15);
}
void GPIO_IRQHandle(uint8_t Pinx)
{
	if((EXTI->PR & (1 << Pinx)))
	{
		EXTI->PR |=  (1 << Pinx);
	}
}
