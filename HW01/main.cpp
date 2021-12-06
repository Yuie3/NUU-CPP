#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int i, j;
int cT = 0, pT = 0;
bool com_f = 0, pla_f = 0;
int end_game = 2, playT = 0;
int com_A[5040][4], ans_Num = 5040;
int pla_A[5040];
int com_Q[4];
vector<int> player_rank;
void com_Adb();
void com_Guess();
void player_Guess();
void again();

int main() {
    srand(time(NULL));
    com_Adb();

    while (end_game) {
        if(!pla_f) player_Guess();
        if(!com_f) com_Guess();
        if(!end_game) again();
    }
    return 0;
}

void again() {
    if(cT>pT) cout<< "看來還是電腦比較勇喔\n";
    else if(cT<pT) cout<< "看來你跟電腦一樣勇喔\n";
    else cout<< "看起來你比電腦還要勇喔\n";
    player_rank.push_back(pT);
    sort(player_rank.begin(), player_rank.end());
    cout<< "第1名: "<< player_rank[0]<< endl;
    for(i = 1; i <= playT; ++i) {
        cout<< "第"<< i+1<< "名: "<< player_rank[i]<< endl;
    }
    playT++;
    char inp;
    cout<< "\n\n要再一局嗎(y/n): ";
    cin >>inp;
    if(inp == 'y') {
        system("CLS");
        com_f = pla_f = 0;
        cT = pT = 0;
        end_game = 2;
        ans_Num = 5040;
        com_Adb();
    }
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
    cout<< "B: ";
    cin >>c_B;
    if(c_A + c_B > 4) {
        cout<< "你認真???\n";
        return;
    }
    cT++;
    if(c_A == 4) {
        com_f = true;
        end_game -= 1;
        cout<< "電腦結束\n\n";
        return;
    } else if(ans_Num == 1) {
        end_game = 0;
        cout<< "再騙啊\n";
        return;
    }
    for (i = 0; i < ans_Num; ++i) {
        c_cA = c_cB = 0;
        for (j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if(com_A[ran][j] == com_A[i][k]) {
                    if(k == j) c_cA++;
                    else c_cB++;
                }
            }
        }
        if (c_A == c_cA and c_B == c_cB) {
            for (j = 0; j < 4; ++j) {
                com_A[time][j] = com_A[i][j];
            }
            time++;
        }
    }
    ans_Num = time;
}

void player_Guess() {
    int inp;
    int p_Ans[4];
    int p_A = 0, p_B = 0;
    cout<< "請輸入猜測的數字: ";
    cin >>inp;
    if(inp < 123 or inp > 9876) {
        cout<< "你認真???\n";
        return;
    }
    p_Ans[0] = inp/1000 % 10;
    p_Ans[1] = inp/100 % 10;
    p_Ans[2] = inp/10 % 10;
    p_Ans[3] = inp % 10;
    for (i = 0; i < 4; ++i) {
        for (j = i+1; j < 4; ++j) {
            if (p_Ans[i] == p_Ans[j])
            {
                cout<< "你輸入的數字有重複喔>_< \n";
                return;
            }
        }
    }
    for (i = 0; i < pT; ++i) {
        if(inp == pla_A[i]) {
            cout<< "你輸入的數字有重複喔>_< \n";
            return;
        }
    }
    pla_A[pT] = inp;
    for (i = 0; i < 4; ++i) {
        if(p_Ans[i] == com_Q[i]) {
            p_A++;
            continue;
        }
        for (j = 0; j < 4; ++j) {
            if(p_Ans[i] == com_Q[j]) p_B++;
        }
    }
    cout<< "A: "<< p_A<< "\tB: "<< p_B<< endl;
    if(p_A == 4) {
        pla_f = true;
        end_game -= 1;
        cout<< "玩家結束\n\n";
    }
    pT++;
}

void com_Adb() {  // 產生所有可能的答案
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
