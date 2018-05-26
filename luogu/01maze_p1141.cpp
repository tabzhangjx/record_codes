#include <bits/stdc++.h>
using namespace std;

int n, m, countnum, Qa, Qb;
int maze[1002][1002];
bool visited[1002][1002];


typedef pair<int, int> pa;
queue<pa> points;

void clean(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            visited[i][j]=0;
    countnum=0;
}

void BFS(){
    pa t, m;
    t=points.front();
    points.pop();
    if((maze[t.first+1][t.second]==(1-maze[t.first][t.second]))&&visited[t.first+1][t.second]==0){
        m=make_pair(t.first+1, t.second);
        points.push(m);
        visited[m.first][m.second]=1;
        countnum++;
    }
    if((maze[t.first-1][t.second]==(1-maze[t.first][t.second]))&&visited[t.first-1][t.second]==0){
        m=make_pair(t.first-1, t.second);
        points.push(m);
        visited[m.first][m.second]=1;
        countnum++;
    }
    if((maze[t.first][t.second+1]==(1-maze[t.first][t.second]))&&visited[t.first][t.second+1]==0){
        m=make_pair(t.first, t.second+1);
        points.push(m);
        visited[m.first][m.second]=1;
        countnum++;
    }
    if((maze[t.first][t.second-1]==(1-maze[t.first][t.second]))&&visited[t.first][t.second-1]==0){
        m=make_pair(t.first, t.second-1);
        points.push(m);
        visited[m.first][m.second]=1;
        countnum++;
    }
}
int main(){
    pa t;
    cin>>n>>m;
    char temp;
    for(int i=0;i<=n+1;i++){
        maze[i][0]=2;
        maze[i][n+1]=2;
        maze[0][i]=2;
        maze[n+1][i]=2;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>temp;
            maze[i][j]=temp-'0';
        }
    for(int i=0;i<m;i++){
        cin>>Qa>>Qb;
        t=make_pair(Qa, Qb);
        points.push(t);
        visited[t.first][t.second]=1;
        countnum++;
        while(!points.empty())
            BFS();
        cout<<countnum<<endl;;
        clean();
    }
    return 0;
}
