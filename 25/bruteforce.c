#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int brute_fource_serch(char *text, int txt_len, char *pattern, int pt_len);
int main (void){
    char text[] = "okinawa nago henoko 905";
    char pattern[] = "a n";
    int result;

    result = brute_fource_serch(text, strlen(text), pattern, strlen(pattern));
    if(result == -1){
        printf("探索失敗\n");
    }else{
        printf("成功！パターン[%s]はテキスト[%s]の%d番目から。\n", pattern, text, result);
    }
    return 0;
}

int brute_fource_serch(char *text, int txt_len, char *pattern, int pt_len){
    int i,j;
    i = 0; j = 0;

    while(i <= txt_len && j <= pt_len){
        if(text[i] == pattern[j]){
            i++; j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    return (j == pt_len ? i-j : -1);
}