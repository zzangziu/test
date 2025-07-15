#include <iostream>

using namespace std;

int n;
int x[1000];
char dir[1000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    bool isW[200000] = {false};
    bool isB[200000] = {false};

    int cur = 100000;
    for(int i = 0; i < n; i++) {
        if(dir[i] == 'R') {
            for(int j = 0; j < x[i]; j++) {
                isW[cur] = false;
                isB[cur] = true;
                cur++;
            }
            cur--;
        }
        else {
            for(int j = 0; j < x[i]; j++) {
                isW[cur] = true;
                isB[cur] = false;
                cur--;
            }
            cur++;
        }
    }

    int white = 0;
    int black = 0;
    for(int i = 0; i < 200000; i++) {
        if(isW[i]) {
            white++;
        }
        if(isB[i]) {
            black++;
        }
    }

    cout << white << " " << black;
    // Please write your code here.

    return 0;
}