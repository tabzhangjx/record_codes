#include <bits/stdc++.h>

int main(){
    std::string a, b;
    long long s, a1[3]={0}, b1[3]={0}, i=0, k=0, t=0;
    std::cin>>a>>b>>s;
    for(i=0; a[i]!='\0'; i++){
        if(a[i]!=':') a1[k]=a1[k]*10+a[i]-'0';
        else k++;
    }
    for(i=0, k=0; b[i]!='\0'; i++){
        if(b[i]!=':') b1[k]=b1[k]*10+b[i]-'0';
        else k++;
    }
    for(i=0; i<3; i++){
        t=t*60+b1[i]-a1[i];
    }
    s*=t;
    std::cout<<s;
}
