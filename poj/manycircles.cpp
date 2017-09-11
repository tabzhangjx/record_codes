//一：跑概率，枚举若干个点，检测所有点都在半径二之内；
//二：

#include <iostream>

struct node{
	int x=0;
	int y=0;
};

int main(){
	int n=0;
	std::cin>>n;
    node point[100000];
    for(int i=0;i<n;i++){
    	std::cin>>point[i].x;
    	std::cin>>point[i].y;
    }
    node mark[100000];
    int marki[4];
    marki[0]=point[0].x;
    int flag=0;
    for(int i=1;i<n;i++){
    	if(point[i].x>marki[0]){
    		marki[0]=point[i].x;
    		flag=i;
    	}
    }
    marki[1]=point[0].x;
    flag=0;
    for(int i=1;i<n;i++){
    	if(point[i].x<marki[1]){
    		marki[1]=point[i].x;
    		flag=i;
    	}
    }
    marki[2]=point[0].y;
    flag=0;
    for(int i=1;i<n;i++){
    	if(point[i].y>marki[2]){
    		marki[2]=point[i].y;
    		flag=i;
    	}
    }
    marki[3]=point[0].y;
    flag=0;
    for(int i=1;i<n;i++){
    	if(point[i].y<marki[3]){
    		marki[3]=point[i].y;
    		flag=i;
    	}
    }
    int x0=(marki[0]+marki[1])/2;
    int y0=(marki[2]+marki[3])/2;
    int total;
    for(int i=0;i<n;i++){
    	total=(point[i].x-x0)*(point[i].x-x0)+(point[i].y-y0)*(point[i].y-y0);
    	if(total>1){
    		std::cout<<"NO";
    		return 0;
    	}
    }
    std::cout<<"yes";
    return 0;
}