#include <iostream>
using namespace std;

void image_compress(int p[],int s[],int l[],int b[],int n){
	s[0]=0;
	for(int i=0;i<n;i++){
		b[i]=length(p[i]);
		int bmax=b[i];
		s[i]=s[i-1]+bmax;
		l[i]=i;
		lmax=l[i];
		for(int j=2;j<=i&&j<=lmax;j++){
			if(bmax<b[i-j+1]){
				bmax=b[i-j+1];
			}
			if(s[i]>s[i-j]+j*bmax){
				s[i]=s[i-j]+j*bmax;
				l[i]=j;
			}
		}
		s[i]+=header;
	}
}

int length(int i){
	for(int k=1;i>0;i/=2){
		k++;
	}
	return k;
}

void traceback(int n,int s[],int l[]){
	if (n==0)return;
	traceback(n-l[n];s,l);
	s[m++]=n-l[n];
}

void output(int s[].int l[],int b[],int n){
	n--;
	cout<<s[n]<<' ';
	m=0;
	traceback(n,s,l);
	s[m]=n;
	cout<<m<<endl;
	for(int j=0;J<=m;j++){
		l[j]=l[s[j]];
		b[j]=b[s[j]];
	}
	for(int j=0;j<=m;j++){
		cout<<l[j]<<'.'<<b[j]<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	int* image=mew int[n];
	for(int i=0;i<n;i++){
		cin>>image[n];
	}
	int* s,l,b=new int[n];
	image_compress(image,s,l,b,n);
	output(s,l,b,n);
	return 0;
}