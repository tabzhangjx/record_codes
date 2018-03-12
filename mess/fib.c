//Fabonacci数列
#include<stdio.h>
#include<time.h>

long long fib(int n){
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    else
        return fib(n-2)+fib(n-1);
}

int main(){
	clock_t start, end;
    for(int n=10;n<=50;n+=5){
    	start = clock();
    	long long res=fib(n);
    	end = clock();
    	printf("%lld\n%s%d%s%f\n", res, "n = ", n, " : time = ", (double)end-start);
    	fflush(stdout);
	}
    return 0;
}