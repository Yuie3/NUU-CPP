#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main () {
    int x, y, num;  // "行" "列" "非零個數"
    int cx, cy, cz;  // 因為我需要其他變數來做事情，讚
    cin >>x >>y >>num;  // 輸入 "行" "列" "非零個數"
    int chg[y][x];  // 因為涂建宏說不需要再輸出原本的，所以只存真的要輸出的

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            chg[i][j] = 0;  // 先在陣列裡面填0，不然底下判斷式用不是零就輸出會很刺激
        }
    }

    for (int i = 0; i < num; i++) {
        cin >>cx >>cy >>cz;  // 輸入，就...輸入啊030
        chg[cy][cx] = cz;  // 把數字存到陣列裡
    }

    cout<< setw(4)<< y<< setw(4)<< x<< setw(4)<< num<< endl; // 對齊，就對齊
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (chg[i][j] != 0) {
                cout<< setw(4)<< i<< setw(4)<< j<< setw(4)<< chg[i][j]<< endl;
                // 把陣列輸出出來，讚!
            }
        }
    }

    int h, w, p;
    cout<< "請輸入地雷區的大小(h, w): ";
    cin >>h >>w;
    if (!h or !w) {
        cout<< "啊你的行跟列是負的喔 OAO!?"<< endl;
        return 0;
    }
    cout<< "請輸入地雷個數: ";
    cin >>p;
    if (!p or p > h*w) {
        cout<< "你的雷點好像很少喔 ^ ^\"\'"<< endl;
        return 0;
    }

    int mapp[h][w];  // 地圖本人
    int opmap[h][w];  // 記地圖誰被開過了
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            mapp[i][j] = 0;
            opmap[i][j] = 1;
        }
    }
    int pt = p;
    do {  // 用亂數把地雷丟進去
        srand( time(NULL) );
        int ph = rand() % h;
        srand( time(NULL) );
        int pw = rand() % w;
        if (!mapp[ph][pw]) {
            mapp[ph][pw] = 9;
            pt--;
        }
    } while(pt);

    system("cls");
    while (pt != h*w-p) {
        cout<< "現在雷區大小: "<< h<< "*"<< w<< endl;
        cout<< "地雷數量: "<< p<< endl;

        cout<<endl << setw(5)<< "";
        for (int i = 0; i < w; i++) cout<< setw(4)<< i+1;
        cout<< endl;
        for (int i = 0; i < h; i++) {
            cout<< setw(4)<< i+1<< "|";
            for (int j = 0; j < w; j++) {
                if (!opmap[i][j]) cout<< setw(4)<< mapp[i][j];  // 被開過了就顯示
                else cout<< setw(4)<< "";  // 沒被開過就謝謝再聯絡
            }
            cout<< endl;
        }

        int oph, opw;
        cout<< "請選擇要開採的位置(h, w): ";
        cin >>oph >>opw;
        oph--;
        opw--;
        if (!oph or !opw) {
            system("cls");
            cout<< "沒有這一格啊，哭啊"<< endl;
            continue;
        }
        if (!opmap[oph][opw]) {
            system("cls");
            cout<< "踩過了拉 OAO, 你還好嗎?"<< endl;
            continue;
        }
        if (mapp[oph][opw]) {
            cout<< "炸!!!"<< endl;
            return 0;
        }

        pt++;
        opmap[oph][opw] = 0;
        system("cls");
    }

    cout<< "恭喜你過關!"<< endl;
    return 0;
}
