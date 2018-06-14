#include <bits/stdc++.h>

bool cmp(int a, int b){
    return a < b;
}
int main(){
    int a[3];
    char m;
    std::cin>>a[0]>>a[1]>>a[2];
    std::sort(a, a+3, cmp);
    for(int i=0;i<3;i++){
        std::cin>>m;
        std::cout<<a[m-'A']<<' ';
    }
    return 0;
}
