/*
 * ProgMemData.h
 *
 * Created: 9/23/2014 7:11:32 PM
 *  Author: jpagel
 */ 


#ifndef PROGMEMDATA_H_
#define PROGMEMDATA_H_

#include <avr/pgmspace.h>
#include <stdint-gcc.h>

typedef struct {
	
	int16_t Scaler;
	int32_t Bsel;
	int16_t DoubleSpeed;
} baud_t;
//

const int32_t baudData[23][3] PROGMEM = 
{
	{3,249,0}, //200
	{1, 1249, 0}, //800
	{-1, 3075, 0}, //1300
	{0, 1249, 0}, //1600
	{0, 999, 0}, //2000
	{-2, 3349, 0}, //2386
	{-2, 2833, 0}, //2820
	{0, 624, 0}, //3200
	{-1, 1103, 0}, //3620
	{-3, 3325, 0}, //4800
	{-4,3317,0}, //9600
	{-5, 3301, 0}, //19200
	{-4, 1095, 0}, //28800
	{-5, 1079, 0}, //57600
	{-7, 2094, 0}, //115200 (115211))
	{-7, 983, 0}, //230400 (230423))
	{-7, 983, 1}, //460800
	{-5, 107, 1}, //920850
	{-6, 214, 1}, //921600
	{0,1,0}, //1000000
	{0,1,1}, //2000000
	{-7,43,1}, //3000000
	{-7, 5, 1} //3849625
		
									
};

#define BAUD_200 ((baud_t){pgm_read_word(&(baudData[0][0])),pgm_read_word_far(&(baudData[0][1])),pgm_read_word(&(baudData[0][2]))})
#define BAUD_800 ((baud_t){pgm_read_word(&(baudData[1][0])),pgm_read_word_far(&(baudData[1][1])),pgm_read_word(&(baudData[1][2]))})
#define BAUD_1300 ((baud_t){pgm_read_word(&(baudData[2][0])),pgm_read_word_far(&(baudData[2][1])),pgm_read_word(&(baudData[2][2]))})
#define BAUD_1600 ((baud_t){pgm_read_word(&(baudData[3][0])),pgm_read_word_far(&(baudData[3][1])),pgm_read_word(&(baudData[3][2]))})
#define BAUD_2000 ((baud_t){pgm_read_word(&(baudData[4][0])),pgm_read_word_far(&(baudData[4][1])),pgm_read_word(&(baudData[4][2]))})
#define BAUD_2386 ((baud_t){pgm_read_word(&(baudData[5][0])),pgm_read_word_far(&(baudData[5][1])),pgm_read_word(&(baudData[5][2]))})
#define BAUD_2820 ((baud_t){pgm_read_word(&(baudData[6][0])),pgm_read_word_far(&(baudData[6][1])),pgm_read_word(&(baudData[6][2]))})
#define BAUD_3200 ((baud_t){pgm_read_word(&(baudData[7][0])),pgm_read_word_far(&(baudData[7][1])),pgm_read_word(&(baudData[7][2]))})
#define BAUD_3620 ((baud_t){pgm_read_word(&(baudData[8][0])),pgm_read_word_far(&(baudData[8][1])),pgm_read_word(&(baudData[8][2]))})
#define BAUD_4800 ((baud_t){pgm_read_word(&(baudData[9][0])),pgm_read_word_far(&(baudData[9][1])),pgm_read_word(&(baudData[9][2]))})
#define BAUD_9600 ((baud_t){pgm_read_word(&(baudData[10][0])),pgm_read_word_far(&(baudData[10][1])),pgm_read_word(&(baudData[10][2]))})
#define BAUD_19200 ((baud_t){pgm_read_word(&(baudData[11][0])),pgm_read_word_far(&(baudData[11][1])),pgm_read_word(&(baudData[11][2]))})
#define BAUD_28800 ((baud_t){pgm_read_word(&(baudData[12][0])),pgm_read_word_far(&(baudData[12][1])),pgm_read_word(&(baudData[12][2]))})
#define BAUD_57600 ((baud_t){pgm_read_word(&(baudData[13][0])),pgm_read_word_far(&(baudData[13][1])),pgm_read_word(&(baudData[13][2]))})
#define BAUD_115200 ((baud_t){pgm_read_word(&(baudData[14][0])),pgm_read_word_far(&(baudData[14][1])),pgm_read_word(&(baudData[14][2]))})
#define BAUD_230400 ((baud_t){pgm_read_word(&(baudData[15][0])),pgm_read_word_far(&(baudData[15][1])),pgm_read_word(&(baudData[15][2]))})
#define BAUD_460800 ((baud_t){pgm_read_word(&(baudData[16][0])),pgm_read_word_far(&(baudData[16][1])),pgm_read_word(&(baudData[16][2]))})
#define BAUD_920850 ((baud_t){pgm_read_word(&(baudData[17][0])),pgm_read_word_far(&(baudData[17][1])),pgm_read_word(&(baudData[17][2]))})
#define BAUD_921600 ((baud_t){pgm_read_word(&(baudData[18][0])),pgm_read_word_far(&(baudData[18][1])),pgm_read_word(&(baudData[18][2]))})
#define BAUD_1000000 ((baud_t){pgm_read_word(&(baudData[19][0])),pgm_read_word_far(&(baudData[19][1])),pgm_read_word(&(baudData[19][2]))})
#define BAUD_2000000 ((baud_t){pgm_read_word(&(baudData[20][0])),pgm_read_word_far(&(baudData[20][1])),pgm_read_word(&(baudData[20][2]))})
#define BAUD_3000000 ((baud_t){pgm_read_word(&(baudData[21][0])),pgm_read_word_far(&(baudData[21][1])),pgm_read_word(&(baudData[21][2]))})
#define BAUD_3849625 ((baud_t){pgm_read_word(&(baudData[22][0])),pgm_read_word_far(&(baudData[22][1])),pgm_read_word(&(baudData[22][2]))})



