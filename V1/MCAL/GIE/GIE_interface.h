/*
 *  Name        : EXTI_interface.h
 *  Created on  : aug 25, 2023 
 *  Description : this file contains the interfacing of GIE
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
  /* File Guard */
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_
                /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
				/*      Macros Defination Section           */
                /*      User Defination Type Section        */
                /*      Function Decleration Section        */
void GIE_VoidEnable  (void) ;
void GIE_VoidDisable (void) ;
	
#endif /*  GIE_INTERFACE_H_ */
