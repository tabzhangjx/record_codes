#include <iostream>
using namespace std;

int flag=0;

void search(int n,long long final=1,int deep=1){
	if(deep>20){
		return;
	}
	if(final%n==0){
		flag=1;
		cout<<final;
		return;
	}
	else{
		search(n,final*10;deep++);
		if(flag==1){
			return;
		}
		search(n,final*10+1;deep++);
	}
	return;
}


};

int main(){
	int target[200];
	for(int i=0;i<200;i++){
		cin>>target[i];
		if(target[i]==0){
			break;
		}
	}
	for(int i=0;target[i]!=0;i++){
		search(target[i]);
	}
	return 0;
}

