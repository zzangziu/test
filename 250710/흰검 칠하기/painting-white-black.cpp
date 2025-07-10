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

    // Please write your code here.
    int white = 0;
    int black = 0;
    int gray = 0;

    int w[200000] = {0};
    int b[200000] = {0};
    bool wh[200000] = {false};
    bool bl[200000] = {false};

    int cur = 100000;
    for(int i = 0; i < n; i++) {
        if(dir[i]=='R') {
            for(int j = 0; j < x[i]; j++) {
                b[cur]++;
                bl[cur]=true;
                wh[cur]=false;
                cur++;
            }
            cur--;
        }
        else {
            for(int j = 0; j < x[i]; j++) {
                w[cur]++;
                wh[cur]=true;
                bl[cur]=false;
                cur--;
            }
            cur++;

        }
    }

    for(int i = 0; i < 200000; i++) {
        if(w[i] >= 2 && b[i] >= 2) gray++;
        else if(wh[i]) white++;
        else if(bl[i]) black++;
    }

    cout << white << " " << black << " " << gray;

    return 0;
}