#include<stdio.h>

int main(void){
  int m[8] = {5, 10, 2, 9, 8, 4, 15, 12};
  int i, j;
  int tmp;
  int n = 8;

  for(i=1; i < n; i++){
    j = i;
    while(j > 0 && m[j-1] > m[j]){
      tmp = m[j];
      m[j] = m[j-1];
      m[j-1] = tmp;
      j--;
    }
  }

  for (i = 0; i < n; i++) {
    printf("%3d", m[i]);
  }
  printf("\n");
  return 0;
}