/*
 *  Name        : UART_private.h
 *  Created on  : sep 12, 2023 
 *  Description : this file contains the privacy of UART
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
 /* File Guard */
 
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


                 /*      Include Section                     */
				 /*      Macros Defination Section           */

/*  USART Control and Status Register A  */
#define UCSRA_RXC		7  //USART Receive Complete  This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is empty
#define UCSRA_TXC		6  //USART Transmit Complete This flag bit is set when the entire frame in the transmit Shift Register has been shifted out and there are no new data currently present in the transmit buffer (UDR)
#define UCSRA_UDRE		5  //USART Data Register Empty is one, the buffer is empty, and therefore ready to be written
#define UCSRA_FE		4  // Frame Error next character in the receive buffer had a Frame Error when received.
#define UCSRA_DOR		3  // Data OverRun occurs when the receive buffer is full (two characters)
#define UCSRA_PE		2  // Parity Error
#define UCSRA_U2X		1  // Double the USART Transmission Speed
#define UCSRA_MPCM		0  // Multi-processor Communication Mode

/*  USART Control and Status Register B  */
#define UCSRB_RXCIE		7
#define UCSRB_TXCIE		6
#define UCSRB_UDRIE		5
#define UCSRB_RXEN		4
#define UCSRB_TXEN		3
#define UCSRB_UCSZ2		2
#define UCSRB_RXB8		1
#define UCSRB_TXB8		0

/*  USART Control and Status Register C  */
#define UCSRC_URSEL 	7
#define UCSRC_UMSEL		6
#define UCSRC_UPM1		5
#define UCSRC_UPM0		4
#define UCSRC_USBS		3
#define UCSRC_UCSZ1		2
#define UCSRC_UCSZ0		1
#define UCSRC_UCPOL		0

/* this bit to control what register access UCSRC "1" or  UBRRH "0"  becouse of same address */
#define UBRRH_URSEL		7

/*********************************************************/

#define DISABLE				                    ( 0 )
#define ENABLE				                    ( 1 )

#define USART_U1X			                    ( 0 )
#define USART_U2X			                    ( 1 )

#define ASYNCHRONOUS		                    ( 0 )
#define SYNCHRONOUS 		                    ( 1 )

#define EVEN_PARITY			                    ( 2 )
#define ODD_PARITY 			                    ( 3 )

#define STOP_BIT_1			                    ( 0 )
#define STOP_BIT_2			                    ( 1 )

#define DATA_SIZE_5_BIT		                    ( 0 )
#define DATA_SIZE_6_BIT		                    ( 1 )
#define DATA_SIZE_7_BIT		                    ( 2 )
#define DATA_SIZE_8_BIT		                    ( 3 )
#define DATA_SIZE_9_BIT		                    ( 7 )

#define XCK_RISING_TX_XCH_FALLING_RX			0
#define XCK_RISING_RX_XCH_FALLING_TX			1

#define UBRRL_MAX								256


/* Famouse Value of UBRR Settings for Frequency"8MHz" using table U1X */
#define UART_2400_BPS             ( 207 )
#define UART_4800_BPS             ( 103 )
#define UART_9600_BPS             ( 51  )
#define UART_19200_BPS            ( 25  )
#define UART_115200_BPS           ( 3   )

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */

#endif //UART_PRIVATE_H_


