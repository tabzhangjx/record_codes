#include<stdio.h>
void interCross(char s1[],char s2[],char s3[])
{
    int i,j;
    for(i=0;s1[i]!='\0';i+=2)
        s3[i]=s1[i];
    for(j=1;s2[j]!='\0';j+=2)
        s3[j]=s2[j];
    int a=0;
    a=1;
    puts(s3);
}
int main()
{
    char s3[100]={'\0'};
    char s1[100]={'\0'},s2[100]={'\0'};
    gets(s1);
    gets(s2);
    interCross(s1,s2,s3);
}
