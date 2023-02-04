#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILE_NAME "data_municipalities_okinawa.csv" // 開くファイルの定義
#define ELEMENTS 42 // 要素数

// データ構造定義
struct DATA{
  float area; // 面積
  float population; // 人口
  float rate; // 人口増加率
  float age;          // 平均年齢
  float unemployment; // 完全失業率
  float income; // 所得
  char city[30]; // 市町村名
};
// 構造体配列
struct DATA m[ELEMENTS];

// プロトタイプ宣言
void strageData();      // データの読み込み
char *isCityName(); // 都市名を入力
void serch();
void sort();
void show();

int main(void){
  strageData();
  // メニュー選択
  int input;
  while (1){
    printf("----------選択してください-------------\n");
    printf("1 : 市区町村で検索\n");
    printf("2 : ソートして表示\n");
    printf("コマンド：");

    scanf("%d", &input);

    switch (input){
      case 1:
        char *str = isCityName();
        break;
      case 2:
        sort();
        show();
        break;
      default:
        printf("数字を入力してください\n");
        break;
    } 
    printf("\n");
  }

  return 0;
}

void serch(){
}
void sort(){
}
char *isCityName(){
  static char str[50];
  printf("検索する市町村名：");
  scanf("%s", str);

  return str;
}
void show(){
  // 選択した項目を表示するようにする
  for (int i = 0; i < ELEMENTS; i++){
    printf("%s:%g\n", m[i].city, m[i].age);
  }
}
void strageData(){
  char buf[300];
  FILE *fp;

  // open file
  fp = fopen(FILE_NAME, "r");
  if (fp == NULL){
    printf("File IO Error!\n");
    exit(EXIT_FAILURE);
  }

  // 1行目の読み込み（格納しない）
  fgets(buf, sizeof(buf), fp);
  
  int i = 0;
  while (fgets((buf), sizeof(buf), fp) != NULL){
    sscanf(buf, "%f,%f,%f,%f,%f,%f,%s", &m[i].area, &m[i].population, &m[i].rate, &m[i].age, &m[i].unemployment, &m[i].income, m[i].city);
    i++;
  }
  fclose(fp);
}
