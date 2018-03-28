#include <iostream>

int label;
int m[20], n[20], count1, count2;
int read(){
    char a;
    std::cin>>a;
    if('0'<=a&&a<='9'){
        return a-'0'+1;
    }
    else if(a=='.'){
        label=1;
    }
    else if(a=='/'){
        label=2;
    }
    else if(a=='%'){
        label=3;
    }
    return 0;
}

void cin_1(){
    while(label==0){
        int temp=read();
        if(label==0){
            m[count1]=temp;
            count1++;
        }
        else if(label==1||label=2){
            cin_2();
            break;
        }
        else{
            break;
        }

    }


}
int main(){
    label=0;
    count1=0;
    count2=0;
    cin_1();


}
