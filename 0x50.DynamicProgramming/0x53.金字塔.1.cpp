#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    vector dp(n + 1, vector(n + 1, 0));
    for (int i = 0; i < n; ++i)
        dp[i][i + 1] = 1;
    for (int len = 2; len <= n; ++len)
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            if (s[l] != s[r - 1]) continue;
            for (int k = l + 2; k < r; ++k)
                if (s[l + 1] == s[k - 1])
                    dp[l][r] = (dp[l][r] + 1LL * dp[l + 1][k] * dp[k][r]) % mod;
        }
    cout << dp[0][n] << '\n';
    return 0;
}