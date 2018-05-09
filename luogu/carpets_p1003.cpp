#include <bits/stdc++.h>

int carpet[4][10005];

int main(){
	int n, x, y, count=-1;
	std::cin>>n;
	for(int i=0;i<n;i++)
		std::cin>>carpet[0][i]>>carpet[1][i]>>carpet[2][i]>>carpet[3][i];
	std::cin>>x>>y;
	for(int i=n-1;i>=0;i--)
		if(carpet[0][i]<=x&&x<=carpet[0][i]+carpet[2][i]&&
				carpet[1][i]<=y&&y<=carpet[1][i]+carpet[3][i]){
			count=i+1;
			break;
		}
	std::cout<<count;
	return 0;
}