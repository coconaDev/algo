// 選択ソート
#include <stdio.h>

int main(void) {
  int m[8] = {5, 10, 2, 9, 8, 4, 15, 12};
  int i;
  int j;
  int min;
  int tmp;
  int n = 8;

  for (i = 0; i < n; i++) {
    printf("%3d", m[i]);
  }
  printf("\n");

  // 選択ソート
  for (i = 0; i < n - 1; i++) {
    // 暫定最小値
    min = i;
    for (j = i; j < n; j++) {
      if (m[min] > m[j]) {
        min = j;
      }
    }
    // 交換
    tmp = m[min];
    m[min] = m[i];
    m[i] = tmp;
  }

  for (i = 0; i < n; i++) {
    printf("%3d", m[i]);
  }
  printf("\n");
  return (0);
}