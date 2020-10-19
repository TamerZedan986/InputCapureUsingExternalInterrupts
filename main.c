/*
 * main.c
 *
 *  Created on: Jan 9, 2020
 *      Author: Tamer_Zedan
 */

#include "timer1.h"

#include "external_interrupts.h"

#include "LCD.h"

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

void APP_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount==1){
		TCNT1=0;
		INT1_Set_Edge(Falling_Edge);
	}else if(g_edgeCount==2){
		g_timeHigh=TCNT1;
		INT1_Set_Edge(Rising_Edge);
	}else if(g_edgeCount==3){
		g_timePeriod=TCNT1;
		INT1_Set_Edge(Falling_Edge);
	}else if(g_edgeCount==4){
		g_timePeriodPlusHigh=TCNT1;
		INT1_Set_Edge(Rising_Edge);
	}
}

int main()
{
	SREG |= (1<<7);
	LCD_init();
	uint32 dutyCycle = 0;
	External_Interrupt_ConfigType INT_Config={Rising_Edge,Int1};
	Timer1_ConfigType Timer_Config={F_CPU_CLK};
	Timer1_init_Normal_Mode(&Timer_Config);
	INT1_init(&INT_Config);
	INT_Set_callback(APP_edgeProcessing);
	while(1)
	{
		if(g_edgeCount == 4)
		{
			INT_Deinit();
			g_edgeCount = 0;
			LCD_displayString("Duty = ");
			/* calculate the dutyCycle */
			dutyCycle = ((float)(g_timePeriodPlusHigh - g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;
			/* display the dutyCycle on LCD screen */
			LCD_intgerToString(dutyCycle);
			LCD_displayCharacter('%');
		}
	}
}
