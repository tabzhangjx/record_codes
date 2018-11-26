#include <iostream>
#include <ctime>
#include <unistd.h>
#define N 100000
typedef unsigned int size_tt;
using namespace std;

int a[N];

//int 4
//size_t 8
//long 8
//long long 8

void fast_memset(void *s, char c, size_tt n){
	unsigned long m = c;
	for(int i=0;i<7;i++){
		m = m << 8;
		m+=c;
	}
	unsigned long *p;
	unsigned char *temp;
	p = (unsigned long*) s;
	temp = (unsigned char*) p;
	while((long long)temp % 8 != 0){
		*(temp++) = c;
		n--;
	}
	p = (unsigned long*) temp;
	int i;

	//put i+8 out
	n-=8;
	for(i=0; i<=n; i+=8){
		*(p++) = m;
	}
	n+=8;
	temp = (unsigned char*) p;
	for(i = i;i<n;i++){
		*(temp++) = c;
	}
	return;
}

void run(){
	clock_t begin, end;
	begin = clock();
	fast_memset(a, 0, N);
	end = clock();
	double time = double(end - begin)/10;
    cout<<time<<endl;
}

int main(){
	for(int i=0;i<10000;i++){
		run();
		sleep(1);
	}
	return 0;
}

//ave 3.1