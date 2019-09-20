/*
 * STM32F4xx.h
 *
 *  Created on: Apr 16, 2019
 *      Author: manu
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include "stdint.h"

/****CROTEX M PROCESSOR ADD*****/
#define DRV_NVIC_ISER_START 0xE000E100
#define DRV_NVIC_ICER_START 0xE000E180
#define DRV_IRQ_PRIORITY_START 0xE000E400

/* Memory Address*/
#define DRV_FLASHSTART 0x08000000U
#define DRV_SRAM1START 0x20000000U
#define DRV_SRAM2START 0x2001C000U

/* PERIPHERALS Address*/
#define DRV_PERIPHERALSSTART 0x40000000U
#define DRV_APB1START 0x40000000U
#define DRV_APB2START 0x40010000U
#define DRV_AHB1START 0x40020000U
#define DRV_AHB2START 0x50000000U
#define DRV_AHB3START 0x60000000U

/* APB1 PERIPHERALS Address*/
/* #define DRV_RESERVED 0x40007800U */
#define DRV_DAC 	0x40007400U
#define DRV_PWR 	0x40007000U
/* #define DRV_RESERVED 0x40006C00U */
#define DRV_CAN2 	0x40006800U
#define DRV_CAN1 	0x40006400U
/* #define DRV_RESERVED 0x40006000U */
#define DRV_I2C3 	0x40005C00U
#define DRV_I2C2 	0x40005800U
#define DRV_I2C1 	0x40005400U
#define DRV_UART5 	0x40005000U
#define DRV_UART4 	0x40004C00U
#define DRV_USART3 	0x40004800U
#define DRV_USART2  0x40004400U
#define DRV_I2S3EXT 0x40004000U
#define DRV_SPI3 	0x40003C00U
#define DRV_SPI2 	0x40003800U
#define DRV_I2S2EXT 0x40003400U
#define DRV_IWDG 	0x40003000U18
#define DRV_WWDG 	0x40002C00U
#define DRV_RTC 	0x40002800U
/* #define DRV_RESERVED 0x40002400U */
#define DRV_TIM14 	0x40002000U
#define DRV_TIM13 	0x40001C00U
#define DRV_TIM12 	0x40001800U
#define DRV_TIM7 	0x40001400U
#define DRV_TIM6 	0x40001000U
#define DRV_TIM5 	0x40000C00U
#define DRV_TIM4 	0x40000800U
#define DRV_TIM3 	0x40000400U
#define DRV_TIM2 	0x40000000U

/* APB2 PERIPHERALS Address*/
/*#define DRV_RESERVED 	0x40014C00U*/
#define DRV_TIM11 		0x40014800U
#define DRV_TIM10 		0x40014400U
#define DRV_TIM9 		0x40014000U
#define DRV_EXTI 		0x40013C00U
#define DRV_SYSCFG 		0x40013800U
#define DRV_SPI4     	0x40013400U
#define DRV_SPI1 		0x40013000U
#define DRV_SDIO 		0x40012C00U
/*#define DRV_RESERVED 	0x40012400U*/
#define DRV_ADC1 		0x40012000U
/*#define DRV_RESERVED 	0x40011800U*/
#define DRV_USART6 		0x40011400U
#define DRV_USART1 		0x40DRV_EXTI011000U
/*#define DRV_RESER	else
	{

	}VED 	0x40010800U*/
#define DRV_TIM8 		0x40010400U
#define DRV_TIM1 		0x40010000U


/* AHB1 PERIPHERALS Address*/
#define DRV_USB_OTG_HS 		0x40040000U
/*#define DRV_RE
 * SERVED 		0x40029400U*/
