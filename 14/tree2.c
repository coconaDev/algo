#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    struct node *left;
    struct node *right;
    char label;
};
// 行きがけ順
void preorder (struct node *p){
    if( p == NULL) return;
    // 1. 立ち寄り
    printf("節%cに立ち寄り。\n", p->label);
    // 2.左部分木のなぞり
    preorder(p->left);
    // 3. 右部分木のなぞり
    preorder(p->right);

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

    //　なぞりの実行
    preorder(&a);

    return 0;
}
