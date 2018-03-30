#include <iostream>
#include <cmath>

int counts;

int size_offf(int n){
    int i=0;
    while(n>=1){
        i++;
        n/=10;
    }
    return i;
}
void num_add(int whole, int n){
    int t;
    t=size_offf(whole);
    int m=n/2;
    int s;
    for(int i=1;i<=m;i++){
        s=i*pow(10,t);
        if(s>=1000) return;
        counts++;
        std::cout<<whole+s<<std::endl;
        num_add(whole+s, i);
    }
}

int main(){
    counts=1;
    int n;
    std::cin>>n;
    if(n==0||n==1){
        std::cout<<1;
        return 0;
    }
    num_add(n,n);
    std::cout<<counts;
    return 0;
}
#include <iostream>
#include <cmath>

int counts;

int size_offf(int n){
    int i=0;
    while(n>=1){
        i++;
        n/=10;
    }
    return i;
}
void num_add(int whole, int n){
    int t;
    t=size_offf(whole);
    int m=n/2;
    int s;
    for(int i=1;i<=m;i++){
        s=i*pow(10,t);
        if(s>=1000) return;
        counts++;
        std::cout<<whole+s<<std::endl;
        num_add(whole+s, i);
    }
}

int main(){
    counts=1;
    int n;
    std::cin>>n;
    if(n==0||n==1){
        std::cout<<1;
        return 0;
    }
    num_add(n,n);
    std::cout<<counts;
    return 0;
}
