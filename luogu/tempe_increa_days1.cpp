#include <iostream>

int main(){
    int n, temps;
    std::cin>>n;
    int count1=0, count2=0;
    int label1=-1;
    for(int i=0;i<n;i++){
        std::cin>>temps;
        if(temps>label1){
            count2++;
        }
        else{
            if(count1<count2){
                count1=count2;
            }
            count2=1;
        }
        label1=temps;
    }
    std::cout<<count1;
    return 0;
}
