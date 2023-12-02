/*
 *  Name        : TIMER_interface.h
 *  Created on  : sep 10, 2023 
 *  Description : this file contains the interfacing of TIMER
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


                 /*      Include Section                     */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

				 /*      Macros Defination Section           */

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

 /***************************************   Timer 0   ***************************************/
void TIMER0_voidInit                (void) ;

void TIMER0_voidSetPreload          (u8 Copy_u8Preload) ;
void TIMER0_voidSetCTC              (u8 Copy_u8CTC) ;
u8   TIMER0_u8GetTimerCounterValue  (void) ;

void TIMER0_voidDelay_1sec_ov_F_Sync  (void);
void TIMER0_voidDelay_1sec_ov_F_ASync ( void (*Ptr_Func)(void));

void TIMER0_voidDelayms_CTC_Sync ( u32 Copy_u32DelayPeriod);
void TIMER0_voidDelayms_CTC_ASync( u32 Copy_u32DelayPeriod , void (*Ptr_Func)(void));


void TIMER0_voidChangePWMMode_DependFrequency ( u8 Copy_u8frequency    );
void TIMER0_voidPWMRun_Percent_0_100          ( u8 Copy_u8DutyCycle    );
void TIMER0_voidPWMRun_Value_0_255            ( u8 Copy_u8CompareValue );



/***************************************   Timer 2   ***************************************/
void TIMER2_voidInit                (void) ;

void TIMER2_voidSetPreload          (u8 Copy_u8Preload) ;
void TIMER2_voidSetCTC              (u8 Copy_u8CTC) ;
u8   TIMER2_u8GetTimerCounterValue  (void) ;

void TIMER2_voidDelay_1sec_ov_F_Sync  (void);
void TIMER2_voidDelay_1sec_ov_F_ASync ( void (*Ptr_Func)(void));

void TIMER2_voidDelayms_CTC_Sync ( u32 Copy_u32DelayPeriod);
void TIMER2_voidDelayms_CTC_ASync( u32 Copy_u32DelayPeriod , void (*Ptr_Func)(void));


void TIMER2_voidChangePWMMode_DependFrequency ( u8 Copy_u8frequency    );
void TIMER2_voidPWMRun_Percent_0_100          ( u8 Copy_u8DutyCycle    );
void TIMER2_voidPWMRun_Value_0_255            ( u8 Copy_u8CompareValue );
/***************************************   Timer 1   ***************************************/


	void TIMER1_voidInit(void) ;
	void TIMER1_voidSetPreload (u16 Copy_u16Preload) ;
	void TIMER1_voidSetCTCA (u16 Copy_u16CTCA) ;
	void TIMER1_voidSetCTCB (u16 Copy_u16CTCB) ;
	void TIMER1_voidSetICR1 (u16 Copy_u16ICR1) ;
	u16  TIMER1_u16GetTimerCounterValue (void) ;


	void TIMER_voidICUInitEnable(void);
	u8   TIMER_voidICUSetTriggerEdge(u8 Copy_u8Edge);
	void TIMER_voidICUEnableInterrupt(void);
	void TIMER_voidICUDisableInterrupt(void);
	u16  TIMER_u16GetICR(void);

	void TIMER_voidSetPWM(u16 Copy_u16CompareValue);
	u8   TIMER_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod);
	u8   TIMER_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod);
	u8   TIMER_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle);
	void TIMER_voidWDTSleep(void);
	void TIMER_voidWDTEnable (void);
	void TIMER_voidWDTDisable(void);


	u8   TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void) , u8 Copy_u8VectorID) ;


/******************************************************* *******************************************************/

/*
    u8   TIMER_u8GetPWMOnPeriod   (u16 * Copy_pu16OnPeriod);
	u8   TIMER_u8GetPWMTotalPeriod(u32 * Copy_pu32TotalPeriod);
	u8   TIMER_u8GetPWMDutyCycle  (u8  * Copy_pu8DutyCycle);
*/
	

#endif //TIMER_INTERFACE_H_


