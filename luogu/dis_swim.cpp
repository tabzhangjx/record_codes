#include <iostream>

int main(){
    double a, b = 2;
    std::cin>>a;
    for(int i=1; 1; i++){
        a-=b;
        if(a<=0){
            std::cout<<i;
            return 0;
        }
        b*=0.98;
    }
    return 0;
}
