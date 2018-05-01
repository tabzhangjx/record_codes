#include <iostream>
#include <algorithm>

int N, R, Q;
struct player{
    int s;
    int w;
    int order;
}ps[100005];

bool cmp(player a, player b){
    if(a.s!=b.s) return a.s>b.s;
    else return a.order<b.order;
}

int main(){
    std::cin>>N>>R>>Q;
    N*=2;
    for(int i=0;i<N;i++) std::cin>>ps[i].s;
    for(int i=0;i<N;i++) std::cin>>ps[i].w;
    for(int i=0;i<N;i++) ps[i].order=i+1;
    for(int i=0;i<R;i++){
        for(int j=0;j<N;j+=2){
            if(ps[j].w>ps[j+1].w) ps[j].s++;
            else ps[j+1].s++;
        }
        std::sort(ps, ps+N, cmp);
    }
    std::cout<<ps[Q-1].order;
    return 0;
}
