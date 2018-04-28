#include <iostream>

int p1, p2, p3;
char str[1000];

void out(int i){
    int label=(p3==1?1:-1);
    int t=str[i+1-label];
    std::cout<<(str[i]);
    for(t=t+1*label; (char)(t)!=str[i+1+label]; t+=label){
    	for(int k=0;k<p2;k++){
    		if(p1==1) std::cout<<(char)(t);
    		else if(p1==2&&t>='a'&&t<='z') std::cout<<(char)(t+'A'-'a');
    		else if(p1==3) std::cout<<'*';
    	}
    }
    std::cout<<(str[i+2]);
}

int main(){
    std::cin>>p1>>p2>>p3;
    std::cin>>str[0];
    std::cin.getline(str+1, 1000);
    for(int i=0; str[i]!='\0';){
        if(str[i+1]=='-'){
            if(str[i]>=str[i+2]) std::cout<<str[i]<<'-'<<str[i+2];
            else if(str[i+2]==str[i]+1) std::cout<<str[i]<<str[i+2];
            else out(i);
            i+=3;
        }
        else{
            std::cout<<str[i];
            i++;
        }
    }
    return 0;
}
