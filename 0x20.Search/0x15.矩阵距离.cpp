#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

vector<string> mat;

int n, m;

vector<vector<int>> bfs() {
    vector<vector<int>> dist(n, vector<int>(m, n * m));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] != '1') continue;
            dist[i][j] = 0;
            q.emplace(i, j);
        } 
    int step = 0;
    while (!q.empty()) {
        int len = size(q);
        while (len--) {
            auto [r, c] = q.front(); q.pop();
            if (step < dist[r][c]) continue;
            for (auto &[dr, dc] : dirs) {
                auto [nr, nc] = pair{r + dr, c + dc};
                if (nr < 0 or nc < 0 or nr >= n or nc >= m) continue;
                if (dist[nr][nc] <= step + 1) continue;
                dist[nr][nc] = step + 1;
                q.emplace(nr, nc);
            }
        }
        ++step;
    }
    return dist;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    mat = vector<string>(n);
    for (auto &row : mat) cin >> row;
    auto dist = bfs();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cout << dist[i][j] << (j + 1 < m ? ' ' : '\n');
    return 0;
}