/*
 *  Name        : EXTI_private.h
 *  Created on  : aug 25, 2023 
 *  Description : this file contains the privacy of EXTI
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

#define MCUCR_REG   *((volatile u8 *)0x55)     //MCU Control Register               => to interrupt sense control 0,1 SignalLatch  
#define MCUCSR_REG  *((volatile u8 *)0x54)     //MCU Control and Status Register    => to interrupt Sense Control 2
#define GICR_REG    *((volatile u8 *)0x5B)     //General Interrupt Control Register => to Enable or Disable EXTI
#define GIFR_REG    *((volatile u8 *)0x5A)     //General Interrupt Flag Register    => to clear flag in EXTI

//#define SREG_REG    *((volatile u8 *)0x5F)    //STATUS Register => to enable GIE 

  
#define NULL 0

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //EXTI_PRIVATE_H_