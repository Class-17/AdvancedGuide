#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 20;

int n, g[maxn][maxn], dp[1 << maxn][maxn];

int Hamilton() {
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    for (int i = 1; i < (1 << n); ++i)
        for (int u = 0; u < n; ++u) {
            if (i >> u & 1 ^ 1) continue;
            for (int v = 0; v < n; ++v) {
                if (u == v or (i >> v & 1 ^ 1)) continue;
                dp[i][u] = min(dp[i][u], dp[i ^ 1 << u][v] + g[u][v]);
            }
        }
    return dp[(1 << n) - 1][n - 1];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    cout << Hamilton() << '\n';
    return 0;
}