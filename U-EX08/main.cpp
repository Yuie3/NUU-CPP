#include <iostream>

using namespace std;

int time = 0;
void Hanoi(int, char, char, char);
int main() {
    int n;
    char A = 'A', B = 'B', C = 'C';
    cin>> n;
    Hanoi(n, A, B, C);
    cout<< "最少"<< time /*2^n-1*/<< "次\n";
}

void Hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        cout<< n<<":"<< A<< "->"<< C<< endl;
        time++;
    }else {
        Hanoi(n-1, A, C, B);
        cout<< n<<":"<< A<< "->"<< C<< endl;
        time++;
        Hanoi(n-1, B, A, C);
    }
}
