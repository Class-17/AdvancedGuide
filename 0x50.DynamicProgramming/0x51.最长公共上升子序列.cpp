#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    a[0] = b[0] = INT_MIN;
    vector dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        int val = 0;
        if (b[0] < a[i]) val = dp[i - 1][0];
        for (int j = 1; j <= n; ++j) {
            if (a[i] == b[j]) dp[i][j] = val + 1;
            else              dp[i][j] = dp[i - 1][j];
            if (b[j] < a[i]) val = max(val, dp[i - 1][j]);
        }
    }
    cout << *max_element(begin(dp[n]), end(dp[n])) << '\n';
    return 0;
}