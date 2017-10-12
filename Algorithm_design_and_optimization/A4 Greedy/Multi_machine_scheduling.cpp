#include <iostream>
using namespace std;

int findmin(int* t,int m){
	int record=inf;
	for(int i=0;i<m;i++){
		if(record>t[i]&&t[i]>0){
			record=t[m];
		}
	}
	return record;
}

bool judge(int* a,int m){
	for(int i=0;i<m;i++){
		if(a[i]>0){
			return true;
		}
	}
	return false;
}

int main(){
	int n,m;
	cin>>n,m;
	int* time=new int[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>time[i];
	}
	quicksort(a,1,n);
	int* machine=new int[m];
	for(int i=0;i<m;i++){
		machine[i]=a[i];
	}
	for(int i=m;judge(machine,m);i++){
		k=findmin(machine,m);
		for(int j=0;j<m;j++){
			machine[i]-=machine[k];
		}
		sum+=machine[k];
		machine[k]=a[i];
	}
	cout<<sum;
	return 0;
}