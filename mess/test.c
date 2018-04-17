#include<stdio.h>
int main()
{
  int n,i,j;
  int aaa[8][8];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      scanf("%d",&aaa[i][j]);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%-5d",aaa[j][i]);
    printf("\n");
  }
 return 0;
}
