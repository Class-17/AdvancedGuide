#include <bits/stdc++.h>
using namespace std;

constexpr int maxm = 5000;

int s[maxm + 1][maxm + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        s[x][y] += w;
    }
    auto f = [&](int r, int c) {
        if (r < 0 || c < 0) return 0;
        return s[r][c];
    };
    for (int i = 0; i <= maxm; ++i)
        for (int j = 0; j <= maxm; ++j)
            s[i][j] += f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);
    int res = 0;
    for (int i = 0; i <= maxm; ++i)
        for (int j = 0; j <= maxm; ++j)
            res = max(res, f(i, j) - f(i - m, j) - f(i, j - m) + f(i - m, j - m));
    cout << res << '\n';
    return 0;
}