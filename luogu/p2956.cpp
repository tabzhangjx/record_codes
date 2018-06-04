#include <bits/stdc++.h>

int main(){
    int a, b, c, nums[4][100000], plat[300][300], count=0;
    std::cin>>a>>b>>c;
    for(int i=0;i<c;i++) std::cin>>nums[0][i]>>nums[1][i]>>nums[2][i]>>nums[3][i];
    for(int i=0;i<=a;i++)
        for(int j=0;j<=b;j++)
            plat[i][j]=0;
    for(int i=0;i<c;i++){
    	for(int j=nums[0][i];j<=nums[2][i];j++)
    		for(int k=nums[1][i];k<=nums[3][i];k++){
    			if(plat[j][k]==0){
    				plat[j][k]=1;
    				count++;
    			}
    		}
    }
    std::cout<<count;
    return 0;
}
