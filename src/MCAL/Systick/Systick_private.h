/*
 * Systick_private.h
 *
 *  Created on: May 26, 2023
 *      Author: ss210
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

#define SINGLE    0
#define PERIODIC  1

typedef struct
{
	volatile u32 CTRL ;
	volatile u32 LOAD ;
	volatile u32 VAL ;
}STK_REG;

#define STK ((STK_REG *)(0xE000E010))

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
