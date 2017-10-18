#include <iostream>
using namespace std;

int n=0;
int minimuntime=inf;
int* recordorder=new int[n];
bool flag=false;
struct object{
	int j1;
	int j2;
	bool b;
}

bool trackback(object* a,int* b,int i){
	if(i==n){
		
	}
	for(int k=0;k<n;k++){
		if(!a[k].b||)
	}

}
int main(){
	cin>>n;
	object* objects=new object[n];
	int* order=new int[n];
	for(int i=0;i<n;i++){
		cin>>objects[i].j1;
		cin>>objects[i].j2;
		objects[i].b=false;
		order[i]=NULL;
	}



	return 0;
}