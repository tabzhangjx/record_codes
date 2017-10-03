#include <iostream>
using namespace std;

class activity{
public:
	char name[10];
	int start=0;
	int end=0;
	acticity operator=(const activity &a)const;
}

inline activity activity::operator=(const activity &a){
	for(int i=0;i<n;i++){
		this.name[i]=a.name[i];
	}
	this.start=a.start;
	this.end=a.end;
}
void reorder(activity* a,int n){

}
int main(){
	int n=0;
	cin>>n;
	activity* A=new activity[n];
	reorder(A);//reorder by the end time which are from low to hiah;
	cout<<"1: "<<A[0].name<<endl;
	int j=2;
	acticity mark=A[0];
	for(int i=1;i<n;i++){
		if(A[i].start>=mark.end){
			cout<<J<<": "<<A[i].name<<endl;
			mark=A[i];
			j++;
		}
	}
	return 0;
}