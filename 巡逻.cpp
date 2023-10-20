#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;

map<int, int> g[N+1];

int bfs(int s, int n) {
    vector<int> st(n+1);
    queue<int> q;
    q.push(s);
    st[s] = 1;
    int res = s;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        res = u;
        for (auto &[v, w] : g[u]) {
            if (st[v]) continue;
            q.push(v);
            st[v] = 1;
        }
    }
    return res;
}

int diameter1(int n) {
    int x = bfs(1, n);
    int y = bfs(x, n);
    int res = 0;
    auto dfs = [&](auto &dfs, int pa, int u) {
        if (u == y) return 1;
        for (auto &[v, w] : g[u]) {
            if (v == pa) continue;
            int curr = dfs(dfs, u, v);
            if (curr == 0) continue;
            g[u][v] = g[v][u] = -1;
            return curr + 1;
        }
        return 0;
    };
    return dfs(dfs, x, x) - 1;
}

int diameter2(int n) {
    int res = 0;
    auto dfs = [&](auto &dfs, int pa, int u)->int {
        int du = 0;
        for (auto &[v, w] : g[u]) {
            if (pa == v) continue;
            int dv = dfs(dfs, u, v);
            res = max(res, du + dv + w);
            du = max(du, dv + w);
        }
        return du;
    };
    dfs(dfs, 1, 1);
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }
    int l1 = diameter1(n);
    int l2 = (k > 1 ? diameter2(n) : 0);
    cout << (n - 1) * 2 - l1 - l2 + k << '\n';
    return 0;
}