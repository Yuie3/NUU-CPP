#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct stu {
    int num;
    string name;
    int score[7];
    // cs, jg, kj, jj, wjv, xccj(avg), rank;
    //  0,  1,  2,  3,   4,         5,    6;
};



void gen_class(stu *, int);
void num_sort(stu *, int);
void avg_sort(stu *, int);
void score_sort(stu *, int, char);
void search_stu(stu*, int);
void print_all(stu*, int);

int main() {

    int clanum;
    cout<< "請輸入全班人數: ";
    cin >>clanum;
    stu cla[clanum];
    gen_class(cla, clanum);

    char menu = ' ';
    while(menu != 'B') {
        cout<< "1. 產生全班資料(一開始就產生好了所以你打了也沒用)\n"
            << "2. 依學號排序(記得顯示全班成績)\n"
            << "3. 依學期成績排序(記得顯示全班成績)\n"    // 6 & 5
            << "4. 依程設成績排序(記得顯示全班成績)\n"    // 0
            << "5. 依計概成績排序(記得顯示全班成績)\n"    // 1
            << "6. 依會計成績排序(記得顯示全班成績)\n"    // 2
            << "7. 依經濟成績排序(記得顯示全班成績)\n"    // 3
            << "8. 依微積分成績排序(記得顯示全班成績)\n"  // 4
            << "9. 顯示全班成績\n"
            << "A. 查詢某生成績\n"
            << "B. 結束程式\n"
            << "   請輸入選擇: ";
        cin >> menu;
        system("CLS");
        switch(menu) {
            case '1':   break;
            case '2':   num_sort(cla, clanum); break;
            case '3':   avg_sort(cla, clanum); break;
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':   score_sort(cla, clanum, menu); break;
            case '9':   print_all(cla, clanum); break;
            case 'A':   search_stu(cla, clanum); break;
        }
    }
    return 0;
}

void num_sort(stu *cla, int clanum) {
    stu tmp;
    for (int i = 0; i < clanum; i++) {
        for (int j = i; j < clanum; j++) {
            if(cla[i].num > cla[j].num) {
                tmp = cla[i];
                cla[i] = cla[j];
                cla[j] = tmp;
            }
        }
    }
}

void avg_sort(stu *cla, int clanum) {
    stu tmp;
    for (int i = 0; i < clanum; i++) {
        for (int j = i; j < clanum; j++) {
            if(cla[i].score[6] < cla[j].score[6]) {
                tmp = cla[i];
                cla[i] = cla[j];
                cla[j] = tmp;
            }
        }
    }
}

void score_sort(stu *cla, int clanum, char menu) {
    stu tmp;
    int k = (int)menu - 4;
    for (int i = 0; i < clanum; i++) {
        for (int j = i; j < clanum; j++) {
            if(cla[i].score[k] < cla[j].score[k]) {
                tmp = cla[i];
                cla[i] = cla[j];
                cla[j] = tmp;
            }
        }
    }
}

void search_stu(stu *cla, int clanum) {
    int num;
    cout<< "請輸入要查詢的學號: ";
    cin >>num;
    for (int i = 0; i < clanum; i++) {
        if(cla[i].num == num) {
            cout<< "學號: "<< cla[i].num
                << "\t姓名: "<< cla[i].name
                << "\n程設: "<< cla[i].score[0]
                << "\n計概: "<< cla[i].score[1]
                << "\n會計: "<< cla[i].score[2]
                << "\n經濟: "<< cla[i].score[3]
                << "\n微積分: "<< cla[i].score[4]
                << "\n平均分: "<< cla[i].score[5]
                << "\n名次: "<< cla[i].score[6]
                << endl;
        }
    }
}

void print_all(stu* cla, int clanum) {
    for (int i = 0; i < clanum; i++) {
        cout<< "學號: "<< cla[i].num
            << "\t姓名: "<< cla[i].name
            << "\n程設: "<< cla[i].score[0]
            << "\n計概: "<< cla[i].score[1]
            << "\n會計: "<< cla[i].score[2]
            << "\n經濟: "<< cla[i].score[3]
            << "\n微積分: "<< cla[i].score[4]
            << "\n平均分: "<< cla[i].score[5]
            << "\n名次: "<< cla[i].score[6]
            << endl;
    }
}

void gen_class(stu *cla, int clanum) {
    int i = 0, j = 0;
    while(i < clanum) {
        srand(time(NULL));
        cla[i].num = rand() % 1000 + 1033000;
        for (j = 0; j < i; j++) {
            if(cla[j].num == cla[i].num) {
                i--;
                break;
            }
        }
        i++;
    }

    i = 0;
    int chkra = 0;
    while(i < clanum) {
        // 亂數取名不好用，
        srand(time(NULL));
        int ra = rand() % 10 + 2;
        if (ra == chkra) {
            continue;
        }
        chkra = ra;
        srand(time(NULL));
        int sra = rand() % 26;
        string tmp = "";
        tmp.push_back(char(sra+65));
        for (j = 1; j < ra; j++) {
            srand(time(NULL));
            sra = rand() % 26;
            if (char(sra+97) == tmp[j - 1]) {
                j--;
                continue;
            }
            tmp.push_back(char(sra+97));
        }
        cla[i].name = tmp;
        // 亂數給成績
        cla[i].score[5] = 0;
        srand(time(NULL));
        cla[i].score[0] = rand() % 101;
        for (j = 1; j < 5; j++) {
            srand(time(NULL));
            cla[i].score[j] = rand() % 101;
            if (cla[i].score[j] == cla[i].score[j - 1]) j--;
        }
        for (j = 0; j < 5; j++) {
            cla[i].score[5] += cla[i].score[j];
        }cla[i].score[5] /= 5;

        i++;
    }

    stu stutmp;
    for (i = 0; i < clanum; i++) {
        for (j = i; j < clanum; j++) {
            if(cla[i].score[5] < cla[j].score[5]) {
                stutmp = cla[i];
                cla[i] = cla[j];
                cla[j] = stutmp;
            }
        }
    }
    for (j = 0; j < clanum; j++) cla[j].score[6] = j + 1;
}
