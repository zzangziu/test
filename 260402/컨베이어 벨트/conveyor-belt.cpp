#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;
    vector<int> v(2*n + 1);
    for(int i=0; i<n*2; i++) {
        cin >> v[i];
    }
    t %= n*2;

    

    for(int i = 0; i<t; i++) {
        for(int j = n*2; j>=0; j--) {
            v[j] = v[j-1];
        }
        v[0] = v[2*n];
    }

    for(int i = 0; i<v.size() - 1; i++) {
        if(i == n) {
            cout << '\n';
        }
        cout << v[i] << ' ';
    }
    return 0;
}