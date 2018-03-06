#include<stdio.h>

int our_abs(int a){
	return a<0?-a:a;
}

int main(){
	int m[5]={1,-3,9,-2,0};
	for(int i = 0; i<5;i++){
		printf("%s%d%s%d\n","the abs of ",m[i]," is ", our_abs(m[i]));
	}
	return 0;
}