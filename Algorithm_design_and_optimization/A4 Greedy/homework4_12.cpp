#include <iostream>
using namespace std;

int whole=0;
struct node{
	int x;
	int y;
}

node search(int** a,bool** b,int n){
	int rec=0;
	node a;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(rec<a[i][j]&&!b){
				rec=a[i][j];
				a.x=i;
				a.y=j;
			}
			b[i][j]=true;
		}
	}
	return a;
}

bool check(int** a,int m,int n){
	int o;
	for(int i=0;i<n;i++){
		if(a[m][i]>0){
			o++;
		}
	}
	if(o>0){
		return true;
	}
	else{
		return false;
	}
}

void break(int** a,bool** b,int n){
	node t;
	while(whole!=n-1){
		t=search(a,b,n);
		if(check(a,t,n)){
			a[t.x,t.y]=0;
			whole--;
		}
	}
}

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
	bool** b=new bool[n][10000]
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=0){
				whole++;
			}
			b[i][j]=false;
		}
	}
	break(a,b,n);
	node flag;
	flag=search(a,n);
	cout<<a(flag.x,flag.y);
	return 0;
}