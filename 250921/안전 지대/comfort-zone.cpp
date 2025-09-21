#include <iostream>

using namespace std;

int N, M;
int K;
int cnt;
int grid[50][50] = {0};
bool visited[50][50];

void DFS(int x, int y) {
    if(x < 0 || y < 0 || x >= N || y >= M) return;
    if(visited[x][y] || grid[x][y] <= K) return;
    visited[x][y] = true;

    DFS(x+1, y);
    DFS(x-1, y);
    DFS(x, y+1);
    DFS(x, y-1);
}

int main() {
    cin >> N >> M;

    int maxH = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
            if(maxH < grid[i][j]) maxH = grid[i][j];
        }
    }

    K = 0;
    int max = 0;
    int maxK = 1;
    for(K = 1; K <= maxH; K++) {
        for (int i=0;i<N;++i) {
            for (int j=0;j<M;++j) {
                visited[i][j] = false;
            }
        }

        int curMax = 0;
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && grid[i][j] > K) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }
        if(cnt > curMax) curMax = cnt;

        if(curMax > max) {
            max = curMax;
            maxK = K;
        }

    }

    cout << maxK << " " << max;



    // Please write your code here.

    return 0;
}
