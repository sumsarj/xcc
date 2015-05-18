#include "ports.h"

void main(){
	while(1){
	unsigned int qwe = get_key();
	switch(qwe){
	case 0 : 
		MotorStart();
	case 1 : 
		DrillDown();
	case 2 :
		DrillUp();
	case 3 :
		Nstep(0);
	case 4:
		DrillHole();
	case 5:
		RefPos();
	case 6:
		DoAuto();
	
	
	
	}
	}
}
