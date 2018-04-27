#include <iostream>
#include <cmath>

int M,N,K;
int x=0, y=0;
int whole=0, steps=0;
int a[20][20]; ;

bool try_step(int m, int n){
    if((steps+std::abs(m-x)+std::abs(n-y)+m+1)<=K){
        steps=steps+std::abs(m-x)+std::abs(n-y)+1;
        x=m;
        y=n;
        whole+=a[m][n];
        return true;
    }
    else return false;
}

int main(){
    std::cin>>M>>N>>K;
    K-=2;
    int label=0;
    int max=0, mark_x=0, mark_y=0;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            std::cin>>a[i][j];
    while(1){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(a[i][j]>max){
                    max=a[i][j];
                    mark_x=i;
                    mark_y=j;
                    if(label==0) y=j;
                }
            }
        }
        label=1;
        if(try_step(mark_x, mark_y)){
            a[mark_x][mark_y]=max=0;
        }
        else break;
    }
    std::cout<<whole;
    return 0;
}
