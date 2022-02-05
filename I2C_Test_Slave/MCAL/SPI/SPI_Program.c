/*
 * SPI_Program.c
 *
 *  Created on: Jan 25, 2022
 *      Author: Abdelrahman Mohamed
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"


void SPI_MasterInit(void)
{
	/* Set MOSI and SCK output, all others input */
	SPI_DDRB = (1<<MOSI)|(1<<SCK);

	/* Configure SPI Oscillator Frequency based on Configuration file*/
#if  SCK_Frequency == FCPU_2
	SET_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_4
	CLR_BIT(SPI_SPCR,SPR0);
	CLR_BIT(SPI_SPCR,SPR1);
	CLR_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_8
	SET_BIT(SPI_SPCR,SPR0);
	CLR_BIT(SPI_SPCR,SPR1);
	SET_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_16
	SET_BIT(SPI_SPCR,SPR0);
	CLR_BIT(SPI_SPCR,SPR1);
	CLR_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_32
	CLR_BIT(SPI_SPCR,SPR0);
	SET_BIT(SPI_SPCR,SPR1);
	SET_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_64
	CLR_BIT(SPI_SPCR,SPR0);
	SET_BIT(SPI_SPCR,SPR1);
	CLR_BIT(SPI_SPSR,SPI2X);
#elif  SPI_CLK == FCPU_128
	SET_BIT(SPI_SPCR,SPR0);
	SET_BIT(SPI_SPCR,SPR1);
	CLR_BIT(SPI_SPSR,SPI2X);
#else
#error "Wrong Frequency Check configuration file"
#endif

#if DATA_MODE 	==	SAMPLE_RISING_LEADING_EDGE
	CLR_BIT(SPI_SPCR,CPOL);
	CLR_BIT(SPI_SPCR,CPHA);
#elif DATA_MODE 	==	SETUP_RISING_LEADING_EDGE
	CLR_BIT(SPI_SPCR,CPOL);
	SET_BIT(SPI_SPCR,CPHA);
#elif DATA_MODE 	==	SAMPLE_FALLING_LEADING_EDGE
	SET_BIT(SPI_SPCR,CPOL);
	CLR_BIT(SPI_SPCR,CPHA);
#elif DATA_MODE 	==	SETUP_FALLING_LEADING_EDGE
	SET_BIT(SPI_SPCR,CPOL);
	SET_BIT(SPI_SPCR,CPHA);

#else
#error "Wrong DATA MODE Check configuration file"
#endif


#if SPI_INTERRUPT	== INTERRPUT_Enable
	SET_BIT(SPI_SPCR,SPIE);
#elif	SPI_INTERRUPT	== INTERRPUT_DISABLE
	CLR_BIT(SPI_SPCR,SPIE);
#else
#error "Wrong Interrupt setting Check configuration file"
#endif


#if	DATA_ORDER ==	MSB_FIRST
	CLR_BIT(SPI_SPCR,DORD);
#elif DATA_ORDER	LSB_FIRST
	SET_BIT(SPI_SPCR,DORD);
#else
#error "Wrong Interrupt setting Check configuration file"
#endif
	/* Enable SPI, Master */
	SPI_SPCR |= (1<<SPE)|(1<<MSTR);
}

void SPI_MasterTransmit(uint8_t cData)
{
	/* Start transmission */
	SPI_SPDR = cData;
	/* Wait for transmission complete */
	while(!(SPI_SPSR & (1<<SPIF)));

}



void SPI_SlaveInit(void)
{
	/* Set MISO output, all others input */
	SPI_DDRB = (1<<MISO);
	/* Enable SPI */
	SPI_SPCR = (1<<SPE);
}

uint8_t SPI_SlaveReceive(void)
{
	/* Wait for reception complete */
	while(!(SPI_SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPI_SPDR;
}
