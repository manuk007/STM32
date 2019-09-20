/*
 * RCC.c
 *
 *  Created on: Apr 19, 2019
 *      Author: manu
 */


#include "stdint.h"
#include "STM32F4xx.h"

#define AHB_PRESCALAR_LOOKUP(x) (1<<(x-7))
#define APB1_PRESCALAR_LOOKUP(x) (1<<(x-3))

RCC_REG_ST *RCC = (RCC_REG_ST*)DRV_RCC;

uint32_t RCC_getCLKSource(void)
{
	return((uint32_t) (RCC->CFGR.SWS));
}
uint32_t RCC_getPCLK1Value(void)
{
	uint32_t clksource,speed,AHBP,APB1P;
	clksource = RCC_getCLKSource();

	switch(clksource)
	{
	case 0:
		speed = 16000000;
		break;
	case 1:
		speed = 80000000;
		break;
	case 2: /*PLL zero for now*/
		speed = 0;
		break;
	default:
		break;
	};
	AHBP = AHB_PRESCALAR_LOOKUP(RCC->CFGR.HPRE);
	APB1P = APB1_PRESCALAR_LOOKUP(RCC->CFGR.PPRE1);

	return((speed/AHBP)/APB1P);
}
