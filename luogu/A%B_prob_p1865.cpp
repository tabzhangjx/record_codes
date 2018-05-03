#include <iostream>
#include <cmath>

int nums[1000005];

int main(){
	int n, m, l, r, flag=0;
	nums[0]=nums[1]=0;
	std::cin>>n>>m;
	for(int i=2;i<=m;i++){
		for(int j=2;j<=sqrt(i);j++){
			if(i%j==0){
				flag=1;
				break;
			}
		}
		if(flag==0) nums[i]=nums[i-1]+1;
		else{
			nums[i]=nums[i-1];
			flag=0;
		}
	}
	for(int i=0;i<n;i++){
		std::cin>>l>>r;
		if(1<=l&&l<=r&&r<=m){
			std::cout<<nums[r]-nums[l-1];
		}
		else std::cout<<"Crossing the line";
		std::cout<<std::endl;
	}
	return 0;
}