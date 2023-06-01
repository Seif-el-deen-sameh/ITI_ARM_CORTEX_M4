#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/Systick/Systick_interface.h"
#include "LIB/song.h"
void main(void){
	RCC_set_system_clock(HSE_CRYSTAL);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOA);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOB);
	RCC_enable_preihreal_clock(RCC_AHB1,RCC_GPIOC);
	GPIO_Init_Pin_Output(GPIO_PORTA,0,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,1,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,2,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,3,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,4,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,5,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,6,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	GPIO_Init_Pin_Output(GPIO_PORTA,7,GPIO_PUSH_PULL,GPIO_SPEED_LOW);
	Systick_init();
	/*GPIO_Init_Pin_Output(GPIO_PORTA,0,GPIO_PUSH_PULL,GPIO_SPEED_LOW);*/
	while(1){

		/*GPIO_Set_Pin_Value(GPIO_PORTA,0,GPIO_OUTPUT_HIGH);
		Systick_Delay_Sync_us(10000);
		GPIO_Set_Pin_Value(GPIO_PORTA,0,GPIO_OUTPUT_LOW);
		Systick_Delay_Sync_us(10000);*/
	}
}
