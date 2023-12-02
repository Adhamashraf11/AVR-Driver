/*
 *  Name        : UART_program.c
 *  Created on  : aug 15, 2023 
 *  Description : this file contains the programming of UART
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : MCAL
 */
 
#include "UART_interface.h"

/****************************  Global variable   ********************************/

/*Global variable to carry the send Data*/
static const u8 * USART_pu8SendData = NULL ;

/*Global variable to carry the Receive Data*/
static u8 * USART_pu8ReceiveData = NULL ;

/*Global variable to carry the buffer size*/
static u8 USART_u8BufferSize ;

/*Global variable to indicate for the current Data index of the buffer*/
static u8 USART_u8Index ;

/*Global pointer to function to carry the notification function called by ISR*/
static void (*USART_pvNotificationFunc)(void)= NULL;



void USART_voidInit (void)
{  
	
	/*Calculate The Baud Rate From The Equation */
	u16 Local_u16UBRR = (u16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)) - 1) ;
	
    /*CLR UCSRC */
	CLR_BIT(UCSRC_Register , UCSRC_URSEL) ; // to accses UBRRH_Register
	/************************************   UBRRL_Register & UBRRH_Register   ************************************/
	UBRRH_Register = (u8)(Local_u16UBRR >> 8) ; /* MSBs at Local_u16UBRR */ 
	UBRRL_Register = (u8)(Local_u16UBRR) ;	    // Hint : UBRRH then UBRRL to avoid problems
	
	/************************************  UCSRA_Register  ************************************/
    /*  Check  Modes   */
	#if   (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_U1X)

		CLR_BIT(UCSRA_Register , UCSRA_U2X) ;

	#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_U2X)

		Local_u16UBRR /= 2 ;
		SET_BIT(UCSRA_Register , UCSRA_U2X) ;

	#elif (USART_MODE == SYNCHRONOUS)

		Local_u16UBRR /= 8 ;

	#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif

    /*Multi-Processor Communication mode*/
	#if   (USART_MPCM == DISABLE)
		CLR_BIT(UCSRA_Register , UCSRA_MPCM) ;
	#elif (USART_MPCM == ENABLE)
		SET_BIT(UCSRA_Register , UCSRA_MPCM) ;
	#else
		#error "Wrong USART_MPCM config"
	#endif

	/************************************   UCSRB_Register   ************************************/
	/*RX Complete Interrupt Enable*/
	#if   (USART_RX_COMPLETE_INTERRUPT == DISABLE)
		CLR_BIT(UCSRB_Register , UCSRB_RXCIE) ;
	#elif (USART_RX_COMPLETE_INTERRUPT == ENABLE)
		SET_BIT(UCSRB_Register , UCSRB_RXCIE) ;
	#else
		#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
	#endif
	/*TX Complete Interrupt Enable*/
	#if   (USART_TX_COMPLETE_INTERRUPT == DISABLE)
		CLR_BIT(UCSRB_Register , UCSRB_TXCIE) ;
	#elif (USART_TX_COMPLETE_INTERRUPT == ENABLE)
		SET_BIT(UCSRB_Register , UCSRB_TXCIE) ;
	#else
		#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
	#endif

	/*UDR Empty Interrupt Enable*/
	#if   (USART_UDR_EMPTY_INTERRUPT == DISABLE)
		CLR_BIT(UCSRB_Register , UCSRB_UDRIE) ;
	#elif (USART_UDR_EMPTY_INTERRUPT == ENABLE)
		SET_BIT(UCSRB_Register , UCSRB_UDRIE) ;
	#else
		#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
	#endif

	/*Receive Enable*/
	#if   (USART_RECEIVER_ENABLE == DISABLE)
		CLR_BIT(UCSRB_Register , UCSRB_RXEN) ;
	#elif (USART_RECEIVER_ENABLE == ENABLE)
		SET_BIT(UCSRB_Register , UCSRB_RXEN) ;
	#else
		#error "Wrong USART_RECEIVER_ENABLE config"
	#endif

	/*Transmitter Enable*/
	#if   (USART_TRANSMITTER_ENABLE == DISABLE)
		CLR_BIT(UCSRB_Register , UCSRB_TXEN) ;
	#elif (USART_TRANSMITTER_ENABLE == ENABLE)
		SET_BIT(UCSRB_Register , UCSRB_TXEN) ;
	#else
		#error "Wrong USART_TRANSMITTER_ENABLE config"
	#endif

	/************************************   UCSRC_Register   ************************************/
	/*Set UCSRC */
	SET_BIT(UCSRC_Register , UCSRC_URSEL) ;

    /*USART Mode BIT6 UMSEL*/
	#if   (USART_MODE == ASYNCHRONOUS)
		CLR_BIT(UCSRC_Register , UCSRC_UMSEL) ;
	#elif (USART_MODE == SYNCHRONOUS)
		SET_BIT(UCSRC_Register , UCSRC_UMSEL) ;
	#else
		#error "Wrong USART_MODE config"
	#endif

	/*Parity Mode*/
	#if   (USART_PARITY_MODE == DISABLE)
		CLR_BIT(UCSRC_Register , UCSRC_UPM0) ;
		CLR_BIT(UCSRC_Register , UCSRC_UPM1) ;
	#elif (USART_PARITY_MODE == EVEN_PARITY)
		CLR_BIT(UCSRC_Register , UCSRC_UPM0) ;
		SET_BIT(UCSRC_Register , UCSRC_UPM1) ;
	#elif (USART_PARITY_MODE == ODD_PARITY)
		SET_BIT(UCSRC_Register , UCSRC_UPM0) ;
		SET_BIT(UCSRC_Register , UCSRC_UPM1) ;
	#else
		#error "Wrong USART_PARITY_MODE config"
	#endif

	/*Stop Bit*/
	#if   (USART_STOP_BIT == STOP_BIT_1)
		CLR_BIT(UCSRC_Register , UCSRC_USBS) ;
	#elif (USART_STOP_BIT == STOP_BIT_2)
		SET_BIT(UCSRC_Register , UCSRC_USBS) ;
	#else
		#error "Wrong USART_STOP_BIT config"
	#endif

	/*Data Size*/
	#if (USART_DATA_SIZE == DATA_SIZE_5_BIT)
		CLR_BIT(UCSRC_Register , UCSRC_UCSZ0) ;
		CLR_BIT(UCSRC_Register , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB_Register , UCSRB_UCSZ2) ;
	#elif (USART_DATA_SIZE == DATA_SIZE_6_BIT)
		SET_BIT(UCSRC_Register , UCSRC_UCSZ0) ;
		CLR_BIT(UCSRC_Register , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB_Register , UCSRB_UCSZ2) ;
	#elif (USART_DATA_SIZE == DATA_SIZE_7_BIT)
		CLR_BIT(UCSRC_Register , UCSRC_UCSZ0) ;
		SET_BIT(UCSRC_Register , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB_Register , UCSRB_UCSZ2) ;
	#elif (USART_DATA_SIZE == DATA_SIZE_8_BIT)
		SET_BIT(UCSRC_Register , UCSRC_UCSZ0) ;
		SET_BIT(UCSRC_Register , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB_Register , UCSRB_UCSZ2) ;
	#elif (USART_DATA_SIZE == DATA_SIZE_9_BIT)
		SET_BIT(UCSRC_Register , UCSRC_UCSZ0) ;
		SET_BIT(UCSRC_Register , UCSRC_UCSZ1) ;
		SET_BIT(UCSRB_Register , UCSRB_UCSZ2) ;
	#else
		#error "Wrong USART_DATA_SIZE config"
	#endif

	/*Clock Polarity (for SYNCHRONOUS mode only)*/
	#if USART_MODE == SYNCHRONOUS
		#if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
			CLR_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
		#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
			SET_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
		#else
			#error "Wrong USART_STOP_BIT config"
		#endif
	#endif

	/*Store the value in UCSRC Register (one operation) */
	// UCSRC_Register = Local_u8UCSRC ;


}


