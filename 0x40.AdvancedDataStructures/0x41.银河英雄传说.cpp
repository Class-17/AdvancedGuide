#include <bits/stdc++.h>

constexpr int N = 3e4;

class UnionFind {
private:
    int n;
    std::vector<int> fa, size, dist;
public:
    UnionFind(int n = 0) : n(n), fa(n, -1), dist(n), size(n, 1) {}

    int find(int x) {
        if (fa[x] == -1) return x;
        int root = find(fa[x]);
        dist[x] += dist[fa[x]];
        return fa[x] = root;
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        fa[x] = y;
        dist[x] += size[y];
        size[y] += size[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get_dist(int x) {
        return dist[x];
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int m; std::cin >> m;
    UnionFind dsu(N + 1);
    while (m--) {
        std::string s;
        int i, j;
        std::cin >> s >> i >> j;
        if (s == "M") {
            dsu.unite(i, j);
        }
        else {
            if (i == j)
                std::cout << 0 << '\n';
            else if (dsu.same(i, j))
                std::cout << std::abs(dsu.get_dist(i) - dsu.get_dist(j)) - 1 << '\n';
            else
                std::cout << -1 << '\n';
        }
    }
    return 0;
}