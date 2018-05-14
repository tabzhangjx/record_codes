#include <bits/stdc++.h>

int n;
int count=0;
int PX[20], PY[20], PXY[40], PYX[40];
int records[15];

void printt(){
	for(int i=1;i<=n;i++){
		std::cout<<records[i];
		if(i<n)
			std::cout<<' ';
	}
	std::cout<<std::endl;
	return;
}

bool check(int i, int j){
	if(PX[i]==0&&PY[j]==0&&PXY[15+j-i]==0&&PYX[i+j]==0)
		return true;
	else
		return false;
}

void dfs(int i){
	if(i>n) return;
	for(int j=1;j<=n;j++){
		if(check(i,j)){
			if(i==n){
				count++;
				PX[i]=1;
				PY[j]=1;
				PXY[15+j-i]=1;
				PYX[i+j]=1;
				records[i]=j;
				if(count<=3)
					printt();
				PX[i]=0;
				PY[j]=0;
				PXY[15+j-i]=0;
				PYX[i+j]=0;
				return;
			}
			else{
				PX[i]=1;
				PY[j]=1;
				PXY[15+j-i]=1;
				PYX[i+j]=1;
				records[i]=j;
				dfs(i+1);
				PX[i]=0;
				PY[j]=0;
				PXY[15+j-i]=0;
				PYX[i+j]=0;
			}
		}
	}
	return;
}

int main(){
	std::cin>>n;
	for(int i=0;i<20;i++) PX[i]=PY[i]=0;
	for(int i=0;i<40;i++) PXY[i]=PYX[i]=0;
	dfs(1);
	std::cout<<count;
    return 0;
}
