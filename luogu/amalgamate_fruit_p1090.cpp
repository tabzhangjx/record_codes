#include <bits/stdc++.h>

struct cmp{
    bool operator()(const int &a, const int &b){
        return a > b;
    }
};

int main(){
    std::priority_queue <int,std::vector<int>,cmp> fru;
    int n, temp, a, b, sum=0;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>temp;
        fru.push(temp);
    }
    for(int i=1;i<n;i++){
        a=fru.top();
        fru.pop();
        b=fru.top();
        fru.pop();
        sum=sum+a+b;
        fru.push(a+b);
    }
    std::cout<<sum;
    return 0;
}
