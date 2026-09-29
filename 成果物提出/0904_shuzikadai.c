#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//上巻7-3

int main(void)
{

//身長の配列
//
enum {LEN=4};
  int hight[LEN]= {162, 161, 154, 185};
  int sum =0;
  int max =hight[0];
  int min = hight[0];

    for (int i =0; i<LEN;i++){
      sum= sum + hight[i];
      
        if (max < hight[i]){
          max = hight[i];
        }
        if (min > hight[i]){
          min = hight[i];
        }

  }
  
printf("一番身長が高い人は%dcm\n",max);
printf("一番身長が低い人は%dcm\n",min);
printf("平均身長は%dcm",sum/LEN);
  return 0;
}


//gcc -o 0904 0904.c ; .\0904.exe