#include <bits/stdc++.h>

char s[1000],num[10][8] = {"|-| |-|","  |   |", " -|-|- ", " -|- -|", "| |-  |", "|- - -|", "|- -|-|", " -|   |", "|-|-|-|", "|-|- -|"};
int size,ls;
int main()
{
    scanf("%d%s",&size,s);ls=strlen(s);
    for(int row=1;row<=5;!(row&1)?:puts(""),row++)
        if(row&1){
            for(int i=0;i<ls;i++){
                putchar(' ');
                for(int j=0;j<size;j++)printf("%c",num[s[i]-'0'][row]);
                printf("  ");
            }
        }
        else if(row==2){
            for(int k=0;k<size;k++,puts("")){
                for(int i=0;i<ls;i++){
                    printf("%c",num[s[i]-'0'][0]);
                    for(int j=0;j<size;j++)putchar(' ');
                    printf("%c ",num[s[i]-'0'][2]);
                }
            }
        }
        else{
            for(int k=0;k<size;k++,puts("")){
                for(int i=0;i<ls;i++){
                    printf("%c",num[s[i]-'0'][4]);
                    for(int j=0;j<size;j++)putchar(' ');
                    printf("%c ",num[s[i]-'0'][6]);
                }
            }
        }
return 0;
}