#define DRV_ETHERNET_MAC 	0x40028000U
#define DRV_RESERVED 		0x40026800U*/
#define DRV_DMA2			0x40026400U
#define DRV_DMA1 			0x40026000U
/*#define DRV_RESERVED 		0x40025000U*/
#define DRV_BKPSRAM 		0x4001824000U
#define DRV_FLASH_INT_REG 	0x40023C00U
#define DRV_RCC 			0x40023800U
/*#define DRV_RESERVED 		0x40023400U*/
#define DRV_CRC 			0x40023000U
/*#define DRV_RESERVED 		0x40022400U*/
#define DRV_GPIOI 			0x40022000U
#define DRV_GPIOH 			0x40021C00U
#define DRV_GPIOG 			0x40021800U
#define DRV_GPIOF 			0x40021400U
#define DRV_GPIOE 			0x40021000U
#define DRV_GPIOD 			0x40020C00U
#define DRV_GPIOC 			0x40020800U
#define DRV_GPIOB 			0x40020400U
#define DRV_GPIOA 			0x40020000U

/* AHB2 PERIPHERALNVIC_ISER+(uint32_t)(IRQ_Number/31)
SYSCFG_REG_ST *SYSCFG = (SYSCFG_REG_ST*)DRV_SYSCFG;S Address*/
#define DRV_RNG 			0x50060800U
/*#define DRV_RESERVED 		0x50050400U*/
#define DRV_DCMI 			0x50050000U

/* AHB3 PERIPHERALS Address*/
#define DRV_FSMCCNTREG 		0xA00000000U
#define DRV_FSMCBANK4 		0xA00000000U
#define DRV_FSMCBANK3 		0xA00000000U
#define DRV_FSMCBANK2 		0xA00000000U
#define DRV_FSMCBANK1 		0xA00000000U

/*********************************************RCC************************/

typedef struct
{
	volatile uint32_t MCO2: 2         ;/*Bits 31:30 Microcontroller clock output 2 */
	volatile uint32_t MCO2PRE:3   ;/* Bits 27:29  MCO2 prescaler  */
	volatile uint32_t MCO1PRE:3   ;/* Bits 24:26  MCO1 prescaler  */
	volatile uint32_t I2SSRC:1       ; /*Bit 23        I2S clock selection */
	volatile uint32_t MCO1:2          ;/*Bits 22:21  Microcontroller clock output 1 */
	volatile uint32_t RTCPRE:5      ;/*Bits 20:16  HSE division factor for RTC clock */
	volatile uint32_t PPRE2:3         ;/*Bits 15:13 APB high-speed prescaler (APB2) */
	volatile uint32_t PPRE1:3         ;/*Bits 12:10 APB Low speed prescaler (APB1) */
	volatile uint32_t Reserved:2     ;/* Bits 9:8     must be kept at reset value.  */
	volatile uint32_t HPRE:4          ;/* Bits 7:4     AHB prescaler   */
	volatile uint32_t SWS: 2           ;/*Bits 3:2    System clock switch status */
	volatile uint32_t SW:2              ;/* Bits 1:0    System clock switch  */
}RCCGFR_REG_ST;

typedef struct
{
	volatile uint32_t CR; 				/* */
	volatile uint32_t PLLCFGR; 			/*  */
	volatile RCCGFR_REG_ST CFGR; 				/* */
	volatile uint32_t CIR; 				/* */
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR; 			/*  */
	volatile uint32_t AHB3RSDRV_EXTITR; 			/*  */
	volatile uint32_t Reserved0; 		/* */
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t Reserved1;
	volatile uint32_t Reserved2;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB225ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t Reserved3;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t Reserved4;
	volatile uint32_t Reserved5;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t Reserved6;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t Reserved7;
	volatile uint32_t Reserved8;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t Reserved9;
	volatile uint32_t Reserved10;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t PLLSAICFGR;
	volatile uint32_t DCKCFGR;
}RCC_REG_ST;

/*********************************************GPIO************************/

