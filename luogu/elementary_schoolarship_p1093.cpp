#include <iostream>
#include <algorithm>

struct student{
    int s;
    int a1;
    int a2;
    int a3;
    int order;
}ss[301];

bool cmp(student a, student b){
    if(a.s!=b.s) return a.s>b.s;
    else if(a.a1!=b.a1) return a.a1>b.a1;
    else return a.order<b.order;
}

int main(){
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        ss[i].order=i+1;
        std::cin>>ss[i].a1;
        std::cin>>ss[i].a2;
        std::cin>>ss[i].a3;
        ss[i].s=ss[i].a1+ss[i].a2+ss[i].a3;
    }
    std::sort(ss, ss+n, cmp);
    for(int i=0;i<5;i++) std::cout<<ss[i].order<<' '<<ss[i].s<<std::endl;
    return 0;
}
