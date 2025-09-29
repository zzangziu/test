#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int dp[1001];
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = min(dp[i-2]+1, dp[i-3]+1);
    }

    cout << dp[n];
    return 0;
}