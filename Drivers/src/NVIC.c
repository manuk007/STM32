/*
 * NVIC.c
 *
 *  Created on: Apr 20, 2019
 *      Author: manu
 */


#include "stdint.h"
#include "STM32F4xx.h"

 uint32_t *NVIC_ISER = (uint32_t*)DRV_NVIC_ISER_START;
 uint32_t *NVIC_ICER = (uint32_t*)DRV_NVIC_ICER_START;
 uint32_t *IRQ_PRIORITY =(uint32_t*)DRV_IRQ_PRIORITY_START;
