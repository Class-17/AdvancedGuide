#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][4][3] {
    {0, 1, 1, 1, 0, 2, 0, -2, 1, -2, 0, 2}, 
    {0, 2, 0, 1, 0, 1, 0, -1, 0, -1, 0, 1}, 
    {0, 1, 2, 2, 0, 0, 0, -1, 2, -1, 0, 0}};

constexpr int maxn = 500;

int n, m;

vector<string> mat;

bool check(int r, int c) {
    if (r < 0 or c < 0 or r >= n or c >= m) return false;
    return mat[r][c] != '#';
}

int bfs(const tuple<int, int, int> &s) {
    bitset<maxn * maxn + 1> st[3];
    queue<tuple<int, int, int>> q;
    st[get<2>(s)][get<0>(s) * maxn + get<1>(s)] = 1;
    q.push(s);
    int step = 0;
    while (!q.empty()) {
        int len = size(q);
        while (len--) {
            auto [r, c, t] = q.front(); q.pop();
            if (t == 0 and mat[r][c] == 'O') return step;
            for (auto [dr, dc, dt] : dirs[t]) {
                auto [nr, nc, nt] = tuple{r + dr, c + dc, dt};
                if (!check(nr, nc) or st[nt][nr * maxn + nc]) continue;
                if (nt == 0 and mat[nr][nc] == 'E') continue;
                if (nt == 1 and !check(nr, nc + 1)) continue;
                if (nt == 2 and !check(nr + 1, nc)) continue;
                st[nt][nr * maxn + nc] = 1;
                q.emplace(nr, nc, nt);
            }
        }
        ++step;
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while (cin >> n >> m and n and m) {
        mat = vector<string>(n);
        for (auto &row : mat) cin >> row;
        auto find = [&]()->tuple<int, int, int> {
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    if (mat[i][j] != 'X') continue;
                    if (j + 1 < m and mat[i][j + 1] == 'X')
                        return {i, j, 1};
                    else if (i + 1 < n and mat[i + 1][j] == 'X')
                        return {i, j, 2};
                    return {i, j, 0};
                }
            return {0, 0, 0};
        };
        int res = bfs(find());
        if (res >= 0) cout << res << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}