#include<iostream>

int main(){
    int a[101];
    int i;
    for(i=0;;i++){
        std::cin>>a[i];
        if (a[i]==0) break;
    }
    for(int j=i-1;j>=0;j--) std::cout<<a[j]<<' ';
    return 0;
}
