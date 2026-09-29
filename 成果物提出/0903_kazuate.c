#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef char String[1024];

//数あてゲーム
//gcc -o 0903-2 0903-2.c ; .\0903-2.exe


int main(void)
{
String num;


//answerにランダム数字入れる
  srand((unsigned)time(NULL));
  int answer =rand() %10+1;

//数字を入れた回数
  int count = 0;

//当たるまで続ける
while(1){

  printf("1~10で数を当ててください！\n");

  //入力した文字をnumに入れる
  scanf("%s",num);
  int n = atoi(num);

  //回数をカウント
  count++;

  if (n==answer){
    printf("正解！すばらしい！\n");
    
    break;
  

  }else{
    printf("残念！もう一回です。\n");
  }

}
  printf("あなたは%d回で正解しました！\n",count);

  return 0;

}