/*
 * led_mat_program.c
 *
 *  Created on: May 29, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/Systick/Systick_interface.h"
#include "led_mat_config.h"
#include "led_mat_interface.h"
#include "led_mat_private.h"
u8 Local_u8RowsArray[ROW_NUM] = {ROW0,ROW1,ROW2,ROW3,ROW4,ROW5,ROW6,ROW7};
u8 Local_u8ColsArray[COL_NUM] = {COL0,COL1,COL2,COL3,COL4,COL5,COL6,COL7};
void LED_MATRIX_Init(void){

}
void LED_MATRIX_Display_Pattern(u8 Pattern_Array[], u32 Time_ms){

}
void LED_MATRIX_Turn_Off(void){

}

