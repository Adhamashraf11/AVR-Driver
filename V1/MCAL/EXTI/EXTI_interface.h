/*
 *  Name        : EXTI_interface.h
 *  Created on  : aug 25, 2023 
 *  Description : this file contains the interfacing of EXTI
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


                 /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
				 /*      Macros Defination Section           */
/*   INTERUPPT ( 0 , 1 , 2 )  */
#define EXTI_LINE0       (6)
#define EXTI_LINE1       (7)
#define EXTI_LINE2       (5)

/* Sense Control */
#define EXTI_FALLING_EDGE  (0)   // INT 0 , 1 , 2
#define EXTI_RISING_EDGE   (1)   // INT 0 , 1 , 2
#define EXTI_LOW_LEVEL     (2)   // INT 0 , 1 
#define EXTI_ON_CHANGE     (3)   // INT 0 , 1 

/*MCU Control Register - MCUCR*/
#define MCUCR_ISC00         (0)  /* FOR CONTROL OF INT0 */
#define MCUCR_ISC01         (1)  /* FOR CONTROL OF INT0 */
#define MCUCR_ISC10         (2)  /* FOR CONTROL OF INT1 */
#define MCUCR_ISC11         (3)  /* FOR CONTROL OF INT1 */

/*MCU Control and Status Register - MCUCSR*/
#define MCUCSR_ISC2        (6)  /* FOR STATUS CONTROL OF INT2 */
 

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

void EXTI_voidInit              ( void                                                  );
void EXTI_voidDisableInterrupt  ( u8 Copy_u8Line                                        );
void EXTI_voidEnableInterrupt   ( u8 Copy_u8Line                                        );
void EXTI_voidClearFlag         ( u8 Copy_u8Line                                        );
u8   EXTI_u8GetFlag             ( u8 Copy_u8Line                                        );
void EXTI_voidSetSignalLatch    ( u8 Copy_u8SenseMode , u8 Copy_u8Line                  );
void EXTI_voidSetCallBack       ( void (*Copy_pvoidCallBack)(void) , u8 Copy_u8EXTILine );

#endif //EXTI_INTERFACE_H_