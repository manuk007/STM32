/*
 * I2C.c
 *
 *  Created on: Jul 21, 2019
 *      Author: manu
 */

#include "I2C.h"

void I2C_Init(I2C_HANDLE_ST* I2C_xhandle){

	/* ACK */
	I2C_xhandle->pI2Cx->CR1.ACK = I2C_xhandle->I2C_Config_Data.ACKEN;
	/*I2C_xhandle->I2C_Config_Data.DutyCyle =
			I2C_xhandle->I2C_Config_Data.I2C_Mode =
					I2C_xhandle->I2C_Config_Data.Speed =
					I2C_xhandle->I2C_Config_Data.ACK =*/

	/* FREQ */
	I2C_xhandle->pI2Cx->CR2.FREQ = RCC_getPCLK1Value() / 1000000;

	/* ADDR */
	I2C_xhandle->pI2Cx->OAR1.ADD7_1 = I2C_xhandle->I2C_Config_Data.ADDRESS;

	/* speed */
	if(I2C_xhandle->I2C_Config_Data.Speed <= I2C_SPEED_SM)
	{
		I2C_xhandle->pI2Cx->CCR.FS   = 0;
		I2C_xhandle->pI2Cx->CCR.CCR   = RCC_getPCLK1Value()
			                        																								/(2 * I2C_xhandle->I2C_Config_Data.Speed);

		/*TRISE*/
		I2C_xhandle->pI2Cx->TRISE.TRISE_5_0 = (RCC_getPCLK1Value()/1000000) + 1;

	}
	else
	{
		I2C_xhandle->pI2Cx->CCR.FS   = 1;
		I2C_xhandle->pI2Cx->CCR.DUTY   = I2C_xhandle->I2C_Config_Data.DutyCyle;
		I2C_xhandle->pI2Cx->CCR.CCR   = RCC_getPCLK1Value()
			                        																								/((I2C_xhandle->I2C_Config_Data.DutyCyle?25:3)
			                        																										* I2C_xhandle->I2C_Config_Data.Speed);

		/*TRISE*/
		I2C_xhandle->pI2Cx->TRISE.TRISE_5_0 = (RCC_getPCLK1Value()*300 / 1000000) + 1;

	}}


void I2C_MasterSend(I2C_HANDLE_ST* I2C_xhandle, uint32_t SAddr,
		uint32_t * Data ,uint32_t size){

	volatile I2C_SR1_REG_ST  AddrClrFlag1;
	volatile I2C_SR2_REG_ST  AddrClrFlag2;

	// Clock
	I2C_Clk_Cntl(I2C1,1);

	//1. Generate Start condition
	I2C_xhandle->pI2Cx->CR1.START = 1;

	//2. Check SB to confirm Start is generated
	while(!I2C_xhandle->pI2Cx->SR1.SB);

	//3. Send the address of slave with r/w bit
	I2C_xhandle->pI2Cx->DR &= (uint32_t)(0xfff0 | ((SAddr<<1)|0x0));

	//4. confirm Addr phase is complete by checking addr
	while(!I2C_xhandle->pI2Cx->SR1.ADDR);

	//5. clear addr
	AddrClrFlag1 = (I2C_xhandle->pI2Cx->SR1);
	AddrClrFlag2 = (I2C_xhandle->pI2Cx->SR2);

	//6. send the data untill Len becomes 0
	while(size > 0)
	{
		if(I2C_xhandle->pI2Cx->SR1.TxE)
		{
			I2C_xhandle->pI2Cx->DR &= (uint32_t)(0xfff0 | (*Data));
			while(!I2C_xhandle->pI2Cx->SR1.BTF);
			size--;
			Data++;
		}
	}
	//7. Ensure TXE and BFT is zero and generate stop sequence.
	while(!I2C_xhandle->pI2Cx->SR1.TxE);
	while(!I2C_xhandle->pI2Cx->SR1.BTF);
	I2C_xhandle->pI2Cx->CR1.STOP = 1;
}

void I2C_MasterRecieve(I2C_HANDLE_ST* I2C_xhandle, uint32_t SAddr,
		uint32_t * Data ,uint32_t  size){

	volatile I2C_SR1_REG_ST  AddrClrFlag1;
	volatile I2C_SR2_REG_ST  AddrClrFlag2;

	// Clock
	I2C_Clk_Cntl(I2C1,1);

	//1. Generate Start condition
	I2C_xhandle->pI2Cx->CR1.START = 1;

	//2. Check SB to confirm Start is generated
	while(!I2C_xhandle->pI2Cx->SR1.SB);

	//3. Send the address of slave with r/w bit
	I2C_xhandle->pI2Cx->DR &= (uint32_t)(0xfff0 | ((SAddr<<1)|0x0));

	//4. confirm Addr phase is complete by checking addr
	while(!I2C_xhandle->pI2Cx->SR1.ADDR);

	//5.if 1 byte
	if(size == 1)
	{
		/*5. ACK */
		I2C_xhandle->pI2Cx->CR1.ACK = 0;

		//5. clear addr
		AddrClrFlag1 = (I2C_xhandle->pI2Cx->SR1);
		AddrClrFlag2 = (I2C_xhandle->pI2Cx->SR2);

		//7.wait for RXNE
		while(!I2C_xhandle->pI2Cx->SR1.RxNE);

		//8.generate stop bit
		I2C_xhandle->pI2Cx->CR1.STOP = 1;

		//9.read data into buffer
		*Data = (uint32_t) I2C_xhandle->pI2Cx->DR;

	}
	//10. if len > 1
	else
	{
		//12.clear addr
		while(size > 0)
		{
			//5. clear addr
			AddrClrFlag1 = (I2C_xhandle->pI2Cx->SR1);
			AddrClrFlag2 = (I2C_xhandle->pI2Cx->SR2);

			//13.wait for rxne
			while(!I2C_xhandle->pI2Cx->SR1.RxNE);

			//14.if second last byte
			if(size == 2)
			{
				//15 clear ack
				I2C_xhandle->pI2Cx->CR1.ACK = 0;

				//8.generate stop bit
				I2C_xhandle->pI2Cx->CR1.STOP = 1;

				//17 read data in buffer
				I2C_xhandle->pI2Cx->DR &= (uint32_t)(0xfff0 | (*Data));

			}

			//18 increment buffer
			size--;
			Data++;
		}
	}

}










void I2C_Clk_Cntl(I2C_REG_ST *pI2Cx, uint8_t EN_DI)
{
	if(EN_DI)
	{
		if(pI2Cx==I2C1)
		{
			I2C1_PCLK_EN();
		}
		else if(pI2Cx==I2C2)
		{
			I2C2_PCLK_EN();
		}
		else if(pI2Cx==I2C3)
		{
			I2C3_PCLK_EN();
		}else
		{
		}
	}
	else
	{
		if(pI2Cx==I2C1)
		{
			I2C1_PCLK_EN();
		}
		else if(pI2Cx==I2C2)
		{
			I2C2_PCLK_EN();
		}
		else if(pI2Cx==I2C3)
		{
			I2C3_PCLK_EN();
		}
	}
}

void I2C_Enable(I2C_HANDLE_ST* I2C_xhandle)
{
	I2C_xhandle->pI2Cx->CR1.PE = 1;
	return;
}
