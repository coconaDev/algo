#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    char label;
};
// 通りがけ順
void inorder(struct node * p){
    if ( p == NULL) return;
    inorder(p->left);
    printf("節%cに立ち寄り。\n", p->label);
    inorder(p->right);
}

int main (void){
    struct node a = {NULL, NULL, 'A'};    
    struct node b = {NULL, NULL, 'B'};    
    struct node c = {NULL, NULL, 'C'};    
    struct node d = {NULL, NULL, 'D'};    

    // 木の作成
    a.left  = &b;   //aの左の子にbのポインタを渡す
    a.right = &c;
    b.right = &d;

    inorder(&a);

    return 0;
}
