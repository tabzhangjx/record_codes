#include <bits/stdc++.h>

int main(){
    long long n, nums[100000];
    std::cin>>n;
    nums[0]=0;
    nums[1]=1;
    nums[2]=1;
    for(int i=3;i<=n;i++){
        nums[i]=nums[i-2]+nums[i-1];
    }
    std::cout<<nums[n]<<".00";
    return 0;
}
