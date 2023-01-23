#include <stdio.h>

#define N 10
#define f(x) (2*(x*x*x)-3*(x*x)+5)

int main(void)
{
  float a, b, si, S, h;
  int i;
  a = 1;
  b = 3;

  h = (b - a) / (N*2);

  S = 0;

  for (i = 1; i <= N; i++){
    si += h / 3 * (f(a + 2*(i - 1) * h) + f(a + 2*(i-1)*h + h) + f(a + 2*i*h));
    S += si;
  }

  printf("関数f(x)の積分区間[%g:%g]の積分値は%gです。\n", a, b, S);
  return 0;
}
