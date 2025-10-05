#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int n, m;

vector<pair<int, int>> graph[100001];
priority_queue<pair<int, int>> pq;
int dist[100001];


int main() {
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[y].push_back(make_pair(x, z));
    }

    for(int i = 1; i<=n; i++) {
        dist[i] = (int)1e9;
    }

    dist[n] = 0;

    pq.push(make_pair(-0, n));

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

    int maxDist = 0;
    for(int i = 1; i<=n; i++) {
        if(dist[i] > maxDist) maxDist = dist[i];
    }
    // Please write your code here.
    cout << maxDist;
    return 0;
}