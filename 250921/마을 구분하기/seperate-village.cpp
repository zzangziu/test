#include <iostream>
#include <algorithm>

using namespace std;

int n;
bool grid[25][25] = {false};
bool visited[25][25] = {false};
int cnt = 0;
int people;
int city[625]={0};

void DFS(int x, int y) {
    // 1) 범위/조건 체크
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (!grid[x][y] || visited[x][y]) return;

    // 2) 현재 칸 방문 처리 (한 번만)
    visited[x][y] = true;
    people++;

    // 3) 네 방향으로 퍼지기 (이웃을 미리 방문표시/증가 X)
    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j] && !visited[i][j]) {
                people = 0;
                DFS(i, j);
                city[cnt++]=people;
            }
        }
    }

    cout << cnt << "\n";
    sort(city, city + cnt);
    for(int i = 0; i < cnt; i++) {
        cout << city[i] << '\n';
    }
    // Please write your code here.

    return 0;
}
