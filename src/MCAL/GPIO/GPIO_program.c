/*
 * GPIO_program.c
 *
 *  Created on: May 11, 2023
 *      Author: ss210
 */
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
void GPIO_Init_Pin_Output(u8 port_id,u8 pin_id,u8 pin_type,u8 pin_speed){
	switch(port_id)
		{
				case GPIO_PORTA:
					// PIN MODE BY MASKING
				GPIOA->MODER   &=~(0b11<<(pin_id*2));
				GPIOA->MODER   |=(0b01<<(pin_id*2));
					//PIN SPEED BY MASKING
				GPIOA->OSPEEDR &=~(0b11<<(pin_id*2));
				GPIOA->OSPEEDR |=(pin_speed<<(pin_id*2));
					// PIN TYPE
				wrt_bit(GPIOA->OTYPER,pin_id,pin_type);
				break;
				case GPIO_PORTB:
				GPIOB->MODER   &=~(0b11<<(pin_id*2));
				GPIOB->MODER   |=(0b01<<(pin_id*2));
				GPIOB->OSPEEDR &=~(0b11<<(pin_id*2));
				GPIOB->OSPEEDR |=(pin_speed<<(pin_id*2));
				wrt_bit(GPIOB->OTYPER,pin_id,pin_type);
				break;
				case GPIO_PORTC:
				GPIOC->MODER   &=~(0b11<<(pin_id*2));
				GPIOC->MODER   |=(0b01<<(pin_id*2));
				GPIOC->OSPEEDR &=~(0b11<<(pin_id*2));
				GPIOC->OSPEEDR |=(pin_speed<<(pin_id*2));
				wrt_bit(GPIOC->OTYPER,pin_id,pin_type);
				break;
			}
		}
void GPIO_Init_Pin_Input (u8 port_id,u8 pin_id,u8 pin_mode){
	switch(port_id)
			{
					case GPIO_PORTA:
					GPIOA->MODER   &=~(0b11<<(pin_id*2));
						//PIN SPEED BY MASKING
					GPIOA->PUPDR &=~(0b11<<(pin_id*2));
					GPIOA->PUPDR |=(pin_mode<<(pin_id*2));
					break;
					case GPIO_PORTB:
						GPIOB->MODER   &=~(0b11<<(pin_id*2));
							//PIN SPEED BY MASKING
						GPIOB->PUPDR &=~(0b11<<(pin_id*2));
						GPIOB->PUPDR |=(pin_mode<<(pin_id*2));
					break;
					case GPIO_PORTC:
						GPIOC->MODER   &=~(0b11<<(pin_id*2));
							//PIN SPEED BY MASKING
						GPIOC->PUPDR &=~(0b11<<(pin_id*2));
						GPIOC->PUPDR |=(pin_mode<<(pin_id*2));
					break;
				}
			}
void GPIO_Set_Pin_Value	 (u8 port_id,u8 pin_id,u8 pin_value){
	switch(port_id)
			{
					case GPIO_PORTA:
						wrt_bit(GPIOA->ODR,pin_id,pin_value);
					break;
					case GPIO_PORTB:
						wrt_bit(GPIOB->ODR,pin_id,pin_value);
					break;
					case GPIO_PORTC:
						wrt_bit(GPIOC->ODR,pin_id,pin_value);
					break;
				}
			}
u8 GPIO_Get_Pin_Value(u8 port_id,u8 pin_id){
	u8 val = 0;
	switch(port_id)
			{
					case GPIO_PORTA:
						val = get_bit(GPIOA->IDR, pin_id);
					break;
					case GPIO_PORTB:
						val = get_bit(GPIOA->IDR, pin_id);
					break;
					case GPIO_PORTC:
						val = get_bit(GPIOA->IDR, pin_id);
					break;
				}
	return val;
			}
void GPIO_Set_Pin_Alt_Function(u8 port_id,u8 pin_id,u8 alt_function){
	switch(port_id)
				{
						case GPIO_PORTA:
							if(pin_id == 13 || pin_id == 14 || pin_id == 15)
												{
													/*Do Nothing*/
												}
												else
												{
													if (pin_id>=0 && pin_id<=7) //Check if the Pin in AFRL OR AFRH
													{
														/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
														GPIOA->AFRL &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
														GPIOA->AFRL |= (alt_function << (pin_id*4));	//Set AF as Configured
													}
													else
													{
														/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
														GPIOA->AFRH &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
														GPIOA->AFRH |= (alt_function << (pin_id*4));	//Set AF as Configured
													}
												}
						break;
						case GPIO_PORTB:
							if(pin_id == 2 || pin_id == 3 || pin_id == 4)
												{
													/*Do Nothing*/
												}
												else
												{
													if (pin_id>=0 && pin_id<=7) //Check if the Pin in AFRL OR AFRH
													{
														/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
														GPIOB->AFRL &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
														GPIOB->AFRL |= (alt_function << (pin_id*4));	//Set AF as Configured
													}
													else
													{
														/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
														GPIOB->AFRH &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
														GPIOB->AFRH |= (alt_function << (pin_id*4));	//Set AF as Configured
													}
												}
						break;
						case GPIO_PORTC:
							if (pin_id>=0 && pin_id<=7) //Check if the Pin in AFRL OR AFRH
											{
												/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
												GPIOC->AFRL &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
												GPIOC->AFRL |= (alt_function << (pin_id*4));	//Set AF as Configured
											}
											else
											{
												/*Set Configuration of Pin to the Desired Alternative Function using (Bit Masking)*/
												GPIOC->AFRH &= (~(0b1111 << (pin_id*4))); 					//Clear the 4 Bits Responsible for Configuration
												GPIOC->AFRH |= (alt_function << (pin_id*4));	//Set AF as Configured
											}
						break;
					}
				}

