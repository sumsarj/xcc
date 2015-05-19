#include "ports.h"
#include "drill.h"

int main(){
	init_clock();
	while(1){
	unsigned int qwe = (unsigned int)get_key();
	switch(qwe){
	case 0 : 
		MotorStart();
		break;
	case 1 :
		MotorStop();
		break;
	case 2 : 
		DrillDown();
		break;
	case 3 :
		DrillUp();
		break;
	case 4 :
		Nstep(1);
		break;
	case 5:
		DrillHole();
		break;
	case 6:
		RefPos();
		break;
	case 7:
		DoAuto();
		break;
	
	
	}
	}
	return 0;
}
