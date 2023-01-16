#include <stdio.h>

#define N 10
#define f(x) (x)

int main(void){
  float a, b, si, S, h;
  int i;
  a = 1;
  b = 3;

  h = (b-a) / N;

  S = 0;

  for (i = 1; i <= N; i++){
    si += h / 2 *(f(a + (i - 1) * h) + f(a + i * h)) ;
    S += si;
  }

  printf("関数f(x)の積分区間[%f:%f]の積分値は%fです。\n", a, b, S);
  return 0;
}
