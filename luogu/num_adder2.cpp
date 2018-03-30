#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int adders[1010];
    adders[0]=adders[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2==1) adders[i]=adders[i-1];
        else adders[i]=adders[i-1]+adders[i/2];
    }
    std::cout<<adders[n];
    return 0;
}
