#ifndef __SPACE_HEADER__
#define __SPACE_HEADER__


#include "stdint.h"

#include "plot.h"


/*
	TODO:
	x data embeddings
	x embedding distances
	* k-means categorization
*/

typedef struct{
	uint64_t	bits[4];
}B256;

typedef struct{
	B256*		embeds;
	int			size;
}EmbedTable;


B256		embedBytes		(uint8_t*, int);
B256		embedBigram		(uint8_t*, int);

int			embedDotDist	(B256, B256);
int			embedXorDist	(B256, B256);

EmbedTable	embedKMeans		(EmbedTable, int);
int			rateKMeans		(EmbedTable, EmbedTable);

void		printEmbedding	(B256);






#endif
