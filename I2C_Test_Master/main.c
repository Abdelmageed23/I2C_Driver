/*
 * main.c
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/I2C/I2C_interface.h"

void main()
{
	I2C_Init();
	I2C_StartCondition();
			I2C_WriteToAddress(0x22	);
			I2C_WriteData('a');
			I2C_WriteData('b');
			I2C_StopCondition();

	while(1)
	{


	}
}



