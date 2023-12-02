/*
 *  Name        : LED_program.c
 *  Created on  : aug 13, 2023 
 *  Description : this file contains the programing of LED
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"

void LED_voidInitialization        ( u8 copy_8uport ,u8 copy_8upin )
{
    DIO_voidSetPinDirection( copy_8uport , copy_8upin, DIO_PIN_OUTPUT );
}
	
void LED_voidOn                    (  u8 copy_8uport ,u8 copy_8upin ,u8 copy_8uState )
{
    if (copy_8uState == ACTIVE_HIGH)
    {
         DIO_voidSetPinValue( copy_8uport , copy_8upin, DIO_PIN_HIGH );
    }
    else if (copy_8uState == ACTIVE_LOW)
    {
         DIO_voidSetPinValue( copy_8uport , copy_8upin, DIO_PIN_LOW  );
    }
    else {}
}

void LED_voidOff                   (  u8 copy_8uport ,u8 copy_8upin ,u8 copy_8uState )
{
    if (copy_8uState == ACTIVE_HIGH)
    {
         DIO_voidSetPinValue( copy_8uport , copy_8upin, DIO_PIN_LOW );
    }
    else if (copy_8uState == ACTIVE_LOW)
    {
         DIO_voidSetPinValue( copy_8uport , copy_8upin, DIO_PIN_HIGH );
    }
    else {}
}
 
void LED_voidToggle                (  u8 copy_8uport ,u8 copy_8upin )
{
    DIO_voidTogglePinValue (copy_8uport,copy_8upin);

}











