#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
void main(void){
	RCC_set_system_clock(HSE_CRYSTAL);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOA);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOB);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOC);
	GPIO_Init_Pin_Output(GPIO_PORTA,0,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Set_Pin_Value(GPIO_PORTA,0,GPIO_OUTPUT_HIGH);
	while(1){

	}
}
