#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 16;

int dp[maxn][maxn * maxn][maxn][maxn][2][2];

tuple<int, int, int, int, int, int> path[maxn][maxn * maxn][maxn][maxn][2][2];

int mat[maxn][maxn];

void print(tuple<int, int, int, int, int, int> &node) {
    auto &[i, j, l, r, x, y] = node;
    if (i == 0) return;
    print(path[i][j][l][r][x][y]);
    for (int p = l; p <= r; ++p)
        cout << i << ' ' << p << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    int res = 0;
    tuple<int, int, int, int, int, int> last;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            for (int l = 1; l <= m; ++l)
                for (int r = l; r <= m; ++r) {
                    if (r - l + 1 > j) continue;
                    auto &curr = dp[i][j][l][r];
                    auto &curr_p = path[i][j][l][r];
                    auto &pre = dp[i - 1][j - (r - l + 1)];
                    int sum = 0, jj = j - (r - l + 1);
                    for (int p = l; p <= r; ++p)
                        sum += mat[i][p];
                    int val[2][2] = {0};
                    for (int x = 0; x <= 1; ++x)
                        for (int p = 1; p <= l; ++p)
                            for (int q = l; q <= r; ++q)
                                if (pre[p][q][x][0] > val[0][0]) {
                                    val[0][0] = pre[p][q][x][0];
                                    curr_p[0][0] = tuple{i - 1, jj, p, q, x, 0};
                                }    
                    for (int x = 0; x <= 1; ++x)
                        for (int y = 0; y <= 1; ++y)
                            for (int p = 1; p <= l; ++p)
                                for (int q = r; q <= m; ++q) 
                                    if (pre[p][q][x][y] > val[0][1]) {
                                        val[0][1] = pre[p][q][x][y];
                                        curr_p[0][1] = tuple{i - 1, jj, p, q, x, y};
                                    }
                    for (int p = l; p <= r; ++p)
                        for (int q = p; q <= r; ++q)
                            if (pre[p][q][1][0] > val[1][0]) {
                                val[1][0] = pre[p][q][1][0];
                                curr_p[1][0] = tuple{i - 1, jj, p, q, 1, 0};
                            }
                    for (int y = 0; y <= 1; ++y)
                        for (int p = l; p <= r; ++p)
                            for (int q = r; q <= m; ++q)
                                if (pre[p][q][1][y] > val[1][1]) {
                                    val[1][1] = pre[p][q][1][y];
                                    curr_p[1][1] = tuple{i - 1, jj, p, q, 1, y};
                                }
                    for (int x = 0; x <= 1; ++x)
                        for (int y = 0; y <= 1; ++y) {
                            curr[x][y] = sum + val[x][y];
                            if (curr[x][y] > res) {
                                res = curr[x][y];
                                last = tuple{i, j, l, r, x, y};
                            }
                        }
                }
    cout << "Oil : " << res << '\n';
    print(last);
    return 0;
}