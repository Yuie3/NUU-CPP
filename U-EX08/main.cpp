#include <iostream>

using namespace std;

int timeT = 0;
void Hanoi(int, char, char, char);
int main() {
    int n;  // 圈圈
    cin>> n;  // 輸入有幾片圈圈
    Hanoi(n, 'A', 'B', 'C');
    cout<< "最少"<< timeT<< "次\n";  // 把次數輸出
}

void Hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        cout<< n<<":"<< A<< "->"<< C<< endl;  // 移動1號圈圈
        timeT++;  // 移動次數加一
    }else {
        Hanoi(n-1, A, C, B);  // 老師的提示
        cout<< n<<":"<< A<< "->"<< C<< endl;  // 移動n號圈圈
        timeT++;  // 移動次數加一
        Hanoi(n-1, B, A, C);  // 老師的提示
    }
}
