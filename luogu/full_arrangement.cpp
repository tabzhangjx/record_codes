#include <iostream>

int label[9];

void print_whole(int n){
	for(int i=0;i<n;i++){
		std::cout<<" "<<label[i];
	}
	std::cout<<std::endl;
}

int full_dps(int n, int r){
    for(int i=0;i<n;i++){
        if(label[i]==0){
            label[i]=r;
            if(r==n){
                print_whole(n);
                label[i]=0;
                return 0;
            }
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