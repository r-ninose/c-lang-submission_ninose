#include <stdio.h>
#include <stdlib.h>

int* readyAges(void)
{
  int* ages = (int*)malloc(16);  //1．段ボール箱16個分の4部屋　マンションを作ります
  return ages;
}

int main(void)
{
  int* a = readyAges();   //2．yマンション情報はagesで持って帰ってきてる
  if(a==NULL){
    printf("ヒープ確保に失敗しました\n");
  }else{
  a[0] = 19;
  printf("ヒープの%p番地に確保しました\n");
  free(a);
  }
  return 0;

}

//gcc -o sample10-5 sample10-5.c ; .\sample10-5.exe