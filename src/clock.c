//void clock_inter_asm(void);
#ifndef port
#include "ports.h"
#define port
#endif
#include "clock.h"
static time_type counter; //avbrottsr�knare

void init_clock(){
	// s�tt avbrottsintervall
	RTICTL = 0x10;
	// aktiver crg
	CRGINT = 0x80; // set MSb
	//nollst�ll counter
	counter = 0;
	//init avbrottsvektor, clock_inter_asm �r assembler turin
	IRQ_VEC = (unsigned short)clock_inter_asm;
	//till�t avbrott
	myCLI();
}

void clock_inter(){ //avbrottsrutin i C
	counter++;  //�ka avrottsr�knaren
	//kvittera avbrott
	CRGFLG = 0x80;
}
time_type get_time(){     //returnera tid i ms
	time_type time;	
	time = counter * 10;  //counter �r i 10-tal ms
	return time;
}
void hold(time_type ms){ //v�nta ms/10-antal avbrott � 10 ms.

	time_type tmp;
	unsigned short msShort;
	
	tmp = counter;
	counter = 0;
	
	msShort	= (unsigned short)ms;
	msShort = msShort/10;
	
	while(msShort != (short)counter);
	counter += tmp;
}
