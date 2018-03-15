#include <iostream>

int main(){
    int n, a, b, c, d, e, f;
    std::cin>>n>>a>>b>>c>>d>>e>>f;
    int c1= b * (int)((n - 1) / a + 1);
    int c2= d * (int)((n - 1) / c + 1);
    int c3= f * (int)((n - 1) / e + 1);
    int a1= c1>c2?c2:c1;
    int a2= a1>c3?c3:a1;
    std::cout<<a2;
    return 0;
}
