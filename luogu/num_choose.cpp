#include <iostream>
#include <cmath>

int num[21];
int label[21];
int count1=0;

int judge(int n){
	if(n==0||n==1){
		return 0;
	}
	for(int j=2;j<=(int)sqrt(n);j++){
		if(n%j==0){
			return 0;
		}
	}
	return 1;
}

void count(int n){
	int sum=0;
	for(int i=0;i<n;i++) if(label[i]==1) sum+=num[i];
	count1+=judge(sum);
}

void pick(int n, int k, int r, int t){
	if(t==k){
		count(n);
		return;
	}
	if((n-r+t)<k){
		return;
	}
	for(int i=r;i<n;i++){
		label[i]=1;
		pick(n, k, i+1, t+1);
		label[i]=0;
	}
	return;
}

int main(){
	int n, k;
	std::cin>>n>>k;
	for(int i=0;i<n;i++) std::cin>>num[i];
	pick(n, k, 0, 0);
	std::cout<<count1;
	return 0;
}
