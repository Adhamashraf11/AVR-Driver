/*
 *  Name        : ADC_interface.h
 *  Created on  : aug 20, 2023 
 *  Description : this file contains the interfacing of Analoge to Digital Converter
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


                 /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "DIO_interface.h"


				 /*      Macros Defination Section           */

#define ADC_DISABLE             0
#define ADC_ENABLE              1

#define INT_DISABLE             0
#define INT_ENABLE              1

#define AREF                    0
#define AVCC                    1
#define INTERNAL_2_56           3  


#define RIGHT_ADJUSTMENT        0
#define LEFT_ADJUSTMENT         1

#define ADC_CHANNEL0            0
#define ADC_CHANNEL1            1
#define ADC_CHANNEL2            2
#define ADC_CHANNEL3            3
#define ADC_CHANNEL4            4
#define ADC_CHANNEL5            5
#define ADC_CHANNEL6            6
#define ADC_CHANNEL7            7

/* // ADC Auto Trigger Source Selections 
#define ADC_SINGLE_CONVERSION   0
#define ADC_FREE_RUNNING        1
#define ADC_ANALOG_COMPARATOR   2
#define ADC_EXTI0               3
#define ADC_TIM0_CTC            4
#define ADC_TIM0_OVF            5
#define ADC_TIM1_CTC_CHANNEL_B  6
#define ADC_TIM1_OVF            7
#define ADC_TIM1_ICU            8
*/

/*Prescaler => determine the division factor between the XTAL frequency and the input clock to the ADC*/
#define ADC_PRE_2               1
#define ADC_PRE_4               2
#define ADC_PRE_8               3
#define ADC_PRE_16              4
#define ADC_PRE_32              5
#define ADC_PRE_64              6
#define ADC_PRE_128             7



                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */
    
void ADC_voidInit             (void) ;
u16 ADC_u8GetResultSync       (u8 Copy_u8Channel );
void ADC_voidEnable           (void);
void ADC_voidDisable          (void);
void ADC_voidInterruptEnable  (void);
void ADC_voidInterruptDisable (void);
void ADC_u8SetPrescaler       (u8 Copy_u8Prescaler);

/*
typedef struct 
{
	u8*  Channel ;
	u16* Result  ;
	u8   Size    ;
	void (*NotificationFunc)(void);
}Chain_t ;
u8   ADC_u8StartConversionAsynch( u8 Copy_u8Channel , u16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) );
u8   ADC_u8StartChainAsynch     ( Chain_t * Copy_Chain);
*/



#endif //ADC_INTERFACE_H_

