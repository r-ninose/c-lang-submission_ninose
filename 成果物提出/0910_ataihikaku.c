#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{


  //1長さ
  char a [] = {49,50,51,52,53,0};
  char b [] = "12345";

  int len = strlen(a);
  printf("Aの長さは%d\n",len);

  len = strlen(b);
  printf("Bの長さは%d\n",len);

  //答えはこれ
  //printf("aの長さ：%ld　bの長さ：%ld¥n", strlen(a), strlen(b));


  //2等しいか

  if(strcmp(a,b)==0){
    printf("等しい\n");  
  }else{
    printf("等しくない\n");
  }

  //3ヒープ領域

  int lenA =strlen(a);  //長さ数える
  int lenB =strlen(b);
  int totalsize = lenA + lenB +1; //足してここで終わりの分も足す
  
  char* c = (char*)malloc(totalsize);  //部屋借りた　ｃという名前
  strcpy(c,a);  //ｃにコピーする
  strcat(c,b);  //その後ろにくっつける

  printf("cの中身は%s",c);

  free(c);

  return 0;
}


//gcc -o practice11-2 practice11-2.c ; .\practice11-2.exe

