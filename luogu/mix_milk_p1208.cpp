#include <bits/stdc++.h>

struct milk{
	int Pi, Ai;
}ms[5005];

bool cmp(const milk &a, const milk &b){
	return a.Pi<b.Pi;
}

int main(){
	int N, M, sum=0, w=0;
	std::cin>>N>>M;
	for(int i=0;i<M;i++){
		std::cin>>ms[i].Pi>>ms[i].Ai;
	}
	std::sort(ms, ms+M, cmp);
	for(int i=0;i<M;i++){
		if(sum+ms[i].Ai>=N){
			w+=(N-sum)*ms[i].Pi;
			break;
		}
		else{
			sum+=ms[i].Ai;
			w+=ms[i].Ai*ms[i].Pi;
		}
	}
	std::cout<<w;
	return 0;
}