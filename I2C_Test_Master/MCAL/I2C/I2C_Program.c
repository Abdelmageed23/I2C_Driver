/*
* I2C_Program.c
*
*  Created on: Jan 27, 2022
*      Author: Abdelrahman Mohamed
*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/DET/Det.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"


#ifndef F_CPU
#define F_CPU 8000000UL
#endif


void I2C_Init()
{
	/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
	/*1- Set TWBR to 2*/
	I2C_TWBR = 2;
	/*2- Clear the prescaler bits (TWPS)*/
	CLR_BIT(I2C_TWSR,TWPS0);
	CLR_BIT(I2C_TWSR,TWPS1);

	/* In Case Slave Configuring my address, Enable/Disable General call */
	I2C_TWAR = (I2C_ADDRESS<<1) + GENERAL_CALL;

	/*Enable TWI*/
	SET_BIT(I2C_TWCR,TWEN);

}


I2C_ErrorStatus I2C_StartCondition(void)
{
/* Define Error State and initialize to no error*/
	I2C_ErrorStatus LocalError = NoError;

	/*Send start condition*/
	SET_BIT(I2C_TWCR, TWSTA);

	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(I2C_TWCR,TWINT);


	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(I2C_TWCR,TWINT))==0);

	/*Check the operation status*/
	if( I2C_GetStatus != I2C_START)
	{
		LocalError = StartConditionError;
	}

	/* Return the Error status */
	return LocalError;
}

I2C_ErrorStatus I2C_RepeatedStartCondition(void)
{
		/* Define Error State and initialize to no error*/
		I2C_ErrorStatus LocalError = NoError;

		/*Send start condition*/
		SET_BIT(I2C_TWCR, TWSTA);

		/*Clear the interrupt flag to start the previous operation*/
		SET_BIT(I2C_TWCR,TWINT);

		/*wait until the operation finishes and the flag is raised*/
		while((GET_BIT(I2C_TWCR,TWINT))==0);

		/*Check the operation status*/
		if( I2C_GetStatus != I2C_REP_START)
		{
			LocalError = RepStartConditionError;
		}

		/* Return the Error status */
		return LocalError;

}
I2C_ErrorStatus I2C_WriteToAddress(uint8_t Address)
{
	/* Define Error State and initialize to no error*/
		I2C_ErrorStatus LocalError = NoError;

		/*send the 7bit slave address to the bus*/
		I2C_TWDR = (Address <<1);
		/* Set the Write Request*/
		CLR_BIT(I2C_TWDR,0);

		/*Clear the start condition bit*/
		CLR_BIT(I2C_TWCR,TWSTA);

		/*Clear the interrupt flag to start the previous operation*/
		SET_BIT(I2C_TWCR,TWINT);

		/*wait until the operation finishes and the flag is raised*/
		while((GET_BIT(I2C_TWCR,TWINT))==0);

		/*Check the operation status*/
		if( I2C_GetStatus != I2C_MT_SLA_W_ACK)
		{
			LocalError = SlaveAddressErrorWrite;
		}

		/* Return the Error status */
		return LocalError;
}

I2C_ErrorStatus I2C_ReadFromAddress(uint8_t Address)
{
		/* Define Error State and initialize to no error*/
		I2C_ErrorStatus LocalError = NoError;

		/*Clear the start condition bit*/
		CLR_BIT(I2C_TWCR,TWSTA);

		/*send the 7bit slave address to the bus*/
		I2C_TWDR = (Address <<1);
		/* Set the Read Request*/
		SET_BIT(I2C_TWDR,0);
		/*Clear the interrupt flag to start the previous operation*/
		SET_BIT(I2C_TWCR,TWINT);

		/*wait until the operation finishes and the flag is raised*/
		while((GET_BIT(I2C_TWCR,TWINT))==0);

		/*Check the operation status*/
		if( I2C_GetStatus != I2C_MT_SLA_R_ACK)
		{
		LocalError = SlaveAddressErrorRead;
		}

		/* Return the Error status */
		return LocalError;

}

I2C_ErrorStatus I2C_WriteData(uint8_t DATA)
{
		/* Define Error State and initialize to no error*/
		I2C_ErrorStatus LocalError = NoError;
		/*Send Data */
		I2C_TWDR = DATA;

		/*Clear the interrupt flag to start the previous operation*/
		SET_BIT(I2C_TWCR,TWINT);

		/*wait until the operation finishes and the flag is raised*/
		while((GET_BIT(I2C_TWCR,TWINT))==0);

		/*Check the operation status*/
		if( I2C_GetStatus != I2C_MT_DATA_ACK)
		{
		LocalError = MasterWriteByteError;
		}

		/* Return the Error status */
		return LocalError;
}



I2C_ErrorStatus I2C_ReadWithACK(uint8_t *Data)
{
		/* Define Error State and initialize to no error*/
		I2C_ErrorStatus LocalError = NoError;
		/*Clear the interrupt flag to allow Reading From Slave*/
		SET_BIT(I2C_TWCR,TWINT);

		/*wait until the operation finishes and the flag is raised*/
		while((GET_BIT(I2C_TWCR,TWINT))==0);

		/*Check the operation status*/
		if( I2C_GetStatus != I2C_SR_DATA_ACK)
		{
		LocalError = MasterReciveDataAckError;
		}
		else
		{
			*Data = I2C_TWDR;
		}

		/* Return the Error status */
		return LocalError;
}


I2C_ErrorStatus I2C_ReadWithoutACK(uint8_t *Data)
{

	/* Define Error State and initialize to no error*/
	I2C_ErrorStatus LocalError = NoError;
	/*Clear the interrupt flag to allow Reading From Slave*/
	SET_BIT(I2C_TWCR,TWINT);

	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(I2C_TWCR,TWINT))==0);

	/*Check the operation status*/
	if( I2C_GetStatus != I2C_MR_DATA_NACK)
	{
	LocalError = MasterReciveDataNAckError;
	}
	else
	{
		*Data = I2C_TWDR;
	}

	/* Return the Error status */
	return LocalError;
}



void I2C_StopCondition()
{
	/*Transmit STOP condition*/
	SET_BIT(I2C_TWCR,TWSTO);
	/*Clear the interrupt flag to start the previous operation*/
	SET_BIT(I2C_TWCR,TWINT);
}


I2C_ErrorStatus I2C_SlaveMatch()
{
	/* Define Error State and initialize to no error*/
	I2C_ErrorStatus LocalError = NoError;

	/*Enable TWI*/
	SET_BIT(I2C_TWCR,TWEN);
	/*Enable Acknowledge bit*/
	SET_BIT(I2C_TWCR,TWEA);
	/*Clear the interrupt flag to allow Reading From Slave*/
	SET_BIT(I2C_TWCR,TWINT);
	/*wait until the operation finishes and the flag is raised*/
	while((GET_BIT(I2C_TWCR,TWINT))==0);

	/*Check the operation status*/
	if( ((I2C_TWSR) & (0xf8)) != I2C_SR_SLA_ACK)
	{
	LocalError = NO_Address_Match;
	}
	else
	{

	}

	/* Return the Error status */
	return LocalError;
}
