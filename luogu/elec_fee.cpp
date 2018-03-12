#include<iostream>
#include<iomanip>

int main(){
    int total;
    float fee=0;
    std::cin>>total;
    std::cout.setf(std::ios::fixed);
    if(total>400){
        fee+=(total-400)*0.5663;
        total=400;
    }
    if(total>150){
        fee+=(total-150)*0.4663;
        total=150;
    }
    fee+=total*0.4463;
    std::cout<<std::setprecision(1)<<fee;
    return 0;
}
