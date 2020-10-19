/*
 * external_interrupt.c
 *
 *  Created on: Jan 6, 2020
 *      Author: Tamer_Zedan
 */

#include "external_interrupts.h"

static  void (*I_callBackPtr)(void) = NULL;

ISR(INT0_vect)
{
	if(I_callBackPtr!=NULL){
			(*I_callBackPtr)();
		}
}

ISR(INT1_vect)
{
	if(I_callBackPtr!=NULL){
			(*I_callBackPtr)();
		}
}

void INT0_init(External_Interrupt_ConfigType *Int_config)
{
	DDRD&=~(1<<PD3);
	MCUCR=(MCUCR&0xf8)|Int_config->I_Sen;
	GICR|=(1<<Int_config->I_Sel);
}

void INT1_init(External_Interrupt_ConfigType *Int_config)
{
	DDRD&=~(1<<PD2);
	MCUCR=(MCUCR&0xf8)|(Int_config->I_Sen<<2);
	GICR|=(1<<Int_config->I_Sel);
}

void INT_Set_callback(void (*a_ptr)(void))
{
	I_callBackPtr=a_ptr;
}

void INT0_Set_Edge(Interrupt_Sense_Control INT_Sense){
	MCUCR=(MCUCR&0xf8)|INT_Sense;
}

void INT1_Set_Edge(Interrupt_Sense_Control INT_Sense){
	MCUCR=(MCUCR&0xf8)|(INT_Sense<<2);
}

void INT_Deinit(void){
	GICR=0;
}
