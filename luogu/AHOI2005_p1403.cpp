#include <iostream>

int *Fs;

int main(){
    int n;
    std::cin>>n;
    Fs=new int[n+1];
    for(int i=0;i<n;i++) Fs[i]=1;
    Fs[0]=0;
    Fs[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
        	if(i%j==0&&(i/j)%j==0){
            	Fs[i]=Fs[i/j]+Fs[j]-1;
            	break;
            }
            else if(i%j==0&&i/j!=j){
            	Fs[i]=Fs[j]+Fs[i/j];
            	break;
            }
            else if(i%j==0&&i/j==j){
            	Fs[i]+=Fs[j];
            	break;
            }
        }
    }
    for(int i=0;i<=n;i++) std::cout<<i<<' '<<Fs[i]<<std::endl;
    return 0;
}
