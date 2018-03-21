#include<iostream>

int main(){
    int n, x;
    int count=0, t, num;
    std::cin>>n>>x;
    for(int i=1;i<=n;i++){
        num=i;
        for(;num!=0;){
            t=num%10;
            num/=10;
            if(t==x) count++;
        }
    }
    std::cout<<count;
    return 0;
}
