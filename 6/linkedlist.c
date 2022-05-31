// linkedlist.c
#include <stdio.h>
#include <stdlib.h>

//連結リストのセルの定義
struct CELL {
  int data;           //要素（データ）
  struct CELL *next;  //次のセルへのポインタ
};

//連結リストの先頭
struct CELL *Header = NULL;

//初期化関数
void Init(void) {
  //１．delete_posを宣言
  struct CELL *delete_pos;
  while (Header != NULL) {
    // 2.delete_posにheaderを代入
    delete_pos = Header;

    // 3.headerの指すセルを次のセルに変更
    Header = Header->next;

    // 4.delete_posの指すセルを解放(free)
    free(delete_pos);
  }
}

int Count(void) {
  int c = 0;
  struct CELL *p;

  for (p = Header; p != NULL;
       p = p->next) {  //リストの範囲で要素のnextを辿っていく。
    c++;
  }

  return (c);
}

void Add(int value) {
  // 0.必要な変数の宣言
  struct CELL *p;
  struct CELL *nc;

  //リストが空の場合
  if (Header == NULL) {
    if ((Header = (struct CELL *)malloc(sizeof(struct CELL))) == NULL) {
      printf("メモリ領域の確保に失敗しました。\n");
      exit(1);
    }
    //要素を追加。（確保した領域にデータを格納）
    Header->data = value;
    Header->next = NULL;
  } else {
    //１．要素へのポインタを先頭のアドレスで初期化
    p = Header;
    //２．リストの末尾までリンクを辿って移動
    while (p->next != NULL) {
      p = p->next;
    }

    // for (p = Header; p->next != NULL; p = p->next);

    //３．メモリ領域を確保し、0で宣言したポインタに代入
    nc = (struct CELL *)malloc(sizeof(struct CELL));
    if (nc == NULL) {
      printf("error!\n");
      exit(EXIT_FAILURE);
    }

    //４．要素を追加。接続
    nc->data = value;
    nc->next = NULL;
    p->next = nc;

    // p->next = (struct CELL *)malloc(sizeof(struc CELL));
    // p->next->data = value;
    // p->next->next = NULL;
  }
}

int main(void) {
  int no = 1;
  int v;
  struct CELL *p;

  while (no) {
    printf("１：初期化\n");
    printf("２：追加\n");
    printf("３：表示\n");
    printf("０：終了\n");
    printf(">> ");
    scanf("%d", &no);

    switch (no) {
      case 1:
        printf("初期化\n");
        Init();
        break;
      case 2:
        printf("追加\n");
        printf("追加する値>> ");
        scanf("%d", &v);
        Add(v);
        break;
      case 3:  //連結リストの状態を表示
        printf("要素数：%d\n", Count());
        printf("リストの状態\n");
        for (p = Header; p != NULL; p = p->next) {
          printf("[%d : ・-]-> ", p->data);
        }
        printf("NULL\n");
        break;
      case 0:
        printf("終了\n");
        break;
      default:
        printf("0～3を選択ください\n");
    }
  }

  return (0);
}