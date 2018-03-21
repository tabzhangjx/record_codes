#include <iostream>

int main(){
    int a[10], b;
    int count=0;
    for(int i=0;i<10;i++) std::cin>>a[i];
    std::cin>>b;
    for(int i=0;i<10;i++) (b+30)>=a[i]?count++:count=count;
    std::cout<<count;
    return 0;
}
