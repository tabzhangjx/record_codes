#include <iostream>

int count=0;
int nums[10];
int plans[10000][10];

void copy(){
    for(int i=0;i<10;i++){
        plans[count][i]=nums[i];
    }
}

void search(int n, int r){
    if(r==10){
        if(n==1||n==2||n==3){
            nums[r-1]=n;
            copy();
            count++;
            return;
        }
    }
    else for(int j=1;j<4;j++){
        nums[r-1]=j;
        search(n-j, r+1);
    }
    return;
}

int main(){
    int n;
    std::cin>>n;
    search(n, 1);
    std::cout<<count;
    if(count==0) return 0;
    for(int i=0;i<count;i++){
        std::cout<<std::endl;
        for(int j=0;j<10;j++){
            std::cout<<plans[i][j]<<' ';
        }
    }
    return 0;
}
