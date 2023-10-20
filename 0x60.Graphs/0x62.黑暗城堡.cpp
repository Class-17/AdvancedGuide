#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

constexpr int N = 1e3;
constexpr int MOD = INT_MAX;

vector<pii> g[N+1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    priority_queue<pii, vector<pii>, greater<>> pq;
    vector<int> dist(n+1, INT_MAX), cnt(n+1);
    pq.emplace(0, 1);
    dist[1] = 0;
    cnt[1] = 1;
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[v] < d + w) continue;
            if (dist[v] == d + w) {
                ++cnt[v];
            }
            else {
                dist[v] = d + w;
                cnt[v] = 1;
                pq.emplace(d + w, v);
            }
        }
    }
    i64 res = 1;
    for (int i = 1; i <= n; ++i)
        res = res * cnt[i] % MOD;
    cout << res << '\n';
    return 0;
}