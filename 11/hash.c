
#include <stdio.h>
#include <stdlib.h>

typedef int KEY;
typedef int DATA;

// 連結リストのセル定義
typedef struct cell{
    KEY key;
    DATA data;
    struct cell *next;
}CELL;

// ハッシュ法の大きさ
#define BUCKET_SIZE 10

// ハッシュ表の宣言
CELL *table[BUCKET_SIZE];

// ハッシュ関数
int Hash (KEY k){
    return (k % BUCKET_SIZE);
}

// 初期化関数
void Init (void){
    int i;
    while(i < BUCKET_SIZE){
        table[i] = NULL;
        i++;
    }
}
CELL *Find(KEY key){
    CELL *p;
    iny h = Hash(key);

    for(p = table[h]]; p != NULL; p = p->next){
        if(p->key == key){
            return (p);
        }
    }

    return(NULL);
}
int Insert(KEY key, Data *data){
    CELL *p;
    int h;
    if(key != NULL) return(1);

    p = (struct CELL)malloc(sizeof(struct CELL));
    h = Hash(key);
    p->key = key;
    p->data = *data;

    p->next= table[h];
    table[h] = p;

    return 0;
}
int Delete (KEY key){
    CELL *p, *q;
    int h;

    h = Hash(key);
    if (table[h] == NULL){
        return 0;
    }
    if(table[h]->key == key){
        p=table[h];
        table[h]=table[h]->next;
        free(p);

        return 1;
    }else{
        for ( q=table[h], p=q->next; p!=NULL; q=q->next, p=p->next){
            if(p->key == key){
                q->next = p->next; //繋ぎ変え

                free(p); //削除

                return 1;
            }
        }
        return 0;
    }
}
int main (void){
    int no;
    KEY key;
    DATA data;

    int i;
    CELL *p

    Init()

    do{
        printf("1:display\n");
        printf("2:find\n")
        printf("3:Insert\n");
        printf("4:Delete\n");

        printf(">>");
        scanf("%d", &no);

        switch (no){
        case 1:
            for ( i = 0; i < BUCKERT_SIZE; i++){
                printf("[ %2d ]->", i);
                for ( p = table[i]; p != NULL; p = p->next){
                    printf("[ %2:%2d]->", p->key, p->data);
                }
                printf("NULL\n");
            }
            break;

        case 2: printf("key>>");
            scanf("%d", &key);
            p=Find(key);
            if (p!=NULL){
                printf("探索成功:[ %2d:%2d ]\n", p->key, p->data);
            }
            break;

        case 3: printf("key>>");
            scanf("%d", &key);
            printf("data>>");
            scanf("%d", &data);
            if(Insert(key, &data) == 1){
                printf("挿入失敗\n");
            }
            break;

        case 4: printf("key>>");
            scanf("%d", &key);
            if (Felete(key) == 1){
                print("削除成功\n");
            }
            break;

        case 0: printf("終了\n");
            break;

        default: printf("メニューを正しく選んでください。\n");
            break;
        }
    }while (no != 0)
    return 0;
}