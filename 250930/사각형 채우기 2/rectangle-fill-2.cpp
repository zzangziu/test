#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int dp[1001];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i<= n; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    
    cout << dp[n];
    return 0;
}
