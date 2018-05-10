#include <bits/stdc++.h>
using namespace std;

struct pe{
    int a, b, c;
}p[100005];

bool cmp(const pe &a, const pe &b){
    if(a.c!=b.c)
        return a.c<b.c;
    else
        return a.b>b.b;
}

class high_precision{
public:
    int w[30010];
    int count;
    high_precision(){};
    high_precision(int a);
    ~high_precision();
    high_precision operator-(const int a);
    high_precision operator*(const int a);
    high_precision operator/(const int a);
    friend ostream& operator<<(ostream &out, high_precision &c);
};

high_precision::high_precision(int a){
    for(int i=1;i<30010;i++)
        w[i]=0;
    w[0]=a;
    count=1;
}

high_precision::~high_precision(){}

high_precision high_precision::operator*(const int a){
    for(int i=0;i<count;i++)
        w[i]*=a;
    for(int i=0;i<count;i++){
        if(w[i]>9){
            w[i+1]+=(w[i]/10);
            w[i]%=10;
        }
    }
    int t=w[count];
    while(t>0){
        count+=1;
        w[count+1]=0;
        if(t>9){
            w[count]=w[count-1]/10;
            w[count-1]%=10;
        }
        else{
            break;
        }
        t=w[count];
    }
    high_precision m;
    for(int i=0;i<count;i++){
        m.w[i]=w[i];
    }
    m.count=count;
    return m;
}

high_precision high_precision::operator/(const int a){//abandun rest
    high_precision m;
    int t=0, label=0;
    for(int i=count-1;i>=0;i--){
        t=t*10+w[i];
        if(t>=a){
            m.w[i]=t/a;
            t%=a;
            if(label==0){
                m.count=i+1;
                label=1;
            }
        }
        else{
            m.w[i]=0;
        }
    }
    if(label==0) count=0;
    return m;
}

ostream  &operator<<(ostream &out, high_precision &c)
{
    for(int i=c.count-1;i>=0;i--){
        cout<<c.w[i];
    }
    return out;
}

int main(){
    int n=0;
    int k1, k2;
    high_precision w(1);
    std::cin>>n>>k1>>k2;
    for(int i=0;i<n;i++){
        std::cin>>p[i].a>>p[i].b;
        p[i].c=p[i].a*p[i].b;
    }
    std::sort(p, p+n, cmp);
    for(int i=0;i<n-1;i++){
        w=w*p[i].a;
    }
    w=w*k1;
    w=w/p[n-1].b;
    if(w.count>0)
        std::cout<<w;
    else
        cout<<k1;
}
