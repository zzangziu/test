#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;
    vector<int> v(3*n+1);
    for(int i = 0; i<n*3; i++) {
        cin >> v[i];
    }
    t = t % (n*3);

    for(int i =0; i<t; i++) {
        for(int j=n*3; j>=0; j--) {
            v[j] = v[j-1];
        }
        v[0] = v[3*n];
    }

    for(int i = 0; i<v.size() - 1; i++) {
        if(i == n || i == 2*n) {
            cout << '\n';
        }
        cout << v[i] << ' ';
    }
    return 0;
}
