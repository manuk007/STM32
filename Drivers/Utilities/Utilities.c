/*
 * Utilities.c
 *
 *  Created on: May 6, 2019
 *      Author: manu
 */

#include "stdint.h"
#include "Utilities.h"

uint8_t OneShotTest(uint8_t Condition, uint32_t count){

	uint32_t Temp=0;
	uint32_t Wait=count;

	while(Wait > 0)
	{
		if(Condition)
		{
			Temp++;
		}
		Wait--;
	}
	return((uint8_t)(Temp == count));
}
