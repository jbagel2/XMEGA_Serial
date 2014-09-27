XMEGA_Serial
============

Working version of XMEGA Serial with USART0 also using PROGMEM


so the whole thing uses about 6 bytes of memory. The library was writen with the 
128D3 in mind, but thanks to the XMEGA desgn, should work with any other XMEGA.

THe calculations for BSEL, BSCALE, and CLK2X have been done externally so the const values
can be added to progmem to save RAM (saves LOTS of RAM)

Just need to #include the headers (as in XMEGA_Util.c)
and call SerialBegin(BAUD_XXXXX) //XXXXX Being one of the given Speed MACRO's in the ProgMemData.h file

there are two different serial write options:

sendChar(unit8_t);

and

sendString(*uint8_t[]); (String... obviously..)


