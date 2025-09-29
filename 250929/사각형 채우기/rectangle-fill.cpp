#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    // Please write your code here.
    int dp[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i = 4; i<= n; i++) {
        dp[i] = (dp[i-2] + dp[i-1])%10007;
    }

    cout << dp[n];
    return 0;
}
