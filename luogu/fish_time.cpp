#include<iostream>

int main(){
    int a, b, c, d;
    std::cin>>a>>b>>c>>d;
    if(d>=b)
        std::cout<<c-a<<' '<<d-b;
    else
        std::cout<<c-1-a<<' '<<d+60-b;
    return 0;
}
