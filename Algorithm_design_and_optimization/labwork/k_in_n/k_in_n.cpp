#include<iostream>
using namespace std;

int comp(int*b,int l,int i){
	for(int p=l;p<i;p++){
		if(b[p]!=-1){
			return p;
		}
	}
}
void search(int* a,int k,int i){
	int record=11;
	int mark=0;
	for(int m=0;m<=k;m++){
		if(a[i]<record){
			record=a[i];
			mark=i;
		}
	}
	for(int m=0;m<i;m++){
		a[m]=-1;
	}
	int s=0;
	for(int m=i+1;s<=(k-mark-1);m++){
		if(a[m]>a[comp(a,m+1,i)]){
			a[m]=-1;
			s++;
			m=i;
		}
	}
}
int main(){
	long long n;int k;
	cin>>n>>k;
	int a[1000]=NULL;int i=0;
	for(;n>0;n++){
		a[i]=n%10;
		n/=10;
		i++;/
	}
	int t=i-1;int* line=new int[i];
	for(int j=0;j<i;j++,t--){
		line[j]=a[k];
	}
	search(line,k,i)
	for(t=0;t<i;t++){
		if(line[t]!=-1){
			cout<<line[t];
		}
	}
	return 0;
}