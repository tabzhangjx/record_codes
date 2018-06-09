#include <bits/stdc++.h>

bool cmp(int a, int b){
    return a>b;
}

int main(){
    long long N, S;
    std::cin>>N>>S;
    int s=0, count=0, H[20010];
    for(int i=0;i<N;i++) std::cin>>H[i];
    std::sort(H,H+N,cmp);
    for(int i=0;i<N;i++){
        s+=H[i];
        count++;
        if(s>=S) break;
    }
    std::cout<<count;
    return 0;
}
