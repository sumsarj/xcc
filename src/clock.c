//void clock_inter_asm(void);
#ifndef port
#include "ports.h"
#define port
#endif
#include "clock.h"
static time_type counter; //avbrottsräknare

void init_clock(){
	// sätt avbrottsintervall
	RTICTL = 0x10;
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
	counter++;  //öka avrottsräknaren
	//kvittera avbrott
	CRGFLG = 0x80;
}
time_type get_time(){     //returnera tid i ms
	time_type time;	
	time = counter * 10;  //counter är i 10-tal ms
	return time;
}
void hold(time_type ms){ //vänta ms/10-antal avbrott á 10 ms.

	time_type tmp;
	unsigned short msShort;
	
	tmp = counter;
	counter = 0;
	
	msShort	= (unsigned short)ms;
	msShort = msShort/10;
	
	while(msShort != (short)counter);
	counter += tmp;
}
