#include<stdio.h>
int main(void) {
   
    printf("こんにちは。\n");
    printf("名前は二瀬利奈です\n");

    printf("私は%d年%d月%d日生まれ%d歳です。\n", 1998, 11, 13, 27);
    printf("身長は%dcmです。\n", 160);
    printf("生まれてから%d日以上経ちました。\n", 365 * 27);


    int maindish = 720;
    int garnish = 140;
    int drink = 0;
    int lunch = 930;

    printf("美味しいものを食べること、作ることとアイドルが好きです。\n");
    printf("昨日の夕飯はすき屋で購入しました。\n");
    printf("シビ辛麻婆茄子牛丼%d円\n", maindish);
    printf("からあげ2個セット%d円\n", garnish );
    printf("緑茶%d円\n", drink );
    printf("合計で%d円です。\n", maindish + garnish + drink );
    
    printf("今日のお昼に食べたモス野菜バーガーセットは%d円でしたので。\n", lunch);
    printf("一食の平均価格は%d円でした。今日の夕飯は自炊にすると誓います。\n", (maindish+garnish+lunch)/2);
    
    printf("おすすめのご飯屋さんなど是非教えてください！川崎でもご飯に行きましょうね！\n");









    return 0;
}