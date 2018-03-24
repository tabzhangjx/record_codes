#include <iostream>

int main(){
    int n, fish[100];
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>fish[i];
    }
    int res[100];
    for(int i=n-1;i>=0;i--){
        res[i]=0;
        for(int j=0;j<i;j++){
            if(fish[j]<fish[i]) res[i]++;
        }
    }
    for(int i=0;i<n;i++){
        std::cout<<res[i]<<' ';
    }
    return 0;
}
