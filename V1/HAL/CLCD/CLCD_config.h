/*
 *  Name        : CLCD_config.h
 *  Created on  : aug 14, 2023 
 *  Description : this file contains the configration of CLCD
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

                 /*      Include Section                     */
				 /*      Macros Defination Section           */
/*MODE LCD 8BIT or 4BIT*/
#define CLCD_MODE       8

//USED   PORTS
/*D0 ---> D7*/
#define CLCD_DATA_PORT         (DIO_PORTA)
/* RS - RW - EN*/
#define CLCD_CONTROL_PORT      (DIO_PORTC)

//USED   PINS
/* RS - RW - EN*/
#define CLCD_RS         (DIO_PIN0)
#define CLCD_RW         (DIO_PIN1)
#define CLCD_EN         (DIO_PIN2)

                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */


#endif //CLCD_CONFIG_H_


