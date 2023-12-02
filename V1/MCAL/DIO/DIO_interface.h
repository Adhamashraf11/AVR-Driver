
 /*
 *  Name        : DIO_interface.h 
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the interfacing of DIO 
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 *  SWC         : DIO/GPIO
 */
 

/* File Guard */
#ifndef   DIO_INTERFACE_H_
#define   DIO_INTERFACE_H_

                 /*      Include Section                     */

				 /*      Macros Defination Section           */
// Port Defines
#define  DIO_PORTA  0
#define  DIO_PORTB  1
#define  DIO_PORTC  2
#define  DIO_PORTD  3

// PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7

// PIN Directions
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT	    0

// PIN Value Options 
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

// PORT Directions
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0

// PORT Value Options 
#define DIO_PORT_HIGH 		0xFF
#define DIO_PORT_LOW  		0

//Pull UP
#define PUD   2

                 /*      User Defination Type Section        */

                 /*      Function Decleration Section        */

// for pins
void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Direction);
void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Value    );
u8   DIO_u8GetPinValue        (u8 Copy_u8Port , u8 Copy_u8Pin                     );
void DIO_voidTogglePinValue   (u8 Copy_u8Port , u8 Copy_u8Pin                     );
//for ports
void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction               );
void DIO_voidSetPortValue     (u8 Copy_u8Port , u8 Copy_u8Value                   );
u8   DIO_voidGetPortValue     (u8 Copy_u8Port                                     );
void DIO_voidTogglePortValue  (u8 Copy_u8Port                                     );
//for nibble 
void DIO_voidWriteHighNibbles (u8 Copy_u8Port , u8 Copy_u8Value                   );
void DIO_voidWriteLowNibbles  (u8 Copy_u8Port , u8 Copy_u8Value                   );
// Internal Pull Up
void DIO_voidConnectPullup    (u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectPullup);



#endif //DIO_INTERFACE_H_

 