typedef struct
{
	volatile uint32_t MODER; 		/* (where x =A..I/J/K) */
	volatile uint32_t OTYPER; ;		/* (where x =A..I/J/K) */
	volatile uint32_t OSPEEDR; 		/* (where x =A..I/J/K) */
	volatile uint32_t PUPDR;
	volatile uint32_t IDR; 			/* (where x =A..I/J/K) */
	volatile uint32_t ODR; 			/* (where x =A..I/J/K) */
	volatile uint32_t BSRR; 		/* (where x =A..I/J/K) */
	volatile uint32_t LCKR; 		/* (where x =A..I/J/K) */
	volatile uint32_t AFR[2]; 		/* (where x =A..I/J/K) High Low Combine */
}GPIO_REG_ST;

#define GPIOA  (GPIO_REG_ST*) DRV_GPIOA
#define GPIOB  (GPIO_REG_ST*) DRV_GPIOB
#define GPIOC  (GPIO_REG_ST*) DRV_GPIOC
#define GPIOD  (GPIO_REG_ST*) DRV_GPIOD
#define GPIOE  (GPIO_REG_ST*) DRV_GPIOE
#define GPIOF  (GPIO_REG_ST*) DRV_GPIOF
#define GPIOG  (GPIO_REG_ST*) DRV_GPIOG
#define GPIOH  (GPIO_REG_ST*) DRV_GPIOH
#define GPIOI  (GPIO_REG_ST*) DRV_GPIOI

#define PORTNAME(x) (x==GPIOA?0:\
		x==GPIOB?1:\
				x==GPIOC?2:\
						x==GPIOD?3:\
								x==GPIOE?4:\
										x==GPIOF?5:\
												x==GPIOG?6:\
														x==GPIOH?7:8)

/*Reset GPIO Clock*/
#define GPIO_REG_RESET(x)    do{  (RCC->AHB1RSTR |= (1 << x))  ; (RCC -> AHB1RSTR &= ~(1 << x)); }while(0)

/*Enable GPIO Clock*/
#define GPIO_PCLK_EN(x) (RCC->AHB1ENR |= (1 << x))

/*Disable GPIO Clock*/
#define GPIO_PCLK_DI(x) (RCC->AHB1ENR &= ~(1 << x))

/*********************************************SPI************************/

typedef struct
{
	volatile uint32_t CPHA:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t CPOL:1; ;		/* (where x =A..I/J/K) */
	volatile uint32_t MSTR:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t BR:3;
	volatile uint32_t SPE:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t LSBFIRST:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t SSI:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t SSM:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t RXONLY:1; 		/* (where x =A..I/J/K) High Low Combine */
	volatile uint32_t DFF:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t CRCNEXT:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t CRCEN:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t BIDIOE:1; 		/* (where x =A..I/J/K) High Low Combine */
	volatile uint32_t BIDIMODE:1; 		/* (where x =A..I/J/K) High Low Combine */
	volatile uint32_t Reserve:15; 		/* (where x =A..I/J/K) High Low Combine */
}SPI_CR1_REG_ST;


typedef struct
{
	volatile uint32_t RXDMAEN:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t TXDMAEN:1; ;		/* (where x =A..I/J/K) */
	volatile uint32_t SSOE:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t FRF:1;
	volatile uint32_t ERRIE:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t RXNEIE:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t TXEIE:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t Reserve:25; 		/* (where x =A..I/J/K) High Low Combine */
}SPI_CR2_REG_ST;

typedef struct
{
	volatile uint32_t RXNE:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t TXE:1; ;		/* (where x =A..I/J/K) */
	volatile uint32_t CHSIDE:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t UDR:1;
	volatile uint32_t CRCERR:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t MODF:1; 			/* (where x =A..I/J/K) */
	volatile uint32_t OVR:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t BSY:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t FRE:1; 		/* (where x =A..I/J/K) */
	volatile uint32_t Reserve:23; 		/* (where x =A..I/J/K) High Low Combine */
}SPI_STS_REG_ST;

