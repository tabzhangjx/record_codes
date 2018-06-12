#include <bits/stdc++.h>


int main(){
    int n, count=0;
    std::string s;
    std::cin>>n>>s;
    char a='V', b='K';
    for(int i=0;i<n-1;i++){
        if(s[i]==a&&s[i+1]==b){
            count++;
            s[i]='0';
            s[i+1]='0';
        }
    }
    for(int i=0;i<n;i++){
        if(i<n-1&&s[i]=='V'){
            if(s[i+1]!='0'){
                count++;
                break;
            }
        }
        if(i>0&&s[i]=='K'){
            if(s[i-1]!='0'){
                count++;
                break;
            }
        }
    }
    std::cout<<count;
    return 0;
}
