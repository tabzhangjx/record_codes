#include <bits/stdc++.h>

int main(){
    int a[3], m, n;
    std::cin>>a[0]>>a[1]>>a[2];
    m=a[0];
    n=a[0];
    for(int i=0;i<3;i++){
        if(m<a[i])
            m=a[i];
        if(n>a[i])
            n=a[i];
    }
    for(int i=n-1;i>1;i--){
        if(m%i==0&&n%i==0){
            m/=i;
            n/=i;
        }
    }
    std::cout<<n<<'/'<<m;
    return 0;
}