typedef struct
{
	volatile SPI_CR1_REG_ST CR1; 		/* (where x =A..I/J/K) */
	volatile SPI_CR2_REG_ST CR2; ;		/* (where x =A..I/J/K) */
	volatile SPI_STS_REG_ST SR; 		/* (where x =A..I/J/K) */
	volatile uint32_t DR;
	volatile uint32_t CRCPR; 			/* (where x =A..I/J/K) */
	volatile uint32_t RXCRCR; 			/* (where x =A..I/J/K) */
	volatile uint32_t TXCRCR; 		/* (where x =A..I/J/K) */
	volatile uint32_t I2SCFGR; 		/* (where x =A..I/J/K) */
	volatile uint32_t I2SPR; 		/* (where x =A..I/J/K) High Low Combine */
}SPI_REG_ST;

#define SPI1_PCLK_EN() (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() (RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() (RCC->APB2ENR |= (1 << 13))

#define SPI1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI() (RCC->APB2ENR &= ~(1 << 13))

#define SPI1  (SPI_REG_ST*) DRV_SPI1
#define SPI2  (SPI_REG_ST*) DRV_SPI2
#define SPI3  (SPI_REG_ST*) DRV_SPI3
#define SPI4  (SPI_REG_ST*) DRV_SPI4
/*********************************************I2C************************/
#define I2C1  (I2C_REG_ST*) DRV_I2C1
#define I2C2  (I2C_REG_ST*) DRV_I2C2
#define I2C3  (I2C_REG_ST*) DRV_I2C3

#define I2C1_PCLK_EN() (RCC->APB2ENR |= (1 << 21))
#define I2C2_PCLK_EN() (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() (RCC->APB1ENR |= (1 << 23))

#define I2C1_PCLK_DI() (RCC->APB2ENR &= ~(1 << 21))
#define I2C2_PCLK_DI() (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI() (RCC->APB1ENR &= ~(1 << 23))

typedef struct
{
	volatile uint32_t PE            :1;/* : Peripheral enable                                                                                                          */
	volatile uint32_t SMBUS         :1;/* : SMBus mode                                                                                                                */
	volatile uint32_t Reserved1     :1;/* , must be kept at reset value                                                                                            */
	volatile uint32_t SMBTYPE       :1;/* : SMBus type                                                                                                                 */
	volatile uint32_t ENARP         :1;/* : ARP enable                                                                                                                  */
	volatile uint32_t ENPEC         :1;/* : PEC enable                                                                                                                  */
	volatile uint32_t ENGC          :1;/* : General call enable                                                                                                        */
	volatile uint32_t NOSTRETCH     :1;/* : Clock stretching disable (Slave mode)                                                                             */
	volatile uint32_t START         :1;/* : Start generation                                                                                                            */
	volatile uint32_t STOP          :1;/* : Stop generation                                                                                                             */
	volatile uint32_t  ACK          :1;/* : Acknowledge enable                                                                                                      */
	volatile uint32_t  POS          :1;/* : Acknowledge/PEC Position (for data reception)                                                               */
	volatile uint32_t  PEC          :1;/* : Packet error checking .                                                                                                  */
	volatile uint32_t  ALERT        :1;/* : SMBus alertThis bit is set and cleared by software, and cleared by hardware when PE=0.  */
	volatile uint32_t  Reserved2    :1;/* , must be kept at reset value                                                                                            */
	volatile uint32_t  SWRST        :1;/* : Software resetWhen set, the I2C is under reset state.                                                      */
	volatile uint32_t Reserve3      :15;   /*                                                                                                                                   */
}I2C_CR1_REG_ST;

typedef struct
{

	volatile uint32_t FREQ           :6; /*    Bits 5:0      : Peripheral clock frequency   */
	volatile uint32_t Reserved       :2; /*    Bits 7:6      must be kept at reset value          */
	volatile uint32_t ITERREN        :1; /*    Bit   8         : Error interrupt enable                 */
	volatile uint32_t ITEVTEN        :1; /*    Bit   9         : Event interrupt enable                */
	volatile uint32_t ITBUFEN        :1; /*    Bit   10       : Buffer interrupt enable                */
	volatile uint32_t DMAEN          :1; /*    Bit   11        :       DMA requests enable        */
	volatile uint32_t LAST           :1; /*    Bit   12       : DMA last transfer                */
	volatile uint32_t Reserved1      :3; /*   Bits 15:13  , must be kept at reset value       */
	volatile uint32_t Reserved2      :15; /*Bits 5:0      : Peripheral clock frequency   */
}I2C_CR2_REG_ST;

