#include<iostream>

int read(){
	char a;
	std::cin>>a;
	if (a=='-')
		std::cin>>a;
	if (a=='X')
		return 10;
	return a-'0';
}
int  main(){
    char m='-';
    int c[9];
    int d;
    int w=0;
    for(int i=1;i<=9;i++){
    	c[i-1]=read();
        w+=c[i-1]*i;
    }
    d=read();
    if((w%11)==d)
        std::cout<<"Right";
    else {
    	int s = w % 11;
    	if (s != 10){
        	std::cout<<c[0]<<m<<c[1]<<c[2]<<c[3]<<m<<c[4]<<c[5]<<c[6]<<c[7]<<c[8]<<m<<s;
    	}
    	else
    		std::cout<<c[0]<<m<<c[1]<<c[2]<<c[3]<<m<<c[4]<<c[5]<<c[6]<<c[7]<<c[8]<<m<<'X';
    }
    return 0;
}