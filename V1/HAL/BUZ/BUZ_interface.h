/*
 *  Name        : BUZ_interface.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the interfacing of buzzer
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef BUZ_INTERFACE_H_
#define BUZ_INTERFACE_H_

                 /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "BUZ_private.h"
#include "BUZ_config.h"
				 /*      Macros Defination Section           */

// Port Defines
#define  BUZ_PORTA  0
#define  BUZ_PORTB  1
#define  BUZ_PORTC  2
#define  BUZ_PORTD  3


// PIN Defines
#define BUZ_PIN0   0
#define BUZ_PIN1   1
#define BUZ_PIN2   2
#define BUZ_PIN3   3
#define BUZ_PIN4   4
#define BUZ_PIN5   5
#define BUZ_PIN6   6
#define BUZ_PIN7   7

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0
  
                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */
void BUZ_voidInit        (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State );

void BUZ_voidOn          (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State );

void BUZ_voidOff         (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State );
 
void BUZ_voidToggle      (u8 Copy_u8Port , u8 Copy_u8Pin                         );
 
#endif //BUZ_INTERFACE_H_