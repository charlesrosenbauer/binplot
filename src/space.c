#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

#include "plot.h"
#include "space.h"
#include "util.h"



B256	embedBytes	(uint8_t* bs, int size){
	B256 ret;
	for(int i = 0; i < 4; i++) ret.bits[i] = 0;

	for(int i = 0; i < size; i++)
		ret.bits[bs[i] / 64] |= (1l << (bs[i] % 64));

	return ret;
}


B256	embedBigram	(uint8_t* bs, int size){
	B256 ret;
	for(int i = 0; i < 4; i++) ret.bits[i] = 0;

	uint8_t a = bs[0];
	for(int i = 1; i < size; i++){
		uint8_t b = bs[i];
		uint8_t c = a ^ (b + 83);	// Not sure this is a good enough hash
		ret.bits[c / 64] |= (1l << (c % 64));
		a = b;
	}

	return ret;
}



int		embedDotDist(B256 a, B256 b){
	int ret = 0;
	for(int i = 0; i < 4; i++) ret += __builtin_popcountl(a.bits[i] & b.bits[i]);
	return ret;
}


int		embedXorDist(B256 a, B256 b){
	int ret = 0;
	for(int i = 0; i < 4; i++) ret += __builtin_popcountl(a.bits[i] ^ b.bits[i]);
	return ret;
}



EmbedTable	embedKMeans(EmbedTable data, int k){
	EmbedTable ret;
	ret.embeds	= malloc(sizeof(B256) * k);
	ret.size	= k;
	for(int i = 0; i < k; i++){
		// TODO: figure out how to efficiently average bitvectors
	}
	return ret;
}



int rateKMeans(EmbedTable means, EmbedTable data){
	int score = 0;
	for(int i = 0; i < data.size; i++){
		int d = embedXorDist(means.embeds[0], data.embeds[i]);
		int m = 0;
		for(int j = 1; j < means.size; i++){
			int dist = embedXorDist(means.embeds[j], data.embeds[i]);
			if(dist < d){
				d = dist;
				m = j;
			}
		}
		score += d;
	}
	return score;
}






void	printEmbedding	(B256 b){
	printf("================================================================\n");
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 64; j++)
			printf("%c", (b.bits[i] & (1l << j))? 'O' : ' ');
		printf("|\n");
	}
}
