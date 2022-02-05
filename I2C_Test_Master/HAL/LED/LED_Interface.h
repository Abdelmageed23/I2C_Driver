/*
 * LED_Interface.h
 *
 *  Created on: Jan 27, 2022
 *      Author: Abdelrahman Mohamed
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


typedef enum
{
	LED0,
	LED1,
	LED2,
	LED3
}LED_Num_t;


uint8_t LED_Init(LED_Num_t	LED_NUM);
uint8_t LED_ON(LED_Num_t	LED_NUM);
uint8_t LED_OFF(LED_Num_t	LED_NUM);
uint8_t LED_TOGGLE(LED_Num_t	LED_NUM);

#endif /* LED_INTERFACE_H */
