#include <bits/stdc++.h>

int main(){
    int w, n, gs=0;
    int pi[30005];
    std::cin>>w>>n;
    for(int i=0;i<n;i++) std::cin>>pi[i];
    std::sort(pi, pi+n);
    for(int i=0,j=n-1;i<=j;){
        if(pi[i]+pi[j]<=w){
            i++;
            j--;
        }
        else j--;
        gs++;
    }
    std::cout<<gs;
    return 0;
}
