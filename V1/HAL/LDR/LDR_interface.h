/*
 *  Name        : LM35_interface.h
 *  Created on  : sep 1, 2023 
 *  Description : this file contains the interfacing of LM35
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_


                 /*      Include Section                     */

#include "LM35_private.h"
#include "LM35_config.h"
				 /*      Macros Defination Section           */
#define ADC_RESOLUTION_10_BIT     0
#define ADC_RESOLUTION_8_BIT      1

#define AREF                    0
#define AVCC                    5     //5v
#define INTERNAL_2_56           2.56

                 /*      User Defination Type Section        */
typedef struct
{
	u8 Copy_u8LM35Channel ;
	u8 Copy_u8ADCVoltageReference ;       /* Vref = 5 , 2.56 , External  *///AREF - AVCC - INTERNAL_2_56
	u8 Copy_u8ADCResolution ;            /* ADC_RESOLUTION_10_BIT or ADC_RESOLUTION_8_BIT  */
} LM35_CONFIG ;

// example :- LM35_CONFIG value = {0 , 5 , 0};

                 /*      Function Decleration Section        */

void LM35_u8GetTemp (LM35_CONFIG * lm35 , u8 * Copy_u8TempValue) ;
u8 LM35_u8GetTemperature ( u8 Copy_u8LM35Channel );
u8 LM35_getTemperature(void);
#endif //LM35_INTERFACE_H_
