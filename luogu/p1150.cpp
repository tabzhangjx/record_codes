#include <bits/stdc++.h>

int main(){
    int n, k, a, b, c=0;
    std::cin>>n>>k;
    c+=n;
    do{
        a=n/k;
        c+=a;
        b=n%k;
        n=a+b;
    }while(n>=k);
    std::cout<<c;
    return 0;
}
