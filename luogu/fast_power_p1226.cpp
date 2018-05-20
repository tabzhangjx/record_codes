#include <bits/stdc++.h>
#define ll long long

ll b, p, k, s, rest=1;

int main(){
    std::cin>>b>>p>>k;
    ll b1=b, p1=p;
    for(;p>1;){
    	if(p%2==1)
    		rest*=b;
        b%=k;
        rest%=k;
        p/=2;
        b*=b;
    }
    s=(b*rest)%k;
    std::cout<<b1<<'^'<<p1<<" mod "<<k<<'='<<s;
    return 0;
}
