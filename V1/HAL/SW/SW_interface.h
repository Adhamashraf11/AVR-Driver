/*
 *  Name        : SW_interface.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the interfacing of switches
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

                 /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SW_config.h"
#include "SW_private.h"
#include "DIO_interface.h"

				 /*      Macros Defination Section           */

#define SW_PRESSED          (1)
#define SW_NOT_PRESSED      (0)


/*  Optins of State */
#define Int_PULL_UP         (0) 
#define Ext_PULL_UP         (1)
#define Ext_PULL_DOWN       (2)
#define FLOATING            (3)

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

void SW_voidInit       ( u8 copy_8uport , u8 copy_8upin , u8 Copy_u8pull_state );
u8   SW_u8GetPressed   ( u8 copy_8uport , u8 copy_8upin , u8 Copy_u8pull_state );





#endif //SW_INTERFACE_H_