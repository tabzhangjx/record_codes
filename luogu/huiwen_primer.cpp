#include <iostream>
#include <cmath>
int num[11];

int judge_primer(int n){
	for(int j=2;j<=(int)sqrt(n);j++){
		if(n%j==0){
			return 0;
		}
	}
	return 1;
}

int judge_huiwen(int n){
	int m=n;
	int i=0;
	while(n>0){
		num[i]=n%10;
		i++;
		n/=10;
	}
	for(int j=0;j<i;j++) if(num[j]!=num[i-j-1]) return 0;
	return judge_primer(m);
}

void produ(int a, int b){
	for(int i=a;i<=b;i=i+2)
		if(judge_huiwen(i)) std::cout<<i<<std::endl;
}

int main(){
	int a, b;
	std::cin>>a>>b;
	if(a%2==0) a++;
	produ(a, b);
	return 0;
}