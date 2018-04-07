#include <iostream>

int mark=0;
int label[10];

bool to_mark(int n){
    int temp;
    for(int i=0;i<3;i++){
        temp=n%10;
        n/=10;
        if(label[temp]==0) return false;
        else label[temp]=1;
    }
    return true;
}
void search(int n, int a, int b, int c){
    for(int i=0;i<10;i++) label[i]=0;
    int p=n*b/a;
    int q=n*c/a;
    if(q>987) return;
    if(to_mark(a)&&to_mark(b)&&to_mark(c)){
        mark=1;
        std::cout<<a<<' '<<b<<' '<<c<<std::endl;
    }
}
int main(){
    int a, b, c;
    std::cin>>a>>b>>c;
    for(int i=123;i<=321;i++){
        if(i%a==0){
            search(i, a, b, c);
        }
    }
    if(mark==0) std::cout<<"No!!!";
    return 0;
}
