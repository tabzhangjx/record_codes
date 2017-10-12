#include <iostream>
using namespace std;

struct object{
	int t=0;
	int V=0;
	int W=0;
	int Ave=0;
}

int main(){
	int C=0;
	cin>>C;
	int n=0;
	cin>>n;
	object* objects=new object[n];
	for(int i=0;i<n;i++){
		cin>>objects[i].t;
		cin>>objects[i].V;
		cin>>objects[i].W;
		objects[i].Ave=objects[i].V/objects[i].W;
	}
	quicksort(objects,1,n);
	float sum=0;
	int comp=0;
	for(int i=0;i<n;i++){
		if(comp+objects[i].W<C){
			comp+=objects[i].W;
			sum+=objects[i].V;
			cout<<objects[i].t<<endl;
		}
		else{
			sum+=objects[i].V*(C-comp)/objects[i].W;
			cout<<"not complete"<<objects[i].t<<endl;
		}
	}
	cout<<"sum: "<<sum;
	delete []objects;
	return 0;
}