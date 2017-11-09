#include <iostream>
#include <algorithm>
using namespace std;



int main(){
	char *str = new char[10003];
	int *record=new int[26];
	for(int i=0;i<10000;i++){
		str[i]=NULL;
	}
	int i;
	for(i=0;i<10000;i++){
		cin>>str[i];
		if(str[i]=='!'){
			break;
		}
	}
	for(int j=0;j<i;j++){
		if(str[i]>='A'&&str[i]<='Z'){
			record[str[i]-'A']++;
		}
	}
	for(int j=0;j<26;j++){
		int comp=
		for(int k=0;k<26;k++){

		}
	}




	delete []str;
	delete []record;
	return 0;
}