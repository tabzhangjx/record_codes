#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=100005;
int f[N],g[N],w[N];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=(f[j]+f[j-w[i]])%10;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j<w[i]){
                g[j]=f[j];
            }
            else{
                g[j]=(f[j]-g[j-w[i]]+10)%10;
            }
        }
        for(int j=1;j<=m;j++)
            cout<<g[j];
        cout<<endl;
    }
    return 0;

}

