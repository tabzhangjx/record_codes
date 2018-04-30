#include <iostream>
#include <stdio.h>
#include <algorithm>

struct student{
    char name[22];
    int score;
    int class_score;
    bool staff;
    bool western;
    int paper;
    int schoolarship;
    int order;
}ss[100];

bool cmp(student a, student b){
	if(a.schoolarship!=b.schoolarship)return a.schoolarship>b.schoolarship;//?
    else return a.order<b.order;
}

int main(){
    int N;
    std::cin>>N;
    for(int i=0;i<N;i++){
        ss[i].order=i;
        scanf("%s %d", ss[i].name, &ss[i].score);
        std::cin>>ss[i].class_score;
        char temp;
        std::cin>>temp;
        ss[i].staff=(temp=='Y'?1:0);
        std::cin>>temp;
        ss[i].western=(temp=='Y'?1:0);
        std::cin>>ss[i].paper;
        ss[i].schoolarship=0;
        if(ss[i].score>80&&ss[i].paper>=1) ss[i].schoolarship+=8000;
        if(ss[i].class_score>80&&ss[i].score>85) ss[i].schoolarship+=4000;
        if(ss[i].score>90) ss[i].schoolarship+=2000;
        if(ss[i].class_score>80&&ss[i].staff) ss[i].schoolarship+=850;
        if(ss[i].score>85&&ss[i].western) ss[i].schoolarship+=1000;
    }
    std::sort(ss, ss+N, cmp);
    int sum=0;
    for(int i=0;i<N;i++) sum+=ss[i].schoolarship;
    std::cout<<ss[0].name<<std::endl<<ss[0].schoolarship<<std::endl<<sum;
    return 0;
}
