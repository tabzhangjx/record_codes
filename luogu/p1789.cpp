#include <bits/stdc++.h>
int n, m, k, x, y, count=0;
bool nums[1005][1005];
void torch(){
	for(int i=-2; i<3; i++) if(x+i>=0&&x+i<n) nums[x+i][y]=true;
	for(int i=-2; i<3; i++) if(y+i>=0&&x+i<n) nums[x][y+i]=true;
	for(int i=-1; i<2; i++) if(x+i>=0&&x+i<n) for(int j=-1; j<2; j++) if(y+j>=0&&y+j<n) nums[x+i][y+j]=true;
}
void fluorspar(){
	for(int i=-2; i<3; i++) if(x+i>=0&&x+i<n) for(int j=-2; j<3; j++) if(y+j>=0&&y+j<n) nums[x+i][y+j]=true;
}
int main(){
    std::cin>>n>>m>>k;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) nums[i][j]=false;
    for(int i=0;i<m;i++){
        std::cin>>x>>y;
        x--, y--;
        torch();
    }
    for(int i=0;i<k;i++){
    	std::cin>>x>>y;
    	x--, y--;
    	fluorspar();
    }
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(nums[i][j]==false) count++;
    std::cout<<count;
    return 0;
}
