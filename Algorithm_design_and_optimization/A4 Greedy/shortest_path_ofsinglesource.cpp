#include <iostream>
using namespace std;


void dijketra(int v,int** a,float* dist,int* prev,int n){
	if(v<1||v>n)return;
	bool* s=new bool[n];
	for(int i=0;i<n;i++){
		dist[i]=a[v][i];
		s[i]=false;
		if(dist[i]==inf)prev[i]=0;
		else prev[i]=v;
	}
	dist[v]=0;
	s[v]=true;
	for(int i=0;i<n;i++){
		float temp=inf;
		int u=v;
		for(int j=0;j<n;j++){
			if(!s[j]&&(dist[j]<temp)){
				u=j;
				temp=dist[j];
			}
		}
		s[u]=true;
		for(int j=1;j<n;j++){
			if((!s[j])&&(a[u][j]<inf)){
				float newdist=dist[u]+a[u][j];
				if(newdist<dist[j]){
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}
int main(){
	int n=0;
	cin>>n;
	int*a =new int[n][10000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int v=0;
	int* dist=new int[n];
	int* prev=new int[n];
	for(int i=0;i<n;i++){
		dist[i]=inf;
		prev[n]=0;
	}
	dijketra(v,a,dist,prev,n);
	return 0;
}