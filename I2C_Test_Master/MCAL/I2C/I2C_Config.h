/*
 * I2C_Config.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_


/*
 * I2C_CLK	(F_CPU)/((16)+((2)*(I2C_DIVISON_FACTOR)*(I2C_BIT_PRESCALER))
 */
/*
 * BIT_RATE_1
 * BIT_RATE_4
 * BIT_RATE_16
 * BIT_RATE_64
 */
#define I2C_BIT_PRESCALER	BIT_RATE_16

/*
 * 0 to 255
 */
#define I2C_DIVISON_FACTOR	0


/*MY I2C Address*/
#define I2C_ADDRESS		0x01

/*
 * GENERAL_CALL_ON
 * GENERAL_CALL_OFF
 */
#define GENERAL_CALL	GENERAL_CALL_ON

#endif /* I2C_CONFIG_H_ */
