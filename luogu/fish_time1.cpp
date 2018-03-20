#include<iostream>

int main(){
    int x, n;
    std::cin>>x>>n;
    int sum = 0;
    sum+=250*5*(int)(n/7);
    n%=7;
    for(int i=n; i>0; i--){
        x=(x+1)%7;
        if(x!=6&&x!=7) sum+=250;
    }
    sum+=250;
    std::cout<<sum;
    return 0;
}
