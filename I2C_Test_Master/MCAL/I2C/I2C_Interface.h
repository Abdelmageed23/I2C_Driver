/*
 * I2C_Interface.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

typedef enum{
	NoError,
	StartConditionError,
	RepStartConditionError,
	SlaveAddressErrorWrite,
	SlaveAddressErrorRead,
	MasterWriteByteError,
	NO_Address_Match,
	MasterReciveDataAckError,
	MasterReciveDataNAckError,


}I2C_ErrorStatus;


void I2C_Init();
I2C_ErrorStatus I2C_StartCondition(void);
I2C_ErrorStatus I2C_RepeatedStartCondition(void);
I2C_ErrorStatus I2C_WriteToAddress(uint8_t Address);
I2C_ErrorStatus I2C_ReadFromAddress(uint8_t Address);
I2C_ErrorStatus I2C_WriteData(uint8_t DATA);
I2C_ErrorStatus I2C_ReadWithACK(uint8_t *Data);
I2C_ErrorStatus I2C_ReadWithoutACK(uint8_t *Data);
void I2C_StopCondition();
I2C_ErrorStatus I2C_SlaveMatch();

void I2C_SendByte(uint8_t Address ,uint8_t Data);




#define I2C_GetStatus	((I2C_TWSR) & (TWSR_STATUS_MASK))


#define WRITE 0
#define READ 1
#endif /* I2C_INTERFACE_H_ */
