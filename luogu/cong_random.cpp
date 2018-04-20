#include <iostream>
#include <algorithm>

int main(){
    int N;
    std::cin>>N;
    int nums[110];
    for(int i=0;i<N;i++) std::cin>>nums[i];
    sort(nums, nums+N, std::less<int>());
	int count=1;
    for(int i=1;i<N;i++) 
    	if(nums[i]!=nums[i-1])
    		count++;
    	std::cout<<count<<std::endl<<nums[0];
    for(int i=1;i<N;i++) 
    	if(nums[i]!=nums[i-1])
    		std::cout<<' '<<nums[i];
    return 0;
}
