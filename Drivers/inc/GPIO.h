/*
 * GPIO.h
 *
 *  Created on: Apr 16, 2019
 *      Author: manu
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stdint.h"
#include "STM32F4xx.h"

typedef struct
{
	uint8_t Pinx; 		/* (where x =A..I/J/K) */
	uint8_t Direction; 		/* (where x =A..I/J/K) */
	uint8_t OutputType; 		/* (where x =A..I/J/K) */
	uint8_t Speed; 	/* (where x =A..I/J/K) */
	uint8_t PullUpPullDn;
	uint8_t AltFunction; 		/* (where x =A..I/J/K) High Low Combine */
}GPIO_CONFIG_ST;

typedef struct
{
	GPIO_REG_ST *pGPIOx;
	GPIO_CONFIG_ST GPIO_Config_Data;

}GPIO_HANDLE_ST;

void GPIO_Clk_Cntl(GPIO_REG_ST *pGPIOx, uint8_t EN_DI);
void GPIO_Init(GPIO_HANDLE_ST *pHandle);
void GPIO_DeInit(GPIO_REG_ST *pGPIOx);

uint8_t GPIO_ReadPin(GPIO_REG_ST *pGPIOx, uint8_t Pinx);
uint16_t GPIO_ReadPort(GPIO_REG_ST *pGPIOx);

void GPIO_WritePin(GPIO_REG_ST *pGPIOx, uint8_t Pinx, uint8_t Value);
void GPIO_WritePort(GPIO_REG_ST *pGPIOx, uint32_t Value);
void GPIO_ToggleOutPin(GPIO_REG_ST *pGPIOx, uint8_t Pinx);

void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t EN_DI);
void GPIO_IRQPRQConfig(uint8_t IRQ_Number, uint8_t Priority);
void GPIO_IRQHandle(uint8_t IRQ_Number);

#define GPIO_MODE_IN 0
#define GPIO_MODE_OUT 1
#define GPIO_MODE_ALT 2
#define GPIO_MODE_ANLG 3
#define GPIO_MODE_INT_RET 4
#define GPIO_MODE_INT_FET 5
#define GPIO_MODE_INT_REFET 6

#define GPIO_OUTTYPE_PSPU 0
#define GPIO_OUTTYPE_OD 1

#define GPIO_SPD_LW 0
#define GPIO_SPD_MED 1
#define GPIO_SPD_HIGH 2
#define GPIO_SPD_VHIGH 3

#define GPIO_PSPU_NOPUPD 0
#define GPIO_PSPU_NOPUUP 1
#define GPIO_PSPU_NOPUDN 2


#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8SYSCFG->
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#endif /* INC_GPIO_H_ */

