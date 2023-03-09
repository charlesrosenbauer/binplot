#ifndef __PLOT_HEADER__
#define __PLOT_HEADER__


#include "stdint.h"



/*
	TODO:
	
	* byte value
	* entropy
	* popcount
	* byte match
	* similarity match (xor pct, and pct, dot product)
	* k-means coloring
	
	* hilbert curve
	* zigzag
	* histogram
	* bigram
	
*/
typedef struct{
	uint32_t*	pix;
	int			h, w;
}Img;

typedef struct{
	uint8_t*	bytes;
	uint64_t	size;
}File;

typedef struct{
	uint32_t*	pix;
	uint64_t	size;
}ColorMap;


typedef struct{
	uint32_t*	colors;
	int			colorct;
}Palette;


void plotBigram		(Img, File);
void plotZigzag		(Img, File, int);
void plotHilbert	(Img, File, int);


ColorMap	popColor(File);


void colorZigzag	(Img, ColorMap, int);
void colorHilbert	(Img, ColorMap, int);



#endif
