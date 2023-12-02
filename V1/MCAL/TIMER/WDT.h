/*
 *  Name        : WDT.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the Watch Dog Timer
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef WDT_H_
#define WDT_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/***************************************   register    ****************************************/

#define WDTCR        *((volatile u8 *)(0x41))



/********************** WDTCR Bits **********************/
	#define		WDTCR_WDTOE 			4
	#define		WDTCR_WDE				3
	#define		WDTCR_WDP2				2
	#define		WDTCR_WDP1				1
	#define		WDTCR_WDP0				0

/********************** WDT Prescaler select  **********************/
	#define		WDT_PS_MASKING				0b11111000
	#define		WDT_PS_16_3_MS				0
	#define		WDT_PS_32_5_MS	    		1
	#define		WDT_PS_65_MS	    		2
	#define		WDT_PS_0_13_S				3
	#define		WDT_PS_0_26_S				4
	#define		WDT_PS_0_52_S				5
	#define		WDT_PS_1_0_S				6
	#define		WDT_PS_2_1_S				7     // 2.1sec



/* WDT Prescaler select */
	/*
	     Options :-
		1- WDT_PS_16_3_MS	   ( for 16.3 ms )
		2- WDT_PS_32_5_MS	   ( for 32.5 ms )
		3- WDT_PS_65_MS	       ( for 65   ms )
		4- WDT_PS_0_13_S	   ( for 0.13  s )
		5- WDT_PS_0_26_S	   ( for 0.26  s )
		6- WDT_PS_0_52_S	   ( for 0.52  s )
		7- WDT_PS_1_0_S	       ( for 1.0   s )
		8- WDT_PS_2_1_S	       ( for 2.1   s )

	*/
#define WDT_PRESCALER      WDT_PS_1_0_S


#define TIMING        WDT_PRESCALER

/* this function is used to start the WDT Operation */
#define WDT_START(TIMING)       WDTCR_Register = (1<<WDTCR_WDE) | TIMING/* Set Bit 3&4 at the same CLK cycle  */
 


/* this function is used to stop the WDT Operation */
#define WDT_STOP ()     do \
                        {\
                            WDTCR_Register |= WDTCR |= 0b00011000 ;/* Set Bit 3&4 at the same CLK cycle  */\
                            WDTCR_Register = 0 ;/* I don't care for any value in this Reg Cuz I want to Disable */\
                            asm("WDR");/*to reset timer WD not system*/\
                        }while(0)

/* this function is used to refresh the WDT Operation */
#define WDT_REFRESH()   asm("WDR") /*to reset timer WD not system and start from zero*/


                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //WDT_H_