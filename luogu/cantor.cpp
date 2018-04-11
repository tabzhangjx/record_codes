#include <iostream>

int main(){
    int N;
    std::cin>>N;
    int i=1;
    int label=1;
    while(N>i){
        N-=i;
        i++;
        label=-label;
    }
    int t=1;
    while(N>1){
        i--;
        t++;
        N--;
    }
    if(label==1) std::cout<<i<<'/'<<t;
    else std::cout<<t<<'/'<<i;
    return 0;
}