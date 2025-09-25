#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
bool a[100][100] = {false};
bool visited[100][100] = {false};
queue<pair<int,int>> q;
int x, y;

bool canGo (int x, int y) {
    if(x < 0 || y < 0 || x > n || y > m) return false;
    if(visited[x][y] || !a[x][y]) return false;
    return true;
}

void BFS() {
    while(!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        x = pos.first;
        y = pos.second;
        if(!a[x][y]) visited[x][y];

        if(canGo(x+1, y)) {
            visited[x+1][y]= true;
            q.push(make_pair(x+1, y));
        }
        if(canGo(x-1, y)) {
            visited[x-1][y]= true;
            q.push(make_pair(x-1, y));
        }
        if(canGo(x, y+1)) {
            visited[x][y+1]= true;
            q.push(make_pair(x, y+1));
        }
        if(canGo(x, y-1)) {
            visited[x][y-1]= true;
            q.push(make_pair(x, y-1));
        }
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // Please write your code here.
    q.push(make_pair(0, 0));
    visited[0][0]=true;
    BFS();
    if(visited[n-1][m-1]) cout << "1";
    else cout << "0";

    return 0;
}
