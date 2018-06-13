#include <bits/stdc++.h>

int main(){
    std::string a[3];
    int count=0;
    std::cin>>a[0]>>a[1]>>a[2];
    if(a[0][1]=='X'||a[1][0]=='X'||a[1][2]=='X'||a[2][1]=='X')
    	std::cout<<"xiaoa will win."<<std::endl;
    else
    	std::cout<<"Dont know."<<std::endl;
    for(int i=0;i<3;i++)
    	for(int j=0;j<3;j++)
    		if(a[i][j]!='-')
    			count++;
    std::cout<<count;

    return 0;
}
