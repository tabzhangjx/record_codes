#include <iostream>
using namespace std;
int main(){
	int T;
	cin>>T;
	char luvletter[10]={"luvletter"};
	char check[100010]={'\0'};
	for(int i=0;i<T;i++){
		int NUM=0;
		cin.getline(check,100001);
        int j=0;
		while(j!=-1){
			for(int k=0;check[k]!='\0';k++){
				if(check[k]==luvletter[j]&&j==8){
					NUM=NUM+1;
					j=0;
				}
				else if(check[k]==luvletter[j]&&j!=8){
					j++;
				}
				else if(check[k]=='\0'){
					j=-1;
				}
				cout<<NUM<<endl;
			}
		}
	}
	return 0;
}