#define BAUD_3620_RAM ((baud_t) {-1,1103,0}) 


//#define b200 (baud_t PROGMEM {3,249,0})
//#define b800 baud_t  PROGMEM = {1, 1249, 0}
//#define b1300 baud_t  PROGMEM {-1, 3075, 0}
//#define b1600 baud_t  PROGMEM {0, 1249, 0}
//#define b2000 baud_t  PROGMEM {0, 999, 0}
//#define b2386 baud_t  PROGMEM {-2, 3349, 0}
//#define b2820 baud_t  PROGMEM {-2, 2833, 0}
//#define b3200 baud_t  PROGMEM {0, 624, 0}
//#define b3620 baud_t  PROGMEM {-1, 1103, 0}


//Pupts a string directly into PROGMEM for using at the same time as declaring ie (Serial.print(F("Test String"));
#define F(string_literal) (reinterpret_cast<const __FlashStringHelper *>(PSTR(string_literal)))



void buildTable()
{
	


	//First number is BSCALE, second is BSEL, Third CLK2X
	//static const baud_t b200 PROGMEM = {3,249,0};
	//static const baud_t b800 PROGMEM = {1, 1249, 0};
	//static const baud_t b1300 PROGMEM ={-1, 3075, 0};
	//static const baud_t b1600 PROGMEM ={0, 1249, 0};
	//static const baud_t b2000 PROGMEM ={0, 999, 0};
	//static const baud_t b2386 PROGMEM ={-2, 3349, 0};
	//static const baud_t b2820 PROGMEM ={-2, 2833, 0};
	//static const baud_t b3200 PROGMEM ={0, 624, 0};
	//static const baud_t b3620 PROGMEM ={-1, 1103, 0};


	//typedef struct BaudTable{
		//
		//baud_t B200;
		//baud_t B800;
		//
		//}BaudTable;
	
	
	
	//BaudRateDataTable dataTable PROGMEM = {b200,b800};
	
	//BaudRateDataTable(B200) = b200;
	
	//static const baud_t thisTable[]  PROGMEM= {
		//(baud_t)b200,
		//(baud_t)b800,
		//(baud_t)b1300,
		//(baud_t)b1600,
		//(baud_t)b2000,
		//(baud_t)b2386,
		//(baud_t)b2820,
		//(baud_t)b3200,
		//(baud_t)b3620			
	//};
}




//thisTable.B200 = b200;


//const baud_t baudRateDataTable[] PROGMEM= {
	//b200;		//200
	//b800; //800
	//{&b1300}, //1300
	//{&b1600},	//1600
	//{&b2000},	//2000
	//{&b2386},	//2386
	//{&b2820},	//2820
	//{&b3200},	//3200
	//{&b3620}	//3620
	////Need to continue calculations for higher speeds
//};


//#define B200 BaudCalcs{3, 1249, 0}
//#define B800 BaudCalcs{1, 1249, 0}
//#define B1300 BaudCalcs{-1, 3075, 0}
//#define B1600 BaudCalcs{0, 1249, 0}
//#define B2000 BaudCalcs{0, 999, 0}}
//#define B2386 BaudCalcs{-2, 3349, 0}
//#define B2820 BaudCalcs{-2, 2833, 0}
//#define B3200 BaudCalcs{0, 624, 0}
//#define B3620 BaudCalcs{-1, 1103, 0}


//struct BaudCalcs bauds [10];






#endif /* PROGMEMDATA_H_ */