#include <iostream>

int primer[46]={2,3,5,7,11,101,131,151,181,191,313,353,373,383,727,757,787,797,919,929,10301,10501,10601,11311,11411,12421,
	12721,12821,13331,13831,13931,14341,14741,15451,15551,16061,16361,16561,16661,17471,17971,18181,18481,19391,19891,19991};

int nums[3];
bool search(int a, int r){
	for(int i=0;i<46;i++){
		if(r==3){
			if(a==i){
				nums[2]=i;
				return true;
			}
		}
		else{
			if(search(a-i, r+1)){
				nums[r-1]=i;
				return true;
			}
		}
	}
	return false;
}

int main(){
    int n;
    std::cin>>n;
    search(n, 1);
    std::cout<<nums[0]<<' '<<nums[1]<<' '<<nums[2];
    return 0;
}