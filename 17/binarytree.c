#include <stdio.h>
#include <stdio.h>

/* ノード */
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

/*初期化*/
NODE *root = NULL;

/*  search 関数 */
NODE *search(int key){
	NODE *p;
	p = root;

	while(p != NULL){
		if(p->data == key){
			return p;
		}else if(p->data > key){
			p = p->left;
		}else{
			p = p->right;
		}
	}
	return NULL;
}

/* insert関数 */
NODE *insert (int key){
	NODE **p, *newNode;
	p = &root;

	while(*p != NULL){
		if((*p)->data == key){
			return NULL;
		}else if((*p)->data > key){
			p = &(*p)->right;
		}else{
			p = &(*p)->left;
		}
	}
	newNode = (NODE *)malloc(sizeof(NODE));
	if(newNode == NULL){
		printf("memory allocation error!\n");
	}

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = key;
	(*p) = newNode;

	return (newNode);
}

/*delete関数 */
int delete (int key){
	NODE **p, *x;
	while(*p != NULL){
		if(key == (*p)->data){
			x = *p;
			if(x->left == NULL && x->left == NULL){
				*p = NULL;
			}else if(x->left == NULL){
				*p = x->left;
			}else if(x->right == NULL){
				*p = x->left;
			}else{
				*p = detectmin(&x->right);
				(*p)->right = x->right;
				(*p)->left = x->left;
			}
			free(x);
			return 1;
		}else if(key < (*p)->data){
			p = &(*p)->left;
		}else{
			p = &(*p)->right;
		}
	}
	return 0;
}

int main (void){
	int no = 1;
	int key, flag;
	NODE *p;

	while(no){
          printf("1 search\n2 insert\n3 delete\n0 exit\n>>");
          scanf("%d", &no);

          switch (no) {
            case 0:
              printf("Exit\n");
              break;
            case 1:
              printf("Search\n");
              printf("please input  search key >>");
              scanf("%d", &key);

              p = search(key);
              if (p != NULL) {
                printf("detect key! [%d]\n", p->data);
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
	return 0;
}