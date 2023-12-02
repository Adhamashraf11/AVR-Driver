/*
 *  Name        : UART_interface.h
 *  Created on  : sep 12, 2023 
 *  Description : this file contains the interfacing of UART
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

                 /*      Include Section                     */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "UART_private.h"
#include "UART_register.h"
#include "UART_config.h"
				 /*      Macros Defination Section           */
                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

void USART_voidInit              (void                     ) ;
void UART_voidInit_Iput_Baud_Rate(u16 Local_u16BaudRate    ) ;
void   USART_u8SendData          (u8 Copy_u8Data           ) ;
void   USART_u8RecevieData       (u8 * Copy_u8ReceviedData ) ;


void USART_SendString    (u8 * Copy_u8String);
void USART_RecevieString (u8 * Copy_u8String);



void   USART_u8SendStringSynch     (const u8 * Copy_pchString);
void   USART_u8SendStringAsynch    (const u8 * Copy_pchString , void (* NotificationFunc)(void)) ;

void   USART_u8ReceiveBufferSynch  (u8 * Copy_pchString , u32 Copy_uint32BufferSize) ;
void   USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_uint32BufferSize , void (* NotificationFunc)(void)) ;



void USART_SendStream    (u8 * Copy_u8DataByte , u8 Copy_u8DataSize );
void USART_RecevieStream (u8 * Copy_u8DataByte , u8 Copy_u8DataSize );

u8  USART_u8RecevieDataValue (void);
void  USART_u8ClearFlag_RXC  (void);


#endif //UART_INTERFACE_H_
