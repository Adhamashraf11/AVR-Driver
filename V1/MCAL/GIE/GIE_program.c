/*
 *  Name        : EXTI_program.h
 *  Created on  : aug 25, 2023 
 *  Description : this file contains the programming of GIE
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
  /* File Guard */


#include "GIE_interface.h"


void GIE_VoidEnable (void)
{
	SET_BIT (SREG_REG , SREG_I) ;
}

void GIE_VoidDisable (void)
{
	CLR_BIT (SREG_REG , SREG_I) ;
}
