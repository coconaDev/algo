/* linkdlist_sample.cではa->b->cと表示していたのを、
c->b->aの順に表示する
*/
#include <stdio.h>
#include <stdlib.h>

/*セルの定義*/
struct CELL {
  struct CELL *next;
  int data;
};

int main(void) {
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

  c = (struct CELL *)malloc(sizeof(struct CELL));
  c->data = 300;
  c->next = NULL;

  //接続
  c->next = b;
  b->next = a;

  //連結リストの状態を表示
  printf("リストの状態\n");
  for (p = c; p != NULL; p = p->next) {
    printf("[%d : ・-]-> ", p->data);
  }
  printf("NULL\n");

  return (0);
}
