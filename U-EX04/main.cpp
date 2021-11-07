#include <iostream>
#include <math.h>

using namespace std;

int main () {
    int snum[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int pnum = 1, inp, max = 0, min = 1000;
    double avg = 0, sd = 0, sd2x = 0;
    int sdx = 0;

    while (1) {
        cout<< "請輸入"<< pnum<< "號的成績: ";
        cin >>inp;
        if (inp < 0 || inp > 100) break;
        if (inp > max) max = inp;
        if (inp < min) min = inp;
        sd2x += inp;
        sdx += inp*inp;
        pnum++;

        if      (inp < 10) snum[0]++;
        else if (inp < 20) snum[1]++;
        else if (inp < 30) snum[2]++;
        else if (inp < 40) snum[3]++;
        else if (inp < 50) snum[4]++;
        else if (inp < 60) snum[5]++;
        else if (inp < 70) snum[6]++;
        else if (inp < 80) snum[7]++;
        else if (inp < 90) snum[8]++;
        else               snum[9]++;

    } pnum--;

    for (int i = 0; i < 10; i++) {
        cout<< i<< "|";
        for (int j = 0; j < snum[i]; j++) {
            cout<< "*";
        }
        cout<< endl;
    }

    avg = sd2x / pnum;
    sd = sdx + pnum*pow(avg, 2) - 2*avg*sd2x;
    sd = sd / pnum;
    cout<< "最低分: "<< min<< endl
        << "最高分: "<< max<< endl
        << "平均分: "<< avg<< endl
        << "標準差: "<< sqrt(sd)<< endl;

    // 標準差為每人成績與平均分的差值平方和除以人數後開根號,用以表示成績的分佈情形

    return 0;
}
