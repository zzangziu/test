#include <iostream>

using namespace std;

int N, M;
int v[1000], t[1000];
int v2[1000], t2[1000];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) cin >> v[i] >> t[i];

    for (int i = 0; i < M; i++) cin >> v2[i] >> t2[i];

    // Please write your code here.

    int A[1000];
    int B[1000];
    int curA = 0;
    int curB = 0;
    int velA = 0;
    int velB = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < t[i]; j++) {
            velA+=v[i];
            A[curA]=velA;
            curA++;
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < t2[i]; j++) {
            velB+=v2[i];
            B[curB]=velB;
            curB++;
        }
    }

    int cnt = 0;
    bool isA = false;
    bool isB = false;
    for(int i = 0; i < curA; i++) {
        if(A[i] > B[i]) {
            if(isB) cnt++;
            isA = true;
            isB = false;
        }
        else if(A[i] < B[i]) {
            if(isA) cnt++;
            isA = false;
            isB = true;
        }
    }

    cout << cnt;

    return 0;
}