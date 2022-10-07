#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector mat(n, vector<int>(n));
    for (auto &row : mat) for (auto &x : row) cin >> x;
    vector dp(n, vector<int>(n, inf));
    dp[0][1] = 0;
    int p = 2;
    for (int i = 0; i < m; ++i) {
        int q; cin >> q; --q;
        vector curr(n, vector<int>(n, inf));
        for (int x = 0; x < n; ++x)
            for (int y = 0; y < n; ++y) {
                if (x == y or x == p or y == p) continue;
                curr[x][y] = min(curr[x][y], dp[x][y] + mat[p][q]);
                curr[p][y] = min(curr[p][y], dp[x][y] + mat[x][q]);
                curr[x][p] = min(curr[x][p], dp[x][y] + mat[y][q]);
            }
        dp = move(curr);
        p = q;
    }
    int res = inf;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j and i != p and j != p)
                res = min(res, dp[i][j]);
    cout << res << '\n';
    return 0;
}