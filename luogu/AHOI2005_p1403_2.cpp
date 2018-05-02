#include <iostream>
int main(){
    int n;
    std::cin>>n;
    int s=0;
    for(int i=1;i<=n;i=n/(n/i)+1) s+=(n/i)*(n/(n/i)-i+1);
    std::cout<<s;
    return 0;
}
