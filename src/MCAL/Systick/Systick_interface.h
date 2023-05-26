/*
 * Systick_interface.h
 *
 *  Created on: May 26, 2023
 *      Author: ss210
 */

#ifndef MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#define MCAL_SYSTICK_SYSTICK_INTERFACE_H_
#include "../../LIB/std_types.h"

void Systick_init(void);
void Systick_handeler(void);
void Systick_Delay_Sync_us(u32 delay_us);
void Systick_Delay_ASync_us(u32 delay_us,void(*ptr)(void));


#endif /* MCAL_SYSTICK_SYSTICK_INTERFACE_H_ */
