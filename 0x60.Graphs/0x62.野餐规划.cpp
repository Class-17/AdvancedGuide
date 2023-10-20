#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    int n, cnt;
    vector<int> dsu;
public:
    UnionFind(int n = 0) : n(n), cnt(n), dsu(n, -1) {}

    int find(int x) {
        return dsu[x] >= 0 ? dsu[x] = find(dsu[x]) : x;
    }

    int size(int x) {
        return -dsu[x = find(x)];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
        cnt -= 1;
        return true;
    }

    int part() {
        return cnt;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m; cin >> m;
    map<string, int> mp;
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < m; ++i) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        if (!mp.count(u)) mp[u] = size(mp);
        if (!mp.count(v)) mp[v] = size(mp);
        es.emplace_back(w, mp[u], mp[v]);
    }
    sort(begin(es), end(es));
    int s; cin >> s;
    int p = mp["Park"], n = size(mp);
    vector<map<int, int>> g(n);
    vector<int> st(m);
    int res = 0;
    UnionFind dsu(n);
    for (int i = 0; i < m; ++i) {
        auto &[w, u, v] = es[i];
        if (u == p or v == p) continue;
        if (dsu.unite(u, v)) {
            res += w;
            st[i] = 1;
            g[u][v] = g[v][u] = w;
        }
    }
    for (int i = 0; i < m and s > 0; ++i) {
        auto &[w, u, v] = es[i];
        if (dsu.unite(u, v)) {
            res += w;
            st[i] = 1;
            g[u][v] = g[v][u] = w;
            --s;
        }
    }
    auto dfs = [&](auto &dfs, int pa, int u, int t)->pair<int,int> {
        for (auto &[v, w] : g[u]) {
            if (pa == v) continue;
            if (v == t) return {u, v};
            auto [x, y] = dfs(dfs, u, v, t);
            if (x == -1) continue;
            if (g[x][y] < w)
                return {u, v};
            else
                return {x, y};
        }
        return {-1, -1};
    };
    vector<int> minus;
    for (int i = 0; i < m; ++i) {
        auto &[w, u, v] = es[i];
        if (st[i] or (u != p and v != p)) continue;
        if (u != p) swap(u, v);
        auto [x, y] = dfs(dfs, u, u, v);
        if (x != -1 and g[x][y] > w)
            minus.push_back(w - g[x][y]);
    }
    sort(begin(minus), end(minus));
    for (int i = 0; i < s and i < size(minus); ++i)
        res += minus[i];
    cout << "Total miles driven: " << res << '\n';
    return 0;
}