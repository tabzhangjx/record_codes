#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    char str[10];
    int comp[10];
    int flag=0;
    for(int i=123;i<=329;i++){
        a=i;
        b=2*i;
        c=3*i;
        str[0]=(int)(a/100)+'0';
        str[1]=(int)((int)(a-(int)(a/100)*100)/10)+'0';
        str[2]=a-(str[0]-'0')*100-(str[1]-'0')*10+'0';
        str[3]=(int)(b/100)+'0';
        str[4]=(int)((int)(b-(int)(b/100)*100)/10)+'0';
        str[5]=b-(str[3]-'0')*100-(str[4]-'0')*10+'0';
        str[6]=(int)(c/100)+'0';
        str[7]=(int)((int)(c-(int)(c/100)*100)/10)+'0';
        str[8]=c-(str[6]-'0')*100-(str[7]-'0')*10+'0';
        str[9]='\0';
        for(int j=0;j<9;j++){
            comp[j]=0;
        }
        for(int j=0;j<9;j++){
            if(str[j]=='0'){
                flag=1;
                break;
            }
            if(comp[str[j]-'0'-1]==0){
                comp[str[j]-'0'-1]=1;
            }
            else{
                flag=1;
                break;
            }
        }
        if(flag==1){
            flag=0;
            continue;
        }
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}
