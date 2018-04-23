#include<iostream>
#include<algorithm>

struct P{
    int num;
    int wei;
}ps[10000001];

bool cmp(P a,P b){
    if(a.wei==b.wei) return a.num<b.num;
    else return a.wei>b.wei;
}

int main(){
	int N,K,E[11];
    std::cin>>N>>K;
    for(int i=0;i<10;i++) std::cin>>E[i];
    for(int i=0;i<N;i++){
        std::cin>>ps[i].wei;
        ps[i].num=i+1;    
    } 
    std::sort(ps,ps+N,cmp);
    for(int i=0;i<N;i++) ps[i].wei+=E[i%10];
    std::sort(ps,ps+N,cmp); 
    for(int i=0;i<K;i++) std::cout<<ps[i].num<<' ';
    return 0;    
}
