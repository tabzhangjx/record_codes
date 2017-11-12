#include <iostream>
using namespace std;

int C;
int n;

struct object{
	float c;
	float V;
};

object *objects=new object[n];

int main(){
	cin>>C>>n;
	for(int i=0;i<n;i++){
		cin>>objects[i].c>>objects[i].V;
	}
	



	return 0;
}