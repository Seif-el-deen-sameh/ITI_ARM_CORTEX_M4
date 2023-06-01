/*
 * NVIC_interface.h
 *
 *  Created on: May 22, 2023
 *      Author: ss210
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
void NVIC_Intialize(void);
void NVIC_Enable_interrupt(u8 Id);
void NVIC_Disable_interrupt(u8 Id);
void NVIC_Set_Pending_Flag(u8 Id);
void NVIC_Clear_Pending_Flag(u8 Id);
void NVIC_Set_Priority(u8 Id,u8 group_prioity,u8 sub_priority);
u8 	 NVIC_Read_Active_flag(u8 Id);
#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
