#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "plot.h"


void hilbertRot(int n, int *x, int* y, int rx, int ry){
	if(ry == 0){
		if(rx == 1){
			*x = (n-1) - *x;
			*y = (n-1) - *y;
		}
		int tmp = *x;
		*x = *y;
		*y = tmp;
	}
}

void hilbert(int n, int d, int* x, int* y){
	int rx, ry, t=d;
	*x = 0;
	*y = 0;
	for(int i = 1; i < n; i *= 2){
		rx = 1 & (t/2);
		ry = 1 & (t ^ rx);
		hilbertRot(i, x, y, rx, ry);
		*x += i * rx;
		*y += i * ry;
		t  /= 4;
	}
}




void plotBigram(Img img, File file){
	uint8_t a = file.bytes[0];
	for(int i = 1; i < file.size; i++){
		uint8_t b = file.bytes[i];
		int n = (a * img.w) + b;
		img.pix[n] = 0xffffff;
		
		a = b;
	}
}


void plotZigzag(Img img, File file, int scroll){
	for(int i = 0; i < 65536; i++){
		int x = i % 256;
		int y = i / 256;
		int n = (y * img.w) + x;
		img.pix[n] = (i+scroll < file.size)? ((uint32_t)file.bytes[i+scroll]) * 0x010101 : 0;
	}
}


void plotHilbert(Img img, File file, int scroll){
	for(int i = 0; i < 65536; i++){
		int x = i % 256;
		int y = i / 256;
		hilbert(256, (y*256)+x, &x, &y);
		int n = (y * img.w) + x;
		img.pix[n] = (i+scroll < file.size)? ((uint32_t)file.bytes[i+scroll]) * 0x010101 : 0;
	}
}



ColorMap popColor(File file){
	ColorMap ret;
	ret.pix   = malloc(sizeof(uint32_t) * file.size);
	ret.size  = file.size;
	for(int i = 0; i < file.size; i++) ret.pix[i] = (__builtin_popcount(file.bytes[i]) << 13) | file.bytes[i];
	return ret;
}





void colorZigzag(Img img, ColorMap map, int scroll){
	for(int i = 0; i < 65536; i++){
		int x = i % 256;
		int y = i / 256;
		int n = (y * img.w) + x;
		img.pix[n] = (i+scroll < map.size)? map.pix[i+scroll] : 0;
	}
}


void colorHilbert(Img img, ColorMap map, int scroll){
	for(int i = 0; i < 65536; i++){
		int x = i % 256;
		int y = i / 256;
		hilbert(256, (y*256)+x, &x, &y);
		int n = (y * img.w) + x;
		img.pix[n] = (i+scroll < map.size)? map.pix[i+scroll] : 0;
	}
}

