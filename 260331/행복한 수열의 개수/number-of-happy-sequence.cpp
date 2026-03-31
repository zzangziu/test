#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    <vector<vector<int>> v(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j = 0; j<n; j++) {
             cin >> v[i][j];
        }
    }
    int happy = 0;
    for(int i=0; i<n; i++) {
        int count = 0;
        for(int j=0; j<n; j++) {
            if(v[i][j] == v[i][j+1]) count++;
            if(m <= count) happy++;
        }
    }
    for(int i=0; i<n; i++) {
        int count = 0;
        for(int j=0; j<n; j++) {
            if(v[j][i] == v[j][i+1]) count++;
            if(m <= count) happy++;
        }
    }
    cout << happy;
    return 0;
}