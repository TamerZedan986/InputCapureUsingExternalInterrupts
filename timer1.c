/*
 * timer1.c
 *
 *  Created on: Jan 9, 2020
 *      Author: Tamer_Zedan
 */

#include "timer1.h"

static  void (*g_timer1_callBackPtr)(void) = NULL;


ISR(TIMER1_OVF_vect){
	if(g_timer1_callBackPtr!=NULL){
		(*g_timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect){
	if(g_timer1_callBackPtr!=NULL){
		(*g_timer1_callBackPtr)();
	}
}

void Timer1_init_PWM_ModeA(Timer1_ConfigType *Timer1_config){
	TCNT1=0;
	OCR1A=Timer1_config->Duty_Cycle;
	DDRB  = DDRB | (1<<PB3);
	TCCR1A |= (1<<WGM10) | (1<<WGM11)|(1<<COM1A0)|(1<<COM1A1);
	TCCR1B|=(1<<WGM12)|(1<<WGM13)| (Timer1_config->clk);
}

void Timer1_init_Normal_Mode(Timer1_ConfigType *Timer1_config){
	TCNT1=0;
	TCCR1A |=(1<<FOC1A)|(1<<FOC1B);
	TCCR1B|=(Timer1_config->clk);
	/*TIMSK|=(1<<TOIE1);*/
}

/*void Timer0_init_Comp_Mode(Timer0_ConfigType *Timer0_config){
	TCNT0=0;
	TCCR0 |=(1<<FOC0)|(Timer0_config->clk)|(1<<COM01);
	TIMSK|=(1<<OCIE0);
}
void Set_Duty_Cycle(uint8 Duty){
	OCR0=Duty;
}*/
