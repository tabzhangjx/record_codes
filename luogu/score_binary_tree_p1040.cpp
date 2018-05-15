#include <bits/stdc++.h>

#define ll long long

int n, ss[30], pa=-1;
ll DPS[30][30], re=-1;
int PAT[30][30];
ll dfs(int le, int ri, int locals, int ttt){
    if(DPS[le][ri]!=-1) return DPS[le][ri];
    if(le==ri){
        DPS[le][ri]=ss[le];
        return ss[le];
    }
    if(le>ri){
        DPS[le][ri]=1;
        return 1;
    }
    ll temp=1;
    int mark=-1;
    for(int i=le;i<=ri;i++){
        if(i==4){
            i=i;
        }
        temp=dfs(le, i-1, i, 0)*dfs(i+1, ri, i, 1)+ss[i];
        if(temp>DPS[le][ri]){
            DPS[le][ri]=temp;
            mark=i;
        }
    }
    PAT[le][ri]=mark;
    return DPS[le][ri];
}

void print_path(int le, int ri){
    if(le>ri||PAT[le][ri]<1) return;
    std::cout<<PAT[le][ri]<<' ';
    print_path(le, PAT[le][ri]-1);
    print_path(PAT[le][ri]+1, ri);
}

int main(){
    std::cin>>n;
    for(int i=1;i<=n;i++)
        std::cin>>ss[i];
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            DPS[i][j]=-1;
            PAT[i][j]=-1;
        }
        PAT[i][i]=i;
    }
    dfs(1, n, 0, 1);
    std::cout<<DPS[1][n]<<std::endl;
    print_path(1, n);
    return 0;
}