void   USART_u8SendData (u8 Copy_u8Data)
{
		u32 Local_u32TimeoutCounter = 0 ;

	/************************************  UDR_Register  ************************************/
	/*Wait until the Transmitter Register is Empty*/
	//while(GET_BIT(UCSRA_Register , UCSRA_TXC ) == 0);
		/*Wait until a Receiving complete or Timing out*/
	while (((GET_BIT(UCSRA_Register , UCSRA_UDRE)) == 0) && (Local_u32TimeoutCounter != USART_u32TIMEOUT))//Hint : TIMEOUT to avoid infinity loop
	{
		Local_u32TimeoutCounter++ ;
	}
	if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
	{
			//Local ErrorState  TIMEOUT_STATE ;
	}
	else
	{
		UDR_Register = Copy_u8Data ;
		//waiting until the data is transmitted through pin Tx
		while (((GET_BIT(UCSRA_Register , UCSRA_TXC)) == 0));
		//clear transmission flag
		SET_BIT(UCSRA_Register , UCSRA_TXC);
	}
 
}


void  USART_u8RecevieData (u8 * Copy_u8ReceviedData)
{
		u32 Local_u32TimeoutCounter = 0 ;

    if (Copy_u8ReceviedData != NULL)
	{
		/************************************  UDR_Register  ************************************/
		/*Wait until a receive complete*/
		while (((GET_BIT(UCSRA_Register , UCSRA_RXC)) == 0) && (Local_u32TimeoutCounter != USART_u32TIMEOUT))
		{
			Local_u32TimeoutCounter++ ;
		}
		if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
		{
			//Local ErrorState  TIMEOUT_STATE ;
		}
		else
		{
			* Copy_u8ReceviedData = UDR_Register ; /*Recevier Data Byte*/
		}
	}
	else
	{
		//NULL_POINTER ;
	}
}

