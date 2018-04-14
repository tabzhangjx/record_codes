#include <iostream>
#include <cmath>

void n_i(int t){
	if(t>1) std::cout<<"^"<<t;
	else return;
}
void putt(int a, int i, int n){
    if(a==0) return;
    else if(i==0&&i==n){
    	std::cout<<a;
    }
    else if(i==0){
    	if(std::abs(a)>1) std::cout<<a<<"x",n_i(n-i);
    	else if(a==-1) std::cout<<"-x",n_i(n-i);
    	else if(a==1) std::cout<<"x",n_i(n-i);
    }
    else if(i!=n){
    	if(a>0) std::cout<<'+';
    	if(a==-1) std::cout<<'-';
    	if(std::abs(a)>1) std::cout<<a;
    	std::cout<<"x",n_i(n-i);
    }
    else{
    	if(a>0) std::cout<<'+';
    	std::cout<<a;
    }
}

int main(){
    int n;
    std::cin>>n;
    int m[105];
    for(int i=0;i<=n;i++){
        std::cin>>m[i];
        putt(m[i],i,n);
    }
}