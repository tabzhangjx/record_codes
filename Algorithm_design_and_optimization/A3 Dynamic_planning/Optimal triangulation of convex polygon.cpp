#include <iostream>
using namespace std;
//语法树与矩阵连乘的语法树同构，因此只需要修改其权函数即可；
//设权函数为w(i,k,j);

class node{
public:
	//
	//
	node(){
		//
		//
		//
	};
	~node(){
		//
		//
		//
	};
}

void funWeight(a,b,c){
	//
	//
	//
	//
	//
}
void minWeightTriangulation(int n,int** t,int** s){
	for(int i=0;i<n;i++){
		t[i][i]=0;
	}
	for(int r=2;r<=n;r++){
		for(int i=0;i<=n-r+1;i++){
			int j=i+r-1;
			t[i][j]=t[i+1][j]+w(i-1,i,j);
			s[i][j]=i;
			for(int k=i+1;k<i+r-1;k++){
				int u=t[i][k]+t[k+1][j]+w(i-1.k.j);
				if(u<t[i][j]){
					t[i][j]=u;
					s[i][j]=k;
				}
			}
		}
	}

}

int main(){
	int n=0;
	cin>>n;
	node* N=new node[n];
	for(int i=0;i<n;i++){
		//
	}
	int t[1000][1000];
	int s[1000][1000];
	minWeightTriangulation(n,t,s);
	return 0;
}