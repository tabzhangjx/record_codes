// luogu-judger-enable-o2
// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
//#include<fstream>
using namespace std;

struct carpet{
    int a,b,g,k;
};

//ifstream fin("carpet.in");
//ofstream fout("carpet.out");

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"-1";
        return 0;
    }
    carpet C[100010];
    for(int i=0;i<n;i++){
        cin>>C[i].a>>C[i].b>>C[i].g>>C[i].k;
    }
    int x,y;
    cin>>x>>y;
    int max=-1;
    for(int i=n-1;i>=0;i++){
        if((C[i].a<=x)&&(C[i].a+C[i].g>=x)&&(C[i].b<=y)&&(C[i].b+C[i].k>=y)){
            max=i+1;
            cout<<max;
            return 0;
        }
    }
    cout<<max;
    return 0;
}