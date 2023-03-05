#ifndef __SPACE_HEADER__
#define __SPACE_HEADER__


#include "stdint.h"

#include "plot.h"


/*
	TODO:
	* data embeddings
	* k-means categorization
*/

typedef struct{
	uint64_t	bits[4];
}B256;


B256	embedBytes	(uint8_t*, int);
B256	embedBigram	(uint8_t*, int);



#endif
