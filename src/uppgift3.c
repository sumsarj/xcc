#ifndef port
#include "ports.h"
#define port
#endif
#include "clock.h"
#include "displayML15.h"

int main(){
	
	while(1){
		display_dec((unsigned int)get_time());
	}
	return 0;
}
