#include <bits/stdc++.h>

int main(){
	int n, k, j=0, label=0;
	std::cin>>n;
	for(int i=0;!(i==n-1&&j==n);){
		std::cin>>k;
		while(k>0){
			if(j==n){
				std::cout<<std::endl;
				j=0;
				i++;
			}
			std::cout<<label;
			k--;
			j++;
		}
		label=1-label;
	}
	return 0;
}
