#include <iostream>

using namespace std;

int n;
int x[100];
char dir[100];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Please write your code here.
    int cnt[2000] = {0};
    bool check[2000] = {false};
    int zone = 0;
    int cur = 1000;
    for (int i = 0; i < n; i++) {
        if(dir[i]=='R') {
            for(int j = 0; j < x[i]; j++) {
                cnt[cur]++;
                if(cnt[cur]==2 && check[cur]==false) {
                    check[cur]=true;
                    zone++;
                }
                cur++;
            }
        }
        else {
            for(int j = 0; j < x[i]; j++) {
                cnt[cur]++;
                if(cnt[cur]==2 && check[cur]==false) {
                    check[cur]=true;
                    zone++;
                }
                cur--;
            }
        }
    }
    cout << zone;
    return 0;
}