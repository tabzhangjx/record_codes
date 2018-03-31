#include <iostream>
#include <cmath>

int main(){
    int n, k;
    std::cin>>n>>k;
    int label=0;
    int m[100010];
    for(int i=0;i<k;i++) std::cin>>m[i];
    for(int i=0;i<k;i++){
    	if(m[i]==0||m[i]==1){
    		std::cout<<"No"<<std::endl;
            continue;
    	}
        for(int j=2;j<=(int)sqrt(m[i]);j++){
            if(m[i]%j==0){
                std::cout<<"No"<<std::endl;
                label=1;
                break;
            }
        }
        if(label==1){
            label=0;
        }
        else{
            std::cout<<"Yes"<<std::endl;
        }

    }
    

    return 0;
}
