/*
 * EXTI_program.c
 *
 *  Created on: May 28, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

void (*Global_PtrToFunc_EXTI[16])(void) = {};
void EXTI_Enable_Int(u8 Int_ID , void(*Copy_ptrToFunc)(void)){
	if(Copy_ptrToFunc != 0)
	{
		Global_PtrToFunc_EXTI[Int_ID] = Copy_ptrToFunc ;
	}
	set_bit(EXTI->IMR , Int_ID);
}
void EXTI_Disable_Int(u8 Int_ID){
	clr_bit(EXTI->IMR , Int_ID);
}
void EXTI_Set_Sense_Signal(u8 Sense_Signal , u8 Int_ID){
	switch(Sense_Signal)
	{
		case FALLING_EDGE:
			clr_bit(EXTI->FTSR , Int_ID);
			set_bit(EXTI->RTSR , Int_ID);
			break;
		case RISING_EDGE:
			clr_bit(EXTI->RTSR , Int_ID);
			set_bit(EXTI->FTSR , Int_ID);
			break;
		case ON_CHANGE:
			set_bit(EXTI->RTSR , Int_ID);
			set_bit(EXTI->FTSR , Int_ID);
			break;
	}
}
void EXTI_Set_Line_Port(u8 Int_ID , u8 Port_ID){
	SYSCFG->EXTICR[Int_ID/4] &= ~(0b1111 << ((Int_ID % 4)*4)) ;
	SYSCFG->EXTICR[Int_ID/4] |= Port_ID <<((Int_ID % 4)*4) ;
}
static void EXTI_Clear_Pending_Flag(u8 Int_ID){
	set_bit(EXTI->PR , Int_ID);
}
void EXTI0_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[0]();
	EXTI_Clear_Pending_Flag(EXTI_LINE0);
}
void EXTI1_IRQHandler(void)
{
	Global_PtrToFunc_EXTI[1]();
	EXTI_Clear_Pending_Flag(EXTI_LINE1);
}
