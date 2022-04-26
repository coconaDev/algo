#include <stdio.h>
#include <string.h>

int makeData(int mat[]);
void sh

struct tag{
    int id;
    float h;
    float w;
    char name[30];
};

int main (void){
    struct tag data[8];
    int i;
    FILE *fp;

    fp = fopen("member.csv", "r");
    if(fp == NULL){
        printf("file io error!\n");
        exit(ECIT_FAILURE);
    }

    i=0;
    whille(fscanf(fp, "%d,%f,%f,%s"
    , &data[i].id, &data[i].h
    , &data[i].w, data[i].name) !=EOF){
        i++;
    }

    fclose(fp);

    printf("探索するID>>");
    scanf("%d", &key);

    no = linear_search(data, key);

    printf("[%d]:%s %.3f %3f\n");

    return 0;
}