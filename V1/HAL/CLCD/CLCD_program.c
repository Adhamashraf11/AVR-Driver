/*
 *  Name        : CLCD_program.h
 *  Created on  : aug 14, 2023 
 *  Description : this file contains the programming of CLCD
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : HAL
 */
 

#include "CLCD_interface.h"
#include "CLCD_private.h"

#include "CLCD_extrachar.h"
//#include <avr/io.h>
//#define F_CPU 8000000UL //unsigned long int
#include "avr/delay.h"


void CLCD_voidInit             (void)
{
    /*********************<<<<  8 BIT MODE   >>>>>>>>***************************/
    #if   ( CLCD_MODE == 8 )
    //must waiting more than 30ms before any action (to rise VDD to 4.5v ) 
    _delay_ms (50);
    //make all pins of LCD as OutPut
    DIO_voidSetPortDirection (CLCD_DATA_PORT       ,        DIO_PORT_OUTPUT);
    DIO_voidSetPinDirection  (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT );
    DIO_voidSetPinDirection  (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT );
    DIO_voidSetPinDirection  (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT );

    //
    CLCD_voidSendCommand      ( LCD_HOME) ; 
    _delay_ms (1); 

    // FUNCTION SET COMMEND :  2 line 5*8 font size  
    CLCD_voidSendCommand      ( 0x38 ) ; // 8 BIT MODE => 0X38
    _delay_ms (1); // Wait more than 39 MicroSecound
    
    // DISPLAY ON/OFF CONTROL  
    CLCD_voidSendCommand      ( LCD_DISPLAYON_CURSOROFF_BLINKOFF ) ; //
    _delay_ms (1); // Wait more than 39 MicroSecound

    // DISPLAY CLEAR
    CLCD_voidClearScreen ();
    // DISPLAY MODE SET
    CLCD_voidSendCommand(LCD_ENTRY_MODE);
    _delay_ms (1);
    /*********************<<<<  4 BIT MODE   >>>>>>>>***************************/
    #elif ( CLCD_MODE == 4)
    _delay_ms (50);


    #endif


}

void CLCD_voidSendData         ( u8 Copy_u8Data    )
{
    if ( CLCD_MODE == 8 )
    {
        DIO_voidSetPortValue     (CLCD_DATA_PORT    , Copy_u8Data);
        DIO_voidSetPinValue      (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH); //send data
        /*RW always conc=nect ground to write */
        DIO_voidSetPinValue      (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW );
     CLCD_voidSendFallingEdge  ();
    }
    else if ( CLCD_MODE == 4)
    {

    }
    else {}
        _delay_ms (1);
}
void CLCD_voidSendCommand      ( u8 Copy_u8Command )
{
    
    if ( CLCD_MODE == 8 )
    {
        DIO_voidSetPortValue     (CLCD_DATA_PORT    , Copy_u8Command);
        DIO_voidSetPinValue      (CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW ); //send COMMAND
        /*RW always conc=nect ground to write */
        DIO_voidSetPinValue      (CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW );
         CLCD_voidSendFallingEdge  ();

    }
    else if ( CLCD_MODE == 4)
    {

    }
    else {}
    _delay_ms (1);

}
static void CLCD_voidSendFallingEdge  (void)
{
            DIO_voidSetPinValue (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_HIGH );
            _delay_ms (1);
            DIO_voidSetPinValue (CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_LOW  );
            _delay_ms (1);
}
void CLCD_voidClearScreen (void)
{
    CLCD_voidSendCommand (LCD_CLEAR);
    _delay_ms (10);
}

void LCD_voidClearPart(u8 Copy_Line,u8 Copy_Start,u8 Copy_End)
{

	switch(Copy_Line) // Copy_u8LineNum --> used to detect the line to write on LCD line 0 or line 1.
		{
			case 0:
				LCD_voidSendCommand(0x80+Copy_Start);

				for(;Copy_Start<Copy_End ; Copy_Start++)
				{
					LCD_voidSendChar(' ');
				}
				break;
			case 1:
				LCD_voidSendCommand(0xC0+Copy_Start);

				for(;Copy_Start<Copy_End ; Copy_Start++)
				{
					LCD_voidSendChar(' ');
				}
				break;
		}
}
void CLCD_voidSendString      ( const u8 *Copy_u8ptrString    )
{
    u8 LOC_Iterator = 0 ;
    while (Copy_u8ptrString [LOC_Iterator] != '\0')
    {
        CLCD_voidSendData(Copy_u8ptrString [LOC_Iterator]);
        LOC_Iterator++;
    }

}
void CLCD_voidSetPostion       ( u8 Copy_u8Row,u8 Copy_u8Col)
{
    u8 LOC_u8data ; 
    /* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = LCD_SETCURSOR ;   // first location
	}
    else if( Copy_u8Row == CLCD_ROW_1 ){

		LOC_u8data = ( ( LCD_SETCURSOR ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}
	else if( Copy_u8Row == CLCD_ROW_2 ){

		LOC_u8data = ( ( LCD_SETCURSOR ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
        else{ LOC_u8data = LCD_SETCURSOR ; /**/}

	CLCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);


}


