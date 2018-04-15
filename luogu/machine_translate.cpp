#include <iostream>
int M,N,start=0,end=0;
int ssd[101];

bool search(int a){
	int i;
    for(i=start;i!=end;i++){
        if(ssd[i]==a) return true;
        i=(i+1)%M;
    }
    if(ssd[i]==a) return true;
    return false;
}

void in_line(int a){
    if(start!=(end+1)%M){
    	end=(end+1)%M;
    }
    else{
    	end=(end+1)%M;
    	start=(start+1)%M;
    }
    ssd[end]=a;
}

int main(){
    std::cin>>M>>N;
    int a,count=0;
    for(int i=0;i<N;i++){
        std::cin>>a;
        if(!search(a)){
            count++;
            in_line(a);
        }
    }
    return 0;
}
