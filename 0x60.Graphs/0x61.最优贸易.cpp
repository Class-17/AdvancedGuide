#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;

vector<int> ga[N+1], gb[N+1];

int w[N+1];

vector<int> spfaA(int n) {
    queue<int> q;
    vector<int> d(n + 1, INT_MAX),  st(n + 1);
    d[1] = w[1];
    st[1] = 1;
    q.push(1);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        st[u] = 0;
        for (auto &v : ga[u])
            if (min(d[u], w[v]) < d[v]) {
                d[v] = min(d[u], w[v]) ;
                if (!st[v]) {
                    q.push(v);
                    st[v] = 1;
                }
            }
    }
    return d;
}

vector<int> spfaB(int n) {
    queue<int> q;
    vector<int> d(n + 1), st(n + 1);
    d[n] = w[n];
    st[n] = 1;
    q.push(n);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        st[u] = 0;
        for (auto &v : gb[u])
            if (max(d[u], w[v]) > d[v]) {
                d[v] = max(d[u], w[v]) ;
                if (!st[v]) {
                    q.push(v);
                    st[v] = 1;
                }
            }
    }
    return d;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        ga[u].push_back(v);
        gb[v].push_back(u);
        if (t == 1) continue;
        ga[v].push_back(u);
        gb[u].push_back(v);
    }
    auto da = spfaA(n);
    auto db = spfaB(n);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, db[i] - da[i]);
    cout << res << '\n';
    return 0;
}