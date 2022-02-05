/*
 * I2C_Private.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


/*********I2C Registers*********/
/*Bit Rate Register*/
#define I2C_TWBR	(*(volatile uint8_t*)(0x20))
/*Control Register*/
#define I2C_TWCR	(*(volatile uint8_t*)(0x56))
/* Status Register*/
#define I2C_TWSR	(*(volatile uint8_t*)(0x21))
/* Data Register */
#define I2C_TWDR	(*(volatile uint8_t*)(0x23))
/* Slave Address Register*/
#define I2C_TWAR	(*(volatile uint8_t*)(0x22))

/* TWSR Status Mask*/
#define TWSR_STATUS_MASK	0xF8



/* I2C Status Bits in the TWSR Register */
#define I2C_START         0x08 // start has been sent
#define I2C_REP_START     0x10 // repeated START condition has been transmitted
#define I2C_MT_SLA_W_ACK  0x18 // Master transmit SLA+W has been transmitted; ACK has been received
#define I2C_MT_SLA_W_NACK 0x20 // Master transmit SLA+W has been transmitted; NOT ACK has been received
#define I2C_MT_DATA_ACK   0x28 // Master transmit Data byte has been transmitted; ACK has been received
#define I2C_MT_DATA_NACK  0x30 // Master transmit Data byte has been transmitted; NOT ACK has been received
#define I2C_MT_LOSS_ARB   0x38 // Master transmit Arbitration lost in SLA+W or data bytes
#define I2C_MT_SLA_R_ACK  0x40 // Master transmit SLA+R has been transmitted; ACK has been received
#define I2C_MT_SLA_R_NACK 0x48 // Master transmit SLA+R has been transmitted; NOT ACK has been received
#define I2C_MR_DATA_ACK   0x50 // Master received data and send ACK
#define I2C_MR_DATA_NACK  0x58 // Master received data and send NOT ACK
#define I2C_SR_SLA_ACK	0x60	//Own SLA+W has been received; ACK has been returned
#define I2C_SR_DATA_ACK	0x80	//Previously addressed with own SLA+W; data has been received; ACK has been returned


/*I2C_TWCR Register */
#define TWINT	7	// TWI Interrupt Flag
#define TWEA	6	// TWI Enable Acknowledge Bit
#define TWSTA	5	// TWI START Condition Bit
#define TWSTO	4	// TWI STOP Condition Bit
#define TWWC	3	// TWI Write Collision Flag
#define	TWEN	2	// TWI Enable Bit
#define	TWIE	0	// TWI Interrupt Enable

/*
 * I2C_*/
#define TWPS0	0
#define TWPS1	1

/*Prescaler Value*/
#define BIT_RATE_1 		0
#define BIT_RATE_4 		1
#define BIT_RATE_16		2
#define BIT_RATE_64		3



/* General Call Recognition*/
#define GENERAL_CALL_ON		1
#define GENERAL_CALL_OFF	0

#define ADDRESS_MIN	0
#define ADDRESS_MAX	127




/* ERRORS*/
#define I2C_ERROR_CODE	28
#define START_ERROR				0		// NO start Condition
#define ADDRESS_RANGE_ERROR		1 		// Address not in range
#define SLAVE_NOT_CONFIRMED		2		// Sent SLV +W and no replay
#define DATA_NOT_CONFIRMED		3		// Data sent and didnt confirmed by slave

#endif /* I2C_PRIVATE_H_ */
