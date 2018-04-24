#include<iostream>
#include<cmath>

int nums=0;
int list[2][100001];
int main(){

	int expec, sales, over;
	std::cin>>expec;
	int cost, num_cost;
	std::cin>>cost>>num_cost;
	std::cin>>list[0][nums]>>list[1][nums];
	while(list[0][nums]!=-1&&list[1][nums]!=-1){
		if(expec==list[0][nums]) sales=list[1][nums];
		nums++;
		std::cin>>list[0][nums]>>list[1][nums];	
	}
	std::cin>>over;
	double min=-99999, max=99999, temp;
	for(int i=0;i<nums;i++){
		if(sales>list[1][nums]){
			temp=((double)((list[0][i]-cost)*list[1][i])+(double)
				((cost-expec)*sales))/(sales-list[1][i]);
			if(temp>min) min=temp;
		}
		else if(sales<list[1][nums]){
			temp=((double)((list[0][i]-cost)*list[1][i])+(double)
				((cost-expec)*sales))/(sales-list[1][i]);
			if(temp<max) max=temp;
		}
	}
	if(min<0) min=int(min);
	else if(min!=int(min)) min=(int)(min)+1;
	if(max<0) min=int(min)-1;
	else if(max!=int(max)) max=(int)(max);
	
	if(abs(min)<abs(max)) std::cout<<(int)(abs(min));
	else std::cout<<(int)(abs(max));

	return 0;
}
