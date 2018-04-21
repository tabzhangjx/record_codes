#include <iostream>
#include <algorithm>

struct presider{
    int num;
    int kth;
    char piao[102];
}pre[20];

bool cmp1(presider p1, presider p2, int t=0){
    if(p1.piao[t]!=p2.piao[t]) return p1.piao[t]>p2.piao[t];
    else return cmp1(p1, p2, t+1);
}

bool cmp(presider p1, presider p2){
    if(p1.num!=p2.num)
        return p1.num>p2.num;
    else return cmp1(p1, p2, 0);
}

int main(){
    int n;
    char temp;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>temp;
        std::cin.getline(pre[i].piao+1,102);
        pre[i].piao[0]=temp;
        pre[i].kth=i+1;
    }
    for(int i=0;i<n;i++){
        pre[i].num=0;
        for(int j=0;pre[i].piao[j]!='\0';j++)
            pre[i].num++;
    }
    std::sort(pre, pre+n, cmp);
    std::cout<<pre[0].kth<<std::endl<<pre[0].piao;
    return 0;
}
