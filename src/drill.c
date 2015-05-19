#include "ports.h"
#include "drill.h"
unsigned char ML4Shadow = 0;

void MotorStart(){
	OutOne(2);
	hold((time_type)250);
}
void MotorStop(){
	OutZero(2);
}
void DrillDown(){
	OutOne(3);
}
void DrillUp(){
	OutZero(3);
}
int Nstep(int a){   //a == antal steg att steppa
	int i;
	for(i = 0; i<a; i++){	//steppa a gånger
		if(0 == (BORR_STATUS & 0x2)){	//borren uppe?
			Alarm(2);
			return 0;
		}
		OutOne(1);
		hold((time_type)250);    //250 ms delay
		OutOne(0);
		hold((time_type)500);
		OutZero(0);
		
	}
	return 1;
}
int DrillDownTest(){
	int retry;
	int i;
	retry = 20;
	for(i=0; i<retry; i++){ //testa om borren är nere (retry) gånger
		if((BORR_STATUS & 0x4))
			return 1;
		hold((time_type)250);   //delat 250 ms
	}
	Alarm(2);
	return 0;
}
void Alarm(int a){
	int i;
	for(i=0; i<a ;i++){
		hold((time_type)500);
		OutOne(4);
		hold((time_type)1000); //delat 1 sekund
		OutZero(4);
	}
	
}

int DrillHole(){
	unsigned int res;
	DrillDown();
	res = DrillDownTest();
	hold((time_type)250);
	DrillUp();
	hold((time_type)250);
	return res;
}
int RefPos(){
	unsigned char alarmtest = 1;
	do{
	if(BORR_STATUS & 0x1)
		return 1;
	alarmtest = Nstep(1);
	}while(alarmtest != 0);
	return 0;
}
void DoAuto(){
	int pattern[21] = {0,1,1,1,1,1,1,1,2,1,5,2,2,2,2,4,4,3,8,2,255};
	int antalSteg;
	int subrutinRes;
	
	if(RefPos()){	
		int i=0;
		MotorStart();
		while(1){
		antalSteg = pattern[i];
		i++;
		if(antalSteg == 255)
			break;
		subrutinRes = Nstep(antalSteg);
		if(subrutinRes == 0)
			break;
		subrutinRes = DrillHole();
		if(subrutinRes == 0)
			break;
		}
	}
	MotorStop();
}
void OutOne(int bit){
	int a = 1;
	a = a << bit;
	set(ML4Shadow,a);
	BORR_CTRL = ML4Shadow;
}
void OutZero(int bit){
	int a = 1;
	a = a << bit;
	clear(ML4Shadow,a);
	BORR_CTRL = ML4Shadow;
}
