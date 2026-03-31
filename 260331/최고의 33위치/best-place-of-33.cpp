#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    int max = 0;

    for(int i=0; i<=n-3; i++) {
        for(int j=0; j<=n-3; j++) {
            int current = 0;
            for(int k=0; k<3; k++) {
                for(int t=0; t<3; t++) {
                    if(v[i+k][j+t]) current++;
                }
            }

            if(current > max) max = current;
        }
    }
    
    cout << max;
    return 0;
}