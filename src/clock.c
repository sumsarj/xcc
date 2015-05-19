//void clock_inter_asm(void);
#ifndef port
#include "ports.h"
#define port
#endif
#include "clock.h"
static time_type counter;

void init_clock(){
	// sätt avbrottsintervall
	RTICTL = 0x20;
	// aktiver crg
	CRGINT = 0x80; // set MSb
	//nollställ counter
	counter = 0;
	//init avbrottsvektor, clock_inter_asm är assembler turin
	IRQ_VEC = (unsigned short)clock_inter_asm;
	//tillåt avbrott
	myCLI();
}

void clock_inter(){ //avbrottsrutin i C
	counter++;
	//kvittera avbrott
	CRGFLG = 0x80;
}
time_type get_time(){
	return counter;
}
void hold(){
	/*unsigned int asd = 0xDF;
	while(asd){
		asd--;
	}*/
	unsigned long int counterCompare;
	counterCompare = counter;
	while((counterCompare + 2) != counter){
	}
	
}
