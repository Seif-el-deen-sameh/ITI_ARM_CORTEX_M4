/*
 * NVIC_private.h
 *
 *  Created on: May 22, 2023
 *      Author: ss210
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

typedef struct
{
	volatile u32 ISER[8];		// Interrupt Set Enable Registers. Used to enable specific interrupts.
	volatile u32 RESERVED1[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ICER[8];       // Interrupt Clear Enable Registers. Used to disable specific interrupts.
	volatile u32 RESERVED2[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ISPR[8];       // Interrupt Set Pending Registers. Used to Fire interrupts Instantly for Testing Purposes.
	volatile u32 RESERVED3[24]; // 24 32-bit registers reserved for future use.
	volatile u32 ICPR[8];       // Interrupt Clear Pending Registers. Used to clear interrupts Instantly for Testing Purposes.
	volatile u32 RESERVED4[24]; // 24 32-bit registers reserved for future use.
	volatile u32 IABR[8];       // Interrupt Active Bit Registers. Used to read the active status of specific interrupts.
	volatile u32 RESERVED5[56]; // 56 32-bit registers reserved for future use.
	volatile u8 IPR[240];       /* Interrupt Priority Registers. Used to set the priority level of specific interrupts.
								 * this 240 Array of u8 is instead Array of 8 u32 as Each U8
								 * Is used to Control a Specific Interrupt */
}NVIC_t;


#define GROUP_4_SUB_0	3	// Support 16 Groups and 0 Subs (Nesting Level Up to 16)
#define GROUP_3_SUB_1	4	// Support  8 Groups and 2 Subs
#define GROUP_2_SUB_2	5	// Support  4 Groups and 4 Subs
#define GROUP_1_SUB_3	6	// Support  2 Groups and 8 Subs
#define GROUP_0_SUB_4	7	// Support  0 Groups and 16 Subs (No Nesting Supported)

#define VECT_KEY (0x05FA0000)
#define NVIC_START	(0xE000E100)
#define NVIC	((volatile NVIC_t*)(NVIC_START))
#define SCB_AIRCR  (*(volatile u32*)(0xE000ED0C))
#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
