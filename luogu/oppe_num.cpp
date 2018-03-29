#include <iostream>

int label;
int record;

void oppo_print(char *a, int start, int end){
    int length=end-start+1;
    if(length==0){
        std::cout<<'0';
        return;
    }
    int label1=0;
    for(int i=end;i>=start;i--){
        if(a[i]!='0'){
            std::cout<<a[i];
            label1=1;
        }
        else if(a[i]=='0'&&label1==1) std::cout<<a[i];
    }
    if(label1==0) std::cout<<'0';
}

void other_print(char *a, int start, int end){
    for(int i=start;i<=end;i++){
        if(a[i]=='0'){
            start++;
        }
        else break;
    }
    int length=end-start+1;
    if(length==0){
        std::cout<<'0';
        return;
    }
    int label1=0;
    for(int i=end;i>=start;i--){
        if(a[i]!='0'){
            std::cout<<a[i];
            label1=1;
        }
        else if(a[i]=='0'&&label1==1) std::cout<<a[i];
    }
    if(label1==0) std::cout<<'0';
}

int main(){
    char num[30];
    std::cin.getline(num,30);
    label=-1;
    int i=0;
    while(num[i]!='\0'){
        if(num[i]=='.'){
            label=1;
            record=i;
        }
        else if(num[i]=='/'){
            label=3;
            record=i;
        }
        else if(num[i]=='%'){
            label=2;
        }
        i++;
    }
    if(label==-1){
        oppo_print(num, 0, i-1);
    }
    else if(label==2){
        oppo_print(num, 0, i-2);
        std::cout<<'%';
    }
    else if(label==3){
        oppo_print(num, 0, record-1);
        std::cout<<num[record];
        oppo_print(num, record+1, i-1);
    }
    else if(label==1){
        oppo_print(num, 0, record-1);
        std::cout<<num[record];
        other_print(num, record+1, i-1);
    }   
    return 0;
}