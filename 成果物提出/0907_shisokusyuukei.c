#include <stdio.h>
#include <stdlib.h>

typedef char String[1024];


//総額　÷　人数　100円未満は切り上げ　余ったお金は幹事が受け取る

int main(void)
{
  int amount; //支払い総額
  int people; //参加人数
  int pay;    //一人当たり支払金額
  int payorg; //幹事の支払金額
  
  String inputStr;
  double dnum;

  //計算データ入力

  printf("支払総額を入力してください：");
  scanf("%s",inputStr);
  amount=atoi(inputStr);    //入力したものを計算用数字に変えた　atoi

  printf("参加人数は：");
  scanf("%s",inputStr);
  people=atoi(inputStr);




  //割り勘計算

  dnum =(double)amount/people;  
  //総額　÷　人数　　doubleを付けることによって小数点のついた答えがdnumに保存される
  pay = (int) (dnum/100)*100;   //100円未満切り捨て　ここは教科書に書いた
  if (dnum>pay){
  
  pay = pay+100;
  }

  //幹事の支払額

  payorg =  amount - pay *(people-1);
  
  //結果
  printf("支払金額\n");
  printf("一人当たり%d円(%d人)幹事は%d円\n",pay,people-1,payorg);



  return 0;
}


//gcc -o practice8-4 practice8-4.c ; .\practice8-4.exe