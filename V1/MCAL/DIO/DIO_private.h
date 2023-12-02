
 /*
 *  Name        : DIO_private.h    /    DIO_register.h 
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the privacy of DIO  
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 

/* File Guard */
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

                 /*      Include Section                     */

				 /*      Macros Defination Section           */

/* Group A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)  // unsigned char *DDRA = *((u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)

/*PULL UP */
#define  SFIOR_Register  *((volatile u8*)0x50)

                 /*      User Defination Type Section        */

                 /*      Function Decleration Section        */

#endif  //DIO_PRIVATE_H_