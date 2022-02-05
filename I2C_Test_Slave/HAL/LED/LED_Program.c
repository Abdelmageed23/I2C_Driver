/*
 * LED_Program.c
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include "LED_config.h"
#include "LED_Interface.h"

uint8_t LED_Init(LED_Num_t	LED_NUM)
{
	switch(LED_NUM)
	{
	case LED0 :
			DIO_SetPinDircection(LED0_PORT,LED0_PIN,OUTPUT);
			return OK;
		break;
	case LED1 :
			DIO_SetPinDircection(LED1_PORT,LED1_PIN,OUTPUT);
			return OK;
		break;
	case LED2 :
			DIO_SetPinDircection(LED2_PORT,LED2_PIN,OUTPUT);
			return OK;
		break;
	case LED3 :
			DIO_SetPinDircection(LED3_PORT,LED3_PIN,OUTPUT);
			return OK;
		break;
	default:
		return NOK;
		break;
	}
}
uint8_t LED_ON(LED_Num_t LED_NUM)
{
	switch(LED_NUM)
		{
		case LED0 :
				DIO_SetPinValue(LED0_PORT,LED0_PIN,HIGH);
				return OK;
			break;
		case LED1 :
				DIO_SetPinValue(LED1_PORT,LED1_PIN,HIGH);
				return OK;
			break;
		case LED2 :
				DIO_SetPinValue(LED2_PORT,LED2_PIN,HIGH);
				return OK;
			break;
		case LED3 :
				DIO_SetPinValue(LED3_PORT,LED3_PIN,HIGH);
				return OK;
			break;
		default:
			return NOK;
			break;
		}
}
uint8_t LED_OFF(LED_Num_t LED_NUM)
{
	switch(LED_NUM)
		{
		case LED0 :
				DIO_SetPinValue(LED0_PORT,LED0_PIN,LOW);
				return OK;
			break;
		case LED1 :
				DIO_SetPinValue(LED1_PORT,LED1_PIN,LOW);
				return OK;
			break;
		case LED2 :
				DIO_SetPinValue(LED2_PORT,LED2_PIN,LOW);
				return OK;
			break;
		case LED3 :
				DIO_SetPinValue(LED3_PORT,LED3_PIN,LOW);
				return OK;
			break;
		default:
			return NOK;
			break;
		}
}

uint8_t LED_TOGGLE(LED_Num_t LED_NUM)
{
	switch(LED_NUM)
	{
		case LED0 :
				DIO_TogglePin(LED0_PORT,LED0_PIN);
				return OK;
			break;
		case LED1 :
				DIO_TogglePin(LED1_PORT,LED1_PIN);
				return OK;
			break;
		case LED2 :
				DIO_TogglePin(LED2_PORT,LED2_PIN);
				return OK;
			break;
		case LED3 :
				DIO_TogglePin(LED3_PORT,LED3_PIN);
				return OK;
			break;
		default:
			return NOK;
			break;
	}
}

