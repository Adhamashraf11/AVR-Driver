/*
 *  Name        : UART_register.h
 *  Created on  : sep 12, 2023 
 *  Description : this file contains the configuration of register
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef UART_REGISTER_H_
#define UART_REGISTER_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/**************************            Registers         **********************/

/*   USART I/O Data Register  */
#define UDR_Register             * ((volatile u8 *) 0X2C)

/*  USART Control and Status Register A  */
#define UCSRA_Register           * ((volatile u8 *) 0X2B)

/*  USART Control and Status Register B  */
#define UCSRB_Register           * ((volatile u8 *) 0X2A)

/*  USART Control and Status Register C  */
#define UCSRC_Register           * ((volatile u8 *) 0X40)

/*  USART Baud Rate Registers  */
#define UBRRH_Register           * ((volatile u8 *) 0X40)
#define UBRRL_Register           * ((volatile u8 *) 0X29)


                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //UART_REGISTER_H_