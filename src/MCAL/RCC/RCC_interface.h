
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB1	1
#define RCC_AHB2	2
#define RCC_APB1	3
#define RCC_APB2	4

#define RCC_AHB1	1

void RCC_enable_preihreal_clock(u8 bus_id,u8 peripheral_id);
void RCC_disable_preihreal_clock(u8 bus_id,u8 peripheral_id);
void RCC_set_system_clock(void);

#endif
