#include <stdio.h>
#include <iostream>

void score_21(char *str, int score){
    int i=0;
    int count1=0, count2=0, count3=0;
    while(str[i]!='E'){
        if(str[i]=='W'){
            count1++;
            count3++;
        }
        else if(str[i]=='L'){
            count2++;
            count3--;
        }
        if((count1>=score||count2>=score)&&(count3>=2||count3<=-2)){
            printf("%d:%d\n",count1,count2);
            count1=count2=count3=0;
        }
        i++;
    }
    printf("%d:%d\n",count1,count2);
}

int main(){
    char str[500010];
    scanf("%c",&str[0]);
    for(int i=0;str[i]!='E';i++) scanf("%c",&str[i+1]);
    score_21(str,11);
    printf("\n");
    score_21(str,21);
    return 0;
}