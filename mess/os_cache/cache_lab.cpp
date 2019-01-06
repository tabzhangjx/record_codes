#include <iostream>
#include <cmath>
#define WORD_LEN 64

using namespace std;


class block{
public:
	int tag_length;
	bool tag[WORD_LEN];
	bool vaild;
	bool dirty;
	int block_length;
	bool blok_area[WORD_LEN];
	block(int b1, int tag1){
		tag_length=tag1;
		block_length=b1;
		vaild=0;
		dirty=0;
		for(int i =0;i<WORD_LEN;i++){
			tag[i]=0;
			blok_area[i]=0;
		}
	}
};

class main_cache{
public:
	int s, e;
	int S, E;
	block *cache[1025][1025];
	main_cache(int s1, int e1, int b1){
		s=s1;
		e=e1;
		S=1;
		E=1;
		for(int i = 0; i < s1; i++)
			S*=2;
		for(int i = 0; i < e1; i++)
			E*=2;
		for(int i=0;i<S;i++){
			for(int j=0;j<E;j++){
				cache[i][j]=new block(b1, WORD_LEN-s1-e1);
			}
		}
	}
};

int main(){
	int s = 2, e = 1, b = 1;
	main_cache cache(s,e,b);




	return 0;
}