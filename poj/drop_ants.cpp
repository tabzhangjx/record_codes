#include<iostream>
using namespace std;
struct ant{
    int position;
    int v;
}ants[100];


int front,rear,last,v0;
int time_=0;

int start(){
    int i,temp;
    int f=0;
    while(1){
        if(ants[rear].position==0||ants[rear].position==100){
            break;
        }
        if(ants[i].position==0){
            front++;
        }
        if(ants[i].position==10){
            last--;
        }
        for(i=front;i<rear;i++){
            if(v0-1>front&&v0+1<=rear&&ants[v0-1].v==1&&ants[v0+1].v==-1&&ants[v0-1].position+1==ants[v0].positiom&&ants[v0+1].position-1==ants[v0].position){
                temo=ants[v0-1],




            }





        }


    }








}
int main(){
    cin>>last;
    for(int i=0;i<last;i++){
        cin>>ants[i].position;
        cin>>ants[i].v;
        if(ants[i].v=0){
            rear=v0=i;
        }
    }
    last--;
        
    for(i=0;i<n;i++){
        



    }



}
