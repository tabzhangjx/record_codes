#include<stdio.h>

void change(int a){//我们称它为a2
	printf("%s%d,\n","a2 value:",a);
	a=10;
	printf("%s%d,\n","a2 value:",a);
}

int main(){
	int a=5;//我们称它为a1
	printf("%s%d,\n","a1 value:",a);
	change(a);
	printf("%s%d,\n","a1 value:",a);
	return 0;
} 
