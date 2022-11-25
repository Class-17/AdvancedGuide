#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        int u, w;
        cin >> u >> arr[i];
        g[u].push_back(i);
    }
    vector dp(n + 1, vector(m + 1, -lim));
    auto dfs = [&](auto &f, int idx)->void {
        dp[idx][0] = 0;
        for (auto &x : g[idx]) {
            f(f, x);
            for (int i = m; i > 0; --i)
                for (int j = 1; j <= i and dp[x][j] > 0; ++j)
                    dp[idx][i] = max(dp[idx][i], dp[idx][i - j] + dp[x][j]);
        }
        if (idx == 0) return;
        for (int i = m; i > 0; --i)
            dp[idx][i] = dp[idx][i - 1] + arr[idx];
    };
    dfs(dfs, 0);
    cout << dp[0][m] << '\n';
    return 0;
}