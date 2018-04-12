#include <iostream>

int para[100];
int ele[100];
int count1=0;
int count2=0;
char funcs[1000];
int mark=1;
char c;

void read(int *i){
   int m=0;
   int label=1;
   if(funcs[*i]=='+'||funcs[*i]=='-'){
   		label*=(funcs[*i]-44);
   		label*=-1;
   		i++;
   }
   while(1){
        if(isdigit(funcs[*i])){
        	m=m*10+funcs[*i]-'0';
        	i++;
        }
        else if(isalpha(funcs[*i])){
        	c=funcs[*i];
        	if(m!=0) para[++count1]=m*label*mark;
        	else para[++count1]=1*mark;
        	i++;
        	return;
        }
        else if(funcs[*i]=='+'||funcs[*i]=='-'||funcs[*i]=='='){
        	ele[++count2]=m*label*mark;
        	i++;
        	return;
        }
    }
	return;
}

int main(){
    std::cin.getline(funcs,1000);
    int i=0;
    while(funcs[i]!='\0'){
    	if(funcs[i]=='='){
    		mark=-1;
    		i++;
    	}
        read(&i);
    }
    for(i=1;i<count1;i++){
    	para[0]+=para[i];
    }
    for(i=1;i<count2;i++){
    	ele[0]+=ele[i];
    }
    if(ele[0]==0){
    	std::cout<<"0.000";
    }
    else{
    	double mmm=ele[0]/para[i];
    	printf("%c=%0.3lf",c,mmm);
    }
    return 0;
}