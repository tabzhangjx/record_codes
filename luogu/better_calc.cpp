#include <iostream>
#include <stdio.h>

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
    int flag=0;
    if(funcs[*i]=='+'||funcs[*i]=='-'){
        label*=(funcs[*i]-44);
        label*=-1;
        (*i)++;
    }
    while(1){
        if(isdigit(funcs[*i])){
            if(funcs[*i]=='0') flag=1;
            m=m*10+funcs[*i]-'0';
            (*i)++;
        }
        else if(isalpha(funcs[*i])){
            c=funcs[*i];
            if(m!=0||flag) para[count1++]=m*label*mark;
            else para[count1++]=1*mark*label;
            (*i)++;
            return;
        }
        else if(funcs[*i]=='+'||funcs[*i]=='-'||funcs[*i]=='='||funcs[*i]=='\0'){
            ele[count2++]=m*label*mark;
            return;
        }
        else{
            *i=*i+1;
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
        std::cout << c << "=0.000";
    }
    else{
        double t1=ele[0];
        double t2=para[0];
        t1=-t1;
        double mmm=t1/t2;
        printf("%c=%0.3lf",c,mmm);
    }
    std::cout<<std::endl;
    return 0;
}
