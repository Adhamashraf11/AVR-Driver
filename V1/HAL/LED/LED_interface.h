/*
 *  Name        : LED_interface.h
 *  Created on  : aug 13, 2023 
 *  Description : this file contains the interfacing of LED
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */
// Port Defines
#define  LED_PORTA  0
#define  LED_PORTB  1
#define  LED_PORTC  2
#define  LED_PORTD  3


// PIN Defines
#define LED_PIN0   0
#define LED_PIN1   1
#define LED_PIN2   2
#define LED_PIN3   3
#define LED_PIN4   4
#define LED_PIN5   5
#define LED_PIN6   6
#define LED_PIN7   7

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

void LED_voidInitialization        (  u8 copy_8uport ,u8 copy_8upin );
void LED_voidOn                    (  u8 copy_8uport ,u8 copy_8upin ,u8 copy_8uState );
void LED_voidOff                   (  u8 copy_8uport ,u8 copy_8upin ,u8 copy_8uState );
void LED_voidToggle                (  u8 copy_8uport ,u8 copy_8upin );



#endif //LED_INTERFACE_H_
