/*
 * EXTI_interface.h
 *
 *  Created on: May 28, 2023
 *      Author: ss210
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

void EXTI_Enable_Int(u8 Int_ID , void(*Copy_ptrToFunc)(void));
void EXTI_Disable_Int(u8 Int_ID);
void EXTI_Set_Sense_Signal(u8 Sense_Signal , u8 Int_ID);
void EXTI_Set_Line_Port(u8 Int_ID , u8 Port_ID);
static void EXTI_Clear_Pending_Flag(u8 Int_ID);
void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
