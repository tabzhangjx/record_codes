#include <iostream>

int main(){
    int n,s,a,b;
    std::cin>>n>>s>>a>>b;
    int mark=999999,label=-1,count=0;;
    int nums[2][5010];
    for(int i=0;i<n;i++) std::cin>>nums[1][i]>>nums[0][i];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(mark>nums[0][j]){
                mark=nums[0][j];
                label=j;
            }
        }
        if(label!=-1&&label!=i){
            nums[0][i]=nums[0][i]+nums[0][label];
            nums[0][label]=nums[0][i]-nums[0][label];
            nums[0][i]=nums[0][i]-nums[0][label];
            nums[1][i]=nums[1][i]+nums[1][label];
            nums[1][label]=nums[1][i]-nums[1][label];
            nums[1][i]=nums[1][i]-nums[1][label];
        }
        mark=999999;
        label=-1;
    }
    for(int i=0;i<n;i++){
        if(s-nums[0][i]>=0){
            if(a+b>=nums[0][i]){
                s-=nums[0][i];
                count++;
            }
        }
        else break;
    }
    std::cout<<count;
    return 0;
}
