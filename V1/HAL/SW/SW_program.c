/*
 *  Name        : SW_program.c
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the programming of switches
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
#include "SW_interface.h"



void SW_voidInit       ( u8 copy_8uport , u8 copy_8upin , u8 Copy_u8pull_state)
{
    DIO_voidSetPinDirection( copy_8uport , copy_8upin, DIO_PIN_INPUT );
     if (Copy_u8pull_state  == ENABLE_PULLUP )
     {
         DIO_voidConnectPullup    (copy_8uport, copy_8upin, ENABLE_PULLUP);
     }

}

u8   SW_u8GetPressed   ( u8 copy_8uport , u8 copy_8upin , u8 Copy_u8pull_state )
{
	u8 LOC_u8Result = SW_NOT_PRESSED ;
	u8 LOC_u8PinVal = SW_NOT_PRESSED ;
	
	if ( (Copy_u8pull_state == Int_PULL_UP) || ( Copy_u8pull_state == Ext_PULL_UP) )
	{
        LOC_u8PinVal = DIO_u8GetPinValue  ( Copy_u8Port ,  Copy_u8Pin );
		
		if (LOC_u8PinVal == 0)
		{
			LOC_u8Result = SW_PRESSED ;
		}
		else if (LOC_u8PinVal == 1)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}

	}
	else if (Copy_u8pull_state == Ext_PULL_DOWN)
	{
        LOC_u8PinVal = DIO_u8GetPinValue  ( Copy_u8Port ,  Copy_u8Pin );
		
		if (LOC_u8PinVal == 0)
		{
			LOC_u8Result = SW_NOT_PRESSED ;
		}
		else if (LOC_u8PinVal == 1)
		{
			LOC_u8Result = SW_PRESSED ;
		}
	}
    else {/*error u are floating */}
		_delay_ms(20); // for debouncing
	return LOC_u8Result ;
	
}










 
