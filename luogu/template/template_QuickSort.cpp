#include <iostream>

void swap(int *data, int a, int b){
    int temp=data[a];
    data[a]=data[b];
    data[b]=temp;
}

int Partition(int *data, int lo, int hi){
    int pivot = (lo + hi) / 2;
    pivot = data[lo] >= data[pivot] ? (data[pivot] >= data[hi] ? pivot : (data[lo] >= data[hi] ? hi : lo)) :
    (data[lo] >= data[hi] ? lo : (data[pivot] >= data[hi] ? hi : pivot));
    // pivot \in [lo, hi]
    int val_pivot=data[pivot];
    // val_pivot == data[pivot]
    int i=lo, j=hi;
    while(i<j){
        // val_pivot == data[pivot]
        // i < j
        // i <= pivot && pivot <= j
        while(pivot<j&&val_pivot<=data[j]) j--;
        // pivot == j || val_pivot > data[j]
        // forall x \in (j, hi], val_pivot <= data[x]
        if((i<j)&&val_pivot>=data[j]){
            //  >= data[j]
            swap(data, pivot, j);
            pivot=j;
        }
        while(pivot>i&&val_pivot>=data[i]) i++;
        if((i<j)&&val_pivot<=data[i]){
            swap(data, i, pivot);
            pivot=i;
        }
    }
    data[pivot]=val_pivot;
    return pivot;
}

void QuickSort(int *data, int lo, int hi){
    int j;
    if(hi>lo) j=Partition(data, lo, hi);
    else return;
    QuickSort(data, lo, j-1);
    QuickSort(data, j+1, hi);
    return;
}
int main(){
    int n;
    std::cin>>n;
    int *data=new int[n];
    for(int i=0;i<n;i++) std::cin>>data[i];
    QuickSort(data, 0, n-1);
    for(int i=0;i<n;i++) (i && std::cout << ' '), std::cout<<data[i];
    std::cout<<std::endl;
    return 0;
}


int Partition(int *data, int lo, int hi){
    int pivot = (lo + hi) / 2;
    pivot = data[lo] >= data[pivot] ? (data[pivot] >= data[hi] ? pivot : (data[lo] >= data[hi] ? hi : lo)) :
    (data[lo] >= data[hi] ? lo : (data[pivot] >= data[hi] ? hi : pivot));
    int val_pivot=data[pivot];
    int i=lo, j=hi;
    while(i<j){
        while(i<j&&val_pivot<=data[j]) j--;
        while(j>i&&val_pivot>=data[i]) i++;
        if(i<j) swap(data, i, j);
    }
    return i;
}


void QuickSort(int *data, int lo, int hi){
    if (lo >= hi) return;
    int i=lo, j=hi;
    int x = data[(i + j) / 2];
    while (i <= j) {
        while (x > data[i]) i++;
        while (x < data[j]) j--;
        if (i <= j) {
            swap(data, i, j);
            i++;
            j--;
        }
    }
    if(lo<j) QuickSort(data, lo, j);
    if(i<hi) QuickSort(data, i, hi);
}
