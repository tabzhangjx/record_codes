#include <bits/stdc++.h>

int main(){
    int a, b, c, k, flag=1;
    std::cin>>k;
    for(int i=10000;i<30001;i++){
        a=i/100;
        b=i/10-(i/10000)*1000;
        c=i%1000;
        if(a%k==0&&b%k==0&&c%k==0){
            std::cout<<i<<std::endl;
            flag=0;
        }
    }
    if(flag)
    	std::cout<<"No";
    return 0;
}
