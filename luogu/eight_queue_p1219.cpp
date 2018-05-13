#include <bits/stdc++.h>

int n;
int plant[14][14];
int count=0;

void printt(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(plant[i][j]==1){
				std::cout<<j;
				if(i<n) std::cout<<' ';
			}
		}
	std::cout<<std::endl;
	return;
}

bool check(int i, int j){
	int i1=i, j1=j;
	for(int t=i;t>0;t--)
		if(plant[t][j]==1)
			return false;
	for(int t=j;t>0;t--)
		if(plant[i][t]==1)
			return false;
	for(;;){
		if(i1<1||j1<1) break;
		if(plant[i1][j1]==1) return false;
		i1--;
		j1--;
	}
	i1=i;
	j1=j;
	for(;;){
		if(i1<1||j1>n) break;
		if(plant[i1][j1]==1) return false;
		i1--;
		j1++;
	}
	return true;
}

void dfs(int i){
	if(i>n) return;
	for(int j=1;j<=n;j++){
		if(check(i,j)){
			if(i==n){
				count++;
				plant[i][j]=1;
				if(count<=3)
					printt();
				plant[i][j]=0;
				return;
			}
			else{
				plant[i][j]=1;
				dfs(i+1);
				plant[i][j]=0;
			}
		}
	}
	return;
}

int main(){
	std::cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			plant[i][j]=0;
	dfs(1);
	std::cout<<count;
    return 0;
}
