#include <iostream>
using namespace std;

struct object{
	int W;
	int V;
}

int main(){
	int n=0;
	cin>>n;
	int C=0;
	cin>>C;//背包总容量
	object* objects=new int[n];
	for(int i=0;i<n;i++){
		cin>>objects[i].W;
		cin>>objects[i].V;
	}
	quicksort(objects,1,n,compear);//O(nlogn)
	int sumW=0;
	int sumV=0;
	for(int i=0;sumW<=C;i++){
		sumW+=objects[i].W;
		sumV+=objects[i].V;
	}
	cout<<sumW<<" "<<sumV;
	return 0;
}
