//两艘船，sum（w_i）<= c1+c2;

#include<iostream>
using namespace std;

struct object{
	int W=0;
	bool b=NULL;
}

int n=0;
int c1=0;
int c2=0;

bool backtrack(object* objects,int* w1,int* w2,int i){
	if(i==n){
		if((w1+objects[i-1].W)<=c1){
			w1+=objects[i-1].W;
			objects[i].b=0;
			return true;
		}
		else if((w2+objects[i-1].W)<=c2){
			w2+=objects[i-1].W;
			objects[i].b=1;
			return true;
		}
		else{
			return false;
		}
	}
	if((w1+objects[i-1].W)<=c1){
		if(backtrack(objects,w1+=objects[i-1].W,w2,i+1)){
			w1+=objects[i-1].W;
			objects[i].b=0;
			return true;
		}
	}
	else if((w2+objects[i-1].W)<=c2){
		if(backtrack(objects,w1,w2+=objects[i-1].W,i+1)){
			w2+=objects[i-1].W;
			objects[i].b=1;
			return true;
		}
	}
	else{
		return false;
	}
}

int main(){
	cin>>n>>c1>>c2;
	object* objects=new object[n];
	for(int i=0;i<n;i++){
		cin>>objects[i].W;
	}
	int* w1,w2;
	*w1=*w2=0;
	if(backtrack(objects,w1,w2,1)){
		cout<<"c1: "<<c1<<",w1: "<<*w1<<endl;
		for(int i=0;i<n;i++){
			if(objects[i].b==0){
				cout<<"order: "<<i+1<<",weight: "<<objects[i].W;
			}
		}
		cout<<"c2: "<<c2<<",w2: "<<*w2<<endl;
		for(int i=0;i<n;i++){
			if(objects[i].b==1){
				cout<<"order: "<<i+1<<",weight: "<<objects[i].W;
			}
		}
	}
	else{
		cout<<"fail to find a solution;"
	}

	return 0;
}