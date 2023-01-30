#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float a, b, c, d, e, f;
	char city[30];
	char buf[300];
	FILE *fp;
	
	fp = fopen("data_municipalities_okinawa.csv", "r");
	if (fp == NULL){
		printf("File IO Error!\n");
		exit(EXIT_FAILURE);
	}
	
	//項目行の読み捨て
	fgets(buf, sizeof(buf), fp);
	
	while (fgets(buf, sizeof(buf), fp) != NULL){
		sscanf(buf, "%f,%f,%f,%f,%f,%f,%s", &a, &b, &c, &d, &e, &f, city);
		printf("---------------------------------\n");
		printf("%s\n", city);
		printf("面積：%.2f\n", a);
		printf("人口：%.2f(増加率：%.2f)\n", b, c);
		printf("平均年齢：%.2f\n", d);
		printf("完全失業率：%.2f\n", e);
		printf("所得（千円）：%.2f\n", f);
	}
	
	fclose(fp);
	return (0);
}
