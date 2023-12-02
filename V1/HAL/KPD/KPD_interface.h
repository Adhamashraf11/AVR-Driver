/*
 *  Name        : KPD_interface.h
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the interfacing of Keypad
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
 
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

                 /*      Include Section                     */
				 /*      Macros Defination Section           */

#define NOTPRESSED 0xff

#define KPAD_PORT_NOT_PRESSED 0x7F       
                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

void KPD_Init(void);
u8   KPD_u8GetPressed( void );

#endif /* KPD_INTERFACE_H_ */


