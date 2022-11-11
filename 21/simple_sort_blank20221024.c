#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000     // レコード長　これ。
#define TRIAL 10  // 試行回数
/************************************************/
/* 比較・交換の計測を行うときはコメントを外す． */
#define COMPSWAP
/************************************************/

typedef int DATA;

// 構造体の定義　この形
typedef struct tag {
  DATA x;  // このメンバxの値によってソートします。
  // 要素サイズを大きくするときはコメントを外す．
  //	double d[10];
} RECORD;

// プロトタイプ宣言
void make_matrix(RECORD data[]);
void disp_record(RECORD data[]);
void bubble_sort(RECORD data[], int *comp, int *swap);
void selection_sort(RECORD data[], int *comp, int *swap);
void insertion_sort(RECORD data[], int *comp, int *swap);

int main(void) {
  int i, comp, swap, sum_c, sum_s;
  clock_t s_time, sum_t;
  RECORD data[N];

  // TRIAL回の平均実行時間，比較・交換回数を出力
  sum_t = 0;
  sum_c = 0;
  sum_s = 0;

  for (i = 0; i < TRIAL; i++) {
#ifdef COMPSWAP  // 初期化(比較・交換用)
    comp = 0;
    swap = 0;
#endif
    // レコードをランダムに生成
    make_matrix(data);
    // レコード確認用
    if (i == 0) {
      disp_record(data);
    }

    // 計算開始時間の測定
    s_time = clock();

    // 実行関数を指定
    // bubble_sort(data, &comp, &swap);
    // selection_sort(data, &comp, &swap);
    insertion_sort(data, &comp, &swap);

    // レコード確認用
    if (i == 0) {
      disp_record(data);
    }

    sum_t += clock() - s_time;

#ifdef COMPSWAP  // 比較・交換回数用
    sum_c += comp;
    sum_s += swap;
#endif
  }

  // 結果の出力
#ifdef COMPSWAP  // 比較・交換回数用
  printf("time = %gms\tcomparison = %.2f回\tswap = %.2f回\n",
         (double)sum_t / TRIAL, (double)sum_c / TRIAL, (double)sum_s / TRIAL);
#else
  // 計算時間用
  printf("time = %gms\n", (double)sum_t / TRIAL);
#endif

  return (0);
}

// レコードの生成関数
void make_matrix(RECORD data[]) {
  int i;

  // 乱数の種の生成
  srand(time(NULL));

  for (i = 0; i < N; i++) {
    data[i].x = (DATA)(rand() / (RAND_MAX + 1.0) * N);
  }
}

// レコード表示関数
void disp_record(RECORD data[]) {
  int i;

  for (i = 0; i < N; i++) {
    printf("%2d", data[i].x);
  }
  printf("\n");
}

// バブルソート関数
void bubble_sort(RECORD data[], int *comp, int *swap) {
  // ここにバブルソート実装するんだけど、仮引数がスライドと違います。
  // RECORD型の構造体配列dataをソートします。
  // やります。
  int i;
  int j;
  //	int tmp//ではだめ。
  RECORD tmp;

  // 配列の大きさもマクロNで定義されているので注意。
  for (i = 0; i < N; i++) {
    for (j = N - 1; j > i; j--) {
      if (data[j - 1].x > data[j].x) {  // メンバの値を比較
        // 入れ替える。
        // 構造体は代入できるから楽だよね。
        // メンバに配列があろうが文字列があろうが
        // 関係なく代入できますよ。
        tmp = data[j];
        data[j] = data[j - 1];
        data[j - 1] = tmp;
        *swap+=1;
      }
      *comp+=1;
    }
  }
}

// 選択ソート関数
void selection_sort(RECORD data[], int *comp, int *swap) {
  int i, j;
  RECORD tmp;
  int min;

  for (i = 0; i < N - 1; i++) {
    // 暫定最小値
    min = i;
    for (j = i; j < N; j++) {
      if (data[min].x > data[j].x) {
        min = j;
        *comp+=1;
      }
    }
    // 交換
    tmp = data[min];
    data[min] = data[i];
    data[i] = tmp;
    *swap+=1;
  }
}

// 挿入ソート関数
void insertion_sort(RECORD data[], int *comp, int *swap) {
  int i, j;
  RECORD tmp;

  for (i = 1; i < N; i++) {
    j = i;
    while (j > 0 && (data[j - 1].x > data[j].x, *comp+=1) ) {
      tmp = data[j];
      data[j] = data[j - 1];
      data[j - 1] = tmp;
      j--;
      *swap+=1;
    }
  }
}
