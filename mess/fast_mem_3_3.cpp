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
    
    //calc m
    unsigned long m = c;
    for(int i=0;i<7;i++){
        m = m << 8;
        m+=c;
    }
    
    //对齐
    unsigned long *p1;
    unsigned char *temp;
    p1 = (unsigned long*) s;
    temp = (unsigned char*) p1;
    while((long long)temp % 8 != 0){
        *(temp++) = c;
        n--;
    }
    p1 = (unsigned long*) temp;
    
    //2*2
    unsigned long *p2 = p1 + 1;
    unsigned long *p3 = p2 + 1;
    int i;
    //put i+8 out
    n-=32;
    //2*2
    for(i=0; i<=n; i+=24){
        *p1 = m;
        *p2 = m;
        p1+=3;
        p2+=3;
        *p3 = m;
        p3+=3;
    }
    n+=32;
    i+=8;
    
    temp = (unsigned char*) p2;
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

//ave 2.09
