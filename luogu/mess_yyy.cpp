#include <bits/stdc++.h>

struct comp{
	int a, b;
}cs[1000005];

bool cmp(const comp &a, const comp &b){
	return a.b<b.b;
}

int main(){
	int n, count, mark=0;
	std::cin>>n;
	for(int i=0;i<n;i++) 
		std::cin>>cs[i].a>>cs[i].b;
	std::sort(cs, cs+n, cmp);
	for(int i=0;i<n;i++){
		if(cs[i].a>=mark){
			count++;
			mark=cs[i].b;

		}
	}
	std::cout<<count;
	return 0;
}