/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
void GPIO_Init_Pin_Output(u8 port_id,u8 pin_id,u8 pin_mode,u8 pin_speed);
void GPIO_Init_Pin_Input (u8 port_id,u8 pin_id,u8 pin_mode);
void GPIO_Set_Pin_Value	 (u8 port_id,u8 pin_id,u8 pin_value);
u8 GPIO_Get_Pin_Value 	 (u8 port_id,u8 pin_id);
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
