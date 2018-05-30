#include <bits/stdc++.h>

int main(){
    int mod[42];
    int a;
    for(int i=0;i<42;i++) mod[i]=0;
    for(int i=0;i<10;i++){
        std::cin>>a;
        mod[a%42]=1;
    }
    a=0;
    for(int i=0;i<42;i++) if(mod[i]==1) a++;
    std::cout<<a;
    return 0;
}
