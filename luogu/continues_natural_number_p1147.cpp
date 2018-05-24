#include <bits/stdc++.h>

int main(){
    int n, t, r, s;
    std::cin>>n;
    for(int i=1;i<=(n/2);i++){
        for(int j=1;;j++){
            s=(2*i+j)*(j+1)/2;
            if(s==n){
                std::cout<<i<<' '<<i+j<<std::endl;
            }
            if(s>n){
                break;
            }
        }
    }
    return 0;
}
