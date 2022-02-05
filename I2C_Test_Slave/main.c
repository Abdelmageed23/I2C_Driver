/*
 * main.c
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/I2C/I2C_Interface.h"
#include "HAL/LED/LED_Interface.h"

void main()
{
	uint8_t result=0;
	I2C_Init();
	DIO_SetPortDirection(PORTA,OUTPUT);
	I2C_SlaveMatch();
	I2C_ReadWithACK(&result);
	DIO_SetPortValue(PORTA,result);
	while(1)
	{


	}
}

