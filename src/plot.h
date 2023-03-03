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


void plotBigram(Img, File);



#endif
