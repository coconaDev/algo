#include<stdio.h>
#include<string.h>

char *input(void){
  static char str[BUFSIZ];
  fgets(str, 50, stdin);
  return str;
}

int main (void){
  printf("入力:");

  char* str = input();
  printf("%s\n", str);

  return 0;
}
