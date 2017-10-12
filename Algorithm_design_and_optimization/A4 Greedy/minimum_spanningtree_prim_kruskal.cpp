#include <iostream>
using namespace std;

void prim(int n,float** c){
	float* lowcost=new float[n+1];
	int* closest=new int[n+1];
	bool* s=new bool[n+1];

	s[1]=true;
	for(int i=2;i<=n;i++){
		lowcost[i]=c[1][i];
		closest[i]=1;
		s[i]=false;
	}

	for(int i=1;i<n;i++){
		float min=INFTY;
		int j=1;
		for(int k=2;k<=n;k++){
			if((lowcost[k]<min)&&(!s[k])){
				min=lowcost[k];
				j=k;
			}
		}
		cout<<j<<','<<closest[j];

		s[j]=true;
		for(int k=2;k<=n;k++){
			if((c[j][k]<lowcost[k])&&(!s[k])){
				lowcost[k]=c[j][k];
				closest[k]=j;
			}
		}
	}
}

void kruskal()
int main(){
	int n=0;
	cin>>n;
	int**a =new int[n][10000];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int v=0;


	return 0;
}