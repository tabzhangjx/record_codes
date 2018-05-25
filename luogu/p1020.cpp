#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
int gcd(int x,int y){
    if(y==0)
    	return x;
    return gcd(y, x%y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=sqrt(m*n);i++) if((n*m)%i==0&&gcd(i,(n*m)/i)==n) ans++;
    cout<<ans*2;
    return 0;
}
