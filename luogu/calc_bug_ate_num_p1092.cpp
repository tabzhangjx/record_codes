#include <bits/stdc++.h>

int n, nums[30], visited[30];
char a[3][30];
int b[3][30];
bool flag=false;

void printt(){
    for(int i=0;i<n;i++){
        std::cout<<nums[i];
        if(i<n-1)
            std::cout<<' ';
    }
}

bool cut1(){
    for(int i=n-1;i>=0;i--){
        int a1=nums[a[0][i]-'A'];
        int b=nums[a[1][i]-'A'];
        int c=nums[a[2][i]-'A'];
        if(a1!= -1&&b!=-1&&c!=-1)
            if(!((a1+b==c)||(a1+b+1==c)||(a1+b==c+n)||(a1+b+1==c+n)))
                return true;
    }
    return false;
}

bool check(){
    for(int i=0;i<n;i++){
        if(nums[i]==-1){
            return false;
        }
    }
    return true;
}

bool Check(){
    int inc=0, a1, b, c;
    for(int i=n-1;i>=0;i--){
        a1=nums[a[0][i]-'A'];
        b=nums[a[1][i]-'A'];
        c=nums[a[2][i]-'A'];
        if(c!=(inc+a1+b)%n)
            return false;
        inc=(inc+a1+b)/n;
    }
    if(inc==1)
        return false;
    return true;
}

void dfs(int x){
    if(check()&&Check()){
        flag=true;
        printt();
        return;
    }
    char mark;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<3;j++){
            if(nums[a[j][i]-'A']==-1){
                mark=a[j][i];
                goto label1;
            }
        }
    }
label1:
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            nums[mark-'A']=i;
            if(nums[3]==4)
                i=i;
            if(!cut1())
                dfs(x+1);
            if(flag) return;
            visited[i]=0;
            nums[mark-'A']=-1;
        }
    }
}

int main(){
    std::cin>>n;
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++){
            std::cin>>a[i][j];
            nums[j]=-1;
            visited[j]=0;
        }
    dfs(1);
    return 0;
}
