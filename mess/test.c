#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){
  double b[16]={0.15,0.12,0.01,0.08,0.09,0.16,0.03,0.01,0.06,0.13,0.07,0.11,0.08,0.01,0.03,0.06};
  double sum=0;
  for(int i=0;i<16;i++){
    sum+=(b[i]-0.075)*(b[i]-0.075);
  }
  printf("%lf", sum/15);
  return 0;
}