/*
 *  Name        : TIMER2_program.c
 *  Created on  : sep 21 , 2023 
 *  Description : this file contains the programming of TIMER2
 *  Version     : v1.1
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
#include "TIMER_interface.h"

/********************************************************************************************************************************************
                                                          Globle Variable section
 ********************************************************************************************************************************************/
static u8  Gu8_Timer2_Prescaler                 ; 

static u32 Gu32_Timer2_Delay_Period             ;

static void (*Ptr_Func_Timer2_ISR)(void) = NULL ; 


/********************************************************************************************************************************************
                                                          Macros Frequency section
 ********************************************************************************************************************************************/

/*fast pwm frequenceies */
#define TIMER_PWM_FREQ_31_25KHz     (TIMER_PRESCALER_1)   // the accurate value of frequency is    31.250      KHz
#define TIMER_PWM_FREQ_3_91KHz      (TIMER_PRESCALER_8)   // the accurate value of frequency is    3.90625     KHz
#define TIMER_PWM_FREQ_500Hz        (TIMER_PRESCALER_64)  // the accurate value of frequency is    488.28125    Hz
#define TIMER_PWM_FREQ_122Hz        (TIMER_PRESCALER_256) // the accurate value of frequency is    122.0703125  Hz
#define TIMER_PWM_FREQ_30Hz         (TIMER_PRESCALER_1024)// the accurate value of frequency is    30.51757813  Hz

/*phase correct pwm frequenceies */
#define PHASE_CORRECT_OFFSET             (10) 
#define TIMER_PWM_FREQ_15_6KHz     (TIMER_PRESCALER_1    + PHASE_CORRECT_OFFSET)  // the accurate value of frequency is    15.625        KHz
#define TIMER_PWM_FREQ_2KHz        (TIMER_PRESCALER_8    + PHASE_CORRECT_OFFSET)  // the accurate value of frequency is    1.953125      KHz
#define TIMER_PWM_FREQ_250Hz       (TIMER_PRESCALER_64   + PHASE_CORRECT_OFFSET)  // the accurate value of frequency is    244.140625     Hz
#define TIMER_PWM_FREQ_61Hz        (TIMER_PRESCALER_256  + PHASE_CORRECT_OFFSET)  // the accurate value of frequency is    61.03515625    Hz
#define TIMER_PWM_FREQ_15Hz        (TIMER_PRESCALER_1024 + PHASE_CORRECT_OFFSET)  // the accurate value of frequency is    15.25878906    Hz

/********************************************************************************************************************************************
                                                             Function section
 ********************************************************************************************************************************************/

