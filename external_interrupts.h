/*
 * external_interrupts.h
 *
 *  Created on: Jan 6, 2020
 *      Author: Tamer_Zedan
 */

#ifndef EXTERNAL_INTERRUPTS_H_
#define EXTERNAL_INTERRUPTS_H_

#include "std_types.h"

#include<avr/io.h>

#include<avr/interrupt.h>

#define NULL ((void*)(0))

typedef enum{
Low_level=0,Any_Logical_Change,Falling_Edge,Rising_Edge
}Interrupt_Sense_Control;

typedef enum{
	Int2=5,Int0=6,Int1=7
}Interrupt_select;

typedef struct{
	Interrupt_Sense_Control I_Sen;
	Interrupt_select I_Sel;
}External_Interrupt_ConfigType;

void INT1_init(External_Interrupt_ConfigType *Int_config);

void INT0_init(External_Interrupt_ConfigType *Int_config);

void INT_Set_callback(void (*a_ptr)(void));

void INT1_Set_Edge(Interrupt_Sense_Control INT_Sense);

void INT0_Set_Edge(Interrupt_Sense_Control INT_Sense);

void INT_Deinit(void);

#endif /* EXTERNAL_INTERRUPTS_H_ */
