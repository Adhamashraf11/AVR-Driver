
 /*
 *  Name        : BIT_MATH.h 
 *  Created on  : aug 12, 2023 
 *  Description : this file contains the bit wise maths 
 *  Version     : v1.0
 *  Author      : Adham
 *  Layer       : LIB
 */
 

/* File Guard */
#ifndef BIT_MATH_H_
#define BIT_MATH_H_
                 /*      Include Section                     */

				 /*      Macros Defination Section           */
#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)     reg|=(1<<bit)
#define CLR_BIT(reg,bit)     reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)     reg^=(1<<bit)
#define GET_BIT(reg,bit)     (reg&(1<<bit))>>bit
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)
#define ROR(reg,num)         reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))
#define ROL(reg,num)         reg= (reg>>(REGISTER_SIZE-num))|(reg<<(num))

                /*      User Defination Type                 */
                /*      Function Decleration Section          */
                
#endif //BIT_MATH_H_