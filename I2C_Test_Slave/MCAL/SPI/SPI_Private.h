/*
 * SPI_Private.h
 *
 *  Created on: Jan 25, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPI_SPCR		(*(volatile uint8_t*)(0x2D))	//SPI Control Register
#define SPI_SPSR		(*(volatile uint8_t*)(0x2E))	//SPI Status Register
#define SPI_SPDR		(*(volatile uint8_t*)(0x2F))	//SPI Data Register

#define SPI_PORTB		(*(volatile uint8_t*)(0x38))
#define SPI_DDRB		(*(volatile uint8_t*)(0x37))
#define SPI_PINB		(*(volatile uint8_t*)(0x36))

/*SPI_SPCR Register*/
#define SPIE	7	// SPI Interrupt Enable
#define SPE		6	// SPI Enable
#define DORD	5	// Data Order
#define MSTR	4	// Master/Slave Select
#define CPOL	3	// Clock Polarity
#define CPHA	2	// Clock Phase
#define SPR1	1	// SPI Clock Rate Select 1
#define SPR0	0	// SPI Clock Rate Select 0

/* SPI_SPSR Register*/
#define SPIF	7	// SPI Interrupt Flag
#define WCOL	6	// Write COLlision Flag
#define SPI2X	0	// Double SPI Speed Bit

/* Pins Mapping*/
#define SS		4
#define MOSI	5
#define MISO	6
#define SCK		7


/*Configuration mapping*/
#define FCPU_2  	1
#define FCPU_4  	2
#define FCPU_8  	3
#define FCPU_16 	4
#define FCPU_32 	5
#define FCPU_64 	6
#define FCPU_128	7

#define SAMPLE_RISING_LEADING_EDGE 		1
#define SETUP_RISING_LEADING_EDGE  		2
#define SAMPLE_FALLING_LEADING_EDGE		3
#define SETUP_FALLING_LEADING_EDGE 		4


#define INTERRPUT_ENABLE 		0
#define INTERRPUT_DISABLE		1

#define  LSB_FIRST		1
#define  MSB_FIRST		2


#endif /* SPI_PRIVATE_H_ */
