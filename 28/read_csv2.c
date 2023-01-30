#include <stdio.h>
#include <stdlib.h>

struct tag {
	float a, b, c, d, e, f;
	char city[30];
};

int main(void)
{
	char buf[300];
	FILE *fp;
	struct tag m[42];	//構造体配列
	int i;
	
	fp = fopen("data_municipalities_okinawa.csv", "r");
	if (fp == NULL){
		printf("File IO Error!\n");
		exit(EXIT_FAILURE);
	}
	
	//項目行の読み捨て
	fgets(buf, sizeof(buf), fp);
	
	i = 0;
	while (fgets(buf, sizeof(buf), fp) != NULL){
		sscanf(buf, "%f,%f,%f,%f,%f,%f,%s"
			, &m[i].a, &m[i].b, &m[i].c, &m[i].d, &m[i].e, &m[i].f, m[i].city);
		printf("---------------------------------\n");
		printf("%s\n", m[i].city);
		printf("面積：%.2f\n", m[i].a);
		printf("人口：%.2f(増加率：%.2f)\n", m[i].b,m[i]. c);
		printf("平均年齢：%.2f\n", m[i].d);
		printf("完全失業率：%.2f\n", m[i].e);
		printf("所得（千円）：%.2f\n", m[i].f);
		
		i++;
	}
	
	for (i = 0; i < 42; i++){
		printf("%s:%.2f\n", m[i].city, m[i].a);
	}
	
	fclose(fp);
	return (0);
}
