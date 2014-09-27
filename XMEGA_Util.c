/*
 * XMEGA_Util.c
 *
 * Created: 9/19/2014 10:43:49 PM
 *  Author: jpagel
 */ 


#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define F_CPU 32000000

#include <XMEGA_CLKSET.h>
#include <XMEGA_USART0.h>
#include <XMEGA_ANALOG.h>
#include "ProgMemData.h"
//#include <xmega_Freq_Set.h>
//#include <xmega_Serial_USART0.h>

int main(void)
{
	//char buffer[10];
	
	set32MhzClock();  
	SerialBegin(BAUD_460800);
	
		PORTA.DIRSET &= ~(1<<3) | (1<<4);
		PORTB.DIRSET = PIN7_bm;
		PORTC.DIRSET |= (1<<3) | (1<<0);
		PORTC.DIRSET &= ~(1<<2);
	
	for(;;)
	{
		
		sendString("test");
		PORTB.OUTTGL = PIN7_bm;
		_delay_ms(100);
		
		
	}
	
}