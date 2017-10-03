#include <iostream>

using namespace std;

struct ticket{
	char from[10];
	char to[10];
};
struct recordinfo{
	char place[10];
}
bool check(char*a,recordinfo*b){
	for(int i=0;;i++){
		if(a[i]!=b.place[i]){
			return false;
		}
		if(a[i]==NULL&&b.place[i]==NULL){
			refturn true;
		}
	}

}

ticket[20];
recordinfo record[20];
int flightmap[20][20];
int main(){
	int n=0;
	cin>>n;
	
	
	for(int i=0;i<n;i++){
		cin>>ticket[i].from;
		cin>>ticket[i].to;
	}
	int calc=0;
	
	for(int i=0;i<n;i++){

	}
	for(int i=0;i<n;i++){

	}
	return 0;
}