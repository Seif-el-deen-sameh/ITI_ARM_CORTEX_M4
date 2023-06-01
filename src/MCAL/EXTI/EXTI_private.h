/*
 * EXTI_private.h
 *
 *  Created on: May 28, 2023
 *      Author: ss210
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESS (0x40013C00)
#define SYSCFG_BASE_ADDRESS (0x40013800)

/* 16 Macros For EXTI Lines */
#define EXTI_LINE0           0
#define EXTI_LINE1           1
#define EXTI_LINE2           2
#define EXTI_LINE3           3
#define EXTI_LINE4           4
#define EXTI_LINE5           5
#define EXTI_LINE6           6
#define EXTI_LINE7           7


/* Macros For Sense Signals */
#define FALLING_EDGE	1
#define RISING_EDGE		2
#define ON_CHANGE		3

typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_REG_t;

typedef struct
{
	u32 MEMRMP ;
	u32 PMC ;
	u32 EXTICR[4] ;
}SYSCFG_REG_t;
#define EXTI        ((volatile EXTI_REG_t *)EXTI_BASE_ADDRESS)
#define SYSCFG 		((volatile SYSCFG_REG_t *)(SYSCFG_BASE_ADDRESS))


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
