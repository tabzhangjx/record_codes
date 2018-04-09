#include<iostream>

int main(){
    double a=7, s, x, w=0;
    std::cin>>s>>x;
    double m=s-x, n=s+x;
    while(w<m){
        w+=a;
        a*=0.98;
    }
    if(w+a>n) std::cout<<'n';
    else std::cout<<'y';
    return 0;
}
