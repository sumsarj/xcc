#include "ports.h"
#define port
#include "keyboardML15.h"
#include "displayML15.h"
int main(){
	unsigned int a;
	while(1){
	a = get_key();
	display_dec(a);
	}
	return 0;
	
}
