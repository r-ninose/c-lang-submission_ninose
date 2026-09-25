#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef char String[1024];


// gcc -o menu menu.c ; .\menu.exe


//構造体　
typedef struct {
    char name[64];     // 名前
    int id;            // 社員ID
    int gender;        // 性別
    char date[16];     // 誕生日
    int department;    // 部署番号
    int salary;        // 給与
} Employee;


// 入力チェック　整数かつ範囲内の入力を強制する関数 inputInteger
int inputInteger(const char *message, int min, int max) {
    String input;
    long long value;
    int isValid;

    while (1) {
        printf("%s", message);
        scanf("%s", input);

        isValid = 1; // 一度正しいと仮定する

        // 1. 文字列が整数の形式であるかチェック
        // 先頭がマイナス符号、または数字であるか
        if (input[0] != '-' && (input[0] < '0' || input[0] > '9')) {
            isValid = 0;
        } else {
            // 2文字目以降がすべて数字であるか
            for (int i = 1; input[i] != '\0'; i++) {
                if (input[i] < '0' || input[i] > '9') {
                    isValid = 0;
                    break;
                }
            }
        }

        // マイナス符号だけの入力（"-" のみ）はエラーにする
        if (input[0] == '-' && input[1] == '\0') {
            isValid = 0;
        }

        // 2. 正しい整数の形式だった場合、範囲チェック
        if (isValid) {
            value = atoi(input);
            if (value >= min && value <= max) {
                return value; // 合格なら数値を返してループを抜ける
            }
        }

        // エラーメッセージを表示して、再入力させる
        printf("%d以上%d以下の整数を入力してください: ", min, max);
    }
}   
    
    
    

// 入力チェック　文字数が範囲内かチェックする関数 inputInteger
void inputString(const char *message,char*output, int min, int max) {
    String input;
    int len;

    while (1) {
        printf("%s", message);
        scanf("%s", input);

        len = strlen(input);

        if(len>=min&&len<=max){
            strcpy(output,input);
            return;
        
        }

        // エラーメッセージを表示して、再入力させる
        printf("%d文字以上%d文字以下の整数を入力してください: ", min, max);
        message="";
    }
}   
    
    



