#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int m, n, p;

    cout<< "請輸入a[m][n]和b[n][p]的m, n, p: ";
    cin >>m >>n >>p;

    vector< vector<int> > a;

    int b[100][100], c[100][100];
    int aT[100][100];

    int i, j;
    int inp;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            system("cls");
            cout<< "範圍: a["<< m<< "]["<< n<< "]\n";
            cout<< "請輸入a["<< i<< "]["<< j<< "]: ";
            cin >>inp;
            a[i][j] = inp;
            aT[j][i] = inp;
        }
    }

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= p; j++) {
            system("cls");
            cout<< "範圍: b["<< n<< "]["<< p<< "]\n";
            cout<< "請輸入b["<< i<< "]["<< j<< "]: ";
            cin >>inp;
            b[i][j] = inp;
        }
    }

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= p; j++) {
            c[i][j] = 0;
            for (int k = 0; k <= n; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    system("cls");
    cout<< "aT:\n";
    for (i = 0; i <= n; i++) {
        cout<< "|";
        for (j = 0; j <= m; j++) {
            cout<< setw(3)<< aT[i][j];
        }
        cout<< "|\n\n";
    }
    cout<< "c:\n";
    for (i = 0; i <= m; i++) {
        cout<< "|";
        for (j = 0; j <= p; j++) {
            cout<< setw(3)<< c[i][j];
        }
        cout<< "|\n";
    }


    return 0;
}
