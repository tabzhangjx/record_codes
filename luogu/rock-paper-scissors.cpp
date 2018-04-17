#include <iostream>

int main(){
    int N, NA, NB;
    int a1[300], a2[300];
    int S[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
    std::cin>>N>>NA>>NB;
    for(int i=0;i<NA;i++) std::cin>>a1[i];
    for(int i=0;i<NB;i++) std::cin>>a2[i];
    int j=0,k=0;
    int p1=0,p2=0;
    for(int i=0;i<N;i++){
        j%=NA;
        k%=NB;
        p1+=S[a1[j]][a2[k]];
        p2+=S[a2[k]][a1[j]];
        j++;
        k++;
    }
    std::cout<<p1<<' '<<p2;
}
