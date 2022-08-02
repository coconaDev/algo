#include <stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    char label;
};

void preorder (struct node *p){
    if(p == NULL) return;
    
    // 立ち寄る
    printf("節%cに立ち寄り。\n", p->label);
    // 左部分木に移動
    preorder(p->left);
    // 右部分木に移動
    preorder(p->right);
}
    
int main (void){
    struct node a = {NULL, NULL, 'A'};
    struct node b = {NULL, NULL, 'B'};
    struct node c = {NULL, NULL, 'C'};
    struct node d = {NULL, NULL, 'D'};

    a.left = &b;
    a.right = &c;
    b.right = &d;

    // なぞり
    preorder(&a);

    return 0;
}
