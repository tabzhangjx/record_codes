#include<iostream>

int main(){
    int time[14];
    for(int i=0;i<14;i++)
        std::cin>>time[i];
    int flag=0;
    int mark=0;
    for(int i=0;i<14;i+=2){
        int a=time[i]+time[i+1];
        if(a>8){
            if(a>mark){
                flag=i/2+1;
                mark=a;
            }
        }
    }
    std::cout<<flag;
    return 0;
}
