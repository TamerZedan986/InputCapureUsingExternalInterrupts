/*
 * timer.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Tamer_Zedan
 */

#include "Timer0.h"

static  void (*g_callBackPtr)(void) = NULL;


ISR(TIMER0_OVF_vect){
		if(g_callBackPtr!=NULL){
			(*g_callBackPtr)();
		}
}

ISR(TIMER0_COMP_vect){
		if(g_callBackPtr!=NULL){
			(*g_callBackPtr)();
		}
}

void Timer0_init_PWM_Mode(Timer0_ConfigType *Timer0_config){
	TCNT0=0;
	OCR0=Timer0_config->Duty_Cycle;
	DDRB  = DDRB | (1<<PB3);
	TCCR0 = (1<<WGM00) | (1<<WGM01)|(1<<COM01) | (Timer0_config->clk);
}

void Timer0_init_Normal_Mode(Timer0_ConfigType *Timer0_config){
	TCNT0=0;
	TCCR0 |=(1<<FOC0)|(Timer0_config->clk);
	TIMSK|=(1<<TOIE0);
}

void Timer0_init_Comp_Mode(Timer0_ConfigType *Timer0_config){
	TCNT0=0;
	TCCR0 |=(1<<FOC0)|(Timer0_config->clk)|(1<<COM01);
	TIMSK|=(1<<OCIE0);
}
void Set_Duty_Cycle(uint8 Duty){
	OCR0=Duty;
}
