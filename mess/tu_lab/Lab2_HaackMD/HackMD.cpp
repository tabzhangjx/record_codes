#define _GNU_SOURCE
#include <sched.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h> 


using namespace std;
#define FIBER_STACK 8192

int id = 10715053;
int res = 0;
int a;

int add_id(){
	printf("This is son, my pid is: %d, the a is: %d\n", getpid(), a);
	while(id != 0){
		res += id % 10;
		id /= 10;
	}
	return res;
}

int main(){
	void * stack;

    a = 1;

    stack = malloc(FIBER_STACK);//为子进程申请系统堆栈

    if(!stack)
    {
        printf("The stack failed\n");
        exit(0);
    }
    printf("creating son thread!!!\n");

	clone(&add_id, (char *)stack + FIBER_STACK);

	printf("This is father, my pid is: %d, the a is: %d\n", getpid(), a);

	cout<<res;
	return 0;
}