void CLCD_voidSendExtraChar    ( u8 Copy_u8Row,u8 Copy_u8Col)
{
    u8 LOC_u8Iterator = 0 ; 
    //step 1 : GO TO CGRAM
	CLCD_voidSendCommand ( LCD_CGRAM ); //make AC refers to first address at CGRAM

    //step 2 : Draw character 
    for (LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar);LOC_u8Iterator++)
    {
     CLCD_voidSendData (CLCD_u8ExtraChar[LOC_u8Iterator]);   
    }

    //step 3 : Return AC  refers to DDRAM
	CLCD_voidSetPostion (Copy_u8Row , Copy_u8Col); //make AC refers to first address at DDRAM

    //step 4 : Send character address 
    for (LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++)
    {
     CLCD_voidSendData ( LOC_u8Iterator );   
    }

	_delay_ms(1);
}
u8 CLCD_u8StringLength (const u8 *Copy_u8ptrString )
{
	u8 LOC_Iterator = 0 ;
	    while (Copy_u8ptrString [LOC_Iterator] != '\0')
	    {
	        LOC_Iterator++;
	    }
	return LOC_Iterator;
}


void CLCD_voidSendNumber   ( u64 Copy_u64Number    )
{

	u64 LOC_u64Reversed = 1 ;

	if( Copy_u64Number == 0 ){ CLCD_voidSendData('0'); }

	else{

		while( Copy_u64Number != 0 ){

			LOC_u64Reversed = ( LOC_u64Reversed * 10 ) + ( Copy_u64Number % 10 );
			Copy_u64Number /= 10 ;//150/10=15/10=1

		}
		while( LOC_u64Reversed != 1 ){

			CLCD_voidSendData( ( LOC_u64Reversed % 10 ) + 48 );
			LOC_u64Reversed /= 10 ;

		}

	}

}

///////////////////////////////////***********************************************************/////////////////
void LCD_voidCustomChar(void)
{
	u8 L_u8AddressCounter=0x40; // variable to give the LCD the address of the first bit to save the custom character.
	u8 L_u8CounterFirstDim; // variable for counting for first (for) loop.
	u8 L_u8CounterSecondDim; // variable for counting for second (for) loop.
	for(L_u8CounterFirstDim=0 ; L_u8CounterFirstDim<=1 ; L_u8CounterFirstDim++) // function to loop in first dimension in array.
	{
		LCD_voidSendCommand(L_u8AddressCounter); // make the lCD read the command of the first address.
		for(L_u8CounterSecondDim=0 ; L_u8CounterSecondDim<=7 ; L_u8CounterSecondDim++) // function to loop in second dimension in array.
		{
			LCD_voidSendChar(A_u8LCD_CustomChar[L_u8CounterFirstDim][L_u8CounterSecondDim]); // send the custom character to store it in LCD.
		}
		LCD_voidSetLocation(0,L_u8CounterFirstDim); // select the location that you want to display the data on it.
		LCD_voidSendChar(L_u8CounterFirstDim); // this line used to tell the LCD to display the data.
		_delay_ms(10); // waiting 10ms.
		L_u8AddressCounter=L_u8AddressCounter+0x08; // increment the address to give the lCD the next custom character.
	}
}
/************************************ADD************************************/
void LCD_voidDisplayNumber(u32 Copy_num)
{
	u8 L_u8Digit=0;
	u8 A_u8array[15];
	s8 L_u8Count=0;
	while(Copy_num>0)
	{
		L_u8Digit = Copy_num % 10;
		Copy_num = Copy_num / 10;
		A_u8array[L_u8Count]=L_u8Digit;
		L_u8Count++;
	}
	while(L_u8Count>0)
	{

			LCD_voidSendChar(A_u8array[L_u8Count-1]+0x30);
			L_u8Count--;
	}
	
}
