/*
 *  Name        : EXTI_config.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the configuration of EXTI
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/*
 Options :-
 	 1-EXTI_LINE0
 	 2-EXTI_LINE1
 	 3-EXTI_LINE2
 */
#define EXTI_LINE   EXTI_LINE0

/*
 Options :-
 	 1-EXTI_FALLING_EDGE
 	 2-EXTI_RISING_EDGE
 	 3-EXTI_LOW_LEVEL
 	 4-EXTI_ON_CHANGE
 */
#define EXTI_SENSE_MODE  EXTI_FALLING_EDGE

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //EXTI_CONFIG_H_
