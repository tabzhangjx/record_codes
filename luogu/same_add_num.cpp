#include<iostream>

int main(){
    int n;
    std::cin>>n;
    int num[100];
    int mark[100];
    int label, count=0;
    for(int i=0;i<n;i++){
        mark[i]=0;
        std::cin>>num[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            label=num[i]+num[j];
            for(int t=0;t<n;t++){
                if(t!=i&&t!=j&&mark[t]!=1)
                    if(num[t]==label){
                        count++;
                        mark[t]=1;
                        break;
                    }
            }
        }
    }
    std::cout<<count;
    return 0;
}
