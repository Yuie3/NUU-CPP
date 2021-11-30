#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int i, j;
int com_A[5040][4];
void com_Adb();
void com_Guess();
void player_Guess(int *);

int main() {
    srand(time(NULL));
    int com_Q[4];
    for (i = 0; i < 4; ++i) {
        com_Q[i] = rand() % 10;
        for (j = 0; j < i; ++j) {
            if(com_Q[i] == com_Q[j]) {
                --i;
                break;
            }
        }
    }
    com_Adb();
    com_Guess();
    player_Guess(com_Q);


    for (i = 0; i < 4; ++i) {
        cout<< com_Q[i];
    }
    return 0;
}

void com_Guess() {

}

void player_Guess(int *com_Q) {
    int inp;
    int pla_A[4];
    cout<< "請輸入猜測的數字: ";
    cin >>inp;
    pla_A[0] = inp/1000 % 10;
    pla_A[1] = inp/100 % 10;
    pla_A[2] = inp/10 % 10;
    pla_A[3] = inp % 10;
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
}
