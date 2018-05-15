#include <bits/stdc++.h>
#define ll long long

int n, ss[30], pa=-1;
ll DPS[30][30], path[3][30], re=-1;
bool visited[30];

ll dfs(int le, int ri){
    if(DPS[le][ri]!=-1) return DPS[le][ri];
    if(le==ri) return ss[le];
    if(le>ri) return 1;
    ll temp=1;
    int mark=-1;
    for(int i=le;i<=ri;i++){
        temp=1;
        if(DPS[le][i-1]!=-1)
            temp*=DPS[le][i-1];
        else{
            DPS[le][i-1]=dfs(le,i-1);
            temp*=DPS[le][i-1];
        }
        if(DPS[i+1][ri]!=-1)
            temp*=DPS[i+1][ri];
        else{
            DPS[i+1][ri]=dfs(i+1,ri);
            temp*=DPS[i+1][ri];
        }
        temp+=ss[i];
        if(temp>DPS[le][ri]){
            DPS[le][ri]=temp;
            mark=i;
        }
    }
    if(path[2][mark]<DPS[le][ri]){
        path[2][mark]=DPS[le][ri];
    }
    return temp;
}

void print_path(int pas, int le, int ri){
    if(le>ri) return;
    std::cout<<pas<<' ';
    pa=-1;
    re=-1;
    for(int i=le;i<pas;i++){
        if(path[2][i]>re){
            re=path[2][i];
            pa=i;
        }
    }
    print_path(pa, le, pas-1);
    pa=-1;
    re=-1;
    for(int i=pas+1;i<=ri;i++){
        if(path[2][i]>re){
            re=path[2][i];
            pa=i;
        }
    }
    print_path(pa, pas+1, ri);
}

int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++)
        std::cin>>ss[i];
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            DPS[i][j]=-1;
        }
        path[0][i]=-1;
        path[1][i]=-1;
        visited[i]=1;
    }
    dfs(1, n);
    std::cout<<DPS[1][n]<<std::endl;
    for(int i=1;i<=n;i++){
        if(path[2][i]>re){
            re=path[2][i];
            pa=i;
        }
    }
    print_path(pa, 1, n);
    return 0;
}
