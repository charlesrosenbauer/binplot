#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "plot.h"



void plotBigram(Img img, File file){
	uint8_t a = file.bytes[0];
	for(int i = 1; i < file.size; i++){
		uint8_t b = file.bytes[i];
		int n = (a * img.w) + b;
		img.pix[n] = 0x7f7f7f;
		
		a = b;
	}
}
