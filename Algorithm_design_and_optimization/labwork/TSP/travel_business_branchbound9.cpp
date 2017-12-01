#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;
































int n;
class heapnode{
public:
	int lc,cc,rc;
	int s;
	int* x;
	heapnode(int a,int b,int c,int* e);
	~heapnode(){};
	int compareto(heapnode x);
}

inline heapnode::heapnode(int a,int b,int c,int* e){
	lc=a;
	cc=b;
	s=c;
	x=e;
}

inline int heapnode::compareto(heapnode x){
	int xlc=x.lc;
	if(lc<xlc){
		return -1;
	}
	else if(lc==xlc){
		return 0;
	}
	else{
		return 1;
	}
}

int TSP(int* v){
	
}
int main(){
	cin>>n;



	return 0;
}







