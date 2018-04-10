#include <iostream>
#define ll long long

int nums[21][21][21]={-1};
ll w(ll a, ll b, ll c){
    if(a<=0||b<=0||c<=0){
    	nums[a][b][c]=1;
    	return 1;
    }
    else if(a>20||b>20||c>20){
    	if(nums[20][20][20]!=0) return nums[20][20][20];
    	else nums[20][20][20]=w(20,20,20);
    	return nums[20][20][20];
    }
    else if(nums[a][b][c]!=-1) return nums[a][b][c];
    else if(a<b&&b<c){
        int sum=0;
        if(nums[a][b][c-1]!=-1) sum+=nums[a][b][c-1];
        else sum+=w(a,b,c-1);
        if(nums[a][b-1][c-1]!=-1) sum+=nums[a][b-1][c-1];
        else sum+=w(a,b-1,c-1);
        if(nums[a][b-1][c]!=0) sum-=nums[a][b-1][c];
        else sum-=w(a,b-1,c);
        nums[a][b][c]=sum;
        return sum;
    }
    else{
        int sum=0;
        if(nums[a-1][b][c]!=-1) sum+=nums[a-1][b][c];
        else sum+=w(a-1,b,c);
        if(nums[a-1][b-1][c]!=-1) sum+=nums[a-1][b-1][c];
        else sum+=w(a-1,b-1,c);
        if(nums[a-1][b][c-1]!=0) sum+=nums[a-1][b][c-1];
        else sum+=w(a-1,b,c-1);
        if(nums[a-1][b-1][c-1]!=0) sum-=nums[a-1][b-1][c-1];
        else sum-=w(a-1,b-1,c-1);
        nums[a][b][c]=sum;
        return sum;
    }
}
int main(){
    ll a,b,c;
    std::cin>>a>>b>>c;

    while(1){
        if(a==-1&&b==-1&&c==-1) break;
        std::cout<<std::endl;
        std::cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        std::cout<<w(a,b,c);
        std::cin>>a>>b>>c;
    }
    return 0;
}
