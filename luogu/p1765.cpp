#include <bits/stdc++.h>

int main(){
	int count, num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	std::string a;
    std::getline(std::cin,a);
    //std::cout<<a;
    for(int i=0;i<a.length();i++){
        if(a[i]>='a'&&a[i]<='z') count+=num[a[i]-'a'];
        if(a[i]==' ') count++;
    }
    std::cout<<count;
    return 0;
}
