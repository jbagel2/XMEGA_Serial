/*
 * XMEGA_USART0.h
 *
 * Created: 9/19/2014 11:57:03 PM
 *  Author: jpagel
 */ 



#ifndef XMEGA_USART0_H_
#define XMEGA_USART0_H_

#include "ProgMemData.h"
#include <stdint-gcc.h>

//void configureSerial2M();
//void configureSerial920K();
void sendChar(char c);
void sendString(char *text);
char usart_receiveByte();
void SerialBegin(baud_t baud);





//
//void configureSerial2M()
//{
	//uint16_t bsel = 128;
	////USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm;
	//USARTC0_BAUDCTRLB = USARTC0.BAUDCTRLB = 0| (bsel >> 8) | (-7 << USART_BSCALE0_bp);
	////USARTC0_BAUDCTRLA = 3317; // 207
	//USARTC0_BAUDCTRLA = bsel;
	//
	////Disable interrupts, just for safety
	//USARTC0_CTRLA = 0;
	////8 data bits, no parity and 1 stop bit
	//USARTC0_CTRLC = USART_CHSIZE_8BIT_gc;
	//
	////Enable receive and transmit
	//USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm | USART_CLK2X_bm;; //  Enable TX, RX, Enable 2X_CLK Mode
	//
//}
//
//void configureSerial920K()
//{
	//
	//uint16_t bsel = 150;
	////USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm; //
	//USARTC0_BAUDCTRLB = USARTC0.BAUDCTRLB = 0| (bsel >> 8) | (-7 << USART_BSCALE0_bp);
	//USARTC0_BAUDCTRLA = bsel;
	//
	////Disable interrupts, just for safety
	//USARTC0_CTRLA = 0;
	////8 data bits, no parity and 1 stop bit
	//USARTC0_CTRLC = USART_CHSIZE_8BIT_gc;
	//
	////Enable receive and transmit
	//USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm | ~USART_CLK2X_bm; // Enable TX, RX, Remove 2X_CLK Mode
	//
//}

void sendChar(char c)
{
	
	while( !(USARTC0_STATUS & USART_DREIF_bm) ); //Wait until DATA buffer is empty
	
	USARTC0_DATA = c;
	
}

void sendString(char *text)
{
	while(*text)
	{
		sendChar(*text++);
	}
}

char usart_receiveByte() //Blocking
{
	while( !(USARTC0_STATUS & USART_RXCIF_bm) ); //Interesting DRIF didn't work.
	return USARTC0_DATA;
}

void SerialBegin(baud_t baud)
{
	//baud_t temp = baud;
	
	int16_t scaler = baud.Scaler;
	int32_t bsel = baud.Bsel;
	int16_t doubleSpeed = baud.DoubleSpeed;
	
	USARTC0_BAUDCTRLB = USARTC0.BAUDCTRLB = 0| (bsel >> 8) | (scaler << USART_BSCALE0_bp);
	USARTC0_BAUDCTRLA = bsel;
	
	//Disable interrupts, just for safety
	USARTC0_CTRLA = 0;
	//8 data bits, no parity and 1 stop bit
	USARTC0_CTRLC = USART_CHSIZE_8BIT_gc;
	
	//Enable receive and transmit
	
	if(doubleSpeed)
	{
		USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm | USART_CLK2X_bm;
	}
	else
	{
		USARTC0_CTRLB = USART_TXEN_bm | USART_RXEN_bm | ~USART_CLK2X_bm;	
	}


}


#endif /* XMEGA_USART0_H_ */