#include <bits/stdc++.h>

int n, w, record[20], count=0, count1=0, mark=-1;
char start;
std::string str[20];
int checks[20][20];

int check(int i, int j){
	int t, label=1;
	int c1=str[i].length();
	int c2=str[j].length();
	for(t=1;t<c1&&t<c2;t++){
		for(int k=0;k<t;k++){
			if(!(str[i][c1-t+k]==str[j][k])){
				label=0;
				break;
			}
		}
		if(label==0)
			label=1;
		else
			return c2-t;
	}
	return 0;
}

void dps(int i){
	for(int j=0;j<n;j++){
		if(checks[i][j]!=0&&record[j]<2){
			count+=checks[i][j];
			if(count>mark) mark=count;
			record[j]++;
			dps(j);
			count-=checks[i][j];
			record[j]--;
		}
	}
	return;
}

int main(){
	std::cin>>n;
    for(int i=0;i<n;i++){
    	std::cin>>str[i];
    	record[i]=0;
    }
    std::cin>>start;
	//str[0]="sgergwqefw";
	//str[1]="sgergwqefw";
	//if(check(0, 1))
		//std::cout<<'1';
	//else
		//std::cout<<'0';
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) checks[i][j]=check(i, j);
    for(int i=0;i<n;i++)
    	if(start==str[i][0]){
    		count=str[i].length();
    		if(count>mark) mark=count;
    		record[i]++;
    		dps(i);
    		record[i]--;
    	}
    std::cout<<mark;
    return 0;
}
