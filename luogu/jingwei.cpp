 
#include<cstdio>
#include<cstring>
#include<algorithm>
inline int read() {
    int x=0;
    char c=getchar() ;
    while(c<'0'||c>'9') c=getchar();
    while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
    return x;
}
const int maxn = 10007;
int v,n,c;
int k[maxn],m[maxn],dp[maxn];
int main() {
    v=read(),n=read(),c=read();
    for(int i=1;i<=n;++i) 
        k[i]=read(),m[i]=read();
    int ans=-1;
    for(int i=1;i<=n;++i) {
        for(int j=c;j>=m[i];--j) {
            dp[j]=std::max(dp[j],dp[j-m[i]]+k[i]);
            if(dp[j]>=v)ans=std::max(ans,c-j);
        }
    }
    if(ans>=0)printf("%d\n",ans);
    else puts("Impossible");
    return 0;
}