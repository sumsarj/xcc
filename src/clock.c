//void clock_inter_asm(void);
#ifndef port
#include "ports.h"
#define port
#endif
#include "clock.h"
time_type counter;

void init_clock(){
	// sätt avbrottsintervall
	RTICTL = 0x1;
	
	// aktiver crg
	CRGINT |= 0x80; // set MSb
	
	counter = 0;
	
	IRQ_VEC = *((vecptr)*clock_inter_asm);
	
	myCLI();

}

void clock_inter(){
	counter++;
	CRGFLG |= 0x80;
}
time_type get_time(){
	//counter++;
	return counter;
}
void hold(){
	unsigned long int asd = 0xFFFFFFFF;
	while(asd){
		asd--;
	}
}
