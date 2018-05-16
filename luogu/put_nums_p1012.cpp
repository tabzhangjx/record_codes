#include <bits/stdc++.h>

int n;
std::string strs[21];

bool cmp(std::string a, std::string b){
    return a+b>b+a;
}

int main(){
    std::cin>>n;
    for(int i=0;i<n;i++)
    	std::cin>>strs[i];
    std::sort(strs, strs+n, cmp);
    for(int i=0;i<n;i++)
    	std::cout<<strs[i];
}