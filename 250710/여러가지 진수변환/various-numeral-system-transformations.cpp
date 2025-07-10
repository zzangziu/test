#include <iostream>

using namespace std;

int N, B;

int main() {
    cin >> N >> B;

    int n = N;
    int digit[20] = {};
    int cnt = 0;
    while(true) {
        if(n < B) {
            digit[cnt++] = n;
            break;
        }

        digit[cnt++] = n % B;
        n /= B;
    }

    for(int i = cnt - 1; i >= 0; i--) {
        cout << digit[i];
    }
    return 0;
}