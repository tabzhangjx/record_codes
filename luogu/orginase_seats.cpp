#include<iostream>

int M,N,K,L,D;
int Ns[2010][4];
int *count1, *count2, *count11, *count22;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int RandPartition(int* a, int p , int q){
	int m=(p+q)/2;
	if(a[p]<a[m])
		swap(&a[p],&a[m]);
	if(a[q]<a[m])
		swap(&a[q],&a[m]);
	if(a[q]<a[p])
		swap(&a[q],&a[p]);
	int key = a[p];
	int i = p;

	for(int j = p+1; j <= q; j++){
		if(a[j] <= key){
			i = i+1;
			if(i != j) swap(&a[i], &a[j]);                 
		}
	}
	swap(&a[i],&a[p]);  
	return i;
}

void QuickSort(int data[], int lo, int hi){
	if (lo<hi){
		int k = RandPartition(data, lo, hi);
		QuickSort(data, lo, k-1);
		QuickSort(data, k+1, hi);
	}
}

int main(){
	std::cin>>M>>N>>K>>L>>D;
	count1=new int[K];
	count11=new int[K];
	count2=new int[L];
	count22=new int[L];
	for(int i=0;i<K;i++) 
		count1[i]=count11[i]=0;
	for(int i=0;i<L;i++) 
		count2[i]=count22[i]=0;
	for(int i=0;i<=D;i++){
		std::cin>>Ns[i][0]>>Ns[i][1]>>Ns[i][2]>>Ns[i][3];
		if(Ns[i][0]==Ns[i][2]){
			count1[Ns[i][0]]++;
			count11[Ns[i][0]]++;
		}
		else{
			count2[Ns[i][1]]++;
			count22[Ns[i][1]]++;
		}
	}

	for(int i=0;i<K;i++){
		for(int j=0;j<K;j++)
			if(count11[j]==count1[i]) std::cout<<j<<' ';
		std::cout<<std::endl;
	}
	for(int i=0;i<L;i++){
		for(int j=0;j<L;j++)
			if(count22[j]==count2[i]) std::cout<<j<<' ';
		std::cout<<std::endl;
	}
	return 0;
}
