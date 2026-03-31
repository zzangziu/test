#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    int max = 0;
    for(int i =0; i<n; i++) {
        for(int j=0; j<m; j++) {
            multiset<int> s;
            int l, r, u, d;
            if(i!=0) {
                u = v[i-1][j];
            } else u = 0;
            if(j!=0) {
                l = v[i][j-1];
            } else l = 0;
            if(i!=n-1) {
                d = v[i+1][j];
            } else d = 0;
            if(j!=m-1) {
                r = v[i][j+1];
            } else r = 0;
            s.insert(l);
            s.insert(r);
            s.insert(u);
            s.insert(d);

            auto it = s.rbegin(); // 가장 큰 값 (50)
            int first_max = *it;

            it++; // 그다음 큰 값으로 이동 (40)
            int second_max = *it;
            int current = first_max + second_max + v[i][j];
            if(max < current) max =current;
        }
    }
    cout << max;
    return 0;
}