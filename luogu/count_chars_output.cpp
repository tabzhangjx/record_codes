#include<iostream>
#include<string>

int main(){
    char a;
    int s[26]={0};
    for(int t=0;t<4;t++){
    	char a1[900];
    	std::cin.getline(a1,900);
    	int j=0;
    	while(a1[j]!='\0'){
    		if(isalpha(a1[j])){
    			s[a1[j]-'A']++;
    		}
            j++;
    	}
    }
    int max=0;
    for(int i=0;i<26;i++){
    	if(s[i]>max){
    		max=s[i];
    	}
    }
    int *record=new int[max];
    for(int i=1;i<=max;i++){
    	record[i]=0;
    	for(int j=0;j<26;j++){
    		if(s[j]>=i){
    			record[i]=j;
    		}
    	}
    }
    while(max>=0){
    	for(int i=0;i<52;i++){
    		if(i%2==1){
    			std::cout<<' ';
    		}
    		else{
    			if(i==(record[max]*2)){
    				std::cout<<std::endl;
    				break;
    			}
    			if(s[i]>=max){
    				std::cout<<'*';
    			}
    			else{
    				std::cout<<" ";
    			}
    		}
    	}
        std::cout<<std::endl;
    	max--;
    }
    for(int i=0;i<26;i++){
    	char b='A'+i;
    	std::cout<<b<<' ';
    }
    return 0;
}
