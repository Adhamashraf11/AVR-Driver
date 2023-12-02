/*
 *  Name        : LDR_private.h
 *  Created on  : sep 5, 2023 
 *  Description : this file contains the privacy of  LMDR
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef LDR_PRIVATE_H_
#define LDR_PRIVATE_H_
/**
    R -> 1/light_intensity 
    v = IR ====> increase light => decrease resistance
    connected R_LDR with ground (like pull down)=> neg_coff "ordinary"  or vcc (like pull up)=> pos_coff
    Pullup_ldr   ==> Inverse proportion R_LDR = R_Known * ((Vcc-V_out)/V_out) 
    Pulldwon_ldr ==> Direct  proportion R_LDR = R_Known * (V_out/(Vcc-V_out))
*/

value = ADC_u8Read (channal);
value = (value /1023)*5;
res   = (1000 * value )/(5-value)  ;
                 /*      Include Section                     */
				 /*      Macros Defination Section           */
                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //LDR_PRIVATE_H_

u32 LDR_u32ResistorValue (u8 Copy_u8LDRChannel);
u32 LDR_u32LuxValue      (u8 Copy_u8LDRChannel);
f32 LDR_f32VoltageValue  (u8 Copy_u8LDRChannel);

#define LDR_MODE       (PULLDWON_LDR)
#define PULLUP_LDR     (5)
#define PULLDWON_LDR   (0)
#define R_KNOWN        (1000)
#define VCC            (5)

u32 LDR_u32ResistorValue (u8 Copy_u8LDRChannel)
{
    u32 R_LDR ;
    #if   (PULLUP_LDR   == LDR_MODE)
        R_LDR = R_KNOWN * ((Vcc*1000UL-V_out)/V_out) ;
    #elif (PULLDWON_LDR == LDR_MODE)
        R_LDR = R_KNOWN * (V_out/(Vcc*1000UL-V_out)) ;
    #ifndef
return R_LDR ;
}

/**
    at 1kohm
    normal LDR at 1kohm
    1lux   --> 200
    50lux  --> 2650
    100lux --> 3350
    150lux --> 3720
    techo LDR  at 5kohm
    1-24              5-1665
    2-122             6-2500
    3-239             7-3569
    4-1000            8-4165         9-4545
*/


u16 LDR_GetLuxPullup(u8 Copy_u8LDRChannel)
{
	u32 lux_value = 0;
	u16 adc_value = 0;

	// Read ADC channel where the temperature sensor is connected
	//adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	adc_value = ADC_u16GetResultSync(Copy_u8LDRChannel);
	//Res_value = (u16)(1000UL * ((5*1000UL-(u32)adc_value)/(u32)adc_value)) ;
	//Res_value = (u16) (1000UL * ((((((u32)adc_value*1000UL)/1024UL)*5))/(5*1000UL-((((u32)adc_value*1000UL)/1024UL)*5)))) ;

	//Res_value =  ((((u32)adc_value*1000UL)/1024)*5);
	//volt_value = (u16)(((u32)adc_value*5000UL)/(1024UL*10));
	lux_value =   (u16)(((u32)adc_value*5000UL)/(1024UL));  // pullup
    //	Res_value = (u16) ( 1 * ((5000UL-(u32)adc_value*1000UL)/(u32)adc_value)) ;

	return lux_value;
}