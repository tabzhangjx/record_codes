#include <bits/stdc++.h>

int n, m;
std::string a;

bool check(int i){
	for(int j=i+1;j<=m-1;j++){
		if(a[j]!='0'){
			return false;
		}
	}
	return true;
}

int main(){
    std::cin>>n>>a;
    m=a.length();
    for(int i=0;i<m-1;i++){
        if(a[i]!='0'){
        	std::cout<<a[i]<<"*"<<n<<"^"<<m-i-1;
        	if(check(i))
        		break;
        	std::cout<<"+";
        }
    }

    if(a[m-1]!='0'){
        std::cout<<a[m-1]<<"*"<<n<<"^"<<0;
    }
    return 0;
}
