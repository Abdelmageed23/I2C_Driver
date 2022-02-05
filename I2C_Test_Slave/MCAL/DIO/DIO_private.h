/*********************************************************/
/* Author  : Abdelrahman Mohamed              			 */
/* Date     : 4 Jan	2022                   				 */
/* Version  : V01                            			 */
/*********************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H


/* REGISTER ADDRESSES FOR PORTA */
#define DIO_PORTA		(*(volatile uint8_t*)(0x3B))
#define DIO_DDRA		(*(volatile uint8_t*)(0x3A))
#define DIO_PINA		(*(volatile uint8_t*)(0x39))

/* REGISTER ADDRESSES FOR PORTB */
#define DIO_PORTB		(*(volatile uint8_t*)(0x38))
#define DIO_DDRB		(*(volatile uint8_t*)(0x37))
#define DIO_PINB		(*(volatile uint8_t*)(0x36))

/* REGISTER ADDRESSES FOR PORTC */
#define DIO_PORTC		(*(volatile uint8_t*)(0x35))
#define DIO_DDRC		(*(volatile uint8_t*)(0x34))
#define DIO_PINC		(*(volatile uint8_t*)(0x33))

/* REGISTER ADDRESSES FOR PORTD */
#define DIO_PORTD		(*(volatile uint8_t*)(0x32))
#define DIO_DDRD		(*(volatile uint8_t*)(0x31))
#define DIO_PIND		(*(volatile uint8_t*)(0x30))


#endif
