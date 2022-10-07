#include <bits/stdc++.h>
using namespace std;

constexpr uint32_t mod = 2147483648;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector dp(n + 1, 0U);
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n; ++j)
            dp[j] = (dp[j] + dp[j - i]) % mod;
    cout << dp[n] << '\n';
    return 0;
}