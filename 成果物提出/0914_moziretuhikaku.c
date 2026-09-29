#include <stdio.h>
#include <stdlib.h>
typedef char String[1024];


//Cを3通りの方法で出す
int main (void)
{
  //手段１  
  char array [1024] ="C";     //1024部屋あるマンションを建てる
  char* msg1 = array;       //一室目にC を住まわせる　msg1の住所を書いて持っておく
  printf("%s",msg1);        //


  //手段2
  char* msg2 = (char*)malloc(1024);   //1024部屋あるマンション借ります
  msg2[0]= 'C';                       //C入れます
  msg2[1]= '\0';                      //シングルコーテーションなので\0と隣に入れないとそのあともずっと見に行ってしまうので止める（？）
  printf("%s",msg2);
  free(msg2);                         //mallocで部屋借りたらfreeで返さなければいけないセットである

  //手段3
  const char* msg3 ="C";              //書き換え禁止の建物　mg3　にCの住所を入れておく
  printf("%s",msg3);

  printf("\n");

  return 0;

}

//gcc -o sample11-3 sample11-3.c ; .\sample11-3.exe