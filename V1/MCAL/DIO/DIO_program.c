
 /*
 *  Name        : BIT_MATH.h 
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the  IO Pins implemntation 
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 *  SWC         : DIO/GPIO
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"


void DIO_voidSetPinDirection  (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Direction)
{
     //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ((Copy_u8Port <= DIO_PORTD ) && (Copy_u8Pin <= DIO_PIN7))
    {
        if ( Copy_u8Direction == DIO_PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(DDRA_Register,Copy_u8Pin); break;
			case DIO_PORTB: SET_BIT(DDRB_Register,Copy_u8Pin); break;
			case DIO_PORTC: SET_BIT(DDRC_Register,Copy_u8Pin); break;
			case DIO_PORTD: SET_BIT(DDRD_Register,Copy_u8Pin); break;
			}
		}
		else if ( Copy_u8Direction == DIO_PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(DDRA_Register,Copy_u8Pin); break;
			case DIO_PORTB: CLR_BIT(DDRB_Register,Copy_u8Pin); break;
			case DIO_PORTC: CLR_BIT(DDRC_Register,Copy_u8Pin); break;
			case DIO_PORTD: CLR_BIT(DDRD_Register,Copy_u8Pin); break;
			}
		}
        else { /*LOC_State = 0 ;*/ }
    }
    else { /*LOC_State = 0 ;*/   }
}

void DIO_voidSetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8Value    )
{
     //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ((Copy_u8Port <= DIO_PORTD ) && (Copy_u8Pin <= DIO_PIN7))
    {
        if (Copy_u8Value == DIO_PIN_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(PORTA_Register,Copy_u8Pin); break;
			case DIO_PORTB: SET_BIT(PORTB_Register,Copy_u8Pin); break;
			case DIO_PORTC: SET_BIT(PORTC_Register,Copy_u8Pin); break;
			case DIO_PORTD: SET_BIT(PORTD_Register,Copy_u8Pin); break;
			}

		}
		else if (Copy_u8Value == DIO_PIN_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(PORTA_Register,Copy_u8Pin); break;
			case DIO_PORTB: CLR_BIT(PORTB_Register,Copy_u8Pin); break;
			case DIO_PORTC: CLR_BIT(PORTC_Register,Copy_u8Pin); break;
			case DIO_PORTD: CLR_BIT(PORTD_Register,Copy_u8Pin); break;
			}
		}    
        else { /*LOC_State = 0 ;*/ }
    }
    else { /*LOC_State = 0 ;*/   }

}

u8   DIO_u8GetPinValue      (u8 Copy_u8Port , u8 Copy_u8Pin                     )
{
	u8 LOC_8uResult ;
	if ((Copy_u8Port <= DIO_PORTD) && (Copy_u8Pin <= DIO_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8Port)
		{
		case DIO_PORTA: LOC_8uResult = GET_BIT(PINA_Register,Copy_u8Pin); break;
		case DIO_PORTB: LOC_8uResult = GET_BIT(PINB_Register,Copy_u8Pin); break;
		case DIO_PORTC: LOC_8uResult = GET_BIT(PINC_Register,Copy_u8Pin); break;
		case DIO_PORTD: LOC_8uResult = GET_BIT(PIND_Register,Copy_u8Pin); break;
		}
	}
	else
	{
		/* in case of error in the Pin ID or PORT ID */
		LOC_8uResult = 0xFF ;
	}

	return LOC_8uResult;
}

void DIO_voidTogglePinValue   (u8 Copy_u8Port , u8 Copy_u8Pin                     )
{
    //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ((Copy_u8Port <= DIO_PORTD ) && (Copy_u8Pin <= DIO_PIN7))
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : TOG_BIT(PORTA_Register,Copy_u8Pin);
		break ;
		case DIO_PORTB : TOG_BIT(PORTB_Register,Copy_u8Pin);
		break ;
		case DIO_PORTC : TOG_BIT(PORTC_Register,Copy_u8Pin);
		break ;
		case DIO_PORTD : TOG_BIT(PORTD_Register,Copy_u8Pin);
		break ;
		}

	}
	else/* in case of error in the Pin ID or PORT ID */
	{
		 /*LOC_State = 0 ;*/
	}
}

