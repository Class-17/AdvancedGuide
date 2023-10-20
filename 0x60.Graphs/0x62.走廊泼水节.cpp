#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
    int n;
    vector<int> dsu;
public:
    UnionFind(int n = 0) : n(n), dsu(n, -1) {}

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
        return true;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        int res = 0;
        UnionFind dsu(n + 1);
        vector<tuple<int, int, int>> es(n - 1);
        for (auto &[w, u, v] : es)
            cin >> u >> v >> w;
        sort(begin(es), end(es));
        for (auto &[w, u, v] : es) {
            int cu = dsu.size(u), cv = dsu.size(v);
            dsu.unite(u, v);
            res += (cu * cv - 1) * (w + 1);
        }
        cout << res << '\n';
    }
    return 0;
}