#include <bits/stdc++.h>

int main(){
    int n, nums[10005], mark=-1, count=1;
    std::cin>>n;
    for(int i=0;i<n;i++) std::cin>>nums[i];
    for(int i=1;i<n;i++){
        if(nums[i]==nums[i-1]+1){
            count++;
        }
        else{
            if(count>mark) mark=count;
            count=1;
        }
    }
    std::cout<<mark;
    return 0;
}
