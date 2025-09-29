#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    int F[46];

    F[1] = 1;
    F[2] = 1;

    // Please write your code here.
    for(int i = 3; i<=N; i++) {
        F[i] = F[i-1] + F[i-2];
    }

    cout << F[N];


    return 0;
}
