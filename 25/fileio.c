#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int brute_force_search(char *text, int txt_len, char *pattern, int pt_len);
int main(void){
    char str[300];
    FILE *fp;
    char pattern[] = "Alice";
    int result;
    int count = 0;

    fp = fopen("Alice_s_Adventures_in_Wonderland.txt", "r");

    while (fgets(str, sizeof(str), fp) != NULL){
        // printf("%s",str);
        if (brute_force_search(str, strlen(str), pattern, strlen(pattern)) != -1){
            count++;
        }
    }

    printf("Aliceの出現回数：%d回\n", count);
    fclose(fp);
    return 0;
}

int brute_force_search(char *text, int txt_len, char *pattern, int pt_len) {
    int i, j;
    i = 0;
    j = 0;

    // テキスト長を超えていない&&パターン長を超えていない
    while (i < txt_len && j < pt_len) {
        // テキストのi番目とパターンのj番目が一致した場合
        if (text[i] == pattern[j]) {
          // パターンの次の文字を比較するため，iとjをインクリメント
          i++;
          j++;
          // 一致しない場合
        } else {
          i = i - j + 1;  // 途中までチェックしていたことを考慮
          // パターンのチェック位置は０にする．
          j = 0;
        }
    }

    // jの値がパターン長と一致：成功）？テキスト位置：失敗(-1)
    return (j == pt_len ? i - j : -1);
}