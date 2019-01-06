#include <stdio.h>
#include <stdlib.h>

#define WORD_LEN 64
struct a_block{
	int tag_length;
	bool tag[WORD_LEN];
	bool vaild;
	bool dirty;
	int block_length;
	bool blok_area[WORD_LEN];
	
};

void init(int b1, int tag1){
		tag_length=tag1;
		block_length=b1;
		vaild=0;
		for(int i =0;i<WORD_LEN;i++){
			tag[i]=0;
			blok_area[i]=0;
		}
	}

	
struct main_cache{
	int s, e;
	int S = 1, E = 1;
	a_block caches[1025][1025];
	void init(int s1, int e1, int b1){
		s=s1;
		e=e1;
		for(int i = 0; i < s1; i++)
			S*=2;
		for(int i = 0; i < e1; i++)
			E*=2;
		for(int i=0;i<S;i++){
			for(int j=0;j<E;j++){
				caches[i][j].init(b1, WORD_LEN-s1-e1-b1);
			}
		}

	}
};

int main(){
	int s = 2, e = 1, b = 1;
	main_cache cache;
	cache.init(s,e,b);


	return 0;
}