void DIO_voidSetPortDirection (u8 Copy_u8Port , u8 Copy_u8Direction               )
{
     //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ( (Copy_u8Port <= DIO_PORTD) && ( (Copy_u8Direction<=255) || (Copy_u8Direction==DIO_PORT_LOW) || (Copy_u8Direction==DIO_PORT_HIGH) )  )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8Port)
		{
		    case     DIO_PORTA: DDRA_Register = Copy_u8Direction; break;
		    case     DIO_PORTB: DDRB_Register = Copy_u8Direction; break;
		    case     DIO_PORTC: DDRC_Register = Copy_u8Direction; break;
		    case     DIO_PORTD: DDRD_Register = Copy_u8Direction; break;
		    default: /*LOC_State = 0 ;*/    break;
		}	
	}
    else { /*LOC_State = 0 ;*/   }
}
void DIO_voidSetPortValue     (u8 Copy_u8Port , u8 Copy_u8Value                   )
{
     //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ((Copy_u8Port <= DIO_PORTD) && ( (Copy_u8Value<=255) || (Copy_u8Value==DIO_PORT_LOW) || (Copy_u8Value==DIO_PORT_HIGH) )  )
	{
		/* Check on the Required PORT Number */
		switch (Copy_u8Port)
		{
		    case     DIO_PORTA: PORTA_Register = Copy_u8Value; break;
		    case     DIO_PORTB: PORTB_Register = Copy_u8Value; break;
		    case     DIO_PORTC: PORTC_Register = Copy_u8Value; break;
		    case     DIO_PORTD: PORTD_Register = Copy_u8Value; break;
		    default: /*LOC_State = 0 ;*/    break;
		}	
	}
    else { /*LOC_State = 0 ;*/   }
}
u8   DIO_voidGetPortValue     (u8 Copy_u8Port                                     )
{
    u8 Copy_Data ; //WE CAN MAKE A POINTER IN FUNCTION BY TAKE ADDRESS 
    //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if ( (Copy_u8Port <= DIO_PORTD))
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : Copy_Data = PINA_Register  ; break ;
		case DIO_PORTB : Copy_Data = PINB_Register  ; break ;
		case DIO_PORTC : Copy_Data = PINC_Register  ; break ;
		case DIO_PORTD : Copy_Data = PIND_Register  ; break ;
		default : Copy_Data = 0xFF;  break;
		}
	}
    else { /*LOC_State = 0 ;*/ Copy_Data = 0xFF;   }
    
     return Copy_Data ; 
}
void DIO_voidTogglePortValue  (u8 Copy_u8Port                                     )
{     
    
    //u8 LOC_State = 1 ; //return DIO_statue ==> OK  NOK
    if (Copy_u8Port <= DIO_PORTD)
	{
		switch (Copy_u8Port)
		{
		case DIO_PORTA : PORTA_Register = ~PORTA_Register ; break ;
		case DIO_PORTB : PORTB_Register = ~PORTB_Register ; break ;
		case DIO_PORTC : PORTC_Register = ~PORTC_Register ; break ;
        case DIO_PORTD : PORTD_Register = ~PORTD_Register ; break ;
		}
	}
	else { /*LOC_State = 0 ;*/   }
}

void DIO_voidWriteHighNibbles (u8 Copy_u8Port,u8 Copy_u8value)
{
	if ( (Copy_u8Port <= DIO_PORTD))
	{
		Copy_u8value &= 0xf0;
		switch(Copy_u8Port)
		{
		case DIO_PORTA :
			PORTA_Register &= 0x0f;                   // make sure the high bits = 0000
			PORTA_Register |= Copy_u8value;			//Set only the high nibble of the port A by the given value
			break ;
		case DIO_PORTB:
			PORTB_Register &= 0x0f;                 //Set only the high nibble of the port B by the given value
			PORTB_Register |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register &= 0x0f;                 //Set only the high nibble of the port C by the given value
			PORTC_Register |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register &= 0x0f;                 //Set only the high nibble of the port D by the given value
			PORTD_Register |= Copy_u8value;
			break ;
		default: break ;

		}
	}
	else{/*LOC_State = 0 ;*/ }

}
void DIO_voidWriteLowNibbles (u8 Copy_u8Port,u8 Copy_u8value)
{
	if ( (Copy_u8Port <= DIO_PORTD))
	{
		Copy_u8value &= 0x0f;
		switch(Copy_u8Port)
		{
		case DIO_PORTA :
			PORTA_Register &= 0xf0;                 //Set only the high nibble of the port A by the given value
			PORTA_Register |= Copy_u8value;
			break ;
		case DIO_PORTB:
			PORTB_Register &= 0xf0;                 //Set only the high nibble of the port B by the given value
			PORTB_Register |= Copy_u8value;
			break ;
		case DIO_PORTC :
			PORTC_Register &= 0xf0;                 //Set only the high nibble of the port C by the given value
			PORTC_Register |= Copy_u8value;
			break ;
		case DIO_PORTD:
			PORTD_Register &= 0xf0;                 //Set only the high nibble of the port D by the given value
			PORTD_Register |= Copy_u8value;
			break ;
		default: break ;

		}
	}
	else{/*LOC_State = 0 ;*/ }

}

void DIO_voidConnectPullup    (u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectPullup)  // PORT 1  DDR 0 PUD  0
{
    if ((Copy_u8Port <= DIO_PORTD) && (Copy_u8Pin <= DIO_PIN7))
	{
		switch(Copy_u8Port)
		{
		        /* Connect or disconnect the pull up resistance to the given pin in port A */
		    case DIO_PORTA: 
                if( Copy_u8ConnectPullup == ENABLE_PULLUP )
			    {
				    CLR_BIT(SFIOR,PUD);
				    CLR_BIT(DDRA_Register,Copy_u8Pin);
				    SET_BIT(PORTA_Register,Copy_u8Pin);
			    }
			    else /*DISABLE_PULLUP*/
			    {
			    	CLR_BIT(PORTA_Register,Copy_u8Pin);
		    	}
			        break;
                /* Connect or disconnect the pull up resistance to the given pin in port B */
		    case DIO_PORTB:
			    if(Copy_u8ConnectPullup==ENABLE_PULLUP)
			    {
				    CLR_BIT(SFIOR,PUD);
				    CLR_BIT(DDRB_Register,Copy_u8Pin);
				    SET_BIT(PORTB_Register,Copy_u8Pin);
			    }
			    else /*DISABLE_PULLUP*/
			    {
				    CLR_BIT(PORTB_Register,Copy_u8Pin);
			    }
			        break;
			    /* Connect or disconnect the pull up resistance to the given pin in port C */
		    case DIO_PORTC:
			    if(Copy_u8ConnectPullup==ENABLE_PULLUP)
		    	{
			    	CLR_BIT(SFIOR,PUD);
				    CLR_BIT(DDRC_Register,Copy_u8Pin);
				    SET_BIT(PORTC_Register,Copy_u8Pin);
			    }
			    else /*DISABLE_PULLUP*/
			    {
				CLR_BIT(PORTC_Register,Copy_u8Pin);
			    }
			        break;
			    /* Connect or disconnect the pull up resistance to the given pin in port D */
		    case DIO_PORTD:
			    if(Copy_u8ConnectPullup==ENABLE_PULLUP)
			    {
				    CLR_BIT(SFIOR,PUD);
				    CLR_BIT(DDRD_Register,Copy_u8Pin);
				    SET_BIT(PORTD_Register,Copy_u8Pin);
			    }
			    else /*DISABLE_PULLUP*/
			    {
				    CLR_BIT(PORTD_Register,Copy_u8Pin);
		    	}
		        	break;
		}        
    }
    else {}
}


