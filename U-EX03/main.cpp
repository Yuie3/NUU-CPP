#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

/*
    因為我把自己的終端機直接改成utf8
    所以如果沒有更改過終端機設定
    或是ide預設使用big5可能會出現亂碼的情況
*/

int main(){

    char sel;
    cout<< "請選擇一般或加分題(a or b): ";
    cin >>sel;

    switch (sel) {
        case 'a': goto normal;
        case 'b': goto extra;
    }

    extra:

        system("cls");
        cout<< "加分題: \n";

        int max, min;
        char chk;
        cout<< "最大: ";
        cin >>max;
        cout<< "最小: ";
        cin >>min;
        cout<< endl<< "大於你的數字打b, 小於你的數字打s"<< endl<< endl;

        do {
            // srand( time(NULL) );
            // int x = rand() % (max - min + 1) + min;
            int x = (max + min) / 2;
            cout<< x<< " 是否正確? ";
            cin >>chk;
            if (chk == 'y') {
                cout<< "水喔"<< endl;
            } else if (chk == 's') {
                min = x + 1;
            } else if (chk == 'b') {
                max = x - 1;
            }
            if (max < min) {
                cout<< "\n沒有這種數字阿，你騙我QAQ\n"<< endl;
                break;
            }
        } while(chk != 'y');

        return 0;


    normal:

        system("cls");
        int num, ans, rnd = 1;
        vector<int> anum = {};
        srand( time(NULL) );
        num = rand()%100;
        cout<< "一般: \n請輸入0~99的數字: ";
        while (1) {
            test:
            cin>> ans;
            for (int i = 0; i < int(anum.size()); i++) {
                if (ans == anum[i]) {
                    cout<< "猜過了= ="<< endl;
                    goto test;
                }
            }
            anum.push_back(ans);
            if (ans < num) {
                cout<< "太小了"<< endl;
                rnd++;
            }else if (ans > num) {
                cout<< "太大了"<< endl;
                rnd++;
            }else{
                if (rnd < 4) {
                    cout<< "神猜中"<< endl;
                } else if (rnd < 7) {
                    cout<< "金頭腦"<< endl;
                } else if (rnd < 10) {
                    cout<< "再加油"<< endl;
                } else if (rnd < 13) {
                    cout<< "你真的是聯大的嗎?"<< endl;
                } else {
                    cout<< "我不認識你"<< endl;
                }
                break;
            }
        }

        return 0;

}
