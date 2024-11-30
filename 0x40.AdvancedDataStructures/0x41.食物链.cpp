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
        if (dsu[x] > dsu[y]) std::swap(x, y);
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
    int n, k;
    std::cin >> n >> k;
    UnionFind dsu(n * 3 + 1);
    // [1, n]: same
    // [n + 1, n * 2]: eat
    // [n * 2 + 1, n * 3]: begin eaten
    int res = 0;
    for (int i = 0; i < k; ++i) {
        int d, x, y;
        std::cin >> d >> x >> y;
        if (x > n or y > n)
            res += 1;
        else if (d == 1) {
            if (dsu.same(x, y + n) or dsu.same(x, y + n * 2))
                res += 1;
            else {
                dsu.unite(x, y);
                dsu.unite(x + n, y + n);
                dsu.unite(x + n * 2, y + n * 2);
            }
        }
        else if (d == 2) {
            if (dsu.same(x, y) or dsu.same(x, y + n))
                res += 1;
            else {
                dsu.unite(x, y + n * 2);
                dsu.unite(x + n, y);
                dsu.unite(x + n * 2, y + n);
            }
        }
    }
    std::cout << res << '\n';
    return 0;
}