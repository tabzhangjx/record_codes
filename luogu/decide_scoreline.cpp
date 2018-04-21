#include <iostream>
#include <algorithm>

struct volunteer{
    int k,s;
}volus[5000];

bool cmp(volunteer p1, volunteer p2){
    if(p1.s!=p2.s) return p1.s>p2.s;
    else return p1.k<p2.k;
}
int main(){
    int n;
    int m;
    std::cin>>n>>m;
    //float sss=m*1.5;
    m*=1.5;
    //if(ttt!=sss) ttt++;
    for(int i=0;i<n;i++) std::cin>>volus[i].k>>volus[i].s;
    std::sort(volus,volus+n,cmp);
    int count=0;
    for(int i=0;i<n;i++) if(volus[i].s>=volus[m-1].s) count++;
    std::cout<<volus[m-1].s<<' '<<count<<std::endl;
    for(int i=0;i<count;i++) std::cout<<volus[i].k<<' '<<volus[i].s<<std::endl;
    return 0;
}
