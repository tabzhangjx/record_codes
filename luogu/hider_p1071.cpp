#include <bits/stdc++.h>

std::string a, b, c;
int trans[26], visited[26];

bool check(){
    for(int i=0;i<26;i++){
        if(visited[i]==0)
            return false;
    }
    return true;
}
int main(){
    std::cin>>a>>b>>c;
    for(int i=0;i<26;i++){
        trans[i]=-1;
        visited[i]=0;
    }
    int i=0;
    for(i=0;;i++){
        if(a[i]=='\0'||(trans[a[i]-'A']==-1&&visited[b[i]-'A']==1)){
            std::cout<<"Failed";
            return 0;
        }
        if(trans[a[i]-'A']==(b[i]-'A')&&visited[b[i]-'A']==1)
            continue;
        trans[a[i]-'A']=b[i]-'A';
        visited[b[i]-'A']=1;
        if(check())
            break;
    }
    for(i=0;c[i]!='\0';i++){
        std::cout<<(char)(trans[c[i]-'A']+'A');
    }
    return 0;
}
