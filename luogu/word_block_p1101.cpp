#include <bits/stdc++.h>
using namespace std;

int n;
char strs[103][103];
bool mark[103][103];
char label[8]="yizhong";
void mark_ys(int i, int j, int a, int b){
	for(int t=0;t<7;t++){
		mark[i][j]=1;
		i+=a;
		j+=b;
	}
}

bool check_it(int i, int j, int a, int b){
	for(int t=0;t<7;t++){
		if(strs[i][j]!=label[t]) return false;
		i+=a;
		j+=b;
	}
	return true;
}

void check_ys(int i, int j){
	if(check_it(i, j, -1, -1)) mark_ys(i, j, -1, -1);
	if(check_it(i, j, 0, -1)) mark_ys(i, j, 0, -1);
	if(check_it(i, j, 1, -1)) mark_ys(i, j, 1, -1);
	if(check_it(i, j, 1, 0)) mark_ys(i, j, 1, 0);
	if(check_it(i, j, 1, 1)) mark_ys(i, j, 1, 1);
	if(check_it(i, j, 0, 1)) mark_ys(i, j, 0, 1);
	if(check_it(i, j, -1, 1)) mark_ys(i, j, -1, 1);
	if(check_it(i, j, -1, 0)) mark_ys(i, j, -1, 0);
}

void search_y(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(strs[i][j]=='y')
				check_ys(i,j);
}

int main(){
	std::cin>>n;
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++){
			strs[i][j]='*';
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			std::cin>>strs[i][j];
			mark[i][j]=0;
		}
	search_y();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mark[i][j]==1) std::cout<<strs[i][j];
			else std::cout<<'*';
		}
		std::cout<<std::endl;
	}
	return 0;
}