#include <bits/stdc++.h>

int main(){
    int a, n, c1=0, c2=0;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>a;
        if(a==5) c1++;
        else c2++;
    }
    //std::cout<<c1;
    if(c1<9){
        std::cout<<"-1";
        return 0;
    }
    else{
        for(;c1>=9;){
            c1-=9;
            for(int i=0;i<9;i++) std::cout<<'5';
        }
        for(int i=0;i<c2;i++){
            std::cout<<0;
        }
    }
    return 0;
}
