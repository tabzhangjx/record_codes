#include<bits/stdc++.h>
#define pa pair<int,int>
#define ll long long
#define inf 10000005
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct cmp{
    bool operator()(pa a,pa b){
        return abs(a.first)>abs(b.first);
    }
};
priority_queue<pa,vector<pa>,cmp>q;
int n,m,tot,a[100005],sum,ans,nxt[100005],pre[100005];
bool mark[100005];
void del(int x){
    mark[x]=1;
    pre[nxt[x]]=pre[x];
    nxt[pre[x]]=nxt[x];
}
int main(){
    n=read();m=read();tot=1;
    for (int i=1;i<=n;i++)
    {
        int x=read();
        if ((ll)a[tot]*x>=0)a[tot]+=x;
        else a[++tot]=x;
    }
    n=tot;
    for (int i=1;i<=n;i++) if (a[i]>0) sum++,ans+=a[i];
    for (int i=1;i<=n;i++)
    {
        nxt[i]=i+1;
        pre[i]=i-1;
        q.push(make_pair(a[i],i));
    }
    while (sum>m)
    {
        sum--;
        while (mark[q.top().second]) q.pop();
        int x=q.top().second;q.pop();
        if (pre[x]!=0&&nxt[x]!=n+1) ans-=abs(a[x]);
        else if (a[x]>0) ans-=a[x];else{sum++;continue;}
        a[x]=a[pre[x]]+a[nxt[x]]+a[x];
        del(pre[x]);del(nxt[x]);
        q.push(make_pair(a[x],x));
    }
    printf("%d",ans);
    return 0;
}