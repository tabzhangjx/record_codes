#include <iostream>
using namespace std;

struct object{
	int i=0;
	int w=0;
}

int main(){
	int C=0;
	int n=0;
	cin>>C>>n;
	int* objects=new object[n];
	for(int i=0;i<n;i++){
		cin>>objects[i].i>>objects[i].w;
	}
	Quicksort(objects,1,n);
	int comp=0;
	int recorde=0;
	for(int i=0;i<n;i++){
		if(comp+=objects[i].w<=C){
			comp+=objects[i].w;
			recorde++;
			cout<<objects[i].i<<endl;
		}
		else{
			break;
		}
	}
	cout<<"final num: "<<recorde;
	return 0;
}