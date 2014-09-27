/*
 * XMEGA_CLKSET.h
 *
 * Created: 9/19/2014 11:57:23 PM
 *  Author: jpagel
 */ 


#ifndef XMEGA_CLKSET_H_
#define XMEGA_CLKSET_H_


void set32MhzClock();

void set32MhzClock_Calibrated();



#include <avr/io.h>

void set32MhzClock()
{
	//OSC.CTRL |= OSC_RC32KEN_bm;
	//while ((OSC.STATUS & OSC_RC32KRDY_bm)==0);



	OSC.CTRL |= OSC_RC32MEN_bm ; /* start 32MHz RC oscillator */


	while (!(OSC.STATUS & OSC_RC32MRDY_bm)); /* wait for ready */

	OSC.DFLLCTRL = 0x02;
	//DFLLRC32M.CTRL = DFLL_ENABLE_bm;

	CCP = 0xd8; /* allow changing CLK.CTRL */
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc; /* system clock is internal 32MHz RC */
	CLK.RTCCTRL = 0x01;
}

void set32MhzClockCalib()
{
	unsigned char n,s;
	
	//CLK.RTCCTRL |= OSC
	
	s=SREG;
	
	// Internal 32 kHz RC oscillator initialization
	// Enable the internal 32 kHz RC oscillator
	OSC.CTRL|=OSC_RC32KEN_bm;
	
	// Wait for the internal 32 kHz RC oscillator to stabilize
	while ((OSC.STATUS & OSC_RC32KRDY_bm)==0);
	
	// Oscillator calibration not enabled yet
	DFLLRC32M.CTRL=0<<DFLL_ENABLE_bp;
	
	// Enable the internal 32 MHz RC oscillator
	OSC.CTRL|=OSC_RC32MEN_bm;
	
	// Wait for the internal 32 MHz RC oscillator to stabilize
	while ((OSC.STATUS & OSC_RC32MRDY_bm)==0);
	
	// Use the Internal 32kHz RC oscillator as DFLL clock reference
	OSC.DFLLCTRL = OSC_RC32MCREF_bm;
	
	// Enable the auto-calibration of the internal 32 MHz RC oscillator
	DFLLRC32M.CTRL=1<<DFLL_ENABLE_bp;
	
	n=(CLK.PSCTRL & (~(CLK_PSADIV_gm | CLK_PSBCDIV1_bm | CLK_PSBCDIV0_bm))) |
	CLK_PSADIV_1_gc | CLK_PSBCDIV_1_1_gc;
	CCP=CCP_IOREG_gc;
	CLK.PSCTRL=n;
	
	
	CLK.CTRL = CLK_SCLKSEL_RC32M_gc;
	
	//// Select the system clock source: 32 MHz Internal RC Osc.
	//n=(CLK.CTRL & (~CLK_SCLKSEL_gm)) | CLK_SCLKSEL_RC32M_gc;
	//CCP=CCP_IOREG_gc;
	//CLK.CTRL=n;
	
	// Disable the unused oscillators: 2 MHz, external clock/crystal oscillator, PLL
	OSC.CTRL&= ~(OSC_RC2MEN_bm | OSC_XOSCEN_bm | OSC_PLLEN_bm);
	
	SREG=s;
	
}



#endif /* XMEGA_CLKSET_H_ */