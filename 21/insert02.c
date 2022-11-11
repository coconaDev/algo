#include <stdio.h>
#include <string.h>

struct tag{
    char name[30];
    int age;
};
int main (void){
    struct tag m[5] = {
        {"青木", 21},
        {"伊藤", 19},
        {"上間", 35},
        {"江原", 24},
        {"大城", 34},
    };
    int i,j;
    int n = 5;
    struct tag tmp;

    for (i = 1; i < n; i++) {
      j = i;
      while (j > 0 && m[j - 1].age > m[j].age) {
        tmp = m[j];
        m[j] = m[j - 1];
        m[j - 1] = tmp;
        j--;
      }
    }

    for (i = 0; i < n; i++) {
        printf("%s(%3d)", m[i].name, m[i].age);
    }
    printf("\n");
    
    return 0;
}