#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int brute_force_search(char *text, int txt_len, char *pattern, int pt_len);
int main (void) {
  char text[] = "okinawa nago henoko 905";
  char pattern[] = "a n";
  int result;

  result = brute_force_search(text, strlen(text), pattern, strlen(pattern));
  if(result == -1){
    printf("探索失敗\n");
  }else{
    printf("成功！パターン[%s]はテキスト[%s]の%d番目から。\n", pattern, text, result);
  }
  return 0;
}

int brute_force_search(char *text, int txt_len, char *pattern, int pt_len) {
  int i,j;
  i = 0; j = 0;

  // テキスト長を超えていない&&パターン長を超えていない
  while (i < txt_len && j < pt_len) {
    // テキストのi番目とパターンのj番目が一致した場合
    if (text[i] == pattern[j]) {
      // パターンの次の文字を比較するため，iとjをインクリメント
      i++;
      j++;
    }
    // 一致しない場合
    else {
      i = i - j + 1;  // 途中までチェックしていたことを考慮
      // パターンのチェック位置は０にする．
      j = 0;
    }
  }

  // jの値がパターン長と一致：成功）？テキスト位置：失敗(-1)
  return (j == pt_len ? i - j : -1);
}