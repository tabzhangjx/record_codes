#include <bits/stdc++.h>

int main(){
    int L, R, temp, count=0;
    std::cin>>L>>R;
    for(int i=L; i<=R; i++){
        temp=i;
        while(temp>0){
            if(temp%10==2) count++;
            temp/=10;
        }
    }
    std::cout<<count;
    return 0;
}
