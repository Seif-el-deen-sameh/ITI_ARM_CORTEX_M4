/*
 * Systick_program.c
 *
 *  Created on: May 26, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "Systick_config.h"
#include "Systick_interface.h"
#include "Systick_private.h"

void (*Global_PtrToFunc)(void);
u8 Global_Async_Repitition = SINGLE ;

void Systick_init(void){
	STK->CTRL = 0 ;
	STK->LOAD = 0 ;
	STK->VAL  = 0 ;
}
void Systick_Delay_Sync_us(u32 delay_us){
		clr_bit(STK->CTRL , 1 ) ;
		STK->LOAD = (delay_us*2) ;
		set_bit(STK->CTRL , 0) ;
		while((get_bit(STK->CTRL,16))==0);
		clr_bit(STK->CTRL , 0) ;
		STK->LOAD = 0 ;
		STK->VAL  = 0 ;
}
void Systick_Delay_ASync_us_Single(u32 delay_us,void (*Copy_ptrToFunc)(void)){
	Global_Async_Repitition = SINGLE ;
	set_bit(STK->CTRL , 1 ) ;
	STK->LOAD = delay_us / 2 ;
	STK->VAL = 0 ;
	if(Copy_ptrToFunc != 0)
	{
		Global_PtrToFunc = Copy_ptrToFunc ;
	}
	set_bit(STK->CTRL , 0) ;
}
void Systick_Delay_ASync_us_Periodic(u32 delay_us, void(*Copy_ptrToFunc)(void)){
	Global_Async_Repitition = PERIODIC ;
	set_bit(STK->CTRL , 1 ) ;
	STK->LOAD = delay_us / 2 ;
	STK->VAL = 0 ;
	if(Copy_ptrToFunc != 0)
	{
		Global_PtrToFunc = Copy_ptrToFunc ;
	}
	set_bit(STK->CTRL , 0) ;
}
void Systick_handeler(void){
	switch(Global_Async_Repitition)
	{
		case SINGLE :
			Global_PtrToFunc();
			clr_bit(STK->CTRL , 0);
			break ;

		case PERIODIC :
			Global_PtrToFunc();
			break ;
	}
}
u32 Systick_Get_Remaining_Time(void){
	return STK->VAL ;
}
u32 Systick_Get_Elapsed_Time(void){
	return (STK->LOAD - STK->VAL) ;
}