typedef struct
{
	volatile uint32_t ADD_0           :1;  /* Bit 0      :  nterface address                                          */
	volatile uint32_t ADD7_1          :7;  /* Bit 1    : Interface address       */
	volatile uint32_t ADD9_8          :2; /* Bit 2   : Addressing mode (slave mode)                                                   */
	volatile uint32_t RES             :1;  /* Bit 1    : Address sent (master mode)/matched (slave mode)       */
	volatile uint32_t ADDMODE         :1;  /* Bit 1    : Addressing mode (slave mode)       */
	volatile uint32_t Reserved2       :15; /* Bit 2   : Byte transfer finished                                                   */

}I2C_OAR1_REG_ST;

typedef struct
{
	volatile uint32_t CCR           :12;  /* Bit 0      :  Start bit (Master mode)                                              */
	volatile uint32_t RES           :2;  /* Bit 1    : Address sent (master mode)/matched (slave mode)       */
	volatile uint32_t DUTY          :1; /* Bit 2   : Byte transfer finished                                                   */
	volatile uint32_t FS            :1;  /* Bit 1    : Address sent (master mode)/matched (slave mode)       */
	volatile uint32_t Reserved1     :15; /* Bit 2   : Byte transfer finished                                                   */

}I2C_CCR_REG_ST;
typedef struct
{
	volatile uint32_t SB           :1;  /* Bit 0      :  Start bit (Master mode)                                              */
	volatile uint32_t ADDR         :1;  /* Bit 1    : Address sent (master mode)/matched (slave mode)       */
	volatile uint32_t BTF          :1; /* Bit 2   : Byte transfer finished                                                   */
	volatile uint32_t ADD10        :1; /* Bit 3   : 10-bit header sent (Master mode)                                  */
	volatile uint32_t STOPF        :1;  /* Bit 4    : Stop detection (slave mode)                                         */
	volatile uint32_t Reserved2    :1;  /* Bit 5    , must be kept at reset value                                          */
	volatile uint32_t RxNE         :1;   /* Bit 6     : Data register not empty (receivers)                               */
	volatile uint32_t TxE          :1;  /* Bit 7     Data register empty (transmitters)                                  */
	volatile uint32_t BERR         :1;  /* Bit 8     Bus error                                                                     */
	volatile uint32_t ARLO         :1;  /* Bit 9    : Arbitration lost (master mode)                                       */
	volatile uint32_t AF           :1; /* Bit 10  Acknowledge failure                                                       */
	volatile uint32_t OVR          :1;  /* Bit 11   Overrun/Underrun                                                         */
	volatile uint32_t PECERR       :1;    /* Bit 12   : PEC Error in reception                                                 */
	volatile uint32_t Reserved1    :1;   /* Bit 13   ,   must be kept at reset value                                       */
	volatile uint32_t TIMEOUT      :1;   /* Bit 14  : Timeout or Tlow error                                                   */
	volatile uint32_t SMBALER      :1;   /* Bit 15 : SMBus alert                                                                 */
	volatile uint32_t Reserved3      :15; /*Bits 5:0      : Peripheral clock frequency   */
}I2C_SR1_REG_ST;

