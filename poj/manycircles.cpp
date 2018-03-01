#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef double ld;
const ld _0=1e-6l;
const int N=100010;
int n;
ld x[N],y[N],r[N];
ld L,R;
int read(){
    int x=0,c=getchar(),f=1;
    while(c>57||c<48){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)x=x*10+c-48,c=getchar();
    return x*f;
}
void get(int id,ld X,ld&a,ld&b){
    X-=x[id];
    X=sqrt(r[id]*r[id]-X*X);
    a=y[id]-X;
    b=y[id]+X;
}
bool chk(ld X,int a,int b){
    if(fabs(X-x[a])>r[a]||fabs(X-x[b])>r[b])return 0;
    ld a1,a2,b1,b2;
    get(a,X,a1,a2);
    get(b,X,b1,b2);
    return a2>b1&&a1<b2;
}
void chk(int a,int b){
    ld xd=x[b]-x[a],yd=y[b]-y[a];
    ld d=sqrt(xd*xd+yd*yd);
    if(d+_0>r[a]+r[b]){
        puts("NO");
        exit(0);
    }
    ld s=(r[a]+r[b]+d)/2.;
    ld h=2*sqrt(s*(s-r[a])*(s-r[b])*(s-d))/d;
    ld m=x[a]+xd*sqrt(r[a]*r[a]-h*h)/d,c=h*fabs(yd)/d;
    if(d*d+r[a]*r[a]<r[b]*r[b])m=x[a]*2-m;
    ld lx=m-c,rx=m+c;
    if(lx>x[a]-r[a]&&chk(x[a]-r[a]+_0,a,b))lx=x[a]-r[a];
    if(lx>x[b]-r[b]&&chk(x[b]-r[b]+_0,a,b))lx=x[b]-r[b];
    if(rx<x[a]+r[a]&&chk(x[a]+r[a]-_0,a,b))rx=x[a]+r[a];
    if(rx<x[b]+r[b]&&chk(x[b]+r[b]-_0,a,b))rx=x[b]+r[b];
    if(lx>L)L=lx;
    if(rx<R)R=rx;
}
int main(){
    n=read();
    for(int i=0;i<n;i++){
        x[i]=read();
        y[i]=read();
        r[i]=read();
    }
    L=x[0]-r[0],R=x[0]+r[0];
    for(int i=1;i<n;i++){
        if(L<x[i]-r[i])L=x[i]-r[i];
        if(R>x[i]+r[i])R=x[i]+r[i];
    }
    while(1){
        if(L+_0>R){
            puts("NO");
            return 0;
        }
        ld M=(L+R)/2.;
        ld y1,y2,a1,a2;
        get(0,M,y1,y2);
        for(int i=1;i<n;i++){
            get(i,M,a1,a2);
            if(a1>y1)y1=a1;
            if(a2<y2)y2=a2;
            if(y1+_0>y2){
                for(int j=0;j<i;j++){
                    get(j,M,y1,y2);
                    if(y1>=a2-_0||y2<=a1+_0){
                        chk(i,j);
                        goto re;
                    }
                }
            }
        }
        puts("YES");
        return 0;
        re:;
    }
}