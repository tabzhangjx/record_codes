
#include <iostream>
using namespace std;

int 
int searchlabel(int* a,int n,int k){
	

}

int sortbylabel(int* a,int lable,int n){
	int tem=a[label];
	int mark=label;
	int flag=0;
	int record=0;
	for(int i=0,j=n;i!=j;){
		if(flag==0){
			if(i<mark){
				flag=1;
				continue;
			}
			if(a[i]<=tem){
				i++;
			}
			else{
				a[mark]=a[i];
				mark=i;
				i++;
				record=i;
				flag=1;
			}
		}
		else{
			if(j>mark){
				flag=0;
				continue;
			}
			if(a[i]>=tem){
				j--;
			}
			else{
				a[mark]=a[j];
				mark=j;
				j--;
				record=j;
				flag=0;
			}
		}
	}
	return record;
}

int sortfew(int* a,int m,int n){
	int min;
	int mark=0;
	for(int k=0;k<(n-m);k++){
		min=INT_MAX;
		for(int i=m+k;i<n;i++){
			if(p[i]<min){
				min=p[i];
				mark=i;
			}
		}
		p[mark]=p[m+k];
		p[m+k]=min;
	}
	return m+(n-m+1)/2;
}

int main(){
	int n,k;
	cin>>n>>k;
	int* line=new int[n];
	for(int i=0;i<n;i++){
		cin>>line[n];
	}




	return 0;
}