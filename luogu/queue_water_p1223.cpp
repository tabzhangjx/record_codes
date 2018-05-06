#include <iostream>
#include <stdio.h>
#include <algorithm>
#define ll long long

struct sss
{
	int a, b;
}p[1005];

bool cmp(const sss &a, const sss &b){
    return a.b<b.b;
}

int main(){
    int n;
    std::cin>>n;
    ll sum=0, b=0;
    for(int i=0;i<n;i++){
        std::cin>>p[i].b;
        p[i].a=i+1;
    }
    std::sort(p, p+n, cmp);
    for(int i=0;i<n;i++){
    	std::cout<<p[i].a<<' ';
        b+=sum;
        sum+=p[i].b;
    }
    double a=b;
    a/=n;
    printf("\n%.2f", a);
    return 0;
}
