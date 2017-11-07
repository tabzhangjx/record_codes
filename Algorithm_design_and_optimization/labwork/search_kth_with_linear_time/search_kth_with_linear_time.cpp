
#include <iostream>
using namespace std;

int searchlabel(float* a,int n,int k){
	int i=(n-4)/5;
	for(int j=0;j<=i;j++){
		int t=sortfew(a,i*5,i*5+4);
		float temp=a[i];
		a[i]=a[t];
		a[t]=temp;
	}
	int t=searchlabel(a,0,i);
	int label=sortbylabel(a,t,n);
	if(label==k){
		return line[label];
	}
	else if(label>k){
		return line[searchlabel(line,n-t-1,k)];
	}
	else{
		return line[searchlabel(line,t,k-t-1)];
	}
}

int sortbylabel(float* a,int lable,int n){
	float tem=a[label];
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

int sortfew(float* a,int m,int n){
	float min;
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
	float* line=new float[n];
	for(int i=0;i<n;i++){
		cin>>line[n];
	}
	int m=(n+1)/2;
	if(n%2==1){
		cout<<line[searchlabel(line,n,m)]<<endl;
	}
	else{
		float w=(searchlabel(line,n,m)+searchlabel(line,n,m+1))/2;
		cout<<w<<endl;
	}
	
	
	return 0;
}