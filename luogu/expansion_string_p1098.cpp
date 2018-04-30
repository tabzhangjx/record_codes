#include <iostream>

int p1, p2, p3;
char str[1000];

void out(int i){
    int label=(p3==1?1:-1);
    int t=str[i+1-label];
    for(t=t+1*label; (char)(t)!=str[i+1+label]; t+=label){
    	for(int k=0;k<p2;k++){
    		if(p1==1) std::cout<<(char)(t);
    		else if(p1==2&&t>='a'&&t<='z') std::cout<<(char)(t+'A'-'a');
    		else if(p1==3) std::cout<<'*';
    	}
    }
}

int main(){
    std::cin>>p1>>p2>>p3;
    std::cin>>str[0];
    std::cin.getline(str+1, 1000);
    std::cout<<str[0];
    int i;
    for(i=1; str[i+1]!='\0';i++){
        if(str[i]=='-'){
            if(
                (str[i-1]>=str[i+1])||
                    (
                        (
                            !(std::isdigit(str[i-1])&&std::isdigit(str[i+1]))
                        )&&
                        (
                            !(std::isalpha(str[i-1])&&std::isalpha(str[i+1]))
                        )
                    )
                )
                std::cout<<'-';
            else if(str[i-1]==(str[i+1]-1)) i=i;
            else out(i-1);
        }
        else std::cout<<str[i];
    }
    std::cout<<str[i];
    return 0;
}
