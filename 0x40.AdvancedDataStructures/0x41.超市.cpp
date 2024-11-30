#include <bits/stdc++.h>

class UnionFind {
private:
    int n;
    std::vector<int> dsu;
public:
    UnionFind(int n = 0) : n(n), dsu(n, -1) {}

    int find(int x) {
        if (dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    int unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return x;
        dsu[x] += dsu[y];
        dsu[y] = x;
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -dsu[find(x)];
    }
};


int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (std::cin >> n) {
        std::vector<std::pair<int, int>> arr(n);
        for (auto &[p, d] : arr)
            std::cin >> p >> d;
        std::sort(arr.rbegin(), arr.rend());
        int maxd = 0;
        for (auto &[p, d] : arr)
            maxd = std::max(maxd, d);
        UnionFind dsu(maxd + 1);
        int res = 0;
        for (auto &[p, d] : arr) {
            d = dsu.find(d);
            if (d == 0) continue;
            res += p;
            dsu.unite(d - 1, d);
        }
        std::cout << res << '\n';
    }
    return 0;
}