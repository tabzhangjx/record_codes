#include <iostream>
using namespace std;

class matrix{
public:
	int NO;
	int hang;
	int lie;
	int nums=new int[hang*lie];
	matrix(){num=hang=lie=0;};
	~matrix(){};
}

void matricChain(int* p,int** m,int** s,int n){
	for(int i=0;i<n;i++){
		m[i][i]=0;
	}

	if(0){
		for(int delta=1;delta<n;delta++){
			for(int i=0;i<n;i++){
				for(int k=0;k<delta;k++){
					t=m[i][i+k]+m[i+k][i+delta]+p[i]*p[i+k]*p[i+delta];
				}
			}
		}
	}

	if(1){
		for(int r=2;r<n+1;r++){
			for(int i=1;i<=n-r+1;i++){
				int j=i+r-1;
				m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
				s[i][i]=i;
				for(int k=i+1;k<j;k++){
					int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
					if(t<m[i][j]){
						m[i][j]=t;
						s[i][j]=k;
					}
				}
			}
		}
	}
}

void traceback(int** s,int i,int j){
	if(i==j){
		return;
	}
	else{
		traceback(s,i,s[i][j]);
		traceback(s,s[i][j]+1,j);
		cout<<"A"<<i<<","<<s[i][j]<<"A"<<s[i][j]+1<<","<<j;
	}
}
int main(){
	int n=0;
	cin>>n;
	//matrix* matrary=new matrix[n];
	//for(int i=0;i<n;i++){
		//cin>>matrary[i].num;
		//cin>>matrary[i].hang;
		//cin>>matrary[i].lie;
	//}
	int* P=new int[n+1];
	for(int i=0;i<n+1;i++){
		cin>>P[i];
	}
	int m[1000][1000];
	int s[1000][1000];
	matricChain(int* P,int** m,int** s,int n);
	traceback(int** s,int i,int j);
	return 0;
}