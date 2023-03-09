#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "plot.h"



Palette paletteA(){
	Palette ret;
	ret.colors     = malloc(sizeof(uint32_t) * 16);
	ret.colorct    = 16;
	ret.colors[ 0] = 0x000000;
	ret.colors[ 1] = 0x575757;
	ret.colors[ 2] = 0xad2323;
	ret.colors[ 3] = 0x2a4bd7;
	ret.colors[ 4] = 0x1d6914;
	ret.colors[ 5] = 0x814a19;
	ret.colors[ 6] = 0x8126c0;
	ret.colors[ 7] = 0xa0a0a0;
	ret.colors[ 8] = 0x81c57a;
	ret.colors[ 9] = 0x9dafff;
	ret.colors[10] = 0x29d0d0;
	ret.colors[11] = 0xff9233;
	ret.colors[12] = 0xffee33;
	ret.colors[13] = 0xe9debb;
	ret.colors[14] = 0xffcdf3;
	ret.colors[15] = 0xf2f3f4;
	return ret;
}

