#include <iostream>

using namespace std;

int n;
int grid[100][100];
int res[100][100] = {0};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    res[0][0] = grid[0][0];
    for(int i = 1; i<n; i++) {
        res[i][0] = res[i-1][0] + grid[i][0];
        res[0][i] = res[0][i-1] + grid[0][i];
    }

    for(int i =1; i<n;i++) {
        for(int j =1; j<n; j++) {
            res[i][j] = max(res[i-1][j], res[i][j-1])+grid[i][j];
        }
    }

    cout << res[n-1][n-1];

    // Please write your code here.

    return 0;
}
