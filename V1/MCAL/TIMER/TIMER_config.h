/*
 *  Name        : TIMER_config.h
 *  Created on  : sep 10, 2023 
 *  Description : this file contains the configuration of TIMER
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

                 /*      Include Section                     */
#include "TIMER_private.h"
#include "TIMER_register.h"
				 /*      Macros Defination Section           */
/***************************************    Timer0    Config    ****************************************/

/*       Mode
 * Set Timer0 Waveform Generation Mode
 * 1. TIMER_NORMAL_MODE
 * 2. TIMER_PWM_Phase_Correct_MODE
 * 3. TIMER_CTC_MODE
 * 4. TIMER_FAST_PWM_MODE
 */
#define TIMER0_WAVEFORM_GENERATION_MODE		TIMER_CTC_MODE

/*      Prescaler
 * set the Required Prescaler
 * - TIMER_NO_CLOCK_SOURCE
 * - TIMER_NO_PRESCALER_FACTOR 
 * - TIMER_DIVISION_FACTOR_8          // using with ov_F MODE
 * - TIMER_DIVISION_FACTOR_64         // using with CTC  MODE
 * - TIMER_DIVISION_FACTOR_256
 * - TIMER_DIVISION_FACTOR_1024
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER0_SET_PRESCALER		TIMER_NO_CLOCK_SOURCE



/* 
 *  This condition macros
 *  Determine modes with (PRELOAD_VAL - COM_VAL - CTC_VAL)
 *	Determine Appropriate prescaler for each modes  
 *  Determine EN/DS INTURRPT
 *  Determine Compare Match Output Mode
**/
#if    (TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE)
		/*Set the Required Preload on TIMER0 Normal Mode*/
		#define TIMER0_PRELOAD_VAL					192
		#define TIMER0_PRESCALER		TIMER_DIVISION_FACTOR_8

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER0_OC0_MODE						TIMER_OC_DISCONNECTED
		/*Set Timer0 Overflow Interrupt
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER0_OVERFLOW_INTERRUPT			ENABLE
#elif  (TIMER0_WAVEFORM_GENERATION_MODE == TIMER_PWM_Phase_Correct_MODE)
		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER0_COM_VAL						0     //250
		#define TIMER0_PRESCALER		TIMER_NO_PRESCALER_FACTOR
		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_COM_UPcount_SET_DOWNcount    // NON Inverting mode
		 * 3. TIMER_SET_COM_UPcount_CLR_DOWNcount    // Inverting mode
		 */
		#define TIMER0_COM_PWM_MODE						TIMER_CLR_COM_UPcount_SET_DOWNcount
#elif  (TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE)

		/*Set the Required Compare Match Value on TIMER0 CTC Mode*/
		#define TIMER0_CTC_VAL						125
		#define TIMER0_PRESCALER		TIMER_DIVISION_FACTOR_64

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER0_OC0_MODE						TIMER_OC_DISCONNECTED

		/*Set Timer0 CTC Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER0_CTC_INTERRUPT			ENABLE
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

		/*Set the Required Compare Match Value on TIMER0 OCR Mode*/
		#define TIMER0_COM_VAL						0
		#define TIMER0_PRESCALER		TIMER_NO_PRESCALER_FACTOR
		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_COM_SET_ON_TOP  // NON Inverting mode
		 * 3. TIMER_SET_ON_COM_CLR_ON_TOP  // Inverting mode
		 */
		#define TIMER0_COM_PWM_MODE						TIMER_CLR_ON_COM_SET_ON_TOP
#else
		#error "Wrong TIMER0_WAVEFORM_GENERATION_MODE Config"
#endif


/***************************************    Timer2    Config    ****************************************/

/*       Mode
 * Set Timer2 Waveform Generation Mode
 * 1. TIMER_NORMAL_MODE
 * 2. TIMER_PWM_Phase_Correct_MODE
 * 3. TIMER_CTC_MODE
 * 4. TIMER_FAST_PWM_MODE
 */
#define TIMER2_WAVEFORM_GENERATION_MODE		TIMER_PWM_Phase_Correct_MODE

/*      Prescaler
 * set the Required Prescaler
 * - TIMER_NO_CLOCK_SOURCE
 * - TIMER_NO_PRESCALER_FACTOR 
 * - TIMER_DIVISION_FACTOR_8          // using with ov_F MODE
 * - TIMER_DIVISION_FACTOR_64         // using with CTC  MODE
 * - TIMER_DIVISION_FACTOR_256
 * - TIMER_DIVISION_FACTOR_1024
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
 */
#define TIMER2_SET_PRESCALER		TIMER_NO_CLOCK_SOURCE



/* 
 *  This condition macros
 *  Determine modes with (PRELOAD_VAL - COM_VAL - CTC_VAL)
 *	Determine Appropriate prescaler for each modes  
 *  Determine EN/DS INTURRPT
 *  Determine Compare Match Output Mode
**/
#if    (TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE)
		/*Set the Required Preload on TIMER2 Normal Mode*/
		#define TIMER2_PRELOAD_VAL					192
		#define TIMER2_PRESCALER		TIMER_DIVISION_FACTOR_8

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER2_OC2_MODE						TIMER_OC_DISCONNECTED
		/*Set Timer2 Overflow Interrupt
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER2_OVERFLOW_INTERRUPT			ENABLE
#elif  (TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_Phase_Correct_MODE)
		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_COM_VAL						0     //250
		#define TIMER2_PRESCALER		TIMER_NO_PRESCALER_FACTOR
		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_COM_UPcount_SET_DOWNcount    // NON Inverting mode
		 * 3. TIMER_SET_COM_UPcount_CLR_DOWNcount    // Inverting mode
		 */
		#define TIMER2_COM_PWM_MODE						TIMER_CLR_COM_UPcount_SET_DOWNcount
