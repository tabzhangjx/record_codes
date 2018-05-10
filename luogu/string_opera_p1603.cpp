#include <bits/stdc++.h>

char a[27][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven",
"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty","a","both",
"another","first","second","third"};
int b[30]={0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};

int match(std::string &x){
	for(int i=0;i<27;i++){
		if(x==a[i])
			return b[i];
	}
	return 0;
}

int main(){
	std::string a;
	int i=0, data[7];
	for(int i=0;i<6;i++){
		std::cin >> a;
		a[0] = tolower(a[0]);
		data[i]=match(a);
	}
	std::sort(data, data+6);
	long long c=0;
	for(int i=0;i<6;i++)
        c=c*100+data[i];
    std::cout<<c<<std::endl;
    return 0;
}
