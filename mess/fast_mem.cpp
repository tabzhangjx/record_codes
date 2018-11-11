#include <iostream>
#include <ctime>
#include <unistd.h>
#define N 1000000
typedef unsigned int size_tt;

using namespace std;
//int 4
//size_t 4
//long 8
//long long 8

void fast_memset(int *s, int c, size_tt n){
	int *p = s;
	for(int i=0; i<n; i++){
		*(p++) = c;
	}
	return;
}

void run(){
	clock_t begin, end;
	int a[N];
	begin = clock();
	fast_memset(a, 0, N);
	end = clock();
	double time = double(end - begin);
    cout<<time<<endl;
}

int main(){
	for(int i=0;i<10000;i++){
		run();
		sleep(1);
	}
	
	return 0;
}