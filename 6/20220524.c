#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *p;
    int n;
    int i;

    printf("大きさ>>");
    scanf("%d", &n);

    p = ( int*)malloc(sizeof(int) * n);
    if(p == NULL){
        printf("memmory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    for(i=0; i<n; i++){
        printf("%d\n", p[i]);
    }

    free(p);
    return 0;
}