#elif  (TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE)

		/*Set the Required Compare Match Value on TIMER2 CTC Mode*/
		#define TIMER2_CTC_VAL						125
		#define TIMER2_PRESCALER		TIMER_DIVISION_FACTOR_64

		/*Set Compare Match Output Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_OC_TOGGEL
		 * 3. TIMER_OC_LOW
		 * 4. TIMER_OC_HIGH
		 */
		#define TIMER2_OC2_MODE						TIMER_OC_DISCONNECTED

		/*Set Timer2 CTC Interrupt
		 * Choose between
		 * 1. DISABLE
		 * 2. ENABLE
		 */
		#define TIMER2_CTC_INTERRUPT			ENABLE
#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE

		/*Set the Required Compare Match Value on TIMER2 OCR Mode*/
		#define TIMER2_COM_VAL						0
		#define TIMER2_PRESCALER		TIMER_NO_PRESCALER_FACTOR
		/*Set PWM Mode
		 * Choose between
		 * 1. TIMER_OC_DISCONNECTED
		 * 2. TIMER_CLR_ON_COM_SET_ON_TOP  // NON Inverting mode
		 * 3. TIMER_SET_ON_COM_CLR_ON_TOP  // Inverting mode
		 */
		#define TIMER2_COM_PWM_MODE						TIMER_CLR_ON_COM_SET_ON_TOP
#else
		#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"
#endif

/***************************************    Timer1    Config    ****************************************/
	/*Timer1 Config*/

	/*Set Timer1 Waveform Generation Mode
	 * Choose between
	 * 1. TIMER1_NORMAL_MODE
	 * 2. TIMER1_PWM_8_BIT_MODE
	 * 3. TIMER1_PWM_9_BIT_MODE
	 * 4. TIMER1_PWM_10_BIT_MODE
	 * 5. TIMER1_CTC_OCR1A_MODE
	 * 6. TIMER1_FAST_PWM_8_BIT_MODE
	 * 7. TIMER1_FAST_PWM_9_BIT_MODE
	 * 8. TIMER1_FAST_PWM_10_BIT_MODE
	 * 9. TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE
	 * 10.TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE
	 * 11.TIMER1_PWM_PHASE_CORRECT_ICR1_MODE
	 * 12.TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE
	 * 13.TIMER1_CTC_ICR1_MODE
	 * 14.TIMER1_FAST_PWM_ICR1_MODE
	 * 15.TIMER1_FAST_PWM_OCR1A_MODE
	 */
	#define TIMER1_WAVEFORM_GENERATION_MODE		TIMER1_FAST_PWM_ICR1_MODE

	/*Set the Required Prescaler
	 * Choose between
	 * - TIMER_NO_CLOCK_SOURCE
	 * - TIMER_NO_PRESCALER_FACTOR
	 * - TIMER_DIVISION_FACTOR_8
	 * - TIMER_DIVISION_FACTOR_64
	 * - TIMER_DIVISION_FACTOR_256
	 * - TIMER_DIVISION_FACTOR_1024
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_FALLING
	 * - TIMER_T0_EXTERNAL_CLOCK_SOURCE_RISING
	 */
	#define TIMER1_PRESCALER					TIMER_DIVISION_FACTOR_8

	/*Set Preload Value for Normal Mode*/
	#define TIMER1_PRELOAD_VAL					0

	/*Set CTCA Value*/
	#define TIMER1_CTCA_VAL						500

	/*Set CTCB Value*/
	#define TIMER1_CTCB_VAL						0

	/*Set Input Capture Value*/
	#define TIMER1_ICR1_VAL						20000

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1A_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Compare Match Output for OCR1A
	 * Choose between
	 *
	 * 		CTC mode				||	PWM & FAST PWM mode
	 *
	 * 1. TIMER_OC_DISCONNECTED		|| TIMER_OC_DISCONNECTED
	 * 2. TIMER_OC_TOGGEL			||
	 * 3. TIMER_OC_LOW				|| TIMER_CLR_ON_CTC_SET_ON_TOP
	 * 4. TIMER_OC_HIGH				|| TIMER_SET_ON_CTC_CLR_ON_TOP
	 */
	#define TIMER1_OCR1B_MODE					TIMER_CLR_ON_CTC_SET_ON_TOP

	/*Set Timer1 Input Capture Noise Canceler
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_NOISE_CANCELER			DISABLE

	/*Set Timer1 Input Capture Edge
	 * Choose between
	 * 1. FALLING_EDGE
	 * 2. RISING_EDGE
	 */
	#define TIMER1_ICR_EDGE				RISING_EDGE

	/*Set Timer1 Overflow Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_OVERFLOW_INTERRUPT			DISABLE

	/*Set Timer1 CTCB Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCB_INTERRUPT			DISABLE

	/*Set Timer1 CTCA Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_CTCA_INTERRUPT			DISABLE

	/*Set Timer1 Input Capture Interrupt
	 * Choose between
	 * 1. DISABLE
	 * 2. ENABLE
	 */
	#define TIMER1_ICR_INTERRUPT			DISABLE

/**************************************/
#define TIMER_u8_ICP_INIT_STATE      TIMER_u8_ICP_RAISING_EDGE





                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //TIMER_CONFIG_H_

