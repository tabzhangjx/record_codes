#include<iostream>

#define N 1000000000000

int main(){
    int k;
    std::cin>>k;
    long long K=k*N;
    long long com=0;
    int i;
    for(i=1;1;i++){
        com+=(N/i);
        if(com>K)
            break;
    }
    std::cout<<i;
    return 0;
}
