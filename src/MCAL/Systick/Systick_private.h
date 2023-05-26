/*
 * Systick_private.h
 *
 *  Created on: May 26, 2023
 *      Author: ss210
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRIVATE_H_
#define MCAL_SYSTICK_SYSTICK_PRIVATE_H_

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
}STK_t;
#define STK	((volatile STK_t*)(0x40020000))

#endif /* MCAL_SYSTICK_SYSTICK_PRIVATE_H_ */
