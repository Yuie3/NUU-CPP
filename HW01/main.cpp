#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int i, j;
int p_A = 0, p_B = 0;
bool com_f = 0, pla_f = 0;
int com_A[5040][4], ans_Num = 5040;
int com_Q[4];
void com_Adb();
void com_Guess();
void player_Guess();

int main() {
    srand(time(NULL));
    com_Adb();

    while (1) {
        if(!com_f) com_Guess();
        if(!pla_f) player_Guess();
    }

    for (i = 0; i < 4; ++i) {
        cout<< com_Q[i];
    }
    return 0;
}


void com_Guess() {
    int c_A, c_B;  // 玩家輸入總共有幾個A幾個B
    int c_cA, c_cB;  // 電腦來檢查答案用
    int time = 0;
    int ran = rand() % ans_Num;
    for (i = 0; i < 4; ++i) {
        cout<< com_A[ran][i];
    }
    cout<< "\nA: ";
    cin >>c_A;
    cout<< "\nB: ";
    cin >>c_B;
    if(c_A == 4) {
        com_f = true;
        cout<< "電腦超勇的拉";
        return;
    } else if(ans_Num == 1) {
        com_f = true;
        cout<< "再騙啊";
        return;
    }
    for (i = 0; i < ans_Num; ++i) {
        c_cA = c_cB = 0;
        for (j = 0; j < 4; ++j) {
            if(com_A[ran][j] == com_A[i][j]) {
                c_cA++;
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                if(com_A[ran][j] == com_A[i][k]) c_cB++;
            }
        }
        if (c_A == c_cA and c_B == c_cB) {
            for (j = 0; j < 4; ++j) {
                com_A[time][j] = com_A[i][j];
                time++;
            }
        }
    }
    ans_Num = time;
}

void player_Guess() {
    int inp;
    int p_Ans[4];
    p_A = p_B = 0;
    cout<< "請輸入猜測的數字: ";
    cin >>inp;
    p_Ans[0] = inp/1000 % 10;
    p_Ans[1] = inp/100 % 10;
    p_Ans[2] = inp/10 % 10;
    p_Ans[3] = inp % 10;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            if (p_Ans[i] == p_Ans[j])
            {
                cout<< "你輸入的數字有重複喔>_< \n";
                return;
            }
        }
    }
    for (i = 0; i < 4; ++i) {
        if(p_Ans[i] == com_Q[i]) {
            p_A++;
            continue;
        }
        for (j = 0; j < 4; ++j) {
            if(p_Ans[i] == com_Q[j]) p_B++;
        }
    }
    if(p_A == 4) pla_f == true;
    cout<< "A: "<< p_A<< "B: "<< p_B;
}

void com_Adb() {  // 產生所有可能的答案
    /*
        原本只想到每次都用亂數猜，但想不到好的演算法
        看到網路上面的分析
        因為幾A幾B的數字不能重複
        所以先把所有可能的答案存起來
        再把不符合條件的剔除
    */
    int n_1, n_10, n_100, n_1000;
    int tmp = 0;
    for (i = 123; i < 9877; ++i) {
        n_1 = (i/1)%10;
        n_10 = (i/10)%10;
        n_100 = (i/100)%10;
        n_1000 = (i/1000)%10;
        if (n_1!=n_10 && n_1!=n_100 && n_1!=n_1000 && n_10!=n_100 && n_10!=n_1000 && n_100!=n_1000) {
            com_A[tmp][0] = n_1000;
            com_A[tmp][1] = n_100;
            com_A[tmp][2] = n_10;
            com_A[tmp][3] = n_1;
            tmp++;
        }
    }

    // 電腦出的題目
    for (i = 0; i < 4; ++i) {
        com_Q[i] = rand() % 10;
        for (j = 0; j < i; ++j) {
            if(com_Q[i] == com_Q[j]) {
                --i;
                break;
            }
        }
    }
}
