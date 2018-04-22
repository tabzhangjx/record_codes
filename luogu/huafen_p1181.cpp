#include <iostream>
#define ll long long
int main(){
    int n,m,count=0,sum=0;
    std::cin>>n>>m;
    int nums[100010];
    for(int i=0;i<n;i++){
    	std::cin>>nums[i];
    	if(sum+nums[i]<=m){
    		sum+=nums[i];
    	}
    	else{
    		count++;
    		sum=0;
    		sum+=nums[i];
    	}
    }
    if(sum!=0) count++;
    std::cout<<count;
    return 0;
}
