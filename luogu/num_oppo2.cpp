#include <iostream>
#define ll long long
int main(){
    ll n;
    ll t=0;
    int label=1;
    std::cin>>n;
    if(n<0){
        n=-n;
        label*=-1;
    }
    while(n!=0){
        t=t*10+n%10;
        n/=10;
    }
    std::cout<<t*label;
    return 0;
}
