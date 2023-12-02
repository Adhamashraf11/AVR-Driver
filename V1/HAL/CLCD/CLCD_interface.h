/*
 *  Name        : CLCD_interface.h
 *  Created on  : aug 14, 2023 
 *  Description : this file contains the interfacing of CLCD (2*16)
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 
 /* File Guard */
 
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
#include "CLCD_config.h"
                 /*      Include Section                     */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"


				 /*      Macros Defination Section           */
/************************************************************************/
/*Check MODE LCD 8BIT or 4BIT*/
#if   (CLCD_MODE == 8)
#define EIGHT_BITS    (0x38)   //8-bit mode intialized
#elif (CLCD_MODE == 4)
#define FOUR_BITS     (0x28)   //4-bit mode intialized
#endif 

/************************************************************************/
#define LCD_DISPLAYOFF_CURSOROFF_BLINKOFF        0x08    //1000
#define LCD_DISPLAYOFF_CURSOROFF_BLINKON         0x09    //1001
#define LCD_DISPLAYOFF_CURSOROON_BLINKOFF        0x0A    //1010
#define LCD_DISPLAYOFF_CURSOROON_BLINKON         0x0B    //1011
#define LCD_DISPLAYON_CURSOROFF_BLINKOFF         0x0C    //1100
#define LCD_DISPLAYON_CURSOROFF_BLINKON          0x0D	 //1101
#define LCD_DISPLAYON_CURSORON_BLINKOFF          0x0E	 //1110
#define LCD_DISPLAYON_CURSORON_BLINKON           0x0F    //1111


#define LCD_CLEAR        0x01
#define LCD_HOME         0x02
#define LCD_ENTRY_MODE   0x06
  



#define LCD_CGRAM                     0x40          // the first Place/Address at CGRAM (0b01xxxxxx)
#define LCD_SETCURSOR                 0x80          // set cursor position at DDRAM (0b1xxxxxxx)
#define lcd_FunctionReset             0x30          // reset the LCD


/************************************************************************/
/* used with DDRAM CLCD*/
// ROW DIMENTIION
#define CLCD_ROW_1      1
#define CLCD_ROW_2      2
// COL DIMENTIION
#define CLCD_COL_1      1
#define CLCD_COL_2      2
#define CLCD_COL_3      3
#define CLCD_COL_4      4
#define CLCD_COL_5      5
#define CLCD_COL_6      6
#define CLCD_COL_7      7
#define CLCD_COL_8      8
#define CLCD_COL_9      9
#define CLCD_COL_10     10
#define CLCD_COL_11     11
#define CLCD_COL_12     12
#define CLCD_COL_13     13
#define CLCD_COL_14     14
#define CLCD_COL_15     15
#define CLCD_COL_16     16
/************************************************************************/



                 /*      User Defination Type Section        */
                 /*      Function Decleration Section        */
void CLCD_voidInit             ( void                       );
void CLCD_voidSendData         ( u8 Copy_u8Data             );
void CLCD_voidSendCommand      ( u8 Copy_u8Command          );

void CLCD_voidClearScreen      ( void                       );
void LCD_voidClearPart      (u8 Copy_Line,u8 Copy_Start,u8 Copy_End);

void CLCD_voidSendString       ( const u8 *Copy_u8ptrString );
u8 CLCD_u8StringLength         (const u8 *Copy_u8ptrString );


  
void CLCD_voidSetPostion       ( u8 Copy_u8Row,u8 Copy_u8Col);  /* used with DDRAM CLCD => to determine postion cursor */


void CLCD_voidSendExtraChar    ( u8 Copy_u8Row,u8 Copy_u8Col); /* used with CGRAM CLCD => to determine postion cursor */



void CLCD_voidSendNumber                ( u64 Copy_u64Number                    );



#endif //SSD_INTERFACE_H_
