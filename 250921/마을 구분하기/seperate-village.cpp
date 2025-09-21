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
    bool flag = false;
    if(!visited[x][y]) {
        visited[x][y]=true;
        people++;
    }

    if(grid[x+1][y] && !visited[x+1][y]) {
        visited[x+1][y]=true;
        people++;
        flag = true;
        DFS(x+1, y);
    }
    if(grid[x-1][y] && !visited[x-1][y]) {
        visited[x-1][y]=true;
        people++;
        flag = true;
        DFS(x-1, y);
    }
    if(grid[x][y+1] && !visited[x][y+1]) {
        visited[x][y+1]=true;
        people++;
        flag = true;
        DFS(x, y+1);
    }
    if(grid[x][y-1] && !visited[x][y-1]) {
        visited[x][y-1]=true;
        people++;
        flag = true;
        DFS(x, y-1);
    }
    
    if(x >= n || y >= n) {
        if(people != 0) {
            city[cnt]=people;
            cnt++;
        }
        return;
    }
    if (!flag) {
        if(people != 0) {
            cout << x << " " << y << '\n';
            city[cnt]=people;
            cnt++;
        }
        return;
    }
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
