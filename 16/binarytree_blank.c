#include <stdio.h>
#include <stdlib.h>

/*節（ノード）のユーザ定義*/
typedef struct node {
  int data;
  struct node *left;   //右の子へのポインタ
  struct node *right;  //左の子へのポインタ
} NODE;                //<-新しい型名

/*根節の宣言（初期化）*/
NODE *root = NULL;

NODE *search(int key) {
  NODE *p;

  //初期化
  p = root;

  //探索
  /* 探索の継続条件：1.探索位置pが末端（NULL）
  になるまで続ける >> NULLじゃない間は続ける*/
  while (p != NULL) {
    //アルゴリズム①
    /* 2.探索キーとデータが一致 */
    if (p->data == key) {
      /* 3.探索したノード（節）を返す */
      return (p);

      //アルゴリズム②
      /* 4.節のデータよりも探索キーが小さいとき */
    } else if (p->data > key) {
      /* 5.左の子に移動 */
      p = p->left;
    } else {
      /* 6.右の子に移動 */
      p = p->right;
    }
  }
  return (NULL);
}

NODE *insert(int key) {
  NODE **p, *newNode;

  /* 1.根節へのポインタrootのアドレスをpに格納*/;
  p = &root;
  while (*p != NULL) {
    /* 2.探索キーkeyとpと指すポインタが指すデータdataが等しい */
    if ((*p)->data == key) {
      return (NULL);
    } else if (key < (*p)->data) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }
  /* 3.ポインタnewNodeに新しい領域を確保 */
  newNode = (NODE *)malloc(sizeof(NODE));
  if (newNode == NULL) {
    printf("memory allocation error!\n");
  }

  /* 4.確保した領域の左の子をNULLとする */
  newNode->left = NULL;
  /* 5.確保した領域の右の子をNULLとする */
  newNode->right = NULL;
  /* 6.確保した領域のdataにkeyを格納 */
  newNode->data = key;
  /* 7.pが指すポインタが指す節を確保した領域にする */
  (*p)=newNode;

  return (newNode);
}

NODE *detectmin(NODE **p) {
  NODE *x;
  /* 1.pが指すポインタが指す節の左の子がNULLじゃない間続ける */
  while ((*p)->left != NULL) {
    /* 2.pにpが指すポインタが指す節の左の子のアドレスを格納（左の子に移動） */
    p = &(*p)->left;
  }

  /* 3.xにpが指すポインタ（アドレス）を格納 */
  x = *p;
  /* 4.pが指すポインタにpが指すポインタが指す節の右の子のアドレスを格納（接続の切り替え）*/
    *p = (*p)->right;

  return (x);
}

int delete (int key) {
  NODE **p, *x;

  /* 1.根節へのポインタrootのアドレスをpに格納*/;
    p = &root;
  while (*p != NULL) {
    if (key == (*p)->data) {
      x = *p;

      /* 2.xが指す節の左の子も右の子もNULL（葉を指す）*/
      if (x->left == NULL && x->right == NULL) {
        *p = NULL;

        /* 3.xが指す節の子の左の子がNULL */
      } else if (x->left == NULL) {
        /* 4.pが指すポインタにxが指す節の右の子を格納（接続の切り替え）*/;
        p = &x->right;
      } else if (x->right == NULL) {
        *p = x->left;
      } else {
        *p = detectmin(&x->right);
        (*p)->right = x->right;
        (*p)->left = x->left;
      }
      free(x);
      return (1);
    } else if (key < (*p)->data) {
      p = &(*p)->left;
    } else {
      p = &(*p)->right;
    }
  }
  return (0);
}

int main(void) {
  int no = 1;
  int key, flag;
  NODE *p;

  while (no) {
    printf("1 search\n2 insert\n3 delete\n0 exit\n>> ");
    scanf("%d", &no);

    switch (no) {
      case 0:
        printf("Exit\n");
        break;
      case 1:
        printf("Search\n");
        printf("please input search key>> ");
        scanf("%d", &key);
        p = search(key);
        if (p != NULL) {
          printf("detect key!! [%d]\n", p->data);
        } else {
          printf("the key not found\n");
        }
        break;
      case 2:
        printf("Insert\n");
        printf("please input data>> ");
        scanf("%d", &key);
        p = insert(key);
        if (p != NULL) {
          printf("complete!! [%d]\n", p->data);
        } else {
          printf("the key already existed\n");
        }
        break;
      case 3:
        printf("Delete\n");
        printf("please input key>> ");
        scanf("%d", &key);
        if (delete (key)) {
          printf("complete!!\n");
        } else {
          printf("the key isn't exist\n");
        }
        break;
    }
  }
  return (0);
}