void TIMER2_voidInit(void)
{
	/*Set Configurable Modes*/
		#if   (TIMER2_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE) //TCCR2 = 0b 0000 0xxx
			/*Initialize Waveform Generation Mode as Normal Mode*/
			CLR_BIT(TCCR2_Register , TCCR2_WGM20) ;
			CLR_BIT(TCCR2_Register , TCCR2_WGM21) ;

			/*Set the Required Preload Value*/
			TCNT2_Register = TIMER2_PRELOAD_VAL ;  //TIMER2_PRELOAD_VAL = 192 with prescaller_8

			/*TIMER2 Overflow Interrupt Enable*/
			#if   (TIMER2_OVERFLOW_INTERRUPT == DISABLE)
				CLR_BIT(TIMSK , TIMSK_TOIE2) ;
			#elif (TIMER2_OVERFLOW_INTERRUPT == ENABLE)
				SET_BIT(TIMSK_Register , TIMSK_TOIE2) ;
			#else
				#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
			#endif
			TCCR2_Register &= TIMER_PRESCALER_MASK ;// TCCR & 0b11111000 = 0b 0000 0000
			TCCR2_Register |= TIMER2_PRESCALER ;    // TCCR | 0b00000xxx = 0b 0x00 0010

		#elif ( TIMER2_WAVEFORM_GENERATION_MODE == TIMER_PWM_Phase_Correct_MODE )//TCCR2 = 0b 01xx 0xxx
			/*Initialize Waveform Generation Mode as PWM Mode*/
			SET_BIT(TCCR2_Register , TCCR2_WGM20) ;
			CLR_BIT(TCCR2_Register , TCCR2_WGM21) ;

			/*Set CM PWM MODE*/
			#if TIMER2_COM_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2_Register , TCCR2_COM20) ;
					CLR_BIT(TCCR2_Register , TCCR2_COM21) ;
			#elif TIMER2_COM_PWM_MODE == TIMER_CLR_COM_UPcount_SET_DOWNcount  /*NON Inverting mode     0b 0110 0000  */ 
					CLR_BIT(TCCR2_Register , TCCR2_COM20) ;
					SET_BIT(TCCR2_Register , TCCR2_COM21) ;
			#elif TIMER2_COM_PWM_MODE == TIMER_SET_COM_UPcount_CLR_DOWNcount   /*Inverting mode        0b 0111 0000 */ 
					SET_BIT(TCCR2_Register , TCCR2_COM20) ;
					SET_BIT(TCCR2_Register , TCCR2_COM21) ;
			#else
					#error "Wrong TIMER2_CM_PWM_MODE Config"
			#endif
			TCCR2_Register &= TIMER_PRESCALER_MASK ;// TCCR & 0b11111000 = 0b 01xx 0000
			TCCR2_Register |= TIMER2_PRESCALER ;    // TCCR | 0b00000xxx = 0b 01xx 0001

			/*Set the Required CTC Value*/
			OCR2_Register = TIMER2_COM_VAL ;

		#elif (TIMER2_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE) //TCCR2 = 0b 0000 1xxx

			/*Initialize Waveform Generation Mode as CTC Mode*/
			CLR_BIT(TCCR2_Register , TCCR2_WGM20) ;
			SET_BIT(TCCR2_Register , TCCR2_WGM21) ;

			/*Set the Required CTC Value*/
			OCR2_Register = TIMER2_CTC_VAL  ;  //TIMER2_CTC_VAL = 125 with prescaller_64

			/*TIMER2 Compare Match Interrupt Enable*/
			#if TIMER2_CTC_INTERRUPT == DISABLE
				CLR_BIT(TIMSK_Register , TIMSK_OCIE0) ;
			#elif TIMER2_CTC_INTERRUPT == ENABLE
				SET_BIT(TIMSK_Register , TIMSK_OCIE0) ;
			#else
				#error "Wrong TIMER2_OVERFLOW_INTERRUPT Config"
			#endif
			TCCR2_Register &= TIMER_PRESCALER_MASK ;// TCCR & 0b11111000 = 0b 0000 1000
			TCCR2_Register |= TIMER2_PRESCALER ;    // TCCR | 0b00000xxx = 0b 0000 1011

		#elif TIMER2_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE //TCCR2 = 0b 01xx 1xxx

			/*Initialize Waveform Generation Mode as Fast PWM Mode*/
			SET_BIT(TCCR2_Register , TCCR2_WGM20) ;
			SET_BIT(TCCR2_Register , TCCR2_WGM21) ;

			/*Set CTC Fast PWM MODE*/
			#if TIMER2_COM_PWM_MODE == TIMER_OC_DISCONNECTED
					CLR_BIT(TCCR2_Register , TCCR2_COM20) ;
					CLR_BIT(TCCR2_Register , TCCR2_COM21) ;
			#elif TIMER2_COM_PWM_MODE == TIMER_CLR_ON_COM_SET_ON_TOP     /*NON Inverting mode*/ 
					CLR_BIT(TCCR2_Register , TCCR2_COM20) ;
					SET_BIT(TCCR2_Register , TCCR2_COM21) ;
			#elif TIMER2_COM_PWM_MODE == TIMER_SET_ON_COM_CLR_ON_TOP    /* Inverting mode*/
					SET_BIT(TCCR2_Register , TCCR2_COM20) ;
					SET_BIT(TCCR2_Register , TCCR2_COM21) ;
			#else
					#error "Wrong TIMER2_CM_PWM_MODE Config"
			#endif
			TCCR2_Register &= TIMER_PRESCALER_MASK ;// TCCR & 0b11111000 = 0b 01xx 1000
			TCCR2_Register |= TIMER2_PRESCALER ;    // TCCR | 0b00000xxx = 0b 01xx 1001
			/*Set the Required CTC Value*/
			OCR2_Register = TIMER2_COM_VAL ;

		#else
			#error "Wrong TIMER2_WAVEFORM_GENERATION_MODE Config"

		#endif

	/*Set the Required Prescaler*/

}
//////////////////////////////////////////////////////
void TIMER2_voidSetPreload          (u8 Copy_u8Preload) 
{
	TCNT2_Register = Copy_u8Preload ;
}
void TIMER2_voidSetCTC              (u8 Copy_u8CTC) 
{
	OCR2_Register = Copy_u8CTC ;
}
u8 TIMER2_u8GetTimerCounterValue    (void)
{
	return TCNT2_Register ;
}
/////////////////////////////////////////////////////


