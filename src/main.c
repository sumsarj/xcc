#include "ports.h"

void main(){
	char a;
	while(1){
		a = ML4READ;
		ML4WRITE = a;
	}
}
