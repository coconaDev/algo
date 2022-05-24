/* ディレクティブ　*/
#include<stdio.h>
#include<stdlib.h>

struct CELL{
    int data;   // 要素
    struct CELL *next;  // 次のセルへのデータ
};
/* 連結リストの先頭 */
struct CELL *Header = NULL;

/*  初期化（lnit）*/
void Init(void){
  struct CELL *delete_pos;
   while (Header != NULL) {
    delete_pos = Header;
    Header = Header->next;
    free(delete_pos);
  }
}
int Count(void){
    int c=0;
    struct CELL *p;

    for(p=Header; p!=NULL; p=p->next){
        c++;
    }
    return c;
}
int main(void){
    struct CELL *a;
    struct CELL *b;
    struct CELL *c;
    struct CELL *p;

    //先頭セルの生成
    a = (struct CELL *)malloc(sizeof(struct CELL));
    a->data = 100;
    a->next = NULL;

    b = (struct CELL *)malloc(sizeof(struct CELL));
    b->data = 200;
    b->next = NULL;
    //接続
    a->next = b;

    c = (struct CELL *)malloc(sizeof(struct CELL));
    c->data = 300;
    c->next = NULL;
    //接続
    b->next = c;

    Header = a;

    //連結リストの状態を表示
    printf("要素数：%d\n", Count());
    printf("リストの状態\n");
    for (p = Header; p != NULL; p = p->next) {
      printf("[%d : ・-]-> ", p->data);
    }
    printf("NULL\n");

    //初期化
    Init();

    //連結リストの状態を表示
    printf("要素数：%d\n", Count());
    printf("リストの状態\n");
    for (p = Header; p != NULL; p = p->next) {
      printf("[%d : ・-]-> ", p->data);
    }
    printf("NULL\n");

    return (0);
}