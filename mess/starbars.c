#include<stdio.h>

void starbar(int a){
	int count;
	for(count = 1; count <= a; count++){
		putchar('*');
	}
	putchar('\n');
}

int main(){
	int i;
	for(i = 1; i <= 20; i++){
		starbar(i);
	}
	return 0;
}