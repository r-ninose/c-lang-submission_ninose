#include <stdio.h>
#include <stdlib.h>
typedef char String[1024];

//成績判定
//gcc -o 0903 0903.c ; .\0903.exe


int main(void)
{
String num;
  printf("100~0でテストの点数を入力してください\n");

  scanf("%s",num);

  int n = atoi(num);

  if (n==100){
    printf("満点すばらしい！\n");
  }
  else if(n>=80){
    printf("いいじゃん！\n");
  }else if(n>=60){
    printf("悪くない！\n");
  }else if(n>=30){
    printf("まーいっか！\n");
  }else{
    printf("頑張ろう！\n");
  }

  return 0;
}
