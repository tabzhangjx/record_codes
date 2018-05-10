#include <bits/stdc++.h>

struct pe{
	long long a, b, c;
}p[100005];

bool cmp(const pe &a, const pe &b){
	return a.c<b.c;
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
	for(int i=0;i<n-1;i++){
		sum*=p[i].a;
		if(p[i].a!=1){
			std::cout<<p[i].a<<' '<<sum<<std::endl;
		}
	}
	std::cout<<sum*k1/p[n-1].b;
}