int main(void)
{

    //文字コード指定
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    String num;
    int n = 0;

    //nが7ではない間、ずっと繰り返す
    while (n != 7) {
        printf("\n=== 社員管理システム ===\n1. 全件表示\n2. 社員名検索\n3. 部署ID検索\n4. 登録\n5. 更新\n6. 削除\n7. 終了\nメニュー番号を入力してください:");


        scanf("%s", num);
        n = atoi(num); 

        switch (n) {
            case 1:
                printf("1. 全件表示\n");

                FILE *rfp;

                // rb（読み書き） emp.csvを開く
                if ((rfp = fopen("emp.csv", "rb")) == NULL) {
                    printf("登録がありません\n");
                    break;
                }

                Employee reademp; // 読み取ったデータを入れる箱
                int cn;             //データの個数

                // freadで読み込む 14-5　受け取って書きこむため&readempになる　
                // 読み込めたデータの個数（cn）が 0 より大きい間、繰り返す
                //1つずつ読みこんでいるためcnは1,1,1…読みこむものがなくなったら0になる
                while ((cn = fread(&reademp, sizeof(Employee), 1, rfp)) > 0) {
                    
                    
                    printf(" 社員番号: %d | 名前: %s | 性別: %d | 生年月日: %s | 部署ID: %d |給与: %d |\n", 
                            reademp.id, reademp.name, reademp.gender, reademp.date,reademp.department,reademp.salary);
                }

                fclose(rfp); // ファイル閉じる
            break;



            case 2:
                printf("2. 社員名検索\n");

            
                //更新する社員の番号を　search_nameに入れる　%s　文字型

                //最初から %d で数字を待つと、文字を打たれた時にプログラムがフリーズ（無限ループ）
                //してしまうから。どんな入力でも一回安全に受け止められる %s をクッションにして、
                //バグを防いでいる

                String search_name;
                
                // printf("社員名を入力してください: ");
                // scanf("%s", search_name);
                 
                inputString("社員名を入力してください:",search_name,1,15);



                FILE *se_rfp;   //ファイル構造体へのポインタ宣言

                // rb（読み書き） emp.csvを開く
                se_rfp = fopen("emp.csv", "rb");
                if (se_rfp == NULL) {
                    printf("登録がありません\n");
                    break;
                }

                Employee search_emp;    //型　変数
                int search_found = 0;   //見つかったら１、見つからなければ0


                // freadで読み込む 14-5　受け取って書きこむため&search_empになる　
                // 読み込めたデータの件数（1件ずつ読み取っている）が 0 より大きい間、繰り返す
                //case1のようにcnがあってもよい　なくてもfreadが件数教えてくれる
                while (fread(&search_emp,sizeof(Employee),1,se_rfp)>0){

                //strcmp （完全一致でないと使えない）の代わりに strstr を使う（曖昧検索が出来るため）
                // 「!= NULL」と書くことで、一部分でも含まれていたらという意味
                //search_emp.name(名簿の名前),search_name（入力した名前）
                    if(strstr(search_emp.name,search_name)!=NULL){
                    
                         printf(" 社員番号: %d | 名前: %s | 性別: %d | 生年月日: %s | 部署ID: %d |給与: %d |\n", 
                            search_emp.id, search_emp.name, search_emp.gender, search_emp.date,search_emp.department,search_emp.salary);
                        

                            //見つかった数
                            search_found++;
                        
                        }
                }
                fclose(se_rfp);

                if(search_found==0){
                    printf("指定された社員が見つかりませんでした\n");
                  }
                   
                



            break;


            case 3:
                printf("3. 部署ID検索\n");

        
                //関数 inputIntegerにより以下はいらなくなった

                // printf("部署ID(1：営業部、2：経理部、3：総務部)を入力してください: ");

                // //検索する部署の番号を　 search_depに入れる　%s　文字型
                // String search_dep;
                // scanf("%s",search_dep);
                // //数値型に変える
                // int search_dep_id;
                // search_dep_id = atoi(search_dep); 


                int search_dep_id;
                search_dep_id = inputInteger("部署ID(1：営業部、2：経理部、3：総務部)を入力してください: ",1,3);

                
                // rb（読み書き） emp.csvを開く
                FILE *dep_rfp;
                dep_rfp = fopen("emp.csv", "rb");
            
                if (dep_rfp == NULL) {
                    printf("登録がありません\n");
                    break;
                }



                Employee dep_emp;
                int dep_found = 0;   //見つかったら１、見つからなければ0

                // freadで読み込む 14-5　受け取って書きこむため&dep_empになる　
                // 読み込めたデータの個数が 0 より大きい間、繰り返す
                //freadが件数教えてくれる
                while (fread(&dep_emp,sizeof(Employee),1,dep_rfp)>0){

                    if(dep_emp.department == search_dep_id){
                    
                         printf(" 社員番号: %d | 名前: %s | 性別: %d | 生年月日: %s | 部署ID: %d |給与: %d |\n", 
                            dep_emp.id, dep_emp.name, dep_emp.gender, dep_emp.date,dep_emp.department,dep_emp.salary);
                        
                            dep_found =1;
                        
                        }
                }
                fclose(dep_rfp);

                if(dep_found==0){
                    printf("指定された社員が見つかりませんでした\n");
                  }
                   
                



            break;




            case 4:
                printf("登録\n");

                Employee emp;   

                // printf("社員IDを入力してください:\n");
                // scanf("%d", &emp.id);
                
                // // printf("名前を入力してください:\n");
                // // scanf("%s", emp.name);

                // printf("性別入力してください(1: 男性, 2: 女性):\n");
                // scanf("%d", &emp.gender);
                

                // printf("生年月日を入力してください（例:2026/04/01）\n");
                // scanf("%d", &emp.date);

                // printf("部署番号を入力してください（1：営業部、2：経理部、3：総務部）:\n");
                // scanf("%d", &emp.department);

                // printf("給与を入力してください　\n");
                // scanf("%d", &emp.salary);


                emp.id = inputInteger("社員IDを入力してください:\n",1,100);
                inputString("名前を入力してください:\n", emp.name,1,15);
                emp.gender = inputInteger("性別入力してください(1: 男性, 2: 女性):\n",1,2);
                inputString("生年月日を入力してください（例:2026/04/01）\n", emp.date,10,10);
                emp.department = inputInteger("部署番号を入力してください（1：営業部、2：経理部、3：総務部）:\n",1,3);
                emp.salary = inputInteger("給与を入力してください(万円)\n",0,1000000);




                FILE *wfp;


                // 何度も追記できるように、上書きではなく ab（追記バイナリ）
                if ((wfp = fopen("emp.csv", "ab")) == NULL) {
                    exit(1);
                }

                // fwriteで wfp (ファイル)に1個書き込む 
                fwrite(&emp, sizeof(Employee), 1, wfp);
                fclose(wfp);

                printf("登録しました\n");
                break;

              
              
            case 5:


                printf("更新\n");


                //関数 inputIntegerにより以下はいらなくなった


                //更新する社員の番号を　  up_numに入れる　%s　文字型

                // String up_num;
                // int update_id;
                // printf("変更する社員の社員IDを入力してください: ");
                // scanf("%s", up_num);
                // //数値型に変える
                // update_id = atoi(up_num); 

                int update_id;
                
                update_id = inputInteger("変更する社員の社員IDを入力してください: ",1,100);



                // 古い名簿から全員を list マンションに一時避難させる
                FILE *up_rfp;
                //rb(読み取り専用)
                up_rfp = fopen("emp.csv", "rb");
                if (up_rfp == NULL) {
                    printf("登録がありません\n");
                    break;
                }

                Employee up_list[100]; // 更新用の臨時のマンション
                int up_count = 0;       //臨時マンションに引っ越した件数

                //読み取る数が0になるまで　1件ずつ　
                //&up_list[up_count]は［0］から一件ずつ増えていく
                while (fread(&up_list[up_count], sizeof(Employee), 1, up_rfp) > 0) {
                    up_count++;
                }
                fclose(up_rfp);

                //更新したいIDがマンションに実在するか、1部屋ずつドアを開けて確認する
                int up_found = 0;
                for (int i = 0; i < up_count; i++) {
                    if (up_list[i].id == update_id) {
                        up_found = 1; 
                        break;
                    }
                }

                // もし見つからなかったら
                if (up_found == 0) {
                    printf("指定された社員IDが見つかりませんでした\n");
                    break;
                }

              
                // update の箱に一時保存
                Employee update;
                update.id = update_id; // IDは変更しないのでそのままコピー

                // printf("新しい社員名を入力してください:\n");
                // scanf("%s", update.name);

                // printf("新しい性別を入力してください(1: 男性, 2: 女性):\n");
                // scanf("%d", &update.gender);

                // printf("新しい生年月日を入力してください（例:20260401）:\n");
                // scanf("%d", &update.date);

                // printf("新しい部署番号を入力してください（1：営業部、2：経理部、3：総務部）:\n");
                // scanf("%d", &update.department);

                // printf("給与を入力してください\n");
                // scanf("%d", &update.salary);





                inputString("新しい名前を入力してください:", update.name,1,15);
                update.id = inputInteger("新しい性別入力してください(1: 男性, 2: 女性):\n",1,2);
                update.id = inputInteger("新しい生年月日を入力してください（例:2026/04/01）\n",1900/01/01,9999/12/31);
                update.id = inputInteger("新しい部署番号を入力してください（1：営業部、2：経理部、3：総務部）:\n",1,3);
                update.id = inputInteger("新しい給与を入力してください\n",0,1000000);





                // emp.csvをけして更地（wb）にする
                FILE *up_wfp;
                up_wfp = fopen("emp.csv", "wb");
                if (up_wfp == NULL) {
                    exit(1);
                }

                // 新しいマンションに住民を書き戻していく
                for (int i = 0; i < up_count; i++) {
                    if (up_list[i].id == update_id) {
                        //
                        fwrite(&update, sizeof(Employee), 1, up_wfp);
                    } else {
                        // 一致しなかった部屋は、臨時マンションにそのまま書き戻す
                        fwrite(&up_list[i], sizeof(Employee), 1, up_wfp);
                    }
                }
                fclose(up_wfp);

                printf("社員情報を更新しました\n");
                break;



            case 6:
                printf("削除\n");



                //関数 inputIntegerにより以下はいらなくなった


                // //削除するIDの箱
                // String del_num; 
                // int delete_id;

                // printf("削除する社員の社員IDを入力してください: \n");
                // // del_numで受け取る　%sは文字列で受け取っている　
                // scanf("%s", del_num);
                // // atoi で数字に変換する　deleteIDは社員番号
                // delete_id = atoi(del_num);


                int delete_id;
                update_id = inputInteger("削除する社員の社員IDを入力してください:  ",1,2147483647);


                //del_rfp　を作って　rb　（読み取り専用）　emp.csvファイル開く
                FILE *del_rfp = fopen("emp.csv", "rb");
                //もしそのファイルの中身が無ければ
                if (del_rfp == NULL){
                    printf("登録がありません\n");
                    break;
                }

                //100個　別部屋用意しておく　
                Employee list[100];
                int count = 0;
                
                //0号室から別マンションに住人を　入れていく　　
                while (fread(&list[count], sizeof(Employee), 1, del_rfp) > 0){
                    count++;
                }
                fclose(del_rfp); // 読み込み窓口を閉じる

                // emp.csvを開く　wbは新規書き込み専用　ファイルがあったら一度中身消してしまう
                FILE *del_wfp = fopen("emp.csv", "wb");
                //もしファイルが無かったら閉じる
                if (del_wfp == NULL){
                    exit(1);
                }
                //削除したい人数をこれから数える
                int found = 0;
                //一部屋ずつ社員番号見に行く
                for(int i = 0; i < count; i++){
                  //もし社員番号とdeleteid（削除したい社員番号）と一致していたら
                    if(list[i].id == delete_id){
                        found = 1; // 一致したら書き込まない

                     //削除するものではなかったら   
                    } else {
                        // 新しいファイルに残す
                        fwrite(&list[i], sizeof(Employee), 1, del_wfp);    
                    }
                }

                fclose(del_wfp); // 書き込み窓口を閉じる

                if (found == 1) {
                    printf("社員情報を削除しました\n");
                } else {
                    printf("指定された社員IDが見つかりませんでした\n");
                }
                break;


            case 7:
                printf("終了\nシステムを終了します\n");
                break; 

            default:
                printf("1から7の数字を入力してください。\n");
            
                
                
                break;
        }
    }

    return 0;
}
