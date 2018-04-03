#include<iostream>
#define N 2010
#define N1 1000
int num[10]={6,2,5,5,4,5,6,3,7,6};
int nums[N];
int sym=2;
int count=0;

int judge(int n, int i, int j){
    if((n-4-nums[i]-nums[j])==nums[i+j]){
        if(i==j){
            //std::cout<<i<<' '<<j<<std::endl;
            return 1;
        }
        else{
            //std::cout<<i<<' '<<j<<std::endl;
            return 2;
        }
    }
    else return 0;
}

void pick(int n, int r, int k){
    for(int i=k;i<N1;i++){
        if(r==2) count+=judge(n, k, i);
        if(r==1) pick(n, 2, i);
    }
    return;
}

int main(){
    int n;
    std::cin>>n;
    int t, j;
    nums[0]=6;
    for(int i=1;i<N;i++){
        nums[i]=0;
        j=i;
        while(j>0){
            t=j%10;
            nums[i]+=num[t];
            j/=10;
        }
    }
    pick(n, 1, 0);
    std::cout<<count;
    return 0;
}
