/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/************************************************************************
 * Set Pin direction from any port
 * INPUT : PORT name , PIN number , (OUTPUT or INPUT)
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPinDircection(uint8_t PORT , uint8_t PIN , uint8_t Mode)
{
	if(PIN >7)
	{
		return -1;
	}
	else
	{
		if(Mode == OUTPUT)
		{
			switch(PORT)
					{
					case PORTA:
						SET_BIT(DIO_DDRA,PIN);
						return 1;
						break;
					case PORTB:
						SET_BIT(DIO_DDRB,PIN);
						return 1;
						break;
					case PORTC:
						SET_BIT(DIO_DDRC,PIN);
						return 1;
						break;
					case PORTD:
						SET_BIT(DIO_DDRD,PIN);
						return 1;
						break;
					default:
						return -2;
					}
		}
		else if( Mode == INPUT)
			{
			switch(PORT)
				{
			case PORTA:
				CLR_BIT(DIO_DDRA,PIN);
					return 1;
					break;
			case PORTB:
				CLR_BIT(DIO_DDRB,PIN);
					return 1;
					break;
			case PORTC:
				CLR_BIT(DIO_DDRC,PIN);
					return 1;
					break;
			case PORTD:
				CLR_BIT(DIO_DDRD,PIN);
					return 1;
					break;
			default:
					return -2;
				}
			}
		else if (Mode == INPUT_PULLUP)
		{
			switch(PORT)
							{
						case PORTA:
							CLR_BIT(DIO_DDRA,PIN);
							SET_BIT(DIO_PORTA,PIN);
								return 1;
								break;
						case PORTB:
							CLR_BIT(DIO_DDRB,PIN);
							SET_BIT(DIO_PORTB,PIN);
								return 1;
								break;
						case PORTC:
							CLR_BIT(DIO_DDRC,PIN);
							SET_BIT(DIO_PORTC,PIN);
								return 1;
								break;
						case PORTD:
							CLR_BIT(DIO_DDRD,PIN);
							SET_BIT(DIO_PORTD,PIN);
								return 1;
								break;
						default:
								return -2;
							}
		}
		else
		{
			return -3;
		}
	}
}

/************************************************************************
 * Set Port direction
 * INPUT : PORT name , (OUTPUT or INPUT)
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPortDirection(uint8_t PORT, uint8_t Mode)
{
	switch(PORT)
	{
	case PORTA:
		if(Mode == OUTPUT)
		{
			DIO_DDRA =0xff;
			return 1;
		}
		else if (Mode == INPUT)
		{
			DIO_DDRA = 0x00;
			return 1;
		}
		else
			return -1;
		break;
	case PORTB:
			if(Mode == OUTPUT)
			{
				DIO_DDRB =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DIO_DDRB = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	case PORTC:
			if(Mode == OUTPUT)
			{
				DIO_DDRC =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DIO_DDRC = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	case PORTD:
			if(Mode == OUTPUT)
			{
				DIO_DDRD =0xff;
				return 1;
			}
			else if (Mode == INPUT)
			{
				DIO_DDRD = 0x00;
				return 1;
			}
			else
				return -1;
			break;
	default:
			return -1;
	}
}


/************************************************************************
 * Set Pin value from any port
 * INPUT : PORT name , PIN number , value
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPinValue(uint8_t PORT , uint8_t PIN , uint8_t value)
{
	if(PIN >7)
		{
			return -1;
		}
		else
		{
			if(value == HIGH)
			{
				switch(PORT)
						{
						case PORTA:
							SET_BIT(DIO_PORTA,PIN);
							return 1;
							break;
						case PORTB:
							SET_BIT(DIO_PORTB,PIN);
							return 1;
							break;
						case PORTC:
							SET_BIT(DIO_PORTC,PIN);
							return 1;
							break;
						case PORTD:
							SET_BIT(DIO_PORTD,PIN);
							return 1;
							break;
						default:
							return -2;
						}
			}
			else if( value == LOW)
				{
				switch(PORT)
					{
				case PORTA:
					CLR_BIT(DIO_PORTA,PIN);
						return 1;
						break;
				case PORTB:
					CLR_BIT(DIO_PORTB,PIN);
						return 1;
						break;
				case PORTC:
					CLR_BIT(DIO_PORTC,PIN);
						return 1;
						break;
				case PORTD:
					CLR_BIT(DIO_PORTD,PIN);
						return 1;
						break;
				default:
						return -2;
					}
				}
			else
			{
				return -3;
			}
		}
}


/************************************************************************
 * Set port value
 * INPUT : PORT name  , value
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_SetPortValue(uint8_t PORT , uint8_t value)
{
	switch(PORT)
		{
		case PORTA:
			DIO_PORTA = value;
				return 1;
				break;
		case PORTB:
				DIO_PORTB = value;
				return 1;
				break;
		case PORTC:
				DIO_PORTC = value;
				return 1;
				break;
		case PORTD:
				DIO_PORTD = value;
				return 1;
				break;
		default:
				return -1;
		}
}


/************************************************************************
 * get Pin value from any port
 * INPUT : PORT name , PIN number , variable to store the data
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_GetPinVal(uint8_t PORT , uint8_t PIN , uint8_t * val)
{

	if(PIN >7)
			{
				return -1;
			}
			else
			{
					switch(PORT)
							{
							case PORTA:
								*val =  GET_BIT(DIO_PINA,PIN);
								return 1;
								break;
							case PORTB:
								*val =  GET_BIT(DIO_PINB,PIN);
								return 1;
								break;
							case PORTC:
								*val =  GET_BIT(DIO_PINC,PIN);
								return 1;
								break;
							case PORTD:
								*val =  GET_BIT(DIO_PIND,PIN);
								return 1;
								break;
							default:
								return -2;
							}
			}
}


/*
NOT TESTED YET
*/
sint8_t DIO_GetPortValue(uint8_t PORT , uint8_t * val)
{
	switch(PORT)
			{
			case PORTA:
				*val =  DIO_PINA;
				return 1;
				break;
			case PORTB:
				*val =  DIO_PINB;
				return 1;
				break;
			case PORTC:
				*val =  DIO_PINC;
				return 1;
				break;
			case PORTD:
				*val =  DIO_PIND;
				return 1;
				break;
			default:
				return -2;
			}

}

/************************************************************************
 * Toggle Pin value of any port
 * INPUT : PORT name , PIN number
 * OUTPUT: 1 if ok and -1 if not ok
 **********************************************************************/
sint8_t DIO_TogglePin(uint8_t PORT , uint8_t PIN )
{
	if(PIN >7)
		{
			return -1;
		}
		else
		{
				switch(PORT)
						{
						case PORTA:
							TOGGLE_BIT(DIO_PORTA,PIN);
							return 1;
							break;
						case PORTB:
							TOGGLE_BIT(DIO_PORTB,PIN);
							return 1;
							break;
						case PORTC:
							TOGGLE_BIT(DIO_PORTC,PIN);
							return 1;
							break;
						case PORTD:
							TOGGLE_BIT(DIO_PORTD,PIN);
							return 1;
							break;
						default:
							return -2;
						}

		}
}

