#include <bits/stdc++.h>
int n, nums[32][32];
void occupy(int i, int j){
	if(nums[i][j]==1||nums[i][j]==-1) return;
	nums[i][j]=-1;
	occupy(i+1, j);
	occupy(i-1, j);
	occupy(i, j+1);
	occupy(i, j-1);
}
int main(){
	std::cin>>n;
	for(int i=0;i<=n+1;i++) for(int j=0;j<=n+1;j++) nums[i][j]=-1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) std::cin>>nums[i][j];
	for(int i=1;i<=n;i++){
		occupy(1, i);
		occupy(n, i);
		occupy(i, 1);
		occupy(i, n);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(nums[i][j]==-1) std::cout<<0<<' ';
			else if(nums[i][j]==1) std::cout<<1<<' ';
			else std::cout<<2<<' ';
		}
		std::cout<<std::endl;
	}
    return 0;
}