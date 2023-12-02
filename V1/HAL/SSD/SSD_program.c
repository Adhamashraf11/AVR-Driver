/*
 *  Name        : SSD_program.c
 *  Created on  : aug 13, 2023 
 *  Description : this file contains the programming of 7-segment Display
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;

void SSD_voidInitialDataPort  (u8 Copy_u8Port )
{
    DIO_voidSetPortDirection (Copy_u8Port ,0xFF);
}

void SSD_voidEnable           ( SSD_Type Copy_structConfig )
{

}
void SSD_voidDisable          ( SSD_Type Copy_structConfig );

void SSD_voidSendNumber( SSD_Type Copy_structConfig,u8 Copy_u8Port, u8 Copy_u8Type, u8 Copy_u8Number ){

	if( Copy_structConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , Local_u8SSDNumbers[ Copy_u8Number ] );

	}else if( Copy_structConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPortValue( Copy_structConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );

	}

}