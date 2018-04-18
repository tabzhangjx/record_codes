#include <stdio.h>

int main(){
    int n, m;
    char temp;
    int last=0;
    scanf("%d%d",&n,&m);
    int p[100001];
    char jobs[100001][11];
    int orders[100001][2];
    for(int i=0;i<n;i++){
        scanf("%d%c",&p[i],&temp);
        gets(jobs[i]+1);
        jobs[i][0]=temp;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&orders[i][0],&orders[i][1]);
        if(orders[i][0]==p[last])
            last=(last+n-orders[i][1])%n;
        else
            last=(last+orders[i][1])%n;
    }
    printf("%s",jobs[last]);
    return 0;
}