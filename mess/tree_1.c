#include <stdio.h>
#define ll long long;

int BTreeCount(struct BTreeNode* BT){
    ll sum=0;
    if(isleaf(BT)) return *BT.num;
    sum+=BTreeCount(*BT.lchild);
    sum+=BTreeCount(*BT.rchild);
    sum+=*BT.num;
    return sum;
}

int BTreeCount(struct BTreeNode* T1, struct BTreeNode* T2){
    if(*T1==NULL&&*T2==NULL) return 1;
    if(*T1.num==**T2.num){
        if(BTreeCount(*T1.lchild, *T2.lchild)&&BTreeCount(*T1.rchild, *T2.rchild)) return 1;
    }
    return 0;
}

int main(){
    ll a=BTreeCount(BT);
    return 0;
}

int count_du(){
    int sum=0;
    for(int i=0;i<N;i++) if(i!=numb-1) sum+=GA[numb][i];
    for(int i=0;i<N;i++) if(i!=numb-1) sum+=GA[i][numb];
    return sum;
}

int count_chudu(){
    int sum=0;
    int mark=-1;
    int label=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) if(i!=numb-1) sum+=GA[i][numb];\
        if(sum>mark){
            mark=sum;
            label=i;
            sum=0;
        }
    }
    return mark;
}
