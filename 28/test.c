#include<stdio.h>
#include<string.h>

struct test{
  int id;
  char name[20];

};

struct test ps[2] ={
  {0, "aaa"},
  {1, "bbb"}
};


int main(void){
  char *access[2] = {ps[0].id, ps[1].name};

  printf("%s", access[0]);
}
