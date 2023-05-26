/*
 * GPIO_interface.h
 *
 *  Created on: May 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
/*turn to enums*/
#define GPIO_PORTA	1
#define GPIO_PORTB	2
#define GPIO_PORTC	3
/*turn to enums*/
#define GPIO_PUSH_PULL	0
#define GPIO_OPEN_DRAIN	1
/*turn to enums*/
#define GPIO_SPEED_LOW			1
#define GPIO_SPEED_MED			2
#define GPIO_SPEED_HIGH			3
#define GPIO_SPEED_VERY_HIGH	4
/*turn to enums*/
#define GPIO_OUTPUT_HIGH	1
#define GPIO_OUTPUT_LOW		0
/*turn to enums*/
#define GPIO_INPUT_NONE		0
#define GPIO_INPUT_PULLUP	1
#define GPIO_INPUT_PULLDOWN	2
/*turn to enums*/
#define GPIO_AF0   0000
#define GPIO_AF1   0001
#define GPIO_AF2   0010
#define GPIO_AF3   0011
#define GPIO_AF4   0100
#define GPIO_AF5   0101
#define GPIO_AF6   0110
#define GPIO_AF7   0111
#define GPIO_AF8   1000
#define GPIO_AF9   1001
#define GPIO_AF10  1010
#define GPIO_AF11  1011
#define GPIO_AF12  1100
#define GPIO_AF13  1101
#define GPIO_AF14  1110
#define GPIO_AF15  1111
/*turn to enums*/
#define GPIO_PIN_A0 	0
#define GPIO_PIN_A1 	1
#define GPIO_PIN_A2 	2
#define GPIO_PIN_A3 	3
#define GPIO_PIN_A4 	4
#define GPIO_PIN_A5 	5
#define GPIO_PIN_A6 	6
#define GPIO_PIN_A7 	7
#define GPIO_PIN_A8 	8
#define GPIO_PIN_A9 	9
#define GPIO_PIN_A10	10
#define GPIO_PIN_A11	11
#define GPIO_PIN_A12	12
//#define GPIO_PIN_A13	13
//#define GPIO_PIN_A14	14
//#define GPIO_PIN_A15	15

/*  Port B  */
#define GPIO_PIN_B0 	16
#define GPIO_PIN_B1 	17
//#define GPIO_PIN_B2 	18
//#define GPIO_PIN_B3 	19
//#define GPIO_PIN_B4 	20
#define GPIO_PIN_B5 	21
#define GPIO_PIN_B6 	22
#define GPIO_PIN_B7 	23
#define GPIO_PIN_B8 	24
#define GPIO_PIN_B9 	25
#define GPIO_PIN_B10	26
#define GPIO_PIN_B11	27
#define GPIO_PIN_B12	28
#define GPIO_PIN_B13	29
#define GPIO_PIN_B14	30
#define GPIO_PIN_B15	31

/*  Port C  */
//#define GPIO_PIN_C0 	32
//#define GPIO_PIN_C1 	33
//#define GPIO_PIN_C2 	34
//#define GPIO_PIN_C3 	35
//#define GPIO_PIN_C4 	36
//#define GPIO_PIN_C5 	37
//#define GPIO_PIN_C6 	38
//#define GPIO_PIN_C7 	39
//#define GPIO_PIN_C8 	40
//#define GPIO_PIN_C9 	41
//#define GPIO_PIN_C10	42
//#define GPIO_PIN_C11	43
//#define GPIO_PIN_C12	44
#define GPIO_PIN_C13	45
#define GPIO_PIN_C14	46
#define GPIO_PIN_C15	47
/*turn to enums*/
void GPIO_Init_Pin_Output(u8 port_id,u8 pin_id,u8 pin_type,u8 pin_speed);
void GPIO_Init_Pin_Input(u8 port_id,u8 pin_id,u8 pin_mode);
void GPIO_Set_Pin_Value(u8 port_id,u8 pin_id,u8 pin_value);
u8 GPIO_Get_Pin_Value(u8 port_id,u8 pin_id);
void GPIO_Set_Pin_Alt_Function(u8 port_id,u8 pin_id,u8 alt_function);
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
