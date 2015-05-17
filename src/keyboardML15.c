#ifndef port
#include "ports.h"
#endif
//#include "keyboardML15.h"


unsigned int get_key(){
	volatile port8ptr kbd_read = KBDIN;
	unsigned int value = 0;
	while(1){
		if(*kbd_read < 128){
			while(*kbd_read < 128){
			}
			value = ((unsigned int)(*kbd_read))-128;
			return value;
		}
	}	
}
