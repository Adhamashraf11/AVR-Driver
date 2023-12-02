/*
 *  Name        : LM35_program.c
 *  Created on  : sep 1, 2023 
 *  Description : this file contains the programming of sensor temprature
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"




void LM35_voidInt (void)
{
	/*Initialize ADC*/
    ADC_voidInit  ()  ;
    ADC_voidEnable()  ;    
	ADC_voidInterruptEnable();
}




void LM35_u8GetTemp (LM35_CONFIG * lm35 , u8 * Copy_u8TempValue) 
{
	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;
	u16 Local_u8ADCReference = ( lm35->Copy_u8ADCVoltageReference ) * 1000 ;  // To Convert from ( V --> mV )2560
	// ADC Digital Reading  
	Local_u16ADCResult = ADC_u16GetResultSync( lm35->Copy_u8LM35Channel  ) ;
	// Check for ADC Resolution  
	if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 1024UL) ;
	}
	else if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 256UL) ;
	}
	// Convert ( mv --> Temp ) 
	* Copy_u8TempValue = Local_u16AnalogValue / 10 ;
}

u8 LM35_u8GetTemperature ( u8 Copy_u8LM35Channel )
{
    u8  Local_u8TempValue ;
    u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;
	u16 Local_u8ADCReference = ( ADCVoltageReference ) * 1000 ;  // To Convert from ( V --> mV )2560
	/* ADC Digital Reading  */
	Local_u16ADCResult = ADC_u16GetResultSync( Copy_u8LM35Channel ) ;
	/* Check for ADC Resolution  */
	if ( ADC_RESOLUTION == ADC_RESOLUTION_10_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / (1024UL*10)) ;
	}
	else if ( ADC_RESOLUTION == ADC_RESOLUTION_8_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) /( 256UL*10)) ;
	}
	/* Convert ( mv --> Temp ) */
	 Local_u8TempValue = Local_u16AnalogValue  ;
    return Local_u8TempValue ;
}





/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
//extern uint16 g_adcResult;  //           shared global variable from another file
u8 LM35_getTemperature(void)
{
	u8 temp_value = 0;
	u16 adc_value = 0;

	// Read ADC channel where the temperature sensor is connected
	//adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	adc_value = ADC_u16GetResultSync(SENSOR_CHANNEL_ID);


#if (ADC_uint8IMPLEMENTATION_BASED == ADC_uint8INTERRUPT_BASED)
	//Calculate the temperature from the ADC value

	temp_value = (u8)(((u32)g_adcResult*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

#elif (ADC_uint8IMPLEMENTATION_BASED == ADC_uint8POOLLING_BASED)
	temp_value = (u16)(((u32)adc_value*5000UL)/(1024UL*10));

	// ADC_REF_VOLT_VALUE -> 5v     SENSOR_MAX_VOLT_VALUE ->  1.5   ADC_MAXIMUM_VALUE -> 1023   SENSOR_MAX_TEMPERATURE -> 150
#endif
	return temp_value;
}







