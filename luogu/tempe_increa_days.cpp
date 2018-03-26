#include <iostream>

#define N 10000010

int partition(int data[],int lo,int hi){
	int key=data[hi];
	int i=lo-1;
 	for(int j=lo;j<hi;j++){
 		if(data[j]<=key){
   			i=i+1;
   			swap(&data[i],&data[j]);
  		}
 	}
 	swap(&data[i+1],&data[hi]);
 	return i+1;
}

void swap(int *a,int *b)
{
 	int temp=*a;
 	*a=*b;
 	*b=temp;
}

void QuickSort(int data[], int lo, int hi)
{
    if (lo<hi)
    {
        int k = partition(data, lo, hi);
        QuickSort(data, lo, k-1);
        QuickSort(data, k+1, hi);
    }
}

int main(){
    int N;
    std::cin>>n;
    int temps[N];
    for(int i=0;i<n;i++) std::cin>>temps[i];
    QuickSort(temps, 0, n-1);
	for(int i=0;i<n;i++){
		
	}



    return 0;
}
