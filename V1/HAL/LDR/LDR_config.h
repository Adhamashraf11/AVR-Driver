/*
 *  Name        : LDR_config.h
 *  Created on  : sep 5, 2023 
 *  Description : this file contains the configuration of LDR
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef LDR_CONFIG_H_
#define LDR_CONFIG_H_
                 /*      Include Section                     */
				 /*      Macros Defination Section           */
/**
    Options RESOLUTION  :-
    ADC_RESOLUTION_10_BIT
    ADC_RESOLUTION_8_BIT
*/
#define ADC_RESOLUTION       ADC_RESOLUTION_10_BIT
#define SENSOR_CHANNEL_ID      1



#define RESISTOR_KNOWN_K0HM    1



#define ADC_uint8INTERRUPT_BASED 0
#define ADC_uint8POOLLING_BASED  1


#define ADC_uint8IMPLEMENTATION_BASED  ADC_uint8POOLLING_BASED
/*
 Options:-
 	 1-AREF
 	 2-AVCC
 	 3-INTERNAL_2_56
 */
#define ADCVoltageReference    AVCC

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */
#endif //LDR_CONFIG_H_






