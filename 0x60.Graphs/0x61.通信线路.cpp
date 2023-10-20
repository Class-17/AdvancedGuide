#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000;

using pii = pair<int, int>;

vector<pii> g[N + 1];

int check(int n, int x) {
    deque<pii> q;
    q.emplace_back(0, 1);
    vector<int> dist(n + 1, n);
    dist[1] = 0;
    while (!q.empty()) {
        auto [d, u] = q.front(); q.pop_front();
        if (d > dist[u]) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[v] <= d + (w > x)) continue;
            dist[v] = d + (w > x);
            if (w > x)
                q.emplace_back(dist[v], v);   
            else
                q.emplace_front(dist[v], v);
        }
    }
    return dist[n];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, p, k;
    cin >> n >> p >> k; 
    int maxw = 0;
    for (int i = 0; i < p; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        maxw = max(maxw, w);
    }
    int lo = 0, hi = maxw;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (check(n, mid) > k)
            lo = mid + 1;
        else
            hi = mid;
    }
    cout << (check(n, lo) < n ? lo : -1) << '\n';
    return 0;
}