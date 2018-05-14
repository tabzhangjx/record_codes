#include <bits/stdc++.h>

int N, M, T, SX, SY, FX, FY, a, b;
int maze[7][7];
int count=0;

void search(int i, int j){
	if(maze[i][j]==0) return;
	else if(i==FX&&j==FY){
		count+=1;
		return;
	}
	else{
		maze[i][j]=0;
		search(i-1, j);
		search(i, j-1);
		search(i+1, j);
		search(i, j+1);
		maze[i][j]=1;
	}
}
int main(){
    std::cin>>N>>M>>T>>SX>>SY>>FX>>FY;
    for(int i=0;i<=N+1;i++){
    	for(int j=0;j<=M+1;j++){
    		maze[i][j]=0;
    	}
    }
    for(int i=1;i<=N;i++){
    	for(int j=1;j<=M;j++){
    		maze[i][j]=1;
    	}
    }
    for(int i=0;i<T;i++){
    	std::cin>>a>>b;
    	maze[a][b]=0;
    }
    search(SX, SY);
    std::cout<<count;
    return 0;
}
