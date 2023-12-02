
/*
 *  Name        : STD_TYPES.h
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the standarize data type definations  
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : LIB
 */
 

/* File Guard */
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

                 /*      Include Section                     */

				 /*      Macros Defination Section           */
#define NULL 0

/* Func States  */
#define IDLE 			0
#define BUSY			1

/* My States  */
#define OK           	0
#define NOK          	1
#define NULL_POINTER 	2
#define BUSY_STATE	 	3
#define TIMEOUT_STATE   4

				 /*      User Defination Type                 */
typedef unsigned char           u8 ;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;
typedef signed char	            s8 ;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;
typedef float                   f32;
typedef double                  f64;
typedef enum
	{
		fasle,
		true,
	}bool;



					/*      Function Decleration Section          */
	
#endif // STD_TYPES_H_ 









