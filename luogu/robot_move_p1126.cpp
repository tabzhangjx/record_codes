#include <bits/stdc++.h>

using namespace std;

struct dire{
    int x_, y_;
}dires[4]={{-1,0},{1,0},{0,1},{0,-1}};
enum direc{left=0, right=1, up=2, down=3};
struct robot_state{
    int x, y;
    direc dir1;
    int steps=0;
}sts, ste;
queue<robot_state> qa;
int N, M, plat[51][51], ans=99999999;
char D;

void BFS_step(){
    
    
}

void BFS_dire(){
    
    
}

int main(){
    int temp;
    cin>>N>>M;
    for(int i=0;i<=N;i++) for(int j=0;j<=M;j++) plat[i][j]=1;
    for(int i=1;i<N;i++) for(int j=1;j<M;j++) plat[i][j]=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>temp;
            if(temp==1){
                plat[i][j]=1;
                plat[i+1][j]=1;
                plat[i][j+1]=1;
                plat[i+1][j+1]=1;
            }
        }
    }
    cin>>sts.x>>sts.y>>ste.x>>ste.y>>D;
    if(D=='E') sts.dir1=direc(1);
    else if(D=='W') sts.dir1=direc(0);
    else if(D=='N') sts.dir1=direc(2);
    else if(D=='S') sts.dir1=direc(3);
    return 0;
}

