#include <bits/stdc++.h>
using namespace std;

struct ant
{
    int x;
    int d;
};
bool cmp(ant a,ant b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int k=0;
        ant a[105],b[105];
        int count_l=0,count_r=0,flag=0; 
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>a[i].d;
        }
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        { 
            if(!flag&&a[i].d==1)
            {
                count_l++;
                b[k++]=a[i];
            }
            if(a[i].d==0)
            {
                flag=1;
            }
            if(flag&&a[i].d==-1)
            {
                count_r++;
                b[k++]=a[i];
            }
        }

    //  cout<<count_l<<" "<<count_r<<endl;
        if(count_l==count_r) cout<<"Cannot fall!"<<endl;
        else if(count_l>count_r)
            cout<<100-b[count_l-count_r-1].x<<endl; 
        else
            cout<<b[2*count_l].x<<endl; 
    }
    return 0;
}