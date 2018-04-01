#include <iostream>

int arr[9];
bool label[9];

int full_dps(int n, int r){
    if(r==n+1){
        for(int i=0;i<n;i++){
            std::cout<<"    "<<arr[i];
        }
        std::cout<<std::endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        if(label[i]!=1){
            arr[r-1]=i+1;
            label[i]=1;
            full_dps(n,r+1);
            label[i]=0;
        }
    }
    return 0;

}
int main(){
    int n;
    std::cin>>n;
    int r=1;
    full_dps(n,r);
    return 0;
}
