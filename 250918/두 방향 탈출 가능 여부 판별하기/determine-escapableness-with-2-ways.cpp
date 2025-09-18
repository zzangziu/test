#include <iostream>

using namespace std;

int n, m;
bool grid[101][101];
bool visited[101][101] = {false};
bool flag = false;

void DFS(int x, int y) {
    if(x>n-1 || y>m-1) {
        flag = false;
        return;
    }
    if(x == n-1 && y == m-1) {
        flag = true;
        return;
    }
    if(grid[x][y+1] && !visited[x][y+1]) {
        visited[x][y+1]=true;
        DFS(x, y+1);
    }
    if(grid[x+1][y] && !visited[x+1][y]) {
        visited[x+1][y]=true;
        DFS(x+1, y);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    DFS(0, 0);

    cout << flag;

    // Please write your code here.

    return 0;
}
