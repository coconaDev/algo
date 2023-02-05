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
int search();   // マッチ
void show();
int isItem();   // ソート項目とソート順の入力
void selectSort();  // 選択ソート
void showList();
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
        char *CityName = isCityName();
        int num = search(CityName);
        show(num);
        break;
      case 2:
        int item, sort = isItem();
        selectSort(item, sort);
        // showList();
        break;
      default:
        printf("\n数字を入力してください");
        break;
    } 
    printf("\n");
  }
  return 0;
}
void showList(){
  for (int i = 0; i < ELEMENTS; i++){
    printf("%s:%.2f\n", m[i].city, m[i].area);
  }
}
void selectSort(int item, int sort){
  int max = 0, i = 0;
  int *p; // ソートする構造体メンバのポインタ
  struct DATA temp;

  switch (item){  // 項目番号から構造体メンバを指定
  case 1: p[i] = m[i].area;
  case 2: p[i] = m[i].population;
  case 3: p[i] = m[i].rate;
  case 4: p[i] = m[i].age;
  case 5: p[i] = m[i].income;
  case 6: p[i] = m[i].unemployment;
  default:break;
  }


  for ( i = 0; i < ELEMENTS-1; i++){
    int max = i;
    for (int j = i; j < ELEMENTS; j++){
        if (p[max] < p[j]){
          max = j;
        }
    }
    temp = m[i];
    m[i] = m[max];
    m[max] = temp;
  }
}
int isItem(){
  int item, sort;
  printf("------ソートする項目を選択してください------\n");
  printf("1 : 面積順\n");
  printf("2 : 人口\n");
  printf("3 : 増加率\n");
  printf("4 : 平均年齢\n");
  printf("5 : 完全失業率\n");
  printf("6 : 所得\n");
  printf("コマンド：");
  scanf("%d", &item);
  printf("\n");

  printf("--ソートする順を選択してください------\n");
  printf("0 : 昇順\n");
  printf("1 : 降順\n");
  scanf("%d", &sort);

  sort = (sort ? -1 : 1);

  return (item, sort);
}
int search(char *CityName){
  for (int i = 0; i < ELEMENTS; i++){
    printf("%s", CityName);
    printf("%s\n", m[i].city);
    if (!(strcmp(m[i].city, CityName))){
        return i;
    }
  }
  return 0;
}
char *isCityName(){
  static char str[50];
  printf("検索する市町村名：");
  scanf("%s", str);

  return str;
}
void show(int num){
  printf("---------検索結果------------\n");
  printf("%s\n", m[num].city);
  printf("面積：%.2f\n", m[num].area);
  printf("人口：%.2f(増加率：%.2f)\n", m[num].population, m[num].rate);
  printf("平均年齢：%.2f\n", m[num].age);
  printf("完全失業率：%.2f\n", m[num].unemployment);
  printf("所得（千円）：%.2f\n", m[num].income);
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
