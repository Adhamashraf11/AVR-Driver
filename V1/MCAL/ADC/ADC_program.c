/*
 *  Name        : ADC_program.h
 *  Created on  : aug 20, 2023 
 *  Description : this file contains the programming of Analoge to Digital Converter
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 

#include <avr/io.h>
#include "ADC_interface.h"

/*Global flag for the ADC Busy State*/
static u8 ADC_u8State = IDLE ;   // IDLE = 0 , BUSY = 1 



void ADC_voidInit (void)
{
    //ADMUX_REGISTER 
	/*  Select the voltage reference*/
	#if ( ADC_VREF == AREF ) /*0b00xx xxxx*/ 
		CLR_BIT(ADMUX , ADMUX_REFS0) ;
		CLR_BIT(ADMUX , ADMUX_REFS1) ;
	#elif ( ADC_VREF == AVCC )  /*0b01xx xxxx*/
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		CLR_BIT(ADMUX , ADMUX_REFS1) ;
	#elif ( ADC_VREF == INTERNAL_2_56 ) /*0b11xx xxxx*/
		SET_BIT(ADMUX , ADMUX_REFS0) ;
		SET_BIT(ADMUX , ADMUX_REFS1) ;
	#else
		#error "Wrong ADC_VREF config"
	#endif
    /*  Select  ADC Adjustment*/
    #if ( ADC_ADJUSTMENT == RIGHT_ADJUSTMENT) /*0bxx0x xxxx*/
        CLR_BIT(ADMUX , ADMUX_ADLAR) ;
    #elif ( ADC_ADJUSTMENT == LEFT_ADJUSTMENT )  /*0bxx1x xxxx*/
    	SET_BIT(ADMUX , ADMUX_ADLAR) ;
    #else
        #error "Wrong ADC_ADJUSTMENT  config"
    #endif 

    //ADCSRA_REGISTER
    /*Set Prescaler Value*//*select CLK 'From 50 KHZ to 200 KHZ'---> Input CLK = 8 MHZ ====> So We will select CLK / 64 */
	ADCSRA &= ADC_PRE_MASK ;
    ADCSRA |= ADC_PRESCALLER ;
    
	/* 	// Disable AutoTrigger Enable
	CLR_BIT(ADCSRA , ADATE);
	*/
 
    /*Enable ADC Peripheral*/
    #if (ADC_STATUS == ADC_DISABLE)
		CLR_BIT(ADCSRA , AADCSRA_ADEN) ;
	#elif (ADC_STATUS == ADC_ENABLE)
		SET_BIT(ADCSRA , ADCSRA_ADEN) ;
	#else
	    #error "Wrong ADC_STATUS config"
	#endif 

    /*Enable ADC Interrupt*/
	#if INT_STATUS == INT_DISABLE
		CLR_BIT(ADCSRA  , ADCSRA_ADIE) ;
	#elif INT_STATUS == INT_ENABLE
		SET_BIT(ADCSRA  , ADCSRA_ADIE) ;
	#else
	#error "Wrong INT_STATUS config"
	#endif 
}

u16 ADC_u8GetResultSync (u8 Copy_u8Channel )
{
    u16 Copy_pu16Result ;
	u8  Local_u8ErrorState = OK ;
	u32 Local_u32TimeoutCounter = 0 ;
	if (Copy_pu16Result <= ADC_CHANNEL7)
	{
		if (ADC_u8State == IDLE)  
		{
			/*ADC is now Busy*/
			ADC_u8State = BUSY ;

			/*Set required channel*/
			ADMUX &= ADC_CH_MASK ; //0B11100000
			ADMUX |= Copy_u8Channel ;

			/*Start Conversion*/
			SET_BIT(ADCSRA , ADCSRA_ADSC) ;

			/*Waiting until the conversion is complete*/
			while (((GET_BIT(ADCSRA , ADCSRA_ADIF)) == 0) && (Local_u32TimeoutCounter < ADC_TIMEOUT))
			{
				Local_u32TimeoutCounter++ ;
			}
			if (Local_u32TimeoutCounter == ADC_TIMEOUT)   // ADC_TIMEOUT = 50000
			{
				//Local_u8ErrorState = TIMEOUT_STATE ;   // ERROR ==> TIMEOUT_STATE = 34 
                //Copy_pu16Result = ADC_DATA_RE ;
                //#error "Time Out state "
                Copy_pu16Result = 0x00 ;
			}
			else
			{
				/*Clear the interrupt flag*/ // ADIF is cleared by writing a logical one to the flag
				SET_BIT(ADCSRA , ADCSRA_ADIF) ;

				/*Return Conversion Result*/
				#if ADC_ADJUSTMENT == RIGHT_ADJUSTMENT
					Copy_pu16Result = (ADCL|(ADCH << 8))  ;

				#elif ADC_ADJUSTMENT == LEFT_ADJUSTMENT
					Copy_pu16Result = ADCH ;
				#else
					#error "Wrong ADC_ADJUSTMENT config"

				#endif
			}

			/*ADC is IDLE*/
			ADC_u8State = IDLE ;
		}
		else
		{
          Copy_pu16Result = 0x00; // ERROR ==>  000
			//Local_u8ErrorState = BUSY_STATE ; // ERROR ==> BUSY_STATE = 3
		}
	}
	else
	{
        // #ERROR "Wrong channal "
		//Local_u8ErrorState = NULL_POINTER ;// ERROR ==> NULL_POINTER = 2
        Copy_pu16Result = 0x00; // ERROR ==>  000
	}
	return Copy_pu16Result ;
}

void ADC_voidEnable (void)
{
	SET_BIT(ADCSRA , ADCSRA_ADEN) ;
}

void ADC_voidDisable (void)
{
	CLR_BIT(ADCSRA , ADCSRA_ADEN) ;
}

void ADC_voidInterruptEnable (void)
{
	SET_BIT(ADCSRA , ADCSRA_ADIE) ;
}

void ADC_voidInterruptDisable (void)
{
	CLR_BIT(ADCSRA , ADCSRA_ADIE) ;
}

void ADC_u8SetPrescaler (u8 Copy_u8Prescaler)
{
	if (Copy_u8Prescaler < 8)
	{
		/*Set Prescaler Value*/
		ADCSRA &= ADC_PRE_MASK ;
		ADCSRA |= Copy_u8Prescaler ;
	}
    else
    {
        //#error "wrong prescaler"
    }
}




 
