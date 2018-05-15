#include<stdio.h>
#include<string.h>

double fun(int a[], int n, int *max, int *min){
  int i, sum = 0;
  *max = 0;
  *min = 0;
  int max1 = a[0];
  int min1 = a[0];
  for (i = 0; i < n; i++){
    sum = sum + a[i];
    if (a[i] > max1) { 
      *max = i; 
      max1 = a[i];
    }
    if (a[i] < min1) {
      *min = i;
      min1 = a[i];
      }
  }
  return sum / n;
}
int main(){
  int b[1000], o, i ;
  int *ma, *mi;
  scanf("%d", &o);
  for (i = 0; i < o; i++){
    scanf("%d", &b[i]);
  }
  double ave=fun(b, o, ma, mi);
  printf("%d/n", b[*ma]);
  printf("%d/n", b[*mi]);
  printf("%lf/n", ave);
  return 0;
}