#ifndef port
#include "ports.h"
#endif

/*void display_digits(unsigned char digitsArray[]){
	unsigned char write_byte = 0;
	int i;
	DISP_MODE_REG_WRITE = 1;
	for(i = 0; i < 6 ; i++){
		DISP_DATA_REG_WRITE = digitsArray[i];
	}
	DISP_DATA_REG_WRITE = write_byte;
	DISP_DATA_REG_WRITE = write_byte;
	
	DISP_MODE_REG_WRITE = 0;
}*/
void display_digits(unsigned char *digitsArrayPtr){
	unsigned char write_byte = 0;
	int i;
	DISP_MODE_REG_WRITE = 1;
	DISP_DATA_REG_WRITE = 208;
	DISP_MODE_REG_WRITE = 0;
	for(i = 0; i < 6 ; i++){
		DISP_DATA_REG_WRITE = *(digitsArrayPtr + i);
	}
	DISP_DATA_REG_WRITE = write_byte;
	DISP_DATA_REG_WRITE = write_byte;
	
	
}


void display_dec(unsigned int segment){
	unsigned char segment_8 = segment;
	unsigned char digitsArray[6];
	int i;
	for(i = 0;i<6;i++){
		digitsArray[5-i] = segment_8%(10^(i+1));
		segment_8 = segment_8-segment_8%(10^(i+1));
	}
	display_digits(&digitsArray[0]);
}

