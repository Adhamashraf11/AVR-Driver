/*
 *  Name        : TIMER_private.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the privacy of TIMER
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/***************************    REGISTER BIT    ****************************/
/*INTERRUPT REGISTER  " TIMSK "*/
    #define TIMSK_TOIE0		0
    #define TIMSK_OCIE0		1
    #define TIMSK_TOIE1		2
    #define TIMSK_OCIE1B	3
    #define TIMSK_OCIE1A	4
    #define TIMSK_TICIE1	5
    #define TIMSK_TOIE2		6
    #define TIMSK_OCIE2		7
/*FLAG REGISTER  " TIFR "*/
    #define TIFR_TOV0		0
    #define TIFR_OCF0		1
    #define TIFR_TOV1		2
    #define TIFR_OCF1B		3
    #define TIFR_OCF1A		4
    #define TIFR_ICF1		5
    #define TIFR_TOV2		6
    #define TIFR_OCV2		7
////////////////////////////////////////////////////////////////////
/*Timer0 REGISTER  " TCCR0 "*/
	#define TCCR0_FOC0      7
	#define TCCR0_WGM00		6
	#define TCCR0_COM01		5
	#define TCCR0_COM00		4
	#define TCCR0_WGM01		3
	#define TCCR0_CS02      2
	#define TCCR0_CS01		1
	#define TCCR0_CS00		0

////////////////////////////////////////////////////////////////////////////
/*Timer1 REGISTER  " TCCR1A ,TCCR1B "*/

	#define TCCR1A_COM1A1		7
	#define TCCR1A_COM1A0		6
	#define TCCR1A_COM1B1		5
	#define TCCR1A_COM1B0		4
	#define TCCR1A_WGM11		1
	#define TCCR1A_WGM10		0

	#define TCCR1B_ICNC1		7
	#define TCCR1B_ICES1		6
	#define TCCR1B_WGM13		4
	#define TCCR1B_WGM12		3

//////////////////////////////////////////////////////////////////////////////////////
/*Timer2 REGISTER  " TCCR2 "*/

	#define TCCR2_WGM20		6
	#define TCCR2_COM21		5
	#define TCCR2_COM20		4
	#define TCCR2_WGM21		3

///////////////////////////////////////////////////////////////
#define DISABLE						                    0
#define ENABLE						                    1
#define FALLING_EDGE				                    0
#define RISING_EDGE					                    1

#define TIMER_CHANNAL_0                                 0
#define TIMER_CHANNAL_1                                 1
#define TIMER_CHANNAL_2                                 2

#define TIMER_PRE_STOP	 	                            0b1111 1000

#define TIMER_PRESCALER_MASK					        0b11111000 /* This Value also could use for bit masking */

/* Clock Select Bit Description */
    #define TIMER_NO_CLOCK_SOURCE	 	                    0
    #define TIMER_NO_PRESCALER_FACTOR 	                    1
    #define TIMER_DIVISION_FACTOR_8	 	                    2
    #define TIMER_DIVISION_FACTOR_64	                    3
    #define TIMER_DIVISION_FACTOR_256	                    4
    #define TIMER_DIVISION_FACTOR_1024	                    5
    #define TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING	        6
    #define TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING	        7


/* Waveform Generation Mode Bit Description WGM*/
    #define TIMER_NORMAL_MODE						        0
    #define TIMER_PWM_Phase_Correct_MODE			        1
    #define TIMER_CTC_MODE							        2
    #define TIMER_FAST_PWM_MODE						        3
/*Compare Output Mode, non-PWM " normal or CTC " mode */
    #define TIMER_OC_DISCONNECTED					        0
    #define TIMER_OC_TOGGEL							        1
    #define TIMER_OC_LOW							        2
    #define TIMER_OC_HIGH							        3
/* Compare Output Mode, Fast PWM Mode */
    #define TIMER_OC_DISCONNECTED					        0
    #define TIMER_CLR_ON_COM_SET_ON_TOP				        2      // NON Inverting mode
    #define TIMER_SET_ON_COM_CLR_ON_TOP				        3      // Inverting mode
/*Compare Output Mode, Phase Correct PWM Mode */
    #define TIMER_OC_DISCONNECTED					        0
    #define TIMER_CLR_COM_UPcount_SET_DOWNcount			    2      // NON Inverting mode
    #define TIMER_SET_COM_UPcount_CLR_DOWNcount		        3      // Inverting mode

/* TIMER1 MODES*/

	#define TIMER1_NORMAL_MODE								0
	#define TIMER1_PWM_8_BIT_MODE							1
	#define TIMER1_PWM_9_BIT_MODE							2
	#define TIMER1_PWM_10_BIT_MODE							3
	#define TIMER1_CTC_OCR1A_MODE							4
	#define TIMER1_FAST_PWM_8_BIT_MODE						5
	#define TIMER1_FAST_PWM_9_BIT_MODE 						6
	#define TIMER1_FAST_PWM_10_BIT_MODE						7
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE		8
	#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE	9
	#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE				10
	#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE				11
	#define TIMER1_CTC_ICR1_MODE							12
	#define TIMER1_FAST_PWM_ICR1_MODE						14
	#define TIMER1_FAST_PWM_OCR1A_MODE						15


	#define TIMER_u8_ICP_FALLING_EDGE                   0
	#define TIMER_u8_ICP_RAISING_EDGE                   1




////////////////////////////////////////////////////////////////


                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //TIMER_PRIVATE_H_
