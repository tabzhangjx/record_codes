#include <bits/stdc++.h>

int main(){
    long long a, b, c=1;
    std::cin>>a>>b;
    for(int i=0;i<b;i++) c+=(c*a);
    std::cout<<c;
}