void USART_SendString (u8 * Copy_u8String)
{
	u32 LOC_u32Index = 0 ;
	if (Copy_u8String != NULL)
	{
		while (Copy_u8String[LOC_u32Index] != '\0')
		{
			USART_u8SendData(Copy_u8String[LOC_u32Index]) ;
			LOC_u32Index++ ;
		}
	}
	else
	{
		//NULL_POINTER ;
	}

}

void USART_RecevieString (u8 * Copy_u8String)
{
	u32 LOC_u32Index = 0 ;
	if (Copy_u8String != NULL)
	{
		while (Copy_u8String[LOC_u32Index] != '\0')
		{
			USART_u8RecevieData(Copy_u8String[LOC_u32Index]) ;
			LOC_u32Index++ ;
		}
	}
	else
	{
		//NULL_POINTER ;
	}
}




void USART_u8SendStringSynch (const u8 * Copy_pchString  , u32 Copy_u32StringSize)
{
	u32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Local_u32Index < Copy_u32StringSize)
		{
			USART_u8SendData(*Copy_pchString[Local_u32Index]) ;
			Local_u32Index++ ;
		}
	}
	else
	{
		//Local ErrorState NULL POINTER ;
	}
}

void   USART_u8SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void))
{
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
		{
			/*USART is now Busy*/
			USART_u8State = BUSY ;

			/*Assign the USART data globally*/
			USART_pu8SendData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;

			/*Set Index to first element*/
			USART_u8Index = 0 ;

			/*Send first Data */
			UDR = USART_pu8SendData[USART_u8Index] ;

			/*USART Transmit Interrupt Enable*/
			SET_BIT(UCSRB , UCSRB_TXCIE) ;
		}
		else
		{
			//Local ErrorState NULL_POINTER ;
		}	
}




void USART_u8ReceiveBufferSynch (u8 * Copy_pchString , u32 Copy_u32BufferSize)
{
	u32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Local_u32Index < Copy_u32BufferSize)
		{
			USART_u8RecevieData(&Copy_pchString[Local_u32Index]) ;
			Local_u32Index++ ;
		}
	}
	else
	{
		//Local ErrorState NULL_POINTER ;
	}
}



void USART_u8ReceiveBufferAsynch (u8 * Copy_pchString , u32 Copy_u32BufferSize , void (* NotificationFunc)(void))
{
	if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
	{
			/*USART is now Busy*/
			USART_u8State = BUSY ;

			/*Assign the USART data globally*/
			USART_pu8ReceiveData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;
			USART_u8BufferSize = Copy_u32BufferSize;

			/*Set Index to first element*/
			USART_u8Index = 0 ;

			/*USART Recieve Interrupt Enable */
			SET_BIT(UCSRB , UCSRB_RXCIE) ;
	}
	else
	{
			//Local ErrorState  NULL_POINTER ;
	}
}


//-------------------------------------------------------------------------------------------------------------------------------
/* ISR for RX complete */
void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void)
{
	/*Receive next Data*/
	USART_pu8ReceiveData[USART_u8Index] = UDR_Register ;

	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	if (USART_u8Index == USART_u8BufferSize)
	{
			/*USART Recieve Interrupt Disable*/
		SET_BIT(UCSRB_Register , UCSRB_RXCIE) ;
		/*Send Data Complete*/

		USART_u8Index=0;
		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Recieve Interrupt Disable*/
		CLR_BIT(UCSRB_Register , UCSRB_RXCIE) ;
	}
	else
	{
		/*Do Noting*/
	}
}

