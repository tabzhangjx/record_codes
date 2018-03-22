#include <iostream>

int main(){
    int N, M;
    std::cin>>N>>M;
    int street[100001];
    int a, b;
    for(int i=0;i<=N;i++) street[i]=1;
    for(int i=0;i<M;i++){
        std::cin>>a>>b;
        for(int j=0;j<=N;j++){
            if(a<=j&&j<=b) street[j]=0;
        }
    }
    int count=0;
    for(int i=0;i<=N;i++){
        street[i]==1?count++:count=count;
    }
    std::cout<<count;
    return 0;
}
