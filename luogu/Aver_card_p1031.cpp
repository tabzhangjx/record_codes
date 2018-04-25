#include <iostream>

int n, sum=0;
int cards[100];
int count;

void move1(int i){
	int a=0, b=0, c=0;
	if(cards[i]>sum){
		cards[i+1]+=(cards[i]-sum);
		cards[i]=sum;
	}
	else{
		a=a+sum-cards[i];
		for(int j=1;;j++){
			if(cards[i+j]>=a){
				cards[i+j]-=a;
				cards[i+j-1]+=a;
				break;
			}
			a=a+sum-cards[i];
		}
	}
	count++;
}

void move(int i){
	cards[i+1]=cards[i+1]+cards[i]-sum;
	cards[i]=sum;
	count++;
}

int main(){
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>cards[i];
        sum+=cards[i];
    }
    sum/=n;
    for(int i=0;i<n;i++) while(cards[i]!=sum) move(i);
    std::cout<<count;
    return 0;
}