void TIMER2_voidDelay_1sec_ov_F_Sync (void)
{
	u16 number_ov =0;
	while (number_ov < 3907)
	{
		while (GET_BIT(TIFR_Register,TIFR_TOV2)==0);
			SET_BIT(TIFR_Register,TIFR_TOV2);
		number_ov ++ ;
	}
}

void TIMER2_voidDelay_1sec_ov_F_ASync ( void (*Ptr_Func)(void))
{
    SET_BIT(SREG_Register,7); //sei()
    Gu32_TIMER2_Delay_Period = 3907 ;
    Ptr_Func_TIMER2_ISR = Ptr_Func ;
    SET_BIT(TIMSK_Register,TIMSK_TOIE2); // flag  clearing automatic in interrupt
}


void TIMER2_voidDelayms_CTC_Sync( u32 Copy_u32DelayPeriod) // tick time 1us
{ 
    while (Copy_u32DelayPeriod -- )  
    {
        while (GET_BIT(TIFR_Register,TIFR_OCV2) == 0);
    	SET_BIT(TIFR_Register,TIFR_OCV2);
    }
    
}

void TIMER2_voidDelayms_CTC_ASync( u32 Copy_u32DelayPeriod , void (*Ptr_Func)(void))
{
       SET_BIT(SREG_Register,7); //sei()

        Gu32_TIMER2_Delay_Period = Copy_u32DelayPeriod;
        Ptr_Func_TIMER2_ISR = Ptr_Func ;
        SET_BIT(TIMSK_Register,TIMSK_OCIE2); // flag  clearing automatic in interrupt
                  
}


void TIMER2_voidChangePWMMode_DependFrequency (   u8 Copy_u8frequency  )
{ 
     Gu8_TIMER2_Prescaler = Copy_u8frequency ;
        switch ( Copy_u8frequency)
        {
           case TIMER2_PWM_FREQ_31_25KHz ... TIMER2_PWM_FREQ_30Hz :
             /* code */
                TCCR2_Register = 0x68; // 0b 0110 1000
                break;
           case TIMER2_PWM_FREQ_15_6KHz ... TIMER2_PWM_FREQ_15Hz :
                  /* code */
                TCCR2_Register = 0x60;
              Gu8_TIMER2_Prescaler -= PHASE_CORRECT_OFFSET ;
                break;
            default:
                break;
            }
}


void TIMER2_voidPWMRun_Percent_0_100 ( u8 Copy_u8DutyCycle   )
{
	/* Compare Value Range 0:255 */
	/*    DutyCycle  Range 0:100 */
	u8  Compare_Value = (u8)((Copy_u8DutyCycle * 255.0) / 100.0 ) ; /* mapping */
	OCR2_Register = Compare_Value ;
}

void TIMER2_voidPWMRun_Value_0_255 ( u8 Copy_u8CompareValue )
{
	/* Compare Value Range 0:255 */
	OCR2_Register = Copy_u8CompareValue;
}








/*TIMER2 Normal Mode ISR*/
void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void)
{
	if ( Ptr_Func_TIMER2_ISR != NULL)
	{
        if(Gu32_TIMER2_Delay_Period != 0)
        {
            Gu32_TIMER2_Delay_Period -- ;
        }
		else 
        {
             Ptr_Func_TIMER2_ISR() ;
            CLR_BIT(TIMSK_Register,TIMSK_TOIE2):
        }
	}
    else 
    {
            //# error "no adress function"
    }
   // asm ("reti"); // reti is return but in assamble
}

/*TIMER2 CTC Mode ISR*/
void __vector_4(void) __attribute__((signal)); //decleration
void __vector_4(void)                          //defination
{
    if ( Ptr_Func_TIMER2_ISR != NULL)
	{
        if(Gu32_TIMER2_Delay_Period != 0)
        {
            Gu32_TIMER2_Delay_Period -- ;
        }
		else 
        {
            Ptr_Func_TIMER2_ISR() ;
            CLR_BIT(TIMSK_Register,TIMSK_OCIE2):
        }
	}
    else 
    {
            //# error "no adress function"
    }
   // asm ("reti"); // reti is return but in assamble
}

