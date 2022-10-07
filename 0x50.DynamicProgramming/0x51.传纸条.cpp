#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector mat(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    vector dp(n + 1, vector(n + 1, INT_MIN));
    dp[1][1] = mat[1][1];
    for (int k = 3; k <= n + m; ++k) {
        vector curr(n + 1, vector(n + 1, INT_MIN));
        for (int r1 = 1; r1 <= n; ++r1)
            for (int r2 = 1; r2 <= n; ++r2) {
                int c1 = k - r1, c2 = k - r2;
                if (c1 <= 0 or c1 > m or c2 <= 0 or c2 > m) continue;
                const int &a = dp[r1 - 1][r2], &b = dp[r1][r2 - 1];
                const int &c = dp[r1 - 1][r2 - 1], &d = dp[r1][r2];
                curr[r1][r2] = max({a, b, c, d}) + mat[r1][c1];
                if (r1 != r2) curr[r1][r2] += mat[r2][c2];
            }
        dp = move(curr);
    }
    cout << dp[n][n] << '\n';
    return 0;
}