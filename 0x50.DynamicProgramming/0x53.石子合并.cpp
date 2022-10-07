#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector dp(n + 1, vector(n + 1, lim));
    partial_sum(begin(arr), end(arr), begin(arr));
    for (int i = 0; i < n; ++i)
        dp[i][i + 1] = 0;
    for (int len = 2; len <= n; ++len)
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len;
            for (int k = l + 1; k < r; ++k)
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
            dp[l][r] += arr[r - 1] - (l > 0 ? arr[l - 1] : 0);
        }
    cout << dp[0][n] << '\n';
    return 0;
}