/*
 *  Name        : EXTI_register.h
 *  Created on  : aug 25, 2023 
 *  Description : this file contains the interfacing of GIE
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
  /* File Guard */
#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

			/* registers*/
	#define SREG_REG		*((volatile u8*) 0X5F)	/* Status Register */
	#define SREG_I			(7)						/* Global Interrupt Enable Bit */

#endif /* GIE_REGISTER_H_ */
