#include<iostream> 

using namespace std;

#define N 1005
struct times{
	int y,M,d,h,m,s;
}
int read(times t){
	char a;
	cin>>a;
	if(a==EOF){
		return 0;
	}
	int b;
	b=a-'0';
	cin>>a;
	b=b*10+a-'0';
	t.h=b;
	cin>>t.m>>t.s>>t.y>>t.M>>t.d;
	return 1;
}

int record(){
	
}
int print(){

	return 0;
}

int main(){
	times ts[N];
	int count=0;
	while(read(ts[count])){
		count++;
	}
	for(int i=0;i<=count;i++){
		record();
	}

	return 0;
}