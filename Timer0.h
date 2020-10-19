/*
 * Timer0.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Tamer_Zedan
 */

#include "common_macros.h"

#include "std_types.h"

#include "micro_config.h"

#include <avr/io.h>

#include <avr/interrupt.h>

#ifndef TIMER0_H_
#define TIMER0_H_

#define NULL ((void*)(0))

typedef enum{
	No_clock,F_CPU_CLK,clk_8,clk_64,clk_256,clk_1024,External_clock_Falling,External_clock_Rising
}Clock_Select;


typedef struct{
	Clock_Select clk;
	uint8 Duty_Cycle;
}Timer0_ConfigType;

void Timer0_init_PWM_Mode(Timer0_ConfigType *Timer0_config);

void Timer0_init_Normal_Mode(Timer0_ConfigType *Timer0_config);

void Timer0_init_Comp_Mode(Timer0_ConfigType *Timer0_config);

void Set_Duty_Cycle(uint8 Duty);

#endif /* TIMER0_H_ */
