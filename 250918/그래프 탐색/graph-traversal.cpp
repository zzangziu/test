#include <iostream>

using namespace std;

int n, m;
int cnt=0;
int from[10000], to[10000];
bool graph[10000][10000] = {false};
bool visited[10000] = {false};

void DFS(int vertex) {
    for(int cur_v = 1; cur_v <= n; cur_v++) {
        if(graph[vertex][cur_v] && !visited[cur_v]) {
            cnt++;
            visited[cur_v] = true;
            DFS(cur_v);
        }
    }
}

int main() {
    cin >> n >> m;

    visited[1] = true;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from][to]=true;
        graph[to][from]=true;
    }

    DFS(1);
    cout << cnt;

    // Please write your code here.

    return 0;
}
