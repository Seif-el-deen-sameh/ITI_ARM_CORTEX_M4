/*
 * NVIC_program.c
 *
 *  Created on: May 22, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"
void NVIC_Intialize(void){
	/* Local Variable for the Value of AIRCR Register */
	u32 AIRCR_Register_Value;

	/* Set Configuration System SW Priority */
	AIRCR_Register_Value = VECT_KEY | (PRIORITY_CONFIG << 8);

	/* Assign the Value to AIRCR Register */
	SCB_AIRCR = AIRCR_Register_Value;
}
void NVIC_Enable_interrupt(u8 Id){
	NVIC->ISER[Id/32]=1<<(Id%32);
}
void NVIC_Disable_interrupt(u8 Id){
	NVIC->ICER[Id/32]=1<<(Id%32);
}
void NVIC_Set_Pending_Flag(u8 Id){
	NVIC->ISPR[Id/32]=1<<(Id%32);
}
void NVIC_Clear_Pending_Flag(u8 Id){
	NVIC->ICPR[Id/32]=1<<(Id%32);
}
void NVIC_Set_Priority(u8 Id,u8 group_prioity,u8 sub_priority){
		NVIC->IPR[Id] = (group_prioity << (7 - PRIORITY_CONFIG));
		NVIC->IPR[Id] = (sub_priority << (PRIORITY_CONFIG - 3));
}
u8 NVIC_Read_Active_flag(u8 Id){
	u8 Active_flag;
	Active_flag=get_bit(NVIC->ICPR[Id/32],(Id%32));
	return Active_flag;
}

