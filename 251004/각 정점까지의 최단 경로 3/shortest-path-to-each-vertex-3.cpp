#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m; 
int graph[101][101];
bool visited[101];
int dist[101];

int main () {
    cin >> n >> m;

    while(m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
    }

    for(int i = 1; i<=n; i++) {
        dist[i] = (int)1e9;
    }

    dist[1] = 0;

    for(int i = 1; i<= n; i++) {
        int minIndex = -1;
        for(int j = 1; j<=n; j++) {
            if(visited[j]) continue;

            if(minIndex == -1 || dist[minIndex] > dist[j]) minIndex = j;
        }

        visited[minIndex] = true;

        for(int j = 1; j <= n; j++) {
            if(graph[minIndex][j] == 0) continue;

            dist[j] = min(dist[j], dist[minIndex] + graph[minIndex][j]);
        }
    }

    for(int i = 2; i<= n; i++) {
        if(dist[i]==(int)1e9) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
}




