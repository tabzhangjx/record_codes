#include <iostream>
#include <algorithm>

int N, R, Q;
int count=0;
struct player{
    int s;
    int w;
    int order;
}ps[200100];

player ps1[100050];
player ps2[100050];

bool cmp(const player &a, const player &b){
    if(a.s!=b.s) return a.s>b.s;
    else return a.order<b.order;
}

void merge_sort(){
    int i=0, j=0;
    for(int k=0;k<N;k++){
        if(i==N/2) ps[k]=ps2[j++];
        else if(j==N/2) ps[k]=ps1[i++];
        else if(cmp(ps1[i], ps2[j])) ps[k]=ps1[i++];
        else ps[k]=ps2[j++];
    }
}

int main(){
    std::cin>>N>>R>>Q;
    N*=2;
    for(int i=0;i<N;i++) std::cin>>ps[i].s;
    for(int i=0;i<N;i++) std::cin>>ps[i].w;
    for(int i=0;i<N;i++) ps[i].order=i+1;
    std::sort(ps, ps+N, cmp);
    for(int i=0;i<R;i++){
        for(int j=0;j<N;j+=2){
            if(ps[j].w>ps[j+1].w){
                ps[j].s++;
                ps1[count]=ps[j];
                ps2[count]=ps[j+1];
                count++;
            }
            else{
                ps[j+1].s++;
                ps2[count]=ps[j];
                ps1[count]=ps[j+1];
                count++;
            }
        }
        merge_sort();
        count=0;
    }
    std::cout<<ps[Q-1].order;
}
