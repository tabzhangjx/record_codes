#include <iostream>

int main(){
    int label=0;
    for(int i=2;i<20000;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                label=1;
                break;
            }
        }
        if(label==0){
            std::cout<<i<<',';
        }
        else label=0;
    }


    return 0;
}
