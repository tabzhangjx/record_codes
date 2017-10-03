#include <iostream>
using namespace std;


void searchpublicsequence(char* x,int m,char* y,int n,int** Ck,int** b){
	Ck[0][0]=0;
	for(int i=0;i<m;i++){
		Ck[i][[0]=0;]
	}
	for(int i=0;i<n;i++){
		Ck[0][i]=0;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(x[i]==y[j]){
				Ck[i][j]=Ck[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(Ck[i-1][j]>Ck[i][j-1]){
				Ck[i][j]=Ck[i-1][j];
				b[i][j]=2;
			}
			else{
				Ck[i][j]=Ck[i][j-1];
				b[i][j]=3;
			}

		}
	}
}

void output(char* x,int m,char* y,int n,int** Ck,int** b){
	if(i==j==0){
		return;
	}
	if(b[i][j]==1){
		output(x,m-1,y,n-1,Ck,b);
		cout<<x[i];
	}
	else if(b[i][j]==2){
		output(x,m-1,y,n,Ck,b);
	}
	else{
		output(x,m,y,n-1,Ck,b);
	}

}
int main(){
	int m=0,n=0;
	cin>>m>>n;
	char* x=new char[m];
	char* y=new char[n];
	for(int i=0;i<m;i++){
		cin>>x[i];
	}
	for(int i=0;i<n;i++){
		cin>>y[i];
	}
	int Ck[100][100];
	int b[100][100];
	searchpublicsequence(x,m,y,n,Ck,b);
	output(x,m,y,n,Ck,b);
	return 0;
}
