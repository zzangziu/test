#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m, k;

vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>> pq;
int dist[20001];


int main() {
    cin >> n >> m;
    cin >> k;


    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }

    for(int i = 1; i<=n; i++) {
        dist[i] = (int)1e9;
    }

    dist[k] = 0;

    pq.push(make_pair(-0, k));

    while(!pq.empty()) {
        int minDist, minIndex;
        tie(minDist, minIndex) = pq.top();
        pq.pop();

        minDist = -minDist;

        if(minDist != dist[minIndex]) continue;

        for(int j = 0; j<(int)graph[minIndex].size(); j++) {
            int targetIndex, targetDist;
            tie(targetIndex, targetDist) = graph[minIndex][j];

            int newDist = dist[minIndex] + targetDist;
            if(dist[targetIndex] > newDist) {
                dist[targetIndex] = newDist;
                pq.push(make_pair(-newDist, targetIndex));
            }
        }
    }

    for(int i = 1; i<=n; i++) {
        if(dist[i] == (int)1e9) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    // Please write your code here.

    return 0;
}
