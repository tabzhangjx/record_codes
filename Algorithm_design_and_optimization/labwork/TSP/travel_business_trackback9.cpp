#include <iostream>
#include <limit.h>
using namespace std;

int n,T;
int pre=new int[n];
int MINCOST=INT_MAX;
bool* visit=new bool[n];
int edge[1002][1002];

int check(){
	int flag=true;
	for(int i=0;i<n;i++){
		if()
	}
	return
}
void search(){
	for(int i=0;i<n;i++){
		if(visit[i]=0){
			visit[i]=1;
			if(check()){
				
			}
			else{
				
			}
		}
	}


}
int main(){
	cin>>n>>T;
	for(int i=0;i<n;i++){
		pre[i]=-1;
		visit[i]=0;
		int(j=0;j<n;j++){
			edge[i][j]=edge[j][i]=-1;
		}
	}

	new int node1,node2,edgenum;
	for(int i=0;i<T;i++){
		
		cin>>node1>>node2,edgenum;
		edge[node1][node2]=edge[node2][node1]=edgenum;
	}
	delete node1,node2,edgenum;

	search();
	return 0;
}