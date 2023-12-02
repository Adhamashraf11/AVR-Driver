/*
 *  Name        : ADC_private.h
 *  Created on  : aug 20, 2023 
 *  Description : this file contains the privacy of Analoge to Digital Converter
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/* Data Reg  */
#define ADCH				*((volatile u8*)0x25)		//ADC high register
#define ADCL				*((volatile u8*)0x24)		//ADC Low register	
#define ADC_DATA_RE 		*((volatile u16*)0x24)		//ADC Low + High	



 // Bit Masking Macros  
#define ADC_PRE_MASK				( 0b11111000 )
#define ADC_CH_MASK				    ( 0b11100000 )

#define ADMUX				*((volatile u8*)0x27)		//ADC multiplexer selection register
/* ADMUX Bits   */
#define ADMUX_REFS1         7							//Reference selection bit 
#define ADMUX_REFS0         6							//Reference selection bit 
#define ADMUX_ADLAR         5							//ADC left adjust result
/*
#define ADMUX_MUX4         4
#define ADMUX_MUX3         3	
#define ADMUX_MUX2         2	
#define ADMUX_MUX1         1	
#define ADMUX_MUX0         0
*/

#define ADCSRA			    	*((volatile u8*)0x26)		//ADC control and status register A
/* ADCSRA Bits   */
#define ADCSRA_ADEN		    	7							//ADC enable
#define ADCSRA_ADSC		    	6                           //Start conversion
#define ADCSRA_ADATE		    5                           //Auto trigger enable
#define ADCSRA_ADIF		    	4                           //Interrupt flag
#define ADCSRA_ADIE			    3                           //Interrupt enable
#define ADCSRA_ADPS2		    2                           //Prescaler bit2
#define ADCSRA_ADPS1		    1                           //Prescaler bit1
#define ADCSRA_ADPS0		    0                           //Prescaler bit0




#define SFIOR  *((volatile u8 *)0x50)
/* SFIOR Bits   */
/*
#define SFIOR_ADTS2			7                          //Trigger Source bit2
#define SFIOR_ADTS1	     	6                          //Trigger Source bit1
#define SFIOR_ADTS0		    5                          //Trigger Source bit0
*/

/* // Values of the global var (ADC_u8ISRSource)  
#define SINGLE_CHANNEL_ASYNCH 0
#define CHAIN_CHANNEL_ASYNCH  1
*/



                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //ADC_PRIVATE_H_