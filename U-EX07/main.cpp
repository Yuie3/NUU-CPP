#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    struct stu {
        int num;
        string name;
        int cs, jg, kj, jj, wjv, xccj, rank;
    };

    int clanum;
    cin >>clanum;
    stu haha[clanum];
    int i = 0;
    while(i < clanum) {
        srand(time(NULL));
        haha[i].num = rand() % 1000 + 1033000;
        for (int j = 0; j < i; j++) {
            if(haha[j].num == haha[i].num) {
                i--;
                break;
            }
        }
        i++;
    }
    // 亂數取名不好用，等老師的姓名庫
    // i = 0;
    // while(i < clanum) {
    //     srand(time(NULL));
    //     int ra = rand() % 10 + 1;
    //     srand(time(NULL));
    //     int sra = rand() % 26;
    //     string tmp = "";
    //     tmp.push_back(char(sra+65));
    //     for (int j = 1; j < ra; j++) {
    //         srand(time(NULL));
    //         sra = rand() % 26;
    //         tmp.push_back(char(sra+97));
    //     }
    //     haha[i].name = tmp;
    //     i++;
    // }
    for (i = 0; i < clanum; i++) {
        cout<< haha[i].num<<endl;
    }




    return 0;
}
