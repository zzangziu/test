#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n));
    if(m==1) {
        cout << n*2;
        return 0;
    }
    for(int i=0; i<n; i++) {
        for(int j = 0; j<n; j++) {
             cin >> v[i][j];
        }
    }
    int happy = 0;
    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=0; j<n-1; j++) {
            if(v[i][j] == v[i][j+1]) count++;
            else count = 1;
            if(m <= count) {
                happy++;
                break;
            }
        }
    }
    for(int i=0; i<n; i++) {
        int count = 1;
        for(int j=0; j<n-1; j++) {
            if(v[j][i] == v[j+1][i]) count++;
            else count=1;
            if(m <= count) {
                happy++;
                break;
            }
        }
    }
    cout << happy;
    return 0;
}