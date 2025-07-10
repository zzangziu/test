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
    bool wOrB[200000] = {false};

    int cur = 100000;
    for(int i = 0; i < n; i++) {
        if(dir[i]=='R') {
            for(int j = 0; j < x[i]; j++) {
                b[cur]++;
                wOrB[cur]=true;
                cur++;
            }
            cur--;
        }
        else {
            for(int j = 0; j < x[i]; j++) {
                w[cur]++;
                wOrB[cur]=false;
                cur--;
            }
            cur++;

        }
    }

    for(int i = 0; i < 200000; i++) {
        if(w[i] >= 2 && b[i] >= 2) gray++;
        else if(b[i] > w[i]) black++;
        else if(b[i] < w[i]) white++;
        else if(b[i]==1 && w[i]==1) {
            if(wOrB[i]) black++;
            else if(!wOrB[i]) white++;
        }
    }

    cout << white << " " << black << " " << gray;

    return 0;
}