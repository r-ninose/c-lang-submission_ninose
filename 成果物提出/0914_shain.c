#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char name[16];
  int id;
  char department[16];
  double height;
}Csv;

int main(void)
{
  FILE*fp;
  char filename[] ="employee";

  //データ
  Csv date[4]={
    {"enta",1,"ochayasan",149.9},
    {"ueoota",2,"owarai",159.1},
    {"ninose",3,"tokuninashi",160.0}
  };


  //書き込み
  if((fp= fopen(filename,"w"))==NULL){
    exit(1);
  }

  for (int i =0; i<3;i++){
    int cn =fprintf(fp, "%s,%d,%s,%4.2f\n", date[i].name, 
      date[i].id, date[i].department, date[i].height);

      
      

  }
      fclose(fp);
  return 0;
}


//gcc -o s0914 s0914.c ; .\s0914.exe

