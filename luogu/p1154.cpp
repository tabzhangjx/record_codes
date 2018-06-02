#include <bits/stdc++.h>

int main(){
    int M, N, k, num[10];
    std::cin>>M>>N;
    for(int i=0;i<10;i++) num[i]=0;
    for(int i=M;i<=N;i++){
        k=i;
        while(k>0){
            num[k%10]++;
            k/=10;
        }
    }
    std::cout<<num[0];
    for(int i=1;i<10;i++) std::cout<<' '<<num[i];
    return 0;
}