typedef struct
{
	volatile uint32_t MSL            :1; /* Bit 0       Master/slave                                                                                                                                                   */
	volatile uint32_t BUSY           :1; /* Bit 1       Bus busy                                                                                                                                                       */
	volatile uint32_t TRA            :1; /*  Bit 2        Transmitter/receiver                                                                                                                                       */
	volatile uint32_t Reserved       :1; /* Bit 3       must be kept at reset value                                                                                                                              */
	volatile uint32_t GENCALL        :1; /* Bit 4       General call address (Slave mode)                                                                                                                   */
	volatile uint32_t SMBDEFAULT     :1; /* Bit 5       SMBus device default address (Slave mode)                                                                                                    */
	volatile uint32_t SMBHOST        :1; /* Bit 6       SMBus host header (Slave mode)                                                                                                                    */
	volatile uint32_t DUALF          :1; /*  Bit 7        Dual flag (Slave mode)– Cleared by hardware after a Stop condition or repeated Start condition, or when PE=0.    */
	volatile uint32_t PEC            :8; /*  Bits 15 8 [7:0] Packet error checking register                                                                                                                 */
	volatile uint32_t Reserved2      :15;
}I2C_SR2_REG_ST;

typedef struct
{
	volatile uint32_t TRISE_5_0      :6; /* Bit 0       Master/slave                                                                                                                                                   */
	volatile uint32_t Res1           :9; /* Bit 1       Bus busy                                                                                                                                                       */
	volatile uint32_t Reserved2      :15;
}I2C_TRISE_REG_ST;

typedef struct
{
	volatile I2C_CR1_REG_ST CR1; 		/* (where x =A..I/J/K) */
	volatile I2C_CR2_REG_ST CR2; ;		/* (where x =A..I/J/K) */
	volatile I2C_OAR1_REG_ST OAR1; 		/* (where x =A..I/J/K) */
	volatile uint32_t OAR2;
	volatile uint32_t DR; 			/* (where x =A..I/J/K) */
	volatile I2C_SR1_REG_ST SR1; 			/* (where x =A..I/J/K) */
	volatile I2C_SR2_REG_ST SR2; 		/* (where x =A..I/J/K) */
	volatile I2C_CCR_REG_ST CCR; 		/* (where x =A..I/J/K) */
	volatile I2C_TRISE_REG_ST TRISE; 		/* (where x =A..I/J/K) High Low Combine */
	volatile uint32_t FLTR; 		/* (where x =A..I/J/K) High Low Combine */
}I2C_REG_ST;

/*********************************************EXTI************************/
typedef struct
{
	volatile uint32_t IMR; 		/* (where x =A..I/J/K) */
	volatile uint32_t EMR; ;		/* (where x =A..I/J/K) */
	volatile uint32_t RTSR; 		/* (where x =A..I/J/K) */
	volatile uint32_t FTSR;
	volatile uint32_t SWIER; 			/* (where x =A..I/J/K) */
	volatile uint32_t PR; 			/* (where x =A..I/J/K) */
}EXTI_REG_ST;

/*#define EXTI_PCLK_EN() (RCC->APB2ENR |= (1 << 12))*/

/*********************************************SYSCONG************************/
typedef struct
{
	volatile uint32_t MEMRMP; 		/* (where x =A..I/J/K) */
	volatile uint32_t PMC; ;		/* (where x =A..I/J/K) */
	volatile uint32_t EXTICR[4]; 		/* (where x =A..I/J/K) */
	volatile uint32_t CMPCR; 			/* (where x =A..I/J/K) */
}SYSCFG_REG_ST;

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))

/****************************************Driver Macros****************/
#define ENABLE 1u
#define DISABLE 0u
#define SET 1u
#define RESET 0u

//#define RCC (RCC_REG_ST*)(0x40023800U)
extern RCC_REG_ST *RCC;
extern SYSCFG_REG_ST *SYSCFG;
extern EXTI_REG_ST *EXTI;
extern  uint32_t *NVIC_ISER;
extern uint32_t *NVIC_ICER;
extern uint32_t *IRQ_PRIORITY;

#define SetBits(reg,loc,val,mask) ((reg & ~((uint32_t)mask << loc)) \
		| ((uint32_t)val << loc))

#endif /* INC_STM32F4XX_H_ */
