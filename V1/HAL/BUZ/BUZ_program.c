/*
 *  Name        : BUZ_program.c
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the programming of buzzer
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 


#include "BUZ_interface.h"


void BUZ_voidInit(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State )
{
    DIO_voidSetPinDirection  ( Copy_u8Port , Copy_u8Pin , DIO_OUTPUT);
}

void BUZ_voidOn  (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State )
{
	
	if( Copy_u8Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( Copy_u8Port , Copy_u8Pin , DIO_HIGH );
		
	}else if(Copy_u8Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( Copy_u8Port , Copy_u8Pin, DIO_LOW  );
		
	}
	
}

void BUZ_voidOff (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Active_State )
{
	if( Copy_u8Active_State == ACTIVE_HIGH ){
		
		DIO_voidSetPinValue( Copy_u8Port , Copy_u8Pin , DIO_LOW );	
	}
    else if(Copy_u8Active_State == ACTIVE_LOW ){
		
		DIO_voidSetPinValue( Copy_u8Port , Copy_u8Pin, DIO_HIGH  );
	}
	
}

void BUZ_voidToggle     (u8 Copy_u8Port , u8 Copy_u8Pin  )
{
	DIO_voidTogglePinValue  ( Copy_u8Port , Copy_u8Pin);
}

