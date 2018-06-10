#include <bits/stdc++.h>

struct num{
    int s;
    int c;
}nums[100];

bool cmp(num a, num b){
    if(a.c!=b.c) return a.c>b.c;
    else return a.s<b.s;
}
int main(){
    int s1, s2, s3;
    std::cin>>s1>>s2>>s3;
    for(int i=1;i<=s1+s2+s3;i++){
    	nums[i].s=i;
    	nums[i].c=0;
    }
    for(int i=1;i<=s1;i++)
        for(int j=1;j<=s2;j++)
            for(int k=1;k<=s3;k++){
                nums[i+j+k].c++;
            }
    std::sort(nums+1, nums+s1+s2+s3+1, cmp);
    std::cout<<nums[1].s;
    return 0;
}
