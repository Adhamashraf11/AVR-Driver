/*
 *  Name        : TIMER_register.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the REGISTER of TIMER
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/***************************************    Timer Register   ****************************************/

#define SREG_Register           *((volatile u8*)0x5F)
#define TIMSK_Register			*((volatile u8*)0X59)
#define TIFR_Register			*((volatile u8*)0X58)


/***************************************   Timer0    ****************************************/
#define TCCR0_Register			*((volatile u8*)0X53)    // MODE Timer/Counter Control Register 0b x0xx 0xxx
#define TCNT0_Register			*((volatile u8*)0X52)    // CTC MODE    Timer/Counter  Register
#define OCR0_Register			*((volatile u8*)0X5C)    // CTC MODE    Output Compare Register

/*************************************************************************************************/



/*Timer1*/
#define TCCR1A			*((volatile u8 *)(0X4F))
#define TCCR1B			*((volatile u8 *)(0X4E))
/**/
#define TCNT1H          *((volatile u8 *)(0x4D))
#define TCNT1L          *((volatile u8 *)(0x4C))
#define TCNT1			*((volatile u16*)(0X4C))    /* u16 for HIGH & LOW ... Mc is little endiness so we start less address*/
/**/
#define OCR1AL          *((volatile u8 *)(0x4A))
#define OCR1AH          *((volatile u8 *)(0x4B))
#define OCR1A			*((volatile u16*)(0X4A))    /* u16 for HIGH & LOW ... Mc is little endiness so we start less address*/
/**/
#define OCR1BL          *((volatile u8 *)(0x48))
#define OCR1BH          *((volatile u8 *)(0x49))
#define OCR1B			*((volatile u16*)(0X48))    /* u16 for HIGH & LOW ... Mc is little endiness so we start less address*/
/**/
#define ICR1H           *((volatile u8 *)(0x47))
#define ICR1L           *((volatile u8 *)(0x46))
#define ICR1			*((volatile u16*)(0X46))    /* u16 for HIGH & LOW ... Mc is little endiness so we start less address*/

/*************************************************************************************************/



/***************************************   Timer2    ****************************************/

#define TCCR2_Register			*((volatile u8*)0X45)
#define TCNT2_Register			*((volatile u8*)0X44)
#define OCR2_Register			*((volatile u8*)0X43)


/*************************************************************************************************/

#define WDTCR_Register        *((volatile u8 *)(0x41))


                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //TIMER_REGISTER_H_
