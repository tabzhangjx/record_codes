#include <bits/stdc++.h>

struct pe{
	long long a, b, c;
}p[100005];

bool cmp(const pe &a, const pe &b){
	return a.c<b.c;
}

class high_precision{
public:
	int w[30010];
	int count;
	high_precision(int a);
	~high_precision();
	high_precision operator*(const int a);
}

high_precision::high_precision(int a){
	for(int i=1;i<30010;i++)
		w[i]=0;
	w[0]=a;
	count=1;
}

high_precision::~high_precision(){}

high_precision high_precision::operator*(const int a){
	for(int i=0;i<count;i++)
		w[i]*=a;
	for(int i=0;i<count;i++){
		if(w[i]>9){
			w[i+1]+=(w[i]/10);
			w[i]%=10;
		}
	}
	int t=w[count];
	while(t>0){
		count+=1;
		if(t>9){
			w[count+1]=w[count]/9;
			w[count]%=9;
		}
		else{
			break;
		}
		t=w[count+1];
	}
}

int main(){
	int n;
	long long k1, k2, sum=1;
	std::cin>>n>>k1>>k2;
	for(int i=0;i<n;i++){
		std::cin>>p[i].a>>p[i].b;
		p[i].c=p[i].a*p[i].b;
	}
	std::sort(p, p+n, cmp);
	
	std::cout<<sum*k1/p[n-1].b;
}
