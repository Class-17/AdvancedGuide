#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> g(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> g[i];
    vector<int> id(n + 1);
    iota(begin(id), end(id), 0);
    sort(begin(id) + 1, end(id), [&](const auto &a, const auto &b) {
        return g[a] > g[b];
    });
    vector dp(n + 1, vector(m + 1, 0x3f3f3f3f * 10LL));
    dp[0][0] = 0;
    vector path(n + 1, vector<pair<int, int>>(m + 1));
    vector sum(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + g[id[i]];
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= m; ++j) {
            dp[i][j] = dp[i][j - i];
            path[i][j] = pair{i, j - i};
            for (int k = 0; k < i; ++k) {
                ll val = dp[k][j - (i - k)] + k * (sum[i] - sum[k]);
                if (val >= dp[i][j]) continue;
                dp[i][j] = val;
                path[i][j] = pair{k, j - (i - k)};
            }
        }
    cout << dp[n][m] << '\n';
    vector<int> res(n + 1);
    auto dfs = [&](auto &dfs, int x, int y) {
        if (x == 0) return;
        auto &[nx, ny] = path[x][y];
        dfs(dfs, nx, ny);
        if (nx == x)
            for (int i = 1; i <= x; ++i)
                ++res[id[i]];
        else
            for (int i = nx + 1; i <= x; ++i)
                res[id[i]] = 1;
    };
    dfs(dfs, n, m);
    for (int i = 1; i <= n; ++i)
        cout << res[i] << (i < n ? ' ' : '\n');
    return 0;
}