//-------------------------------------------------------------------------------------------------------------------------------
/* ISR for TX complete */
void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{

	/*Increment Data index of the buffer*/
	USART_u8Index++ ;

	if (USART_pu8SendData[USART_u8Index] == '\0')
	{
		SET_BIT(UCSRB_Register , UCSRB_TXCIE) ;

		/*Receive Data Complete*/
		USART_u8Index=0;

		/*Call Notification Function*/
		USART_pvNotificationFunc() ;

		/*USART Transmit Interrupt Disable*/
		CLR_BIT(UCSRB_Register , UCSRB_TXCIE) ;
	}
	else
	{
		/*Send Data not Complete*/
		/*Send next Data*/
		UDR_Register = USART_pu8SendData[USART_u8Index] ;
	}
}

///////////////////////////////////////////////////////////////////////////////
/* ISR for  Data Register Empty complete */
void __vector_14 (void)		__attribute__ ((signal)) ;
void __vector_14 (void)
{




}

















void USART_SendStream (u8 * Copy_u8DataByte , u8 Copy_u8DataSize )
{  /** anther form for USART_SendString */
	if (Copy_u8DataByte != NULL)
	{
		while (Copy_u8DataSize--)
		{
			USART_u8SendData(*Copy_u8DataByte) ;
			Copy_u8DataByte++ ;
		}
	}
	else
	{
		//NULL_POINTER ;
	}
}


void USART_RecevieStream (u8 * Copy_u8DataByte , u8 Copy_u8DataSize )
{  /** anther form for USART_RecevieString */
	if (Copy_u8DataByte != NULL)
	{
		while (Copy_u8DataSize--)
		{
			USART_u8RecevieData(*Copy_u8DataByte) ;
			Copy_u8DataByte++ ;
		}
	}
	else
	{
		//NULL_POINTER ;
	}
}



u8  USART_u8RecevieDataValue (void)
{

		while (((GET_BIT(UCSRA_Register , UCSRA_RXC)) == 0));
		return UDR_Register ;
}

void  USART_u8ClearFlag_RXC (void)
{

		u8 LOC_Var =  UDR_Register ;
}






//initilize func but take baud rate
void UART_voidInit_Iput_Baud_Rate(u16 Local_u16BaudRate)
{
	u8 Local_u8_UCSRCValue=0b1000000;
	// NORMAL SPEED
	CLR_BIT(UCSRA_Register, UCSRA_U2X);
	// DISABLE MULTI PROCESSOR
	CLR_BIT(UCSRA_Register, UCSRA_MPCM);

	// RECIEVER & TRANSMITTER ENABLE
	SET_BIT(UCSRB_Register, UCSRB_RXEN);
	SET_BIT(UCSRB_Register, UCSRB_TXEN);

	// 8BIT DATA
	CLR_BIT(UCSRB_Register, UCSRB_UCSZ2);

	// ASYNCHRONOUS MODE
	CLR_BIT(Local_u8_UCSRCValue, UCSRC_UMSEL);

	//DISABLE PARITY MODE
	CLR_BIT(Local_u8_UCSRCValue, UCSRC_UPM0);
	CLR_BIT(Local_u8_UCSRCValue, UCSRC_UPM1);

	// 2 STOP BIT
	SET_BIT(Local_u8_UCSRCValue, UCSRC_USBS);

	// UPDATE UCSRC VALUE
	UCSRC_Register = Local_u8_UCSRCValue;

	// SET BAUD RATE
	switch(Local_u16BaudRate)
	{
	case 2400:
		UBRR_Register  = 207;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	case 4800:
		UBRR_Register   = 103;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	case 9600:
		LUBRR_Register = 51;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	case 19200:
		UBRR_Register  = 25;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	case 115200:
		UBRR_Register  = 3;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	
	default:
		UBRR_Register  = (F_CPU/(16*(u32)BAUD_RATE))-1 ;
		UBRRH_Register = (u8) (Local_u16BaudRate >> 8);
		UBRRL_Register = (u8) Local_u16BaudRate;
		break;
	}
}

