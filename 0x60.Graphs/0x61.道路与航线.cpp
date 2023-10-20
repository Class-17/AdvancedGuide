#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

constexpr int N = 25000;

vector<pii> g[N+1];

int dist[N+1], id[N+1];

vector<int> part[N+1];

void dfs(int u, int x) {
    if (id[u]) return;
    id[u] = x;
    part[x].push_back(u);
    for (auto &[v, w] : g[u])
        dfs(v, x);
}

void dijkstra(int x) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    for (auto &u : part[x])
        pq.emplace(dist[u], u);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto &[v, w] : g[u]) {
            if (id[v] != id[u]) continue;
            if (dist[v] <= d + w) continue;
            dist[v] = d + w;
            pq.emplace(d + w, v);
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m1, m2, s;
    cin >> n >> m1 >> m2 >> s;
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    for (int i = 0; i < m1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int cnt = 1;
    for (int i = 1; i <= n; ++i)
        if (id[i] == 0) dfs(i, cnt++);
    vector<int> de(cnt);
    for (int i = 0; i < m2; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        ++de[id[v]];
    }
    queue<int> q;
    for (int i = 1; i < cnt; ++i)
        if (de[i] == 0) q.push(i);
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        dijkstra(x);
        for (auto &u : part[x])
            for (auto &[v, w] : g[u]) {
                if (id[u] == id[v]) continue;
                dist[v] = min(dist[v], dist[u] + w);
                if (--de[id[v]] == 0)
                    q.push(id[v]);
            }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] <= 0x3f3f3f3f / 2)
            cout << dist[i] << '\n';
        else
            cout << "NO PATH" << '\n';
    }
    return 0;
}