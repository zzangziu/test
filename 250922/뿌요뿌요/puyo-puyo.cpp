#include <iostream>

using namespace std;

int n;
int grid[100][100]={0};
bool visited[100][100] = {false};
int bomb;
bool result;

void DFS(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= n) return;
    if(visited[x][y]) return;
    
    int tmp = grid[x][y];
    visited[x][y]=true;
    bomb++;
    if(bomb >= 4) result = false;

    if(tmp == grid[x+1][y]) DFS(x+1, y);
    if(tmp == grid[x-1][y]) DFS(x-1, y);
    if(tmp == grid[x][y+1]) DFS(x, y+1);
    if(tmp == grid[x][y-1]) DFS(x, y-1);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    int maxBlock = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] > 0 && !visited[i][j]) {
                bomb = 0;
                result = true;
                DFS(i, j);
                if(!result) {
                    cnt++;
                }
                if(bomb > maxBlock) maxBlock = bomb;
            }
        }
    }

    cout << cnt << " " << maxBlock;



    return 0;
}
