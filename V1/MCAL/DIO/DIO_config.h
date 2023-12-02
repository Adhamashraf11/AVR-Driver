
 /*
 *  Name        : DIO_config.h
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the configration of DIO 
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 

/* File Guard */
#ifndef  DIO_CONFIG_H_
#define  DIO_CONFIG_H_
                 /*      Include Section                     */
		 /*      Macros Defination Section           */
                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */
                 
/*   two nibbles of port ==>     LOW_NIBBLE       HIGH_NIBBLE   */
#define LOW_NIBBLE_OUTPUT  0x0f
#define HIGH_NIBBLE_OUTPUT 0xf0

/*    BITS   */
#define ONE_BIT     1
#define TWO_BITS    2
#define THREE_BITS  3
#define FOUR_BITS   4
#define FIVE_BITS   5
#define SIX_BITS    6
#define SEVEN_BITS  7
#define EIGHT_BITS  8

/*  options of pullup connection ==>  ENABLE_PULLUP   DISABLE_PULLUP */
#define ENABLE_PULLUP  1
#define DISABLE_PULLUP 0

#endif //DIO_CONFIG_H_

