/*
 * timer1.h
 *
 *  Created on: Jan 9, 2020
 *      Author: Tamer_Zedan
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "common_macros.h"

#include "std_types.h"

#include "micro_config.h"

#include <avr/io.h>

#include <avr/interrupt.h>

#define NULL ((void*)(0))

typedef enum{
	No_clock,F_CPU_CLK,clk_8,clk_64,clk_256,clk_1024,External_clock_Falling,External_clock_Rising
}Clock_Select;


typedef struct{
	Clock_Select clk;
	uint16 Duty_Cycle;
}Timer1_ConfigType;

void Timer1_init_PWM_ModeA(Timer1_ConfigType *Timer1_config);
void Timer1_init_Normal_Mode(Timer1_ConfigType *Timer1_config);

/*void Timer1_init_Comp_Mode(Timer0_ConfigType *Timer0_config);

void Set_Timer1_Duty_Cycle(uint8 Duty);*/

#endif /* TIMER1_H_ */
