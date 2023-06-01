/*
 * led_mat_interface.h
 *
 *  Created on: May 29, 2023
 *      Author: ss210
 */

#ifndef HAL_LED_MATRIX_LED_MAT_INTERFACE_H_
#define HAL_LED_MATRIX_LED_MAT_INTERFACE_H_

void LED_MATRIX_Init(void);
void LED_MATRIX_Display_Pattern(u8 Pattern_Array[], u32 Time_ms);
void LED_MATRIX_Turn_Off(void);

#endif /* HAL_LED_MATRIX_LED_MAT_INTERFACE_H_ */
