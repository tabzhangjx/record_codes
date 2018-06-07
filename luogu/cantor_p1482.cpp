#include <iostream>

int main(){
    std::string a, b;
    std::cin>>a>>b;
    int a1[2]={0,0}, b1[2]={0,0};
    for(int i=0,k=0;a[i]!='\0';i++){
        if(a[i]=='/'){
            k++;
        }
        else{
            a1[k]=a1[k]*10+a[i]-'0';
        }
    }
    for(int i=0,k=0;b[i]!='\0';i++){
        if(b[i]=='/'){
            k++;
        }
        else{
            b1[k]=b1[k]*10+b[i]-'0';
        }
    }
    a1[0]*=b1[0];
    a1[1]*=b1[1];
    for(int i=a1[0];i>=1;i--){
        if(a1[0]%i==0&&a1[1]%i==0){
            a1[0]/=i;
            a1[1]/=i;
        }
    }
    std::cout<<a1[1]<<' '<<a1[0];
    